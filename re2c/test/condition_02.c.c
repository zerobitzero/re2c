/* Generated by re2c */
#line 1 "condition_02.c.re"

#line 5 "condition_02.c.c"
{
	YYCTYPE yych;
	switch (YYGETCONDITION()) {
	case yyc0: goto yyc_0;
	case yycr1: goto yyc_r1;
	case yycr2: goto yyc_r2;
	}
/* *********************************** */
yyc_0:
#line 3 "condition_02.c.re"
	{ return NULL; }
#line 17 "condition_02.c.c"
/* *********************************** */
yyc_r1:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy7;
	case 'b':	goto yy9;
	default:	goto yy6;
	}
yy6:
yy7:
	++YYCURSOR;
#line 4 "condition_02.c.re"
	{ return "a"; }
#line 32 "condition_02.c.c"
yy9:
	++YYCURSOR;
#line 5 "condition_02.c.re"
	{ return "b"; }
#line 37 "condition_02.c.c"
/* *********************************** */
yyc_r2:
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy14;
	default:	goto yy13;
	}
yy13:
yy14:
	++YYCURSOR;
#line 5 "condition_02.c.re"
	{ return "b"; }
#line 51 "condition_02.c.c"
}
#line 7 "condition_02.c.re"

re2c: warning: line 3: rule in condition '0' matches empty string [-Wmatch-empty-string]
re2c: warning: line 7: control flow in condition 'r1' is undefined for strings that match '[\x0-\x60\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
re2c: warning: line 7: control flow in condition 'r2' is undefined for strings that match '[\x0-\x61\x63-\xFF]', use default rule '*' [-Wundefined-control-flow]
