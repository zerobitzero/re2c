/* Generated by re2c */

{
	YYCTYPE yych;
	long yyt0;
	long yyt0p;
	YYCTXMARKER = YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy4;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
	{}
yy4:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case 'b':
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy6;
	case 'c':
		yyt0 = yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy8;
	case 'd':
		yyt0 = yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy11;
	default:
		yyt0 = yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy5;
	}
yy5:
	YYCURSOR = YYCTXMARKER + yyt0;
	{ (YYCTXMARKER + yyt0p) }
yy6:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy6;
	case 'c':
		yyt0 = (YYCURSOR - YYCTXMARKER);
		goto yy8;
	case 'd':
		yyt0 = (YYCURSOR - YYCTXMARKER);
		goto yy11;
	default:
		yyt0 = (YYCURSOR - YYCTXMARKER);
		goto yy5;
	}
yy8:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'c':	goto yy8;
	default:	goto yy10;
	}
yy10:
	YYCURSOR = YYCTXMARKER + yyt0;
	{ (YYCTXMARKER + yyt0p) }
yy11:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'd':	goto yy11;
	default:	goto yy5;
	}
}



{
	YYCTYPE yych;
	long yyt0p;
	long yyt1p;
	YYCTXMARKER = YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy17;
	default:	goto yy15;
	}
yy15:
	++YYCURSOR;
	{}
yy17:
	++YYCURSOR;
	switch ((yych = *YYCURSOR)) {
	case 'b':
		yyt0p = yyt1p = (YYCURSOR - YYCTXMARKER);
		goto yy19;
	case 'c':
		yyt0p = yyt1p = (YYCURSOR - YYCTXMARKER);
		goto yy21;
	default:
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy18;
	}
yy18:
	{ (YYCTXMARKER + yyt0p) }
yy19:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy19;
	case 'c':
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy21;
	default:	goto yy18;
	}
yy21:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'c':	goto yy21;
	default:	goto yy23;
	}
yy23:
	YYCURSOR = YYCTXMARKER + yyt0p;
	{ (YYCTXMARKER + yyt1p) }
}



{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	long yyt0p;
	long yyt1;
	YYCTXMARKER = YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy28;
	default:	goto yy26;
	}
yy26:
	++YYCURSOR;
	{}
yy28:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case 'b':
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy30;
	case 'c':
		yyt0p = yyt1 = (YYCURSOR - YYCTXMARKER);
		goto yy32;
	default:
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy29;
	}
yy29:
	{ (YYCTXMARKER + yyt0p) }
yy30:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy30;
	case 'c':
		yyt1 = (YYCURSOR - YYCTXMARKER);
		goto yy32;
	default:	goto yy29;
	}
yy32:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'd':	goto yy34;
	default:	goto yy33;
	}
yy33:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy29;
	case 1: 	goto yy29;
	default:	goto yy35;
	}
yy34:
	yyaccept = 2;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'c':	goto yy32;
	default:	goto yy35;
	}
yy35:
	YYCURSOR = YYCTXMARKER + yyt1;
	{ (YYCTXMARKER + yyt0p) }
}



{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	long yyt0p;
	long yyt1;
	YYCTXMARKER = YYCURSOR;
	if ((YYLIMIT - YYCURSOR) < 2) YYFILL(2);
	yych = *YYCURSOR;
	switch (yych) {
	case 'a':	goto yy40;
	default:	goto yy38;
	}
yy38:
	++YYCURSOR;
yy39:
	{}
yy40:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'b':
		yyt0p = (YYCURSOR - YYCTXMARKER);
		goto yy41;
	default:	goto yy39;
	}
yy41:
	yyaccept = 0;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'b':	goto yy41;
	case 'c':
		yyt1 = (YYCURSOR - YYCTXMARKER);
		goto yy44;
	default:	goto yy43;
	}
yy43:
	{ (YYCTXMARKER + yyt0p) }
yy44:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'd':	goto yy46;
	default:	goto yy45;
	}
yy45:
	YYCURSOR = YYMARKER;
	if (yyaccept == 0) {
		goto yy43;
	} else {
		goto yy47;
	}
yy46:
	yyaccept = 1;
	YYMARKER = ++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch (yych) {
	case 'c':	goto yy44;
	default:	goto yy47;
	}
yy47:
	YYCURSOR = YYCTXMARKER + yyt1;
	{ (YYCTXMARKER + yyt0p) }
}
