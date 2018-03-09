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

#ifndef YY_YY_PREPROCESSOR_TAB_H_INCLUDED
# define YY_YY_PREPROCESSOR_TAB_H_INCLUDED
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
    ELSE = 258,
    IF = 259,
    INT = 260,
    RETURN = 261,
    VOID = 262,
    WHILE = 263,
    ID = 264,
    NUM = 265,
    PLUS = 266,
    MINUS = 267,
    TIMES = 268,
    DIVISION = 269,
    LT = 270,
    LTEQ = 271,
    GT = 272,
    GTEQ = 273,
    EQUAL = 274,
    NEQ = 275,
    ASSIGN = 276,
    SEMICOLON = 277,
    COMMA = 278,
    LEFT_PAREN = 279,
    RIGHT_PAREN = 280,
    LEFT_BRACKET = 281,
    RIGHT_BRACKET = 282,
    LEFT_BRACE = 283,
    RIGHT_BRACE = 284,
    INCREASE = 285,
    DECREASE = 286,
    INCR_EQUAL = 287,
    DECR_EQUAL = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "preprocessor.y" /* yacc.c:1909  */

	char *word;
	
#line 19 "preprocessor.y" /* yacc.c:1909  */

	char *character;
	

#line 97 "preprocessor.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PREPROCESSOR_TAB_H_INCLUDED  */
