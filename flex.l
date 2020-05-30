%{
	#include "bison.h"
%}
LETTER [a-zA-Z]
DIGIT [0-9]
WORD {LETTER}({LETTER}|{DIGIT})*

%x C_COMMENT
%x PHP
%x QUOTE
%x SINGLE_QUOTE
%x DOUBLE_QUOTE
%%

"<?php"                      {BEGIN(PHP);}
<PHP>"?>"                    {BEGIN(INITIAL);}


<PHP>"/*"                    {BEGIN(C_COMMENT);}
<C_COMMENT>"*/"              {BEGIN(PHP);}
<C_COMMENT>.                 {}
<PHP>"//"(.+|\n)             {}

<PHP>"echo"                 {
    yylval.string = yytext;
    return ECHO_KW;
}

<PHP>"break" 				{
    yylval.string = yytext;
    return BREAK;
}

<PHP>"while" 				{
    yylval.string = yytext;
    return WHILE;
}

<PHP>"do"					{
    yylval.string = yytext;
    return DO;
}

<PHP>"for"					{
    yylval.string = yytext;
    return FOR;
}

<PHP>"foreach"				{
    yylval.string = yytext;
    return FOREACH;
}

<PHP>"as"					{
    yylval.string = yytext;
    return AS;
}

<PHP>"if"					{
    yylval.string = yytext;
    return IF;
}

<PHP>"else"					{
    yylval.string = yytext;
    return ELSE;
}

<PHP>"elseif"				{
    yylval.string = yytext;
    return ELSEIF;
}

<PHP>"switch"				{
    yylval.string = yytext;
    return	SWITCH;
}
<PHP>"case"					{
    yylval.string = yytext;
    return CASE;
}
<PHP>"default"				{
    yylval.string = yytext;
    return DEFAULT;
}
<PHP>"function" 			{
    yylval.string = yytext;
    return FUNCTION;
}
<PHP>"class"				{
    yylval.string = yytext;
    return CLASS;
}
<PHP>"public"				{
    yylval.string = yytext;
    return PUBLIC;
}
<PHP>"private"				{
    yylval.string = yytext;
    return PRIVATE;
}
<PHP>"protected"			{
    yylval.string = yytext;
    return PROTECTED;
}
<PHP>"extends"				{
    yylval.string = yytext;
    return EXTENDS;
}
<PHP>"return"               {
    yylval.string = yytext;
    return RETURN;
}
<PHP>":"					{
    yylval.string = yytext;
    return ':';
}
<PHP>";"					{
    yylval.string = yytext;
    return ';';
}
<PHP>"("					{
    yylval.string = yytext;
    return '(';
}
<PHP>")"					{
    yylval.string = yytext;
    return ')';
}
<PHP>"{"					{
    yylval.string = yytext;
    return '{';
}
<PHP>"}"					{
    yylval.string = yytext;
    return '}';
}
<PHP>"["					{
    yylval.string = yytext;
    return '[';
}
<PHP>"]"					{
    yylval.string = yytext;
    return ']';
}
<PHP>">"                    {
    yylval.string = yytext;
    return '>';
}
<PHP>"<"                    {
    yylval.string = yytext;
    return '<';
}
<PHP>"="                    {
    yylval.string = yytext;
    return '=';
}
<PHP>"==" 					{
    yylval.string = yytext;
    return EQ;
}
<PHP>"!="					{
    yylval.string = yytext;
    return NE;
}
<PHP>">="					{
    yylval.string = yytext;
    return GEQ;
}
<PHP>"<="					{
    yylval.string = yytext;
    return LEQ;
}
<PHP>"&&" 					{
    yylval.string = yytext;
    return AND;
}
<PHP>"||" 					{
    yylval.string = yytext;
    return OR;
}
<PHP>"!"					{
    yylval.string = yytext;
    return '!';
}
<PHP>"-"					{
    yylval.string = yytext;
    return '-';
}
<PHP>"+" 					{
    yylval.string = yytext;
    return '+';
}
<PHP>"*" 					{
    yylval.string = yytext;
    return '*';
}
<PHP>"/" 					{
    yylval.string = yytext;
    return '/';
}
<PHP>"array" 				{
    yylval.string = yytext;
    return ARRAY;
}
<PHP>"new" 				    {
    yylval.string = yytext;
    return NEW;
}
<PHP>"=>"					{
    yylval.string = yytext;
    return SV;
}

<PHP>"->"					{
    yylval.string = yytext;
    return ARROW;
}

<PHP>\${WORD}           	{
    yylval.string = yytext;
    return VARNAME;
    }
<PHP>{WORD}                 {
    yylval.string = yytext;
    return ID;
}
<PHP>{DIGIT}+               {
    yylval.string = yytext;
    return INTCONST;
}
<PHP>","                    {
    yylval.string = yytext;
    return ',';
}
<PHP>"."                    {
    yylval.string = yytext;
    return '.';
}
<PHP>"\""   {
    BEGIN(QUOTE);
}

<QUOTE>"\""  {
    BEGIN(PHP);
}

<PHP>"\'"    {
    BEGIN(QUOTE);
}

<QUOTE>"\'"  {
    BEGIN(PHP);
}

<QUOTE>[^'"]* {
    yylval.string = yytext;
    return CHARCONST;
}

<PHP>[\n\r\t\s]                 {}
[\n\r\t\s]                 {}



%%