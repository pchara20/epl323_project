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

#ifndef YY_YY_PARSER_952304_1003060_932787_TAB_H_INCLUDED
# define YY_YY_PARSER_952304_1003060_932787_TAB_H_INCLUDED
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
    PLUS = 258,
    MINUS = 259,
    TIMES = 260,
    DIVISION = 261,
    LT = 262,
    LTEQ = 263,
    GT = 264,
    GTEQ = 265,
    EQUAL = 266,
    NEQ = 267,
    ASSIGN = 268,
    SEMICOLON = 269,
    COMMA = 270,
    LEFT_PAREN = 271,
    RIGHT_PAREN = 272,
    LEFT_BRACKET = 273,
    RIGHT_BRACKET = 274,
    LEFT_BRACE = 275,
    RIGHT_BRACE = 276,
    IF = 277,
    ELSE = 278,
    RETURN = 279,
    VOID = 280,
    INT = 281,
    WHILE = 282,
    ID = 283,
    NUM = 284
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser_952304_1003060_932787.y" /* yacc.c:1909  */

	char *word;
	
#line 34 "parser_952304_1003060_932787.y" /* yacc.c:1909  */

	char *character;
	

#line 93 "parser_952304_1003060_932787.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_952304_1003060_932787_TAB_H_INCLUDED  */
