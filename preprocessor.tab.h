/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define PLUS 258
#define MINUS 259
#define TIMES 260
#define DIVISION 261
#define LT 262
#define LTEQ 263
#define GT 264
#define GTEQ 265
#define EQUAL 266
#define NEQ 267
#define ASSIGN 268
#define SEMICOLON 269
#define COMMA 270
#define LEFT_PAREN 271
#define RIGHT_PAREN 272
#define LEFT_BRACKET 273
#define RIGHT_BRACKET 274
#define LEFT_BRACE 275
#define RIGHT_BRACE 276
#define IF 277
#define ELSE 278
#define RETURN 279
#define VOID 280
#define INT 281
#define WHILE 282
#define ID 283
#define NUM 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "preprocessor.y"
{
	char *word;
	
#line 22 "preprocessor.y"

	char *character;
	}
/* Line 1529 of yacc.c.  */
#line 115 "preprocessor.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

