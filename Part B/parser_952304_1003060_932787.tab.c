/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser_952304_1003060_932787.y" /* yacc.c:339  */

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


#line 106 "parser_952304_1003060_932787.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser_952304_1003060_932787.tab.h".  */
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 43 "parser_952304_1003060_932787.y" /* yacc.c:355  */
	char *word;	
#line 44 "parser_952304_1003060_932787.y" /* yacc.c:355  */
	char *character; 

#line 173 "parser_952304_1003060_932787.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_952304_1003060_932787_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "parser_952304_1003060_932787.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
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

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "$@1", "params", "param_list", "param", "compound_stmt",
  "local_declarations", "statement_list", "statement", "expression_stmt",
  "selection_stmt", "if", "else", "iteration_stmt", "for_stmt", "forloop",
  "whileloop", "return_stmt", "expression", "$@2", "var",
  "simple_expression", "relop", "additive_expression", "addop", "term",
  "mulop", "factor", "call", "$@3", "id2", "args", "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,    43,    45,    42,    47,    60,   258,    62,
     259,   260,   261,    61,    59,    44,    40,    41,    91,    93,
     123,   125,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,  -114,   195,   169,     1,  -114,  -114,   192,  -114,
     190,    28,  -114,  -114,  -113,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,   -48,  -114,   105,  -114,  -114,   117,
    -114,   120,  -114,   119,  -114,  -114,    -4,  -114,  -114
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    22,    10,    26,    23,    24,
      25,    56,    40,    44,    57,    58,    59,    60,   148,    61,
      62,    63,    64,    65,    66,    89,    67,    68,    98,    69,
      99,    70,   102,    71,    72,   105,    73,   136,   137
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 99 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1395 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1401 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 103 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1407 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
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
	if ((createNode(&hashtableNode, nodeName, (yyvsp[-2].character), (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	}
	if (insertNode(hashtableNode, stack) == EXIT_FAILURE){
      printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable '\x1b[33m%s\x1b[0m' already defined!\n", yylineno, nodeName);
	}	
}
#line 1436 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 134 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	NODE *tableNode = NULL;
	if ((createNode(&tableNode, nodeName, (yyvsp[-5].character), (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	} 	
   if (insertNode(tableNode, stack) == EXIT_FAILURE){
      printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Array '\x1b[33m%s\x1b[0m' already defined!\n", yylineno, nodeName);
	}
}
#line 1451 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 144 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok; yyclearin; }
#line 1457 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 148 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	(yyval.character) = "int";
}
#line 1467 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 154 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	(yyval.character) = "void";
}
#line 1477 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 160 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	bzero(nodeType, 50);
	strcpy(nodeType, yytext);
	(yyval.character) = "float";
}
#line 1487 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 166 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	yyclearin;
}
#line 1495 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 171 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
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
	
   }
#line 1514 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 184 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1520 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 185 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1526 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 189 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1532 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 190 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1538 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 193 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	stack->hashTables[(stack->size) - 1].countparamfunc++;
   }
#line 1546 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 196 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	stack->hashTables[(stack->size) - 1].countparamfunc++;
   }
#line 1554 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 201 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	NODE *node = NULL;
	if ((createNode(&node, nodeName, (yyvsp[-1].character), (stack->size) - 1, yylineno, 1) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");
		exit(-1);
	} 
	insertNode(node, stack);		
	}
#line 1567 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 209 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	NODE *node = NULL;
	if ((createNode(&node, nodeName, (yyvsp[-3].character), (stack->size) - 1, yylineno, 0) != EXIT_SUCCESS)) {
		fprintf(stderr, "Node initialization failed!\n");	
	}
	insertNode(node, stack);			
   }
#line 1579 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 216 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    { yyerrok; yyclearin; }
#line 1585 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 220 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
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
}
#line 1601 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 232 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1607 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 233 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1613 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 236 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1619 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 237 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1625 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 240 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1631 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 241 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1637 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 242 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1643 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 243 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1649 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 244 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1655 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 245 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok; yyclearin;}
#line 1661 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 248 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1667 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 249 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1673 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 250 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyclearin;}
#line 1679 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 253 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1685 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 254 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1691 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 257 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
            hashtable *ifHashtable = NULL;
            if (createHashTable(&ifHashtable, "if", "null", 0) != EXIT_SUCCESS) {
		        fprintf(stderr, "IF Hashtable initialization failed!\n");
	        } else {
		        push(ifHashtable, stack);
	        }
    }
#line 1704 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 266 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	            hashtable *elseHashtable = NULL;
	            if (createHashTable(&elseHashtable, "else", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "ELSE Hashtable initialization failed!\n");
	            } else {
		            push(elseHashtable, stack);
	            }
    }
#line 1717 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 275 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1723 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 276 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1729 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 277 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1735 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 278 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1741 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 281 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1747 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 282 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1753 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 283 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1759 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 284 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1765 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 285 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1771 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 288 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {             
	            hashtable *forHashtable = NULL;
	            if (createHashTable(&forHashtable, "for", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "FOR Hashtable initialization failed!\n");
	            } else {
		            push(forHashtable, stack);		          
	            }
    }
#line 1784 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 298 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {  
               hashtable *whileHashtable = NULL;
	            if (createHashTable(&whileHashtable, "while", "null", 0) != EXIT_SUCCESS) {
		            fprintf(stderr, "WHILE Hashtable initialization failed!\n");
	            } else {
		            push(whileHashtable, stack);
	            }
    }
#line 1797 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 309 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1803 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 310 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1809 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 313 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {strcpy(typeoftemp,typeleft); strcpy(typeleft,"NULL");}
#line 1815 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 314 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
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
	}
#line 1831 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 325 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1837 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 326 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    { }
#line 1843 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 327 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1849 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 328 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1855 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 329 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1861 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 330 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1867 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 333 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {        
	        (yyval.character) = (yyvsp[0].word);	             	        
	        strcpy(typeleft,searchHash((yyvsp[0].word), stack));
	        if (strcmp(typeleft, "NULL") ==  0){
		         printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable '\x1b[33m%s\x1b[0m' used but not declared!\n", yylineno, (yyvsp[0].word));
	        }
}
#line 1879 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 340 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	                        (yyval.character) = (yyvsp[-3].word);
	                        strcpy(typeleft,searchHash((yyvsp[-3].word), stack));
	                        if (strcmp(typeleft, "NULL") ==  0){
		                       printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Array '\x1b[33m%s\x1b[0m' used but not declared!\n", yylineno, (yyvsp[-3].word));
	                        }
    }
#line 1891 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 347 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1897 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 348 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1903 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 351 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1909 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 352 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
             if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
                if (strcmp(typeleft, typeright) != 0) {
			printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable is of type: '\x1b[32m%s\x1b[0m' but '\x1b[33m%s\x1b[0m' was given!\n", yylineno, typeleft, typeright);
                                                        }
                                                    }
}
#line 1921 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 361 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1927 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 362 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1933 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 363 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1939 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 364 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1945 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 365 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1951 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 366 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1957 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 370 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    { }
#line 1963 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 373 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1969 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 374 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1975 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 377 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
                                if ((strcmp(typeleft, "NULL") != 0) && (strcmp(typeright, "NULL") != 0)){
                                    if (strcmp(typeleft, typeright) != 0) {
			printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Variable is of type: '\x1b[32m%s\x1b[0m' but '\x1b[33m%s\x1b[0m' was given!\n", yylineno, typeleft, typeright);
                                    }
                                }
    }
#line 1987 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 384 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {(yyval.character) = (yyvsp[0].character); }
#line 1993 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 387 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 1999 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 388 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 2005 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 391 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 2011 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 392 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 2017 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 393 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 2023 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 395 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	strcpy(typeright,"int");
	if (positionInHashtable != -1) {
	    strcpy(typeofarg,"int");
	}
}
#line 2034 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 402 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	strcpy(typeright,"float");
	if (positionInHashtable != -1) {
	    strcpy(typeofarg,"float");
	}
}
#line 2045 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 411 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	positionInHashtable = -1;
	positionInHashtable = searchPosition((yyvsp[0].word),helpstack);	
	if (positionInHashtable == -1){
	   printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Function '\x1b[33m%s\x1b[0m' used but not declared!\n", yylineno, (yyvsp[0].word));
	}
}
#line 2057 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 419 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
   if (positionInHashtable != -1){
	   hashtable *hashTable = &helpstack->hashTables[positionInHashtable];	
	   if (hashTable[positionInHashtable].countparamfunc != countArgList){
		   printf("\x1b[31mERROR\x1b[0m (line: \x1b[36m%d\x1b[0m): Function '\x1b[33m%s\x1b[0m' called with wrong number of parameters\n", yylineno, hashTable->namefunction);
	   }
   }
	countArgList = 0;
	positionInHashtable = -1;

}
#line 2073 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 432 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
            strcpy(nodeName, yytext);           
            (yyval.word) = nodeName;            
            if (positionInHashtable != -1) {                     
               strcpy(typeofarg,searchHash(nodeName, stack));  
            }
          
    }
#line 2086 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 441 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 2092 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 442 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {}
#line 2098 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 446 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	countArgList++;
}
#line 2106 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 450 "parser_952304_1003060_932787.y" /* yacc.c:1646  */
    {
	countArgList++;
}
#line 2114 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
    break;


#line 2118 "parser_952304_1003060_932787.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 454 "parser_952304_1003060_932787.y" /* yacc.c:1906  */

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

