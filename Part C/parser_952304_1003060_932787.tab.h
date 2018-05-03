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
     LTEQ = 258,
     GTEQ = 259,
     EQUAL = 260,
     NEQ = 261,
     IF = 262,
     ELSE = 263,
     RETURN = 264,
     VOID = 265,
     INT = 266,
     FLOAT = 267,
     FLOAT_NUM = 268,
     WHILE = 269,
     ID = 270,
     NUM = 271,
     PLUSEQ = 272,
     MINUSEQ = 273,
     INC = 274,
     DEC = 275,
     FOR = 276
   };
#endif
/* Tokens.  */
#define LTEQ 258
#define GTEQ 259
#define EQUAL 260
#define NEQ 261
#define IF 262
#define ELSE 263
#define RETURN 264
#define VOID 265
#define INT 266
#define FLOAT 267
#define FLOAT_NUM 268
#define WHILE 269
#define ID 270
#define NUM 271
#define PLUSEQ 272
#define MINUSEQ 273
#define INC 274
#define DEC 275
#define FOR 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "parser_952304_1003060_932787.y"
{
    int a_number;
    float b_number;
    char *str;
    struct Exp *exp;
    struct Stmt *stmt;
    int type;
    char *op;
}
/* Line 1529 of yacc.c.  */
#line 101 "parser_952304_1003060_932787.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

