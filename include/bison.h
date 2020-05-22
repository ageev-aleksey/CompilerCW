/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_HOME_NRX_PROGRAMMING_CPP_COMPILERS_FLEX_BISON_DUMMY_PARSER_SRC_BISON_HPP_INCLUDED
# define YY_YY_HOME_NRX_PROGRAMMING_CPP_COMPILERS_FLEX_BISON_DUMMY_PARSER_SRC_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BREAK = 258,
    CLONE = 259,
    ENDSWITCH = 260,
    HTML = 261,
    WHILE = 262,
    DO = 263,
    FOR = 264,
    FOREACH = 265,
    VARNAME = 266,
    AS = 267,
    SV = 268,
    RETURN = 269,
    INTCONST = 270,
    CHARCONST = 271,
    PAS = 272,
    DIVAS = 273,
    MODAS = 274,
    EQ = 275,
    NE = 276,
    TEQ = 277,
    TNE = 278,
    LEQ = 279,
    GEQ = 280,
    AND = 281,
    OR = 282,
    PP = 283,
    MM = 284,
    UPLUS = 285,
    UMINUS = 286,
    ARRAY = 287,
    ID = 288,
    ARROW = 289,
    NEW = 290,
    PARENT = 291,
    DCOL = 292,
    IF = 293,
    ELSE = 294,
    ELSEIF = 295,
    SWITCH = 296,
    DEFAULT = 297,
    CASE = 298,
    FUNCTION = 299,
    CLASS = 300,
    EXTENDS = 301,
    VAR = 302,
    PUBLIC = 303,
    PRIVATE = 304,
    PROTECTED = 305,
    ECHO_KW = 306,
    MAS = 307,
    MULAS = 308,
    UNDEFINED = 309
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_HOME_NRX_PROGRAMMING_CPP_COMPILERS_FLEX_BISON_DUMMY_PARSER_SRC_BISON_HPP_INCLUDED  */
