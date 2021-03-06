/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser_952304_1003060_932787.y"

	/******************************************************************
	Panayiotis Charalambous - pchara20 ID: 952304					***
	Andreas Costi			- acosti01 ID: 1003060					***
	Stephanie Nicolaou		- snikol07 ID: 932787					***
																	***
	Part A - Compiler												***
	bison -d parser_952304_1003060_932787.y							***
	flex preprocessor_952304_1003060_932787.fl						***
	gcc parser_952304_1003060_932787.tab.c lex.yy.c -lfl -o a.out	***
	./a.out inputFile.c outputFile.c								***
	*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "symboltable.h"

	extern char *yytext;
	extern int yylex();
	extern int yylineno;
	extern FILE *yyin;
	int yydebug = 1;
	char nodeName[50];
	char nodeType[50];
	char typeleft[10];
	char typeright[10];
	char typeoftemp[10];
	char typeofarg[10];
	STACK *stack = NULL;
	STACK *helpstack=NULL;
	int countArgList = 0;
	int positionInHashtable=-1;
   
#define YYDEBUG_LEXER_TEXT yytext

	void yyerror(const char *s);



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 43 "parser_952304_1003060_932787.y"
{	char *word;	
#line 44 "parser_952304_1003060_932787.y"
	char *character; }
/* Line 193 of yacc.c.  */
#line 182 "parser_952304_1003060_932787.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 195 "parser_952304_1003060_932787.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      16,    17,     5,     3,    15,     4,     2,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    14,
       7,    13,     9,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    18,     2,    19,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    20,     2,    21,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     8,    10,
      11,    12,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    18,    25,
      28,    30,    32,    34,    36,    37,    45,    52,    54,    56,
      60,    62,    65,    70,    72,    77,    80,    81,    84,    85,
      87,    89,    91,    93,    95,    98,   101,   103,   105,   111,
     119,   121,   123,   129,   131,   137,   143,   153,   163,   173,
     183,   193,   195,   197,   200,   204,   205,   210,   214,   216,
     219,   222,   226,   230,   232,   237,   242,   247,   249,   253,
     255,   257,   259,   261,   263,   265,   269,   271,   273,   275,
     279,   281,   283,   285,   289,   291,   293,   295,   297,   298,
     304,   306,   308,   309,   313
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    40,    41,    -1,    41,    -1,
      42,    -1,    44,    -1,    43,    74,    14,    -1,    43,    74,
      18,    31,    19,    14,    -1,    43,     1,    -1,    26,    -1,
      25,    -1,    27,    -1,     1,    -1,    -1,    43,    74,    16,
      45,    46,    17,    49,    -1,    43,    74,     1,    46,    17,
      49,    -1,    47,    -1,    25,    -1,    47,    15,    48,    -1,
      48,    -1,    43,    74,    -1,    43,    74,    18,    19,    -1,
       1,    -1,    20,    50,    51,    21,    -1,    50,    42,    -1,
      -1,    51,    52,    -1,    -1,    53,    -1,    49,    -1,    54,
      -1,    57,    -1,    61,    -1,     1,    14,    -1,    62,    14,
      -1,    14,    -1,     1,    -1,    55,    16,    62,    17,    52,
      -1,    55,    16,    62,    17,    52,    56,    52,    -1,    22,
      -1,    23,    -1,    60,    16,    62,    17,    52,    -1,    58,
      -1,    60,     1,    62,    17,    52,    -1,    60,    16,    62,
       1,    52,    -1,    59,    16,    62,    14,    62,    14,    62,
      17,    52,    -1,    59,     1,    62,    14,    62,    14,    62,
      17,    52,    -1,    59,    16,    62,     1,    62,    14,    62,
      17,    52,    -1,    59,    16,    62,    14,    62,     1,    62,
      17,    52,    -1,    59,    16,    62,    14,    62,    14,    62,
       1,    52,    -1,    36,    -1,    29,    -1,    24,    14,    -1,
      24,    62,    14,    -1,    -1,    64,    63,    13,    62,    -1,
      64,     1,    62,    -1,    65,    -1,    64,    34,    -1,    64,
      35,    -1,    64,    32,    31,    -1,    64,    33,    31,    -1,
      74,    -1,    74,    18,    62,    19,    -1,    74,     1,    62,
      19,    -1,    74,    18,    62,     1,    -1,    67,    -1,    67,
      66,    67,    -1,     8,    -1,     7,    -1,     9,    -1,    10,
      -1,    11,    -1,    12,    -1,    67,    68,    69,    -1,    69,
      -1,     3,    -1,     4,    -1,    69,    70,    71,    -1,    71,
      -1,     5,    -1,     6,    -1,    16,    62,    17,    -1,    64,
      -1,    72,    -1,    31,    -1,    28,    -1,    -1,    74,    73,
      16,    75,    17,    -1,    30,    -1,    76,    -1,    -1,    76,
      15,    62,    -1,    62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   102,   103,   106,   107,   110,   134,   144,
     147,   153,   159,   165,   171,   171,   185,   189,   190,   193,
     196,   201,   209,   216,   219,   232,   233,   236,   237,   240,
     241,   242,   243,   244,   245,   248,   249,   250,   253,   254,
     257,   266,   275,   276,   277,   278,   281,   282,   283,   284,
     285,   288,   298,   309,   310,   313,   313,   325,   326,   327,
     328,   329,   330,   333,   340,   347,   348,   351,   352,   361,
     362,   363,   364,   365,   366,   369,   370,   373,   374,   377,
     384,   387,   388,   391,   392,   393,   394,   401,   411,   410,
     432,   441,   442,   445,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'+'", "'-'", "'*'", "'/'", "'<'",
  "LTEQ", "'>'", "GTEQ", "EQUAL", "NEQ", "'='", "';'", "','", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "IF", "ELSE", "RETURN", "VOID", "INT",
  "FLOAT", "FLOAT_NUM", "WHILE", "ID", "NUM", "PLUSEQ", "MINUSEQ", "INC",
  "DEC", "FOR", "\"if\"", "$accept", "program", "declaration_list",
  "declaration", "var_declaration", "type_specifier", "fun_declaration",
  "@1", "params", "param_list", "param", "compound_stmt",
  "local_declarations", "statement_list", "statement", "expression_stmt",
  "selection_stmt", "if", "else", "iteration_stmt", "for_stmt", "forloop",
  "whileloop", "return_stmt", "expression", "@2", "var",
  "simple_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "factor", "call", "@3", "id2", "args", "arg_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    43,    45,    42,    47,    60,   258,    62,
     259,   260,   261,    61,    59,    44,    40,    41,    91,    93,
     123,   125,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      43,    43,    43,    43,    45,    44,    44,    46,    46,    47,
      47,    48,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    54,    54,
      55,    56,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    59,    60,    61,    61,    63,    62,    62,    62,    62,
      62,    62,    62,    64,    64,    64,    64,    65,    65,    66,
      66,    66,    66,    66,    66,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    73,    72,
      74,    75,    75,    76,    76
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     2,
       1,     1,     1,     1,     0,     7,     6,     1,     1,     3,
       1,     2,     4,     1,     4,     2,     0,     2,     0,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     5,     7,
       1,     1,     5,     1,     5,     5,     9,     9,     9,     9,
       9,     1,     1,     2,     3,     0,     4,     3,     1,     2,
       2,     3,     3,     1,     4,     4,     4,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     0,     5,
       1,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    11,    10,    12,     0,     0,     4,     5,     0,
       6,     1,     3,     9,    90,     0,     0,     7,    14,     0,
      23,    11,     0,     0,    17,    20,     0,     0,    21,     0,
       0,     0,     0,     0,    26,    16,    19,     0,     8,    22,
       0,    15,    25,     0,     0,     0,    37,    36,     0,    24,
      40,     0,    87,    52,    86,    51,    30,    27,    29,    31,
       0,    32,    43,     0,     0,    33,     0,     0,    58,    67,
      76,    80,    85,     0,    34,     0,    53,     0,     0,     0,
       0,     0,     0,    35,     0,     0,     0,    59,    60,     0,
      77,    78,    70,    69,    71,    72,    73,    74,     0,     0,
      81,    82,     0,     0,     0,     0,    83,    54,     0,     0,
       0,     0,     0,    57,    61,    62,     0,    84,    68,    75,
      79,     0,     0,    92,     0,     0,     0,     0,     0,     0,
       0,    56,    65,    66,    64,    94,     0,    91,    38,     0,
       0,     0,    44,    45,    42,    89,     0,    41,     0,     0,
       0,     0,     0,    93,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,    48,    49,    50,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    22,    10,    26,    23,    24,
      25,    56,    40,    44,    57,    58,    59,    60,   148,    61,
      62,    63,    64,    65,    66,    89,    67,    68,    98,    69,
      99,    70,   102,    71,    72,   105,    73,   136,   137
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
      18,  -114,  -114,  -114,  -114,     2,    26,  -114,  -114,     7,
    -114,  -114,  -114,  -114,  -114,   116,    37,  -114,  -114,   -18,
      10,    25,    36,    66,    56,  -114,    37,    78,    88,    89,
      68,    97,    94,    99,  -114,  -114,  -114,    89,  -114,  -114,
      60,  -114,  -114,     7,    91,     6,   102,  -114,    42,  -114,
    -114,   186,  -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,
     108,  -114,  -114,     5,    13,  -114,   112,   178,  -114,   160,
      54,  -114,  -114,   143,  -114,   111,  -114,   121,    42,    42,
      42,    42,    42,  -114,    42,   110,   134,  -114,  -114,   123,
    -114,  -114,  -114,  -114,  -114,  -114,  -114,  -114,    42,    42,
    -114,  -114,    42,    42,    42,   126,  -114,  -114,   149,   129,
       9,   156,     8,  -114,  -114,  -114,    42,  -114,    96,    54,
    -114,   155,     3,    42,   109,    42,    42,    42,   109,   109,
     109,  -114,  -114,  -114,  -114,  -114,   163,   179,   173,   184,
     185,    53,  -114,  -114,  -114,  -114,    42,  -114,   109,    42,
      42,    42,    42,  -114,  -114,   188,   189,   191,    11,   109,
     109,   109,   109,   109,  -114,  -114,  -114,  -114,  -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,   195,   169,     1,  -114,  -114,   192,  -114,
     190,    28,  -114,  -114,  -113,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,   -48,  -114,   105,  -114,  -114,   117,
    -114,   120,  -114,   119,  -114,  -114,    -4,  -114,  -114
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -89
static const yytype_int16 yytable[] =
{
      75,     9,    11,    77,   133,    15,    79,     9,    13,   129,
     126,   138,   162,    27,    81,   142,   143,   144,    28,     1,
      17,    80,   134,   127,    19,   130,    -2,     1,   163,    82,
     108,   109,   110,   111,   112,   154,   113,    14,    20,    45,
     -13,    43,   -18,     2,     3,     4,   164,   165,   166,   167,
     168,     2,     3,     4,   151,   121,   122,    35,    48,   100,
     101,     1,    21,     3,     4,    41,    14,   152,   131,    20,
      52,    30,    14,    54,   -28,   135,   -28,   139,   140,   141,
     -28,   -28,   -28,    29,   -28,     2,     3,     4,   -28,   -28,
     -28,   -28,    46,     2,     3,     4,   -28,    32,   153,    90,
      91,   155,   156,   157,   158,    47,    33,    48,    38,    34,
      46,    34,    49,    50,    37,    51,    74,    16,    39,    52,
      53,    14,    54,    47,    78,    48,    83,    55,   106,    34,
      17,    50,    18,    51,    19,   107,   116,    52,    53,    14,
      54,   114,   123,   125,   103,    55,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -88,
     -63,   104,   -63,    90,    91,   115,   124,    92,    93,    94,
      95,    96,    97,   128,   132,   -63,   -63,   -63,   -63,    84,
     145,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -84,   -55,   -84,   -84,   146,   -84,   147,   -84,   149,   150,
      76,    12,    48,   117,   117,   159,   160,   117,   161,    42,
      85,    86,    87,    88,    52,   118,    14,    54,    31,   119,
      36,   120
};

static const yytype_uint8 yycheck[] =
{
      48,     0,     0,    51,     1,     9,     1,     6,     1,     1,
       1,   124,     1,    31,     1,   128,   129,   130,    22,     1,
      14,    16,    19,    14,    18,    17,     0,     1,    17,    16,
      78,    79,    80,    81,    82,   148,    84,    30,     1,    43,
      30,    40,    17,    25,    26,    27,   159,   160,   161,   162,
     163,    25,    26,    27,     1,   103,   104,    29,    16,     5,
       6,     1,    25,    26,    27,    37,    30,    14,   116,     1,
      28,    15,    30,    31,    14,   123,    16,   125,   126,   127,
      20,    21,    22,    17,    24,    25,    26,    27,    28,    29,
      30,    31,     1,    25,    26,    27,    36,    19,   146,     3,
       4,   149,   150,   151,   152,    14,    18,    16,    14,    20,
       1,    20,    21,    22,    17,    24,    14,     1,    19,    28,
      29,    30,    31,    14,    16,    16,    14,    36,    17,    20,
      14,    22,    16,    24,    18,    14,    13,    28,    29,    30,
      31,    31,    16,    14,     1,    36,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     3,     4,    31,    17,     7,     8,     9,
      10,    11,    12,    17,    19,    32,    33,    34,    35,     1,
      17,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    15,    17,    23,    19,    14,    14,
      14,     6,    16,    98,    99,    17,    17,   102,    17,    40,
      32,    33,    34,    35,    28,    98,    30,    31,    26,    99,
      30,   102
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    25,    26,    27,    39,    40,    41,    42,    43,
      44,     0,    41,     1,    30,    74,     1,    14,    16,    18,
       1,    25,    43,    46,    47,    48,    45,    31,    74,    17,
      15,    46,    19,    18,    20,    49,    48,    17,    14,    19,
      50,    49,    42,    43,    51,    74,     1,    14,    16,    21,
      22,    24,    28,    29,    31,    36,    49,    52,    53,    54,
      55,    57,    58,    59,    60,    61,    62,    64,    65,    67,
      69,    71,    72,    74,    14,    62,    14,    62,    16,     1,
      16,     1,    16,    14,     1,    32,    33,    34,    35,    63,
       3,     4,     7,     8,     9,    10,    11,    12,    66,    68,
       5,     6,    70,     1,    18,    73,    17,    14,    62,    62,
      62,    62,    62,    62,    31,    31,    13,    64,    67,    69,
      71,    62,    62,    16,    17,    14,     1,    14,    17,     1,
      17,    62,    19,     1,    19,    62,    75,    76,    52,    62,
      62,    62,    52,    52,    52,    17,    15,    23,    56,    14,
      14,     1,    14,    62,    52,    62,    62,    62,    62,    17,
      17,    17,     1,    17,    52,    52,    52,    52,    52
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 99 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 3:
#line 102 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 4:
#line 103 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 7:
#line 110 "parser_952304_1003060_932787.y"
    {
	//if stack is empty create it and then create/push a hashtable called global
	if (stack == NULL) {		
		if ((initStack(&stack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		}
		hashtable *globalHashtable = NULL;
		if (createHashTable(&globalHashtable, "global", "void", -1) != EXIT_SUCCESS) {
			fprintf(stderr, "Global hashtable initialization failed\n!");
			exit(-1);
		}
		push(globalHashtable, stack);		
	}
	//create node and insert to stack in top hashtable
	NODE *hashtableNode= NULL;
	if ((createNode(&hashtableNode, nodeName, (yyvsp[(1) - (3)].character), (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	}
	if (insertNode(hashtableNode, stack) == EXIT_FAILURE){
      printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable '\x1b[33m%s\x1b[0m' already defined!\n", yylineno, nodeName);
	}	
;}
    break;

  case 8:
#line 134 "parser_952304_1003060_932787.y"
    {
	NODE *tableNode = NULL;
	if ((createNode(&tableNode, nodeName, (yyvsp[(1) - (6)].character), (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	} 	
   if (insertNode(tableNode, stack) == EXIT_FAILURE){
      printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Array '\x1b[33m%s\x1b[0m' already defined!\n", yylineno, nodeName);
	}
;}
    break;

  case 9:
#line 144 "parser_952304_1003060_932787.y"
    {yyerrok; yyclearin; ;}
    break;

  case 10:
#line 148 "parser_952304_1003060_932787.y"
    {
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	(yyval.character) = "int";
;}
    break;

  case 11:
#line 154 "parser_952304_1003060_932787.y"
    {
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	(yyval.character) = "void";
;}
    break;

  case 12:
#line 160 "parser_952304_1003060_932787.y"
    {
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	(yyval.character) = "float";
;}
    break;

  case 13:
#line 166 "parser_952304_1003060_932787.y"
    {
	yyclearin;
;}
    break;

  case 14:
#line 171 "parser_952304_1003060_932787.y"
    {   
	if (stack == NULL) {
	   if ((initStack(&stack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		}
	}
	hashtable *hashTable = NULL;
	if (createHashTable(&hashTable, nodeName, nodeType, 1) != EXIT_SUCCESS) {
		fprintf(stderr, "hashtable initialization failed\n!");
	} 
	push(hashTable, stack);
	
   ;}
    break;

  case 15:
#line 184 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 16:
#line 185 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 17:
#line 189 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 18:
#line 190 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 19:
#line 193 "parser_952304_1003060_932787.y"
    {
	stack->hashTables[(stack->size) - 1].countparamfunc++;
   ;}
    break;

  case 20:
#line 196 "parser_952304_1003060_932787.y"
    {
	stack->hashTables[(stack->size) - 1].countparamfunc++;
   ;}
    break;

  case 21:
#line 201 "parser_952304_1003060_932787.y"
    {
	NODE *node = NULL;
	if ((createNode(&node, nodeName, (yyvsp[(1) - (2)].character), (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	} 
	insertNode(node, stack);		
	;}
    break;

  case 22:
#line 209 "parser_952304_1003060_932787.y"
    {
	NODE *node = NULL;
	if ((createNode(&node, nodeName, (yyvsp[(1) - (4)].character), (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");	
	}
	insertNode(node, stack);			
   ;}
    break;

  case 23:
#line 216 "parser_952304_1003060_932787.y"
    { yyerrok; yyclearin; ;}
    break;

  case 24:
#line 220 "parser_952304_1003060_932787.y"
    {
   if (helpstack==NULL)
      if ((initStack(&helpstack) != EXIT_SUCCESS)) {
			fprintf(stderr, "Stack initialization failed\n!");
			exit(-1);
		}
	hashtable *hashTable = NULL;
	hashTable=pop(stack);
	if (hashTable->isFunction==1)
	   push(hashTable,helpstack);
;}
    break;

  case 25:
#line 232 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 26:
#line 233 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 27:
#line 236 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 28:
#line 237 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 29:
#line 240 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 30:
#line 241 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 31:
#line 242 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 32:
#line 243 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 33:
#line 244 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 34:
#line 245 "parser_952304_1003060_932787.y"
    {yyerrok; yyclearin;;}
    break;

  case 35:
#line 248 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 36:
#line 249 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 37:
#line 250 "parser_952304_1003060_932787.y"
    {yyclearin;;}
    break;

  case 38:
#line 253 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 39:
#line 254 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 40:
#line 257 "parser_952304_1003060_932787.y"
    {
            hashtable *ifHashtable = NULL;
            if (createHashTable(&ifHashtable, "if", "null", 0) != EXIT_SUCCESS) {
		        fprintf(stderr, "IF Hashtable initialization failed!\n");
	        } else {
		        push(ifHashtable, stack);
	        }
    ;}
    break;

  case 41:
#line 266 "parser_952304_1003060_932787.y"
    {
	            hashtable *elseHashtable = NULL;
	            if (createHashTable(&elseHashtable, "else", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "ELSE Hashtable initialization failed!\n");
	            } else {
		            push(elseHashtable, stack);
	            }
    ;}
    break;

  case 42:
#line 275 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 43:
#line 276 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 44:
#line 277 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 45:
#line 278 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 46:
#line 281 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 47:
#line 282 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 48:
#line 283 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 49:
#line 284 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 50:
#line 285 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 51:
#line 288 "parser_952304_1003060_932787.y"
    {             
	            hashtable *forHashtable = NULL;
	            if (createHashTable(&forHashtable, "for", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "FOR Hashtable initialization failed!\n");
	            } else {
		            push(forHashtable, stack);		          
	            }
    ;}
    break;

  case 52:
#line 298 "parser_952304_1003060_932787.y"
    {  
               hashtable *whileHashtable = NULL;
	            if (createHashTable(&whileHashtable, "while", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "WHILE Hashtable initialization failed!\n");
	            } else {
		            push(whileHashtable, stack);
	            }
    ;}
    break;

  case 53:
#line 309 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 54:
#line 310 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 55:
#line 313 "parser_952304_1003060_932787.y"
    {strcpy(typeoftemp,typeleft); strcpy(typeleft,"NULL");;}
    break;

  case 56:
#line 314 "parser_952304_1003060_932787.y"
    {    
	if ((strcmp(typeoftemp, "NULL") != 0) && (strcmp(typeleft, "NULL")) != 0){
	   if (strcmp(typeoftemp, typeleft) != 0){		 
			printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable is of type: '\x1b[32m%s\x1b[0m' but '\x1b[33m%s\x1b[0m' was given!\n", yylineno, typeoftemp, typeleft);
		}
	}
	else if ((strcmp(typeoftemp, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
	   if (strcmp(typeoftemp,typeright)!=0)
		   printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable is of type: '\x1b[32m%s\x1b[0m' but '\x1b[33m%s\x1b[0m' was given!\n", yylineno, typeoftemp, typeright);
   }		
	;}
    break;

  case 57:
#line 325 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 58:
#line 326 "parser_952304_1003060_932787.y"
    { ;}
    break;

  case 59:
#line 327 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 60:
#line 328 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 61:
#line 329 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 62:
#line 330 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 63:
#line 333 "parser_952304_1003060_932787.y"
    {        
	        (yyval.character) = (yyvsp[(1) - (1)].word);	             	        
	        strcpy(typeleft,searchHash((yyvsp[(1) - (1)].word), stack));
	        if (strcmp(typeleft, "NULL") ==  0){
		         printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable '\x1b[33m%s\x1b[0m' used but not declared!\n", yylineno, (yyvsp[(1) - (1)].word));
	        }
;}
    break;

  case 64:
#line 340 "parser_952304_1003060_932787.y"
    {
	                        (yyval.character) = (yyvsp[(1) - (4)].word);
	                        strcpy(typeleft,searchHash((yyvsp[(1) - (4)].word), stack));
	                        if (strcmp(typeleft, "NULL") ==  0){
		                       printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Array '\x1b[33m%s\x1b[0m' used but not declared!\n", yylineno, (yyvsp[(1) - (4)].word));
	                        }
    ;}
    break;

  case 65:
#line 347 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 66:
#line 348 "parser_952304_1003060_932787.y"
    {yyerrok;;}
    break;

  case 67:
#line 351 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 68:
#line 352 "parser_952304_1003060_932787.y"
    {
             if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
                if (strcmp(typeleft, typeright) != 0) {
			printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable is of type: '\x1b[32m%s\x1b[0m' but '\x1b[33m%s\x1b[0m' was given!\n", yylineno, typeleft, typeright);
                                                        }
                                                    }
;}
    break;

  case 69:
#line 361 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 70:
#line 362 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 71:
#line 363 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 72:
#line 364 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 73:
#line 365 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 74:
#line 366 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 76:
#line 370 "parser_952304_1003060_932787.y"
    { ;}
    break;

  case 77:
#line 373 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 78:
#line 374 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 79:
#line 377 "parser_952304_1003060_932787.y"
    {
                                if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
                                    if (strcmp(typeleft, typeright) != 0) {
			printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable is of type: '\x1b[32m%s\x1b[0m' but '\x1b[33m%s\x1b[0m' was given!\n", yylineno, typeleft, typeright);
                                    }
                                }
    ;}
    break;

  case 80:
#line 384 "parser_952304_1003060_932787.y"
    {(yyval.character) = (yyvsp[(1) - (1)].character); ;}
    break;

  case 81:
#line 387 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 82:
#line 388 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 83:
#line 391 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 84:
#line 392 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 85:
#line 393 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 86:
#line 395 "parser_952304_1003060_932787.y"
    {
	strcpy(typeright,"int");
	if (positionInHashtable != -1) {
	    strcpy(typeofarg,"int");
	}
;}
    break;

  case 87:
#line 402 "parser_952304_1003060_932787.y"
    {
	strcpy(typeright,"float");
	if (positionInHashtable != -1) {
	    strcpy(typeofarg,"float");
	}
;}
    break;

  case 88:
#line 411 "parser_952304_1003060_932787.y"
    {
	positionInHashtable = -1;
	positionInHashtable = searchPosition((yyvsp[(1) - (1)].word),helpstack);	
	if (positionInHashtable == -1){
	   printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Function '\x1b[33m%s\x1b[0m' used but not declared!\n", yylineno, (yyvsp[(1) - (1)].word));
	}
;}
    break;

  case 89:
#line 419 "parser_952304_1003060_932787.y"
    {
   if (positionInHashtable != -1){
	   hashtable *hashTable = &helpstack->hashTables[positionInHashtable];	
	   if (hashTable[positionInHashtable].countparamfunc != countArgList){
		   printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Function '\x1b[33m%s\x1b[0m' called with wrong number of parameters\n", yylineno, hashTable->namefunction);
	   }
   }
	countArgList = 0;
	positionInHashtable = -1;

;}
    break;

  case 90:
#line 432 "parser_952304_1003060_932787.y"
    {
            strcpy(nodeName, yytext);           
            (yyval.word) = nodeName;            
            if (positionInHashtable != -1) {                     
               strcpy(typeofarg,searchHash(nodeName, stack));  
            }
          
    ;}
    break;

  case 91:
#line 441 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 92:
#line 442 "parser_952304_1003060_932787.y"
    {;}
    break;

  case 93:
#line 446 "parser_952304_1003060_932787.y"
    {
	countArgList++;
;}
    break;

  case 94:
#line 450 "parser_952304_1003060_932787.y"
    {
	countArgList++;
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2189 "parser_952304_1003060_932787.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 454 "parser_952304_1003060_932787.y"

int main(int argc, char *argv[]) {
  
	if (argc < 2) {
		printf("Wrong number of arguments given!\n");
		return -1;
	} else {
		yyin = fopen(argv[1], "r");
	   printf("\n");
		yyparse();
	}
	printf("\n");
	return 1;
}

void yyerror(const char *s) {

	printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): \x1b[32m%s\x1b[0m : \x1b[33m%s\x1b[0m\n", yylineno, s, yytext);
}


