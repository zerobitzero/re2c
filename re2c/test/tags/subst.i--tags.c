/* Generated by re2c */
// Be careful with substitution of tag names:
// if one tag's name is a prefix of another tag's name,
// tag with longer name must be substituted first.


{
	YYCTYPE yych;
	long yyt0p;
	long yyt0p1;
	long yyt0p12;
	long yyt0p123;
	YYCTXMARKER = YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
	{}
yy4:
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'a':
	case 'b':	goto yy6;
	default:	goto yy3;
	}
yy5:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy6:
	switch (yych) {
	case 'a':	goto yy5;
	case 'b':
		yyt0p12 = (YYCURSOR - YYCTXMARKER);
		goto yy8;
	default:	goto yy7;
	}
yy7:
	YYCURSOR = YYMARKER;
	goto yy3;
yy8:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy8;
	case 'c':
		yyt0p123 = (YYCURSOR - YYCTXMARKER);
		goto yy10;
	default:	goto yy7;
	}
yy10:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'c':	goto yy10;
	case 'd':
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy12;
	default:	goto yy7;
	}
yy12:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'd':	goto yy12;
	case 'e':
		yyt0p1 = (YYCURSOR - YYCTXMARKER);
		goto yy14;
	default:	goto yy7;
	}
yy14:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'e':	goto yy14;
	default:	goto yy16;
	}
yy16:
	{ (YYCTXMARKER + yyt0p) (YYCTXMARKER + yyt0p1) (YYCTXMARKER + yyt0p12) (YYCTXMARKER + yyt0p123) }
}
