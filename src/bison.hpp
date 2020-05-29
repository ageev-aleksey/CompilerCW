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
    NON_TERM = 258,
    BREAK = 259,
    CLONE = 260,
    ENDSWITCH = 261,
    HTML = 262,
    WHILE = 263,
    DO = 264,
    FOR = 265,
    FOREACH = 266,
    VARNAME = 267,
    AS = 268,
    SV = 269,
    RETURN = 270,
    INTCONST = 271,
    CHARCONST = 272,
    PAS = 273,
    DIVAS = 274,
    MODAS = 275,
    EQ = 276,
    NE = 277,
    TEQ = 278,
    TNE = 279,
    LEQ = 280,
    GEQ = 281,
    AND = 282,
    OR = 283,
    PP = 284,
    MM = 285,
    UPLUS = 286,
    UMINUS = 287,
    ARRAY = 288,
    ID = 289,
    ARROW = 290,
    NEW = 291,
    PARENT = 292,
    DCOL = 293,
    IF = 294,
    ELSE = 295,
    ELSEIF = 296,
    SWITCH = 297,
    DEFAULT = 298,
    CASE = 299,
    FUNCTION = 300,
    CLASS = 301,
    EXTENDS = 302,
    VAR = 303,
    PUBLIC = 304,
    PRIVATE = 305,
    PROTECTED = 306,
    ECHO_KW = 307,
    MAS = 308,
    MULAS = 309,
    UNDEFINED = 310
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
