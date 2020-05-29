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
<PHP>"?>"                         {BEGIN(INITIAL);}


<PHP>"/*"                    {BEGIN(C_COMMENT);}
<C_COMMENT>"*/"              {BEGIN(PHP);}
<C_COMMENT>.                 {}
<PHP>"//"(.+|\n)             {}

<PHP>"echo"                 {return ECHO_KW;}
<PHP>"break" 				{return BREAK;}
<PHP>"while" 				{return WHILE;}
<PHP>"do"					{return DO;}
<PHP>"for"					{return FOR;}
<PHP>"foreach"				{return FOREACH;}
<PHP>"as"					{return AS;}
<PHP>"if"					{return IF;}
<PHP>"else"					{return ELSE;}
<PHP>"elseif"				{return ELSEIF;}
<PHP>"switch"				{return	SWITCH;}
<PHP>"case"					{return CASE;}
<PHP>"default"				{return DEFAULT;}
<PHP>"function" 			{return FUNCTION;}
<PHP>"class"				{return CLASS;}
<PHP>"public"				{return PUBLIC;}
<PHP>"private"				{return PRIVATE;}
<PHP>"protected"			{return PROTECTED;}
<PHP>"extends"				{return EXTENDS;}
<PHP>"return"               {return RETURN;}
<PHP>":"					{return ':';}
<PHP>";"					{return ';';}
<PHP>"("					{return '(';}
<PHP>")"					{return ')';}
<PHP>"{"					{return '{';}
<PHP>"}"					{return '}';}
<PHP>">"                    {return '>';}
<PHP>"<"                    {return '<';}
<PHP>"="                    {return '=';}
<PHP>"==" 					{return EQ;}
<PHP>"!="					{return NE;}
<PHP>">="					{return GEQ;}
<PHP>"<="					{return LEQ;}
<PHP>"&&" 					{return AND;}
<PHP>"||" 					{return OR;}
<PHP>"!"					{return '!';}
<PHP>"-"					{return '-';}
<PHP>"+" 					{return '+';}
<PHP>"*" 					{return '*';}
<PHP>"/" 					{return '/';}
<PHP>"array" 				{return ARRAY;}
<PHP>"new" 				    {return NEW;}
<PHP>"=>"					{return SV;}
<PHP>\${WORD}           	{return VARNAME;}
<PHP>{WORD}                 {return ID;}
<PHP>{DIGIT}+               {return INTCONST;}
<PHP>","                    {return ',';}
<PHP>"."                    {return '.';}
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
    return CHARCONST;
}

<PHP>[\n\r\t\s]                 {}
[\n\r\t\s]                 {}



%%

    /*<DOUBLE_QUOTE>\$({WORD})|(\{{WORD}\}) {
    printf("ID in str: %s\n", yytext);
  }

<SINGLE_QUOTE>[^']+ {
    printf("Quote: %s\n", yytext);
}

<DOUBLE_QUOTE>[^"${}]+ {
    printf("Quote: %s\n", yytext);
}*/