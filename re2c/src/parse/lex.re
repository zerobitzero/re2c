#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>

#include "src/ir/dfa/dfa.h"
#include "src/globals.h"
#include "src/parse/extop.h"
#include "src/parse/parser.h"
#include "src/parse/scanner.h"
#include "src/parse/unescape.h"
#include "y.tab.h"
#include "src/util/s_to_n32_unsafe.h"

extern YYSTYPE yylval;

#define	YYCTYPE		unsigned char
#define	YYCURSOR	cur
#define	YYLIMIT		lim
#define	YYMARKER	ptr
#define	YYCTXMARKER ctx
#define	YYFILL(n)	{ fill (n); }

namespace re2c
{

// source code is in ASCII: pointers have type 'char *'
// but re2c makes an implicit assumption that YYCTYPE is unsigned
// when it generates comparisons
/*!re2c
	re2c:yych:conversion = 1;
*/

/*!re2c
zero    = "\000";
dstring = "\"" ((. \ [\\"] ) | "\\" .)* "\"";
sstring = "'"  ((. \ [\\'] ) | "\\" .)* "'" ;
letter  = [a-zA-Z];
digit   = [0-9];
lineno  = [1-9] digit*;
name    = (letter|digit|"_")+;
space   = [ \t];
ws      = (space | [\r\n]);
eol     = ("\r\n" | "\n");
lineinf = lineno (space+ dstring)? eol;

	esc = "\\";
	hex_digit = [0-9a-fA-F];
	esc_hex = esc ("x" hex_digit{2} | [uX] hex_digit{4} | "U" hex_digit{8});
	esc_oct = esc [0-3] [0-7]{2}; // max 1-byte octal value is '\377'
	esc_simple = esc [abfnrtv\\];
*/

Scanner::ParseMode Scanner::echo()
{
	bool ignore_eoc = false;
	int  ignore_cnt = 0;

	if (eof && cur == eof) // Catch EOF
	{
		return Stop;
	}

	tok = cur;
echo:
/*!re2c
   beginRE     =  "%{" | "/*!re2c";
   beginRE     {
					if (opts->rFlag)
					{
						fatal("found standard 're2c' block while using -r flag");
					}
					if (opts->target == opt_t::CODE)
					{
						const size_t lexeme_len = cur[-1] == '{'
							? sizeof ("%{") - 1
							: sizeof ("/*!re2c") - 1;
						out.write(tok, tok_len () - lexeme_len);
					}
					tok = cur;
					return Parse;
				}
	"/*!rules:re2c"	{
					if (opts->rFlag)
					{
						opts.reset_mapCodeName ();
					}
					else
					{
						fatal("found 'rules:re2c' block without -r flag");
					}
					tok = cur;
					return Rules;
				}
	"/*!use:re2c"	{
					if (!opts->rFlag)
					{
						fatal("found 'use:re2c' block without -r flag");
					}
					reuse();
					if (opts->target == opt_t::CODE)
					{
						const size_t lexeme_len = sizeof ("/*!use:re2c") - 1;
						out.write(tok, tok_len () - lexeme_len);
					}
					tok = cur;
					return Reuse;
				}
	"/*!max:re2c" {
					if (opts->target != opt_t::DOT)
					{
						out.insert_yymaxfill ();
					}
					tok = pos = cur;
					ignore_eoc = true;
					goto echo;
				}
	"/*!getstate:re2c" {
					tok = pos = cur;
					out.insert_state_goto (opts->topIndent);
					ignore_eoc = true;
					goto echo;
				}
	"/*!ignore:re2c" {
					tok = pos = cur;
					ignore_eoc = true;
					goto echo;
				}
	"/*!types:re2c" {
					tok = pos = cur;
					ignore_eoc = true;
					if (opts->target != opt_t::DOT)
					{
						out.insert_line_info ();
						out << "\n";
						out.insert_types ();
						out << "\n";
						out.write_line_info (cline, get_fname ().c_str ());
					}
					goto echo;
				}
	"*" "/"	"\r"? "\n"	{
					cline++;
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out.write_line_info (cline, get_fname ().c_str ());
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else if (opts->target == opt_t::CODE)
					{
						out.write(tok, tok_len ());
					}
					tok = pos = cur;
					goto echo;
				}
	"*" "/"		{
					if (ignore_eoc)
					{
						if (ignore_cnt)
						{
							out << "\n";
							out.write_line_info (cline, get_fname ().c_str ());
						}
						ignore_eoc = false;
						ignore_cnt = 0;
					}
					else if (opts->target == opt_t::CODE)
					{
						out.write(tok, tok_len ());
					}
					tok = pos = cur;
					goto echo;
				}
	"\n" space* "#" space* "line" space+ / lineinf {
					set_sourceline ();
					goto echo;
				}
	"\n"		{
					if (ignore_eoc)
					{
						ignore_cnt++;
					}
					else if (opts->target == opt_t::CODE)
					{
						out.write(tok, tok_len ());
					}
					tok = pos = cur;
					cline++;
					goto echo;
				}
	zero		{
					if (!ignore_eoc && opts->target == opt_t::CODE)
					{
						out.write(tok, tok_len () - 1);
						// -1 so we don't write out the \0
					}
					if(cur == eof)
					{
						return Stop;
					}
				}
	*			{
					goto echo;
				}
*/
}

int Scanner::scan()
{
	uint32_t depth;

scan:
	tchar = cur - pos;
	tline = cline;
	tok = cur;
	switch (lexer_state)
	{
		case LEX_NORMAL:    goto start;
		case LEX_FLEX_NAME: goto flex_name;
	}

start:
/*!re2c
	"{"			{
					depth = 1;
					goto code;
				}

	":" / "=>"	{
					return *tok;
				}

	":="		{
					tok += 2; /* skip ":=" */
					depth = 0;
					goto code;
				}

        "//"            {
				goto nextLine;
			}
	"/*"		{
					depth = 1;
					goto comment;
				}

   endRE    =  "%}" | "*/";
   endRE    {
					tok = cur;
					return 0;
				}

	"'"
	{
		std::vector<uint32_t> cpoints;
		lex_str ('\'', cpoints);
		yylval.regexp = cpoint_string (cpoints, opts->bCaseInsensitive || !opts->bCaseInverted);
		return REGEXP;
	}
	"\""
	{
		std::vector<uint32_t> cpoints;
		lex_str ('"', cpoints);
		yylval.regexp = cpoint_string (cpoints, opts->bCaseInsensitive || opts->bCaseInverted);
		return REGEXP;
	}

	"["  { yylval.regexp = lex_cls(false); return REGEXP; }
	"[^" { yylval.regexp = lex_cls(true);  return REGEXP; }

	"<>" / (space* ("{" | "=>" | ":=")) {
					return NOCOND;
				}
	"<!"		{
					return SETUP;
				}
	[<>,()|=;/\\]	{
					return *tok;
				}

	"*"			{
					yylval.op = *tok;
					return STAR;
				}
	[+?]		{
					yylval.op = *tok;
					return CLOSE;
				}

	"{" [0-9]+ "}"	{
					if (!s_to_u32_unsafe (tok + 1, cur - 1, yylval.extop.min))
					{
						fatal ("repetition count overflow");
					}
					yylval.extop.max = yylval.extop.min;
					return CLOSESIZE;
				}

	"{" [0-9]+ "," [0-9]+ "}"	{
					const char * p = strchr (tok, ',');
					if (!s_to_u32_unsafe (tok + 1, p, yylval.extop.min))
					{
						fatal ("repetition lower bound overflow");
					}
					if (!s_to_u32_unsafe (p + 1, cur - 1, yylval.extop.max))
					{
						fatal ("repetition upper bound overflow");
					}
					return CLOSESIZE;
				}

	"{" [0-9]+ ",}"		{
					if (!s_to_u32_unsafe (tok + 1, cur - 2, yylval.extop.min))
					{
						fatal ("repetition lower bound overflow");
					}
					yylval.extop.max = UINT32_MAX;
					return CLOSESIZE;
				}

	"{" [0-9]* ","		{
					fatal("illegal closure form, use '{n}', '{n,}', '{n,m}' where n and m are numbers");
				}

	"{" name "}"	{
					if (!opts->FFlag) {
						fatal("curly braces for names only allowed with -F switch");
					}
					yylval.str = new std::string (tok + 1, tok_len () - 2); // -2 to omit braces
					return ID;
				}

	"re2c:" { lex_conf (); return CONF; }

	name / (space+ [^=>,])	{
					yylval.str = new std::string (tok, tok_len ());
					if (opts->FFlag)
					{
						lexer_state = LEX_FLEX_NAME;
						return FID;
					}
					else
					{
						return ID;
					}
				}

	name / (space* [=>,])	{
					yylval.str = new std::string (tok, tok_len ());
					return ID;
				}

	name / [^]	{
					if (!opts->FFlag) {
						yylval.str = new std::string (tok, tok_len ());
						return ID;
					} else {
						std::vector<uint32_t> cpoints;
						for (char * p = tok; p < cur; ++p)
						{
							cpoints.push_back (static_cast<uint8_t> (*p));
						}
						yylval.regexp = cpoint_string (cpoints, opts->bCaseInsensitive || opts->bCaseInverted);
						return REGEXP;
					}
				}

	"."			{
					yylval.regexp = mkDot();
					return REGEXP;
				}

	space+		{
					goto scan;
				}

	eol space* "#" space* "line" space+ / lineinf {
					set_sourceline ();
					goto scan;
				}

	eol			{
					if (cur == eof) return 0;
					pos = cur;
					cline++;
					goto scan;
				}

	*			{
					fatalf("unexpected character: '%c'", *tok);
					goto scan;
				}
*/

flex_name:
/*!re2c
	eol
	{
		YYCURSOR = tok;
		lexer_state = LEX_NORMAL;
		return FID_END;
	}
	*
	{
		YYCURSOR = tok;
		goto start;
	}
*/

code:
/*!re2c
	"}"			{
					if (depth == 0)
					{
						fatal("Curly braces are not allowed after ':='");
					}
					else if (--depth == 0)
					{
						yylval.code = new Code (tok, tok_len (), get_fname (), tline);
						return CODE;
					}
					goto code;
				}
	"{"			{
					if (depth == 0)
					{
						fatal("Curly braces are not allowed after ':='");
					}
					else
					{
						++depth;
					}
					goto code;
				}
	"\n" space* "#" space* "line" space+ / lineinf {
					set_sourceline ();
					goto code;
				}
	"\n" /  ws	{
					if (depth == 0)
					{
						goto code;
					}
					else if (cur == eof)
					{
						fatal("missing '}'");
					}
					pos = cur;
					cline++;
					goto code;
				}
	"\n"		{
					if (depth == 0)
					{
						tok += strspn(tok, " \t\r\n");
						while (cur > tok && strchr(" \t\r\n", cur[-1]))
						{
							--cur;
						}
						yylval.code = new Code (tok, tok_len (), get_fname (), tline);
						return CODE;
					}
					else if (cur == eof)
					{
						fatal("missing '}'");
					}
					pos = cur;
					cline++;
					goto code;
				}
	zero		{
					if (cur == eof)
					{
						if (depth)
						{
							fatal("missing '}'");
						}
						return 0;
					}
					goto code;
				}
	dstring | sstring	{
					goto code;
				}
	*			{
					goto code;
				}
*/

comment:
/*!re2c
	"*/"		{
					if (--depth == 0)
					{
						goto scan;
					}
					else
					{
						goto comment;
					}
				}
	"/*"		{
					++depth;
					fatal("ambiguous /* found");
					goto comment;
				}
	"\n" space* "#" space* "line" space+ / lineinf {
					set_sourceline ();
					goto comment;
				}
	"\n"		{
					if (cur == eof)
					{
						return 0;
					}
					tok = pos = cur;
					cline++;
					goto comment;
				}
	*			{
					if (cur == eof)
					{
						return 0;
					}
					goto comment;
				}
*/

nextLine:
/*!re2c                                  /* resync emacs */
   "\n"     { if(cur == eof) {
                  return 0;
               }
               tok = pos = cur;
               cline++;
               goto scan;
            }
   *        {  if(cur == eof) {
                  return 0;
               }
               goto nextLine;
            }
*/
}

static void escape (std::string & dest, const std::string & src)
{
	dest = src;
	size_t l = dest.length();
	for (size_t p = 0; p < l; ++p)
	{
		if (dest[p] == '\\')
		{
			dest.insert(++p, "\\");
			++l;
		}
	}
}

void Scanner::lex_str (char quote, std::vector<uint32_t> & cs)
{
	for (;;)
	{
		tok = cur;
	/*!re2c
		*          { fatal ((tok - pos) - tchar, "syntax error"); }
		esc [xXuU] { fatal ((tok - pos) - tchar, "syntax error in hexadecimal escape sequence"); }
		esc [0-7]  { fatal ((tok - pos) - tchar, "syntax error in octal escape sequence"); }
		esc        { fatal ((tok - pos) - tchar, "syntax error in escape sequence"); }

		["']       { if (quote == tok[0]) return; cs.push_back(static_cast<uint8_t>(tok[0])); continue; }
		esc_hex    { cs.push_back(unesc_hex(tok, cur)); continue; }
		esc_oct    { cs.push_back(unesc_oct(tok, cur)); continue; }
		esc "a"    { cs.push_back(static_cast<uint8_t>('\a')); continue; }
		esc "b"    { cs.push_back(static_cast<uint8_t>('\b')); continue; }
		esc "f"    { cs.push_back(static_cast<uint8_t>('\f')); continue; }
		esc "n"    { cs.push_back(static_cast<uint8_t>('\n')); continue; }
		esc "r"    { cs.push_back(static_cast<uint8_t>('\r')); continue; }
		esc "t"    { cs.push_back(static_cast<uint8_t>('\t')); continue; }
		esc "v"    { cs.push_back(static_cast<uint8_t>('\v')); continue; }
		esc "\\"   { cs.push_back(static_cast<uint8_t>('\\')); continue; }
		esc .      { cs.push_back(static_cast<uint8_t>(tok[1])); if (quote != tok[1]) warn.useless_escape(tline, tok - pos, tok[1]); continue; }
		. \ esc    { cs.push_back(static_cast<uint8_t>(tok[0])); continue; }
	*/
	}
}

RegExp * Scanner::lex_cls (bool neg)
{
	std::vector<uint32_t> cs;
	std::set<size_t> esc;
	for (;;)
	{
		tok = cur;
	/*!re2c
		*          { fatal ((tok - pos) - tchar, "syntax error"); }
		esc [xXuU] { fatal ((tok - pos) - tchar, "syntax error in hexadecimal escape sequence"); }
		esc [0-7]  { fatal ((tok - pos) - tchar, "syntax error in octal escape sequence"); }
		esc        { fatal ((tok - pos) - tchar, "syntax error in escape sequence"); }

		"]"        { break; }
		esc_oct    { cs.push_back(unesc_oct(tok, cur)); continue; }
		esc_hex    { cs.push_back(unesc_hex(tok, cur)); continue; }
		esc "a"    { cs.push_back(static_cast<uint8_t>('\a')); continue; }
		esc "b"    { cs.push_back(static_cast<uint8_t>('\b')); continue; }
		esc "f"    { cs.push_back(static_cast<uint8_t>('\f')); continue; }
		esc "n"    { cs.push_back(static_cast<uint8_t>('\n')); continue; }
		esc "r"    { cs.push_back(static_cast<uint8_t>('\r')); continue; }
		esc "t"    { cs.push_back(static_cast<uint8_t>('\t')); continue; }
		esc "v"    { cs.push_back(static_cast<uint8_t>('\v')); continue; }
		esc "\\"   { cs.push_back(static_cast<uint8_t>('\\')); continue; }
		esc "]"    { cs.push_back(static_cast<uint8_t>(']'));  continue; }
		esc "-"    { cs.push_back(static_cast<uint8_t>('-')); esc.insert(cs.size() - 1); continue; }
		esc .      { cs.push_back(static_cast<uint8_t>(tok[1])); warn.useless_escape(tline, tok - pos, tok[1]); continue; }
		. \ esc    { cs.push_back(static_cast<uint8_t>(tok[0])); continue; }
	*/
	}
	Range * r = NULL;
	const size_t count = cs.size ();
	for (size_t i = 0; i < count; ++i)
	{
		uint32_t l = cs[i];
		uint32_t u = count - i >= 3 && (cs[i + 1] == '-' && esc.find(i + 1) == esc.end())
			? cs[i += 2]
			: l;
		if (l > u)
		{
			warn.swapped_range (get_line (), l, u);
			std::swap (l, u);
		}
		Range * s = opts->encoding.encodeRange (l, u);
		if (!s)
		{
			fatalf ("Bad code point range: '0x%X - 0x%X'", l, u);
		}
		r = Range::add (r, s);
	}
	if (neg)
	{
		r = Range::sub (opts->encoding.fullRange (), r);
	}
	return matchSymbolRange (r);
}

void Scanner::set_sourceline ()
{
sourceline:
	tok = cur;
/*!re2c	
	lineno		{
					if (!s_to_u32_unsafe (tok, cur, cline))
					{
						fatal ("line number overflow");
					}
					goto sourceline; 
				}
	dstring		{
					escape (in.file_name, std::string (tok + 1, tok_len () - 2)); // -2 to omit quotes
			  		goto sourceline; 
				}
	"\n"			{
  					if (cur == eof)
  					{
						--cur; 
					}
			  		else
			  		{
			  			pos = cur; 
			  		}
			  		tok = cur;
			  		return; 
				}
	*			{
  					goto sourceline;
  				}
*/
}

} // end namespace re2c
