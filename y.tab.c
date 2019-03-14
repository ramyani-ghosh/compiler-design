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
#line 1 "proj.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int curr_scope = 0;
typedef struct symbol_table
{
	char *name;		//name of the token	(in case of keywords, the name is the "keyword" itself)
	char *symbol;
	char *type;		//type of token (in case of keywords, the type is the name of the keyword)
	char *value; 	//saving value as a string
	int lno;		//line number where token is declared (default 0)
	int *lno_used;	//line number where token is first used (defult 0)
	int size;		//size of the token
	int scope;
	struct symbol_table *next;	//symbol table is LL
}symbol_table;

typedef struct tempvals
{
	char *name;
	char *value;
	struct tempvals *next;
}tempvals;

tempvals *tvhead =NULL;
symbol_table *st = NULL;
int lookup(char *s, char *type, char*);
symbol_table* initialize();
void insert(char *s, char *type, char*);
void deletetempval(tempvals *temp);
void tempval(char *var, char *val);
void check_scope(char *s, char *type, char *token_type);


extern char yytext[];
extern int column;
extern FILE *yyin;
int scope_error= 0;
char *wrong_symbol;



#line 111 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    INC_OP = 262,
    DEC_OP = 263,
    LE_OP = 264,
    GE_OP = 265,
    EQ_OP = 266,
    NE_OP = 267,
    H = 268,
    AND_OP = 269,
    OR_OP = 270,
    MUL_ASSIGN = 271,
    DIV_ASSIGN = 272,
    MOD_ASSIGN = 273,
    ADD_ASSIGN = 274,
    SUB_ASSIGN = 275,
    CHAR = 276,
    SHORT = 277,
    INT = 278,
    LONG = 279,
    FLOAT = 280,
    DOUBLE = 281,
    VOID = 282,
    IF = 283,
    ELSE = 284,
    CONTINUE = 285,
    BREAK = 286,
    RETURN = 287,
    HASH = 288,
    INCLUDE = 289,
    LIBRARY = 290
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define STRING_LITERAL 260
#define SIZEOF 261
#define INC_OP 262
#define DEC_OP 263
#define LE_OP 264
#define GE_OP 265
#define EQ_OP 266
#define NE_OP 267
#define H 268
#define AND_OP 269
#define OR_OP 270
#define MUL_ASSIGN 271
#define DIV_ASSIGN 272
#define MOD_ASSIGN 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define CHAR 276
#define SHORT 277
#define INT 278
#define LONG 279
#define FLOAT 280
#define DOUBLE 281
#define VOID 282
#define IF 283
#define ELSE 284
#define CONTINUE 285
#define BREAK 286
#define RETURN 287
#define HASH 288
#define INCLUDE 289
#define LIBRARY 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 47 "proj.y" /* yacc.c:355  */

	int ival;
	char string[128];

#line 226 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   625

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  47
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,     2,     2,    49,    42,     2,
      36,    37,    43,    44,    41,    45,    40,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    55,
      50,    54,    51,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,    46,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    70,    71,    72,    76,    77,    78,    79,
      80,    81,    82,    86,    87,    91,    92,    93,    94,    95,
      96,   100,   101,   102,   103,   104,   105,   109,   110,   111,
     112,   116,   117,   118,   122,   123,   124,   125,   126,   130,
     131,   132,   136,   137,   141,   142,   146,   147,   151,   152,
     156,   157,   158,   159,   160,   161,   166,   167,   172,   185,
     186,   194,   195,   203,   204,   205,   206,   207,   208,   209,
     213,   216,   217,   218,   222,   223,   227,   228,   232,   233,
     238,   239,   240,   244,   245,   249,   249,   250,   251,   252,
     257,   258,   259,   260,   264,   265,   269,   270,   274,   275,
     279,   280,   281,   286,   287,   288,   289,   293,   294,   298,
     299,   303,   304,   308,   308,   308,   309,   309,   309,   309,
     310,   310,   310,   311,   311,   311
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "INC_OP", "DEC_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "H", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "CHAR", "SHORT", "INT", "LONG",
  "FLOAT", "DOUBLE", "VOID", "IF", "ELSE", "CONTINUE", "BREAK", "RETURN",
  "HASH", "INCLUDE", "LIBRARY", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "declaration", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "parameter_list",
  "parameter_declaration", "identifier_list", "initializer",
  "initializer_list", "statement", "$@1", "compound_statement",
  "declaration_list", "statement_list", "expression_statement",
  "selection_statement", "jump_statement", "hashinclude",
  "translation_unit", "external_declaration", "function_definition", "$@2",
  "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    40,    41,    91,    93,
      46,    44,    38,    42,    43,    45,   126,    33,    47,    37,
      60,    62,    63,    58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -117

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     115,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -24,
     -74,    13,   201,    18,   132,   -74,   -74,    15,   -34,   -74,
     107,    34,   -74,    13,   245,    19,   -74,   -74,    85,    13,
     -74,   359,   245,    19,   -74,   -74,    13,     6,   -74,     9,
     -13,   -74,    19,   163,   -74,    55,   -74,   -74,   -74,   -74,
     565,   578,   578,   578,   -74,   -74,   -74,   -74,   -74,   -74,
     359,   -74,    32,    10,   578,   101,    42,     3,    33,    83,
     -10,   -74,   -74,   -74,    19,   -74,    63,   -74,   245,   -74,
     120,   -74,    91,    90,    92,   508,   -74,   -74,   -74,    39,
     -74,    19,   208,   253,   -74,   -74,   -74,   -74,   133,   553,
     -74,   -74,   -74,    36,   -74,    26,   -74,   -74,   377,   578,
     148,   -74,   -74,   -74,   -74,   -74,   -74,   578,   -74,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   -74,   -74,   -74,   -74,   -74,   578,   -74,
     -74,   -74,    43,   578,   -74,   -74,   -74,   298,   -74,   -74,
     111,   127,   -74,   314,   -74,   -74,    41,   -74,   -30,   -74,
     -74,   -74,   -74,   -74,   -74,   101,   101,    42,    42,    42,
      42,     3,     3,    33,    83,   -22,   -74,   -74,    52,   -74,
     -74,   -74,   115,   -74,   -74,   -74,   -74,   578,   -74,   578,
     494,   -74,   -74,   -74,   404,   494,   -74,   449,   494,   -74,
     -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    70,    64,    65,    66,    67,    68,    69,    63,     0,
     112,     0,   123,     0,   108,   109,   111,     0,     0,    59,
      61,     0,    94,     0,   120,     0,     1,   110,     0,     0,
      58,     0,   113,     0,    78,    73,    77,     0,    74,     0,
      61,    95,     0,    85,   124,     0,    60,     2,     3,     4,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    26,
       0,     6,    15,    27,     0,    31,    34,    39,    42,    44,
      46,    48,    80,    62,     0,   117,    76,    71,     0,    72,
       0,   121,     0,     0,     0,     0,    98,    90,    56,     0,
      96,     0,    85,    85,    87,    88,    89,   125,     0,     0,
      19,    16,    17,     0,    83,     0,    11,    12,     0,     0,
       0,    51,    52,    53,    54,    55,    50,     0,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   114,   118,    75,    79,   122,     0,   103,
     104,   105,     0,     0,    99,    86,    92,    85,    91,    97,
       0,     0,     5,     0,    81,     8,     0,    13,     0,    10,
      49,    28,    29,    30,    27,    32,    33,    37,    38,    35,
      36,    40,    41,    43,    45,     0,   115,   119,     0,   106,
      57,    93,     0,    20,    82,    84,     9,     0,     7,     0,
      85,   107,    14,    47,    85,    85,   100,    85,    85,   101,
     102
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -16,   -74,   -21,    53,    -9,    22,
      44,   -74,   -17,   -27,   -74,   -47,     0,   -74,   136,     1,
      40,   -74,    96,   -74,   -57,   -74,   -73,   -74,   -25,   -18,
      89,   -74,   -74,   -74,    14,   -74,   178,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    61,    62,   156,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    88,   117,    89,    22,    18,    19,    23,
      12,    37,    38,    39,    73,   105,    90,    91,    44,    24,
      93,    94,    95,    96,    13,    14,    15,    16,    74,   176,
      33,   134,   177,    42,   137,    25,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      10,    11,    32,   104,    72,   131,   103,    29,    75,   188,
      17,   143,   124,   125,    10,    11,     1,    81,    26,   143,
     149,    30,    36,    21,    41,    92,   111,   112,   113,   114,
     115,   189,    41,    72,   100,   101,   102,    34,   142,   106,
     107,    31,   132,    77,   128,   129,    79,    78,   118,   133,
      80,    20,   103,   126,   127,     2,     3,     4,     5,     6,
       7,     8,   158,    40,   116,    28,   145,   153,   108,    40,
     109,    35,   110,   152,   149,    43,    76,   143,   186,    36,
     143,   157,   187,   154,   143,   175,   122,   123,    45,   190,
     160,   178,    41,   143,   144,    98,   185,   130,   179,    21,
     151,   165,   166,   161,   162,   163,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,   180,   194,     1,   171,
     172,   196,   198,   136,   199,   200,    72,   138,     2,     3,
       4,     5,     6,     7,     8,     1,     2,     3,     4,     5,
       6,     7,     8,    21,   119,   139,   150,   140,     9,   120,
     121,   159,   173,     2,     3,     4,     5,     6,     7,     8,
     192,    31,   182,  -116,   183,    46,    47,    48,    49,    50,
      51,    52,   193,   164,   135,   174,   197,   167,   168,   169,
     170,   147,    10,    11,     2,     3,     4,     5,     6,     7,
       8,    82,    27,    83,    84,    85,   191,    41,     0,    53,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    47,    48,    49,    50,    51,    52,     0,    86,     0,
      87,     0,     2,     3,     4,     5,     6,     7,     8,     2,
       3,     4,     5,     6,     7,     8,    82,    21,    83,    84,
      85,     0,     0,     0,    53,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,    47,    48,    49,    50,
      51,    52,     0,    86,     0,   146,     2,     3,     4,     5,
       6,     7,     8,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,    83,    84,    85,     0,     0,     0,    53,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    47,    48,    49,    50,    51,    52,     0,    86,     0,
     148,     0,     0,     0,     0,     0,     0,    47,    48,    49,
      50,    51,    52,     0,     0,     0,    82,     0,    83,    84,
      85,     0,     0,     0,    53,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
      53,     0,     0,    86,     0,   181,    54,    55,    56,    57,
      58,    59,    47,    48,    49,    50,    51,    52,     0,     0,
      60,   184,     0,     0,     0,     0,     0,     0,     0,     0,
      47,    48,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    47,    48,    49,
      50,    51,    52,    53,   155,    60,     0,     0,     0,    54,
      55,    56,    57,    58,    59,     2,     3,     4,     5,     6,
       7,     8,    82,   195,    83,    84,    85,     0,     0,     0,
      53,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    47,    48,    49,    50,    51,    52,     0,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     3,     4,     5,     6,     7,     8,    82,     0,    83,
      84,    85,     0,     0,     0,    53,     0,     0,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    47,    48,    49,
      50,    51,    52,     0,    86,     0,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    51,    52,     0,     0,     0,
       0,     0,    82,     0,    83,    84,    85,     0,     0,     0,
      53,     0,     0,     0,     0,     0,    54,    55,    56,    57,
      58,    59,     0,     0,    53,     0,     0,     0,     0,    86,
      54,    55,    56,    57,    58,    59,    47,    48,    49,    50,
      51,    52,     0,   141,     0,     0,     0,     0,    47,    48,
      49,    50,    51,    52,     2,     3,     4,     5,     6,     7,
       8,    47,    48,    49,    50,    51,    52,     0,     0,    53,
       0,     0,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    99,     0,     0,     0,     0,     0,    54,    55,    56,
      57,    58,    59,     0,    53,     0,     0,     0,     0,     0,
      54,    55,    56,    57,    58,    59
};

static const yytype_int16 yycheck[] =
{
       0,     0,    20,    60,    31,    15,    53,    41,    33,    39,
      34,    41,     9,    10,    14,    14,     3,    42,     0,    41,
      93,    55,    21,    36,    24,    43,    16,    17,    18,    19,
      20,    53,    32,    60,    50,    51,    52,     3,    85,     7,
       8,    54,    52,    37,    11,    12,    37,    41,    64,    74,
      41,    11,    99,    50,    51,    21,    22,    23,    24,    25,
      26,    27,   109,    23,    54,    50,    91,    41,    36,    29,
      38,    37,    40,    37,   147,    56,    36,    41,    37,    78,
      41,   108,    41,    57,    41,   132,    44,    45,     3,    37,
     117,   138,    92,    41,    55,    40,   153,    14,    55,    36,
      99,   122,   123,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   143,   190,     3,   128,
     129,   194,   195,     3,   197,   198,   153,    36,    21,    22,
      23,    24,    25,    26,    27,     3,    21,    22,    23,    24,
      25,    26,    27,    36,    43,    55,    13,    55,    33,    48,
      49,     3,   130,    21,    22,    23,    24,    25,    26,    27,
     187,    54,    51,    56,    37,    29,     3,     4,     5,     6,
       7,     8,   189,   189,    78,   131,   194,   124,   125,   126,
     127,    92,   182,   182,    21,    22,    23,    24,    25,    26,
      27,    28,    14,    30,    31,    32,   182,   197,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,     3,     4,     5,     6,     7,     8,    -1,    55,    -1,
      57,    -1,    21,    22,    23,    24,    25,    26,    27,    21,
      22,    23,    24,    25,    26,    27,    28,    36,    30,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
       7,     8,    -1,    55,    -1,    57,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    -1,    30,    31,    32,    -1,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,     3,     4,     5,     6,     7,     8,    -1,    55,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    28,    -1,    30,    31,
      32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47,    -1,    -1,    -1,    -1,
      36,    -1,    -1,    55,    -1,    57,    42,    43,    44,    45,
      46,    47,     3,     4,     5,     6,     7,     8,    -1,    -1,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,     3,     4,     5,
       6,     7,     8,    36,    37,    56,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    47,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,     3,     4,     5,     6,     7,     8,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      31,    32,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    47,     3,     4,     5,
       6,     7,     8,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    30,    31,    32,    -1,    -1,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    47,    -1,    -1,    36,    -1,    -1,    -1,    -1,    55,
      42,    43,    44,    45,    46,    47,     3,     4,     5,     6,
       7,     8,    -1,    55,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    21,    22,    23,    24,    25,    26,
      27,     3,     4,     5,     6,     7,     8,    -1,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      47,    36,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    47,    -1,    36,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    21,    22,    23,    24,    25,    26,    27,    33,
      74,    77,    78,    92,    93,    94,    95,    34,    75,    76,
      78,    36,    74,    77,    87,   103,     0,    94,    50,    41,
      55,    54,    87,    98,     3,    37,    77,    79,    80,    81,
      78,    74,   101,    56,    86,     3,    76,     3,     4,     5,
       6,     7,     8,    36,    42,    43,    44,    45,    46,    47,
      56,    59,    60,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    82,    96,    86,    78,    37,    41,    37,
      41,    86,    28,    30,    31,    32,    55,    57,    71,    73,
      84,    85,    87,    88,    89,    90,    91,   104,    40,    36,
      62,    62,    62,    73,    82,    83,     7,     8,    36,    38,
      40,    16,    17,    18,    19,    20,    54,    72,    62,    43,
      48,    49,    44,    45,     9,    10,    50,    51,    11,    12,
      14,    15,    52,    86,    99,    80,     3,   102,    36,    55,
      55,    55,    73,    41,    55,    86,    57,    88,    57,    84,
      13,    77,    37,    41,    57,    37,    61,    71,    73,     3,
      71,    62,    62,    62,    62,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    68,    73,    97,   100,    73,    55,
      71,    57,    51,    37,    57,    82,    37,    41,    39,    53,
      37,    92,    71,    70,    84,    29,    84,    87,    84,    84,
      84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    82,    83,    83,    85,    84,    84,    84,    84,
      86,    86,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    91,    91,    91,    91,    92,    92,    93,
      93,    94,    94,    96,    97,    95,    98,    99,   100,    95,
     101,   102,    95,   103,   104,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     2,     2,     1,     3,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     1,     3,     2,     1,     1,     3,
       1,     3,     4,     1,     3,     0,     2,     1,     1,     1,
       2,     3,     3,     4,     1,     2,     1,     2,     1,     2,
       6,     7,     8,     2,     2,     2,     3,     8,     1,     1,
       2,     1,     1,     0,     0,     6,     0,     0,     0,     6,
       0,     0,     5,     0,     0,     4
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
#line 69 "proj.y" /* yacc.c:1646  */
    {}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 70 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string));}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 71 "proj.y" /* yacc.c:1646  */
    {}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "proj.y" /* yacc.c:1646  */
    {}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 76 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "proj.y" /* yacc.c:1646  */
    {}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 78 "proj.y" /* yacc.c:1646  */
    {}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 79 "proj.y" /* yacc.c:1646  */
    {}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 80 "proj.y" /* yacc.c:1646  */
    {}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 81 "proj.y" /* yacc.c:1646  */
    {}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 82 "proj.y" /* yacc.c:1646  */
    {}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "proj.y" /* yacc.c:1646  */
    {}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "proj.y" /* yacc.c:1646  */
    {}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 91 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 92 "proj.y" /* yacc.c:1646  */
    {}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 93 "proj.y" /* yacc.c:1646  */
    {}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 94 "proj.y" /* yacc.c:1646  */
    {}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 95 "proj.y" /* yacc.c:1646  */
    {}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 96 "proj.y" /* yacc.c:1646  */
    {}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 100 "proj.y" /* yacc.c:1646  */
    {}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 101 "proj.y" /* yacc.c:1646  */
    {}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 102 "proj.y" /* yacc.c:1646  */
    {}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 103 "proj.y" /* yacc.c:1646  */
    {}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 104 "proj.y" /* yacc.c:1646  */
    {}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 105 "proj.y" /* yacc.c:1646  */
    {}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 109 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 110 "proj.y" /* yacc.c:1646  */
    {}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 111 "proj.y" /* yacc.c:1646  */
    {}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 112 "proj.y" /* yacc.c:1646  */
    {}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 116 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 117 "proj.y" /* yacc.c:1646  */
    {}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 118 "proj.y" /* yacc.c:1646  */
    {}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 122 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 123 "proj.y" /* yacc.c:1646  */
    {}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 124 "proj.y" /* yacc.c:1646  */
    {}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 125 "proj.y" /* yacc.c:1646  */
    {}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 126 "proj.y" /* yacc.c:1646  */
    {}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 130 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 131 "proj.y" /* yacc.c:1646  */
    {}
#line 1792 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 132 "proj.y" /* yacc.c:1646  */
    {}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 136 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 137 "proj.y" /* yacc.c:1646  */
    {}
#line 1810 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 141 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1816 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 142 "proj.y" /* yacc.c:1646  */
    {}
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 146 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 147 "proj.y" /* yacc.c:1646  */
    {}
#line 1834 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 151 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 152 "proj.y" /* yacc.c:1646  */
    {}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 156 "proj.y" /* yacc.c:1646  */
    {}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 157 "proj.y" /* yacc.c:1646  */
    {}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 158 "proj.y" /* yacc.c:1646  */
    {}
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 159 "proj.y" /* yacc.c:1646  */
    {}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 160 "proj.y" /* yacc.c:1646  */
    {}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 161 "proj.y" /* yacc.c:1646  */
    {}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 166 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 167 "proj.y" /* yacc.c:1646  */
    {}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 172 "proj.y" /* yacc.c:1646  */
    {
								// printf("%s %s", $1, $2);
								char *p = strtok((yyvsp[-1].string), ",");
								while(p!=NULL)
								{
									lookup(p, (yyvsp[-2].string), "identifier");
									p=strtok(NULL, ",");
								}

							}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 185 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 186 "proj.y" /* yacc.c:1646  */
    {
														strcpy((yyval.string),(yyvsp[0].string));
														strcat((yyval.string), ",");
														strcat((yyval.string), (yyvsp[-2].string));
													}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 194 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 195 "proj.y" /* yacc.c:1646  */
    {
										tempval((yyvsp[-2].string), (yyvsp[0].string));
										strcpy((yyval.string),(yyvsp[-2].string));
									}
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 203 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 204 "proj.y" /* yacc.c:1646  */
    {}
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 205 "proj.y" /* yacc.c:1646  */
    {}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 206 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 207 "proj.y" /* yacc.c:1646  */
    {}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 208 "proj.y" /* yacc.c:1646  */
    {}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 209 "proj.y" /* yacc.c:1646  */
    {}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 213 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 216 "proj.y" /* yacc.c:1646  */
    {}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "proj.y" /* yacc.c:1646  */
    {}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 218 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string), (yyvsp[-2].string));}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 222 "proj.y" /* yacc.c:1646  */
    {}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 223 "proj.y" /* yacc.c:1646  */
    {}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 227 "proj.y" /* yacc.c:1646  */
    {}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 228 "proj.y" /* yacc.c:1646  */
    {}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 232 "proj.y" /* yacc.c:1646  */
    {}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 233 "proj.y" /* yacc.c:1646  */
    {}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 238 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 239 "proj.y" /* yacc.c:1646  */
    {}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 240 "proj.y" /* yacc.c:1646  */
    {}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 244 "proj.y" /* yacc.c:1646  */
    {}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 245 "proj.y" /* yacc.c:1646  */
    {}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 249 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 249 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 250 "proj.y" /* yacc.c:1646  */
    {}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 251 "proj.y" /* yacc.c:1646  */
    {}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 252 "proj.y" /* yacc.c:1646  */
    {}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 258 "proj.y" /* yacc.c:1646  */
    {}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 259 "proj.y" /* yacc.c:1646  */
    {}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 260 "proj.y" /* yacc.c:1646  */
    {}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 264 "proj.y" /* yacc.c:1646  */
    {}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 265 "proj.y" /* yacc.c:1646  */
    {}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 269 "proj.y" /* yacc.c:1646  */
    {}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 270 "proj.y" /* yacc.c:1646  */
    {}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 274 "proj.y" /* yacc.c:1646  */
    {}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 275 "proj.y" /* yacc.c:1646  */
    {}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 279 "proj.y" /* yacc.c:1646  */
    {}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 280 "proj.y" /* yacc.c:1646  */
    {}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 281 "proj.y" /* yacc.c:1646  */
    {}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 286 "proj.y" /* yacc.c:1646  */
    {}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 287 "proj.y" /* yacc.c:1646  */
    {}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 288 "proj.y" /* yacc.c:1646  */
    {}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 289 "proj.y" /* yacc.c:1646  */
    {}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 293 "proj.y" /* yacc.c:1646  */
    {}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 294 "proj.y" /* yacc.c:1646  */
    {}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 298 "proj.y" /* yacc.c:1646  */
    {}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 299 "proj.y" /* yacc.c:1646  */
    {}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 303 "proj.y" /* yacc.c:1646  */
    {}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 304 "proj.y" /* yacc.c:1646  */
    {}
#line 2234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 308 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 308 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2246 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 308 "proj.y" /* yacc.c:1646  */
    { lookup((yyvsp[-4].string), (yyvsp[-5].string), "function");}
#line 2252 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 309 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2258 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 309 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 309 "proj.y" /* yacc.c:1646  */
    {}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 309 "proj.y" /* yacc.c:1646  */
    { lookup((yyvsp[-4].string), (yyvsp[-5].string), "function");}
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 310 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 310 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 310 "proj.y" /* yacc.c:1646  */
    {}
#line 2294 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 311 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 311 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 311 "proj.y" /* yacc.c:1646  */
    {}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2316 "y.tab.c" /* yacc.c:1646  */
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
#line 314 "proj.y" /* yacc.c:1906  */



symbol_table* initialize()
{
	symbol_table *temp = (symbol_table*)malloc(sizeof(symbol_table));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->type = (char*)malloc(sizeof(char)*10);
	temp->symbol = (char*)malloc(sizeof(char)*11);
	temp->value = (char*)malloc(sizeof(char)*10);
	strcpy(temp->value, "0");
	temp->lno = 0;
	temp->lno_used = (int*)malloc(sizeof(int));
	temp->size = 0;
	temp->next = NULL;
	temp->scope = curr_scope;
	return temp;
}

int lookup(char *s, char *type, char *token_type)
{
		check_scope(s,type,token_type);
	if(st == NULL)
	{

		insert(s, type, token_type);
		return 0;
	}
	symbol_table *temp = st;
	while(st!=NULL)
	{
		if(strcmp(st->name, s)==0&&strcmp(st->type,type)==0)
		{
	  	check_scope(s,type,token_type);
			return 0;
		}
		st = st->next;
	}
	st = temp;
//  check_scope(s,type,token_type);
	insert(s, type, token_type);

	return 0;
}

void check_scope(char *s, char *type, char *token_type)
{

	//printf("\nscope error %s= %d", s,scope_error);
  wrong_symbol=(char*)malloc(128*sizeof(char));
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, s)==0&&temp->scope==curr_scope)
		{
			strcpy(wrong_symbol, temp->name);
			scope_error=1;
			printf("\n%*s\n%*s   <--- already declared in current scope \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		temp = temp->next;
	}

}

void insert(char *s, char *type, char* token_type)
{
	symbol_table *new_entry;
	if(st==NULL)
	{
		st = initialize();
		new_entry = st;

	}
	else
	{
		symbol_table *temp = st;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		new_entry = initialize();
		temp->next = new_entry;
	}
	strcpy(new_entry->name, s);
	tempvals *temp = tvhead;
	while(temp!=NULL)
	{
		if(strcmp(new_entry->name, temp->name)==0)
		{
			strcpy(new_entry->value, temp->value);
			deletetempval(temp);
		}
		temp = temp->next;
	}
	strcpy(new_entry->type, type);
	strcpy(new_entry->symbol, token_type);
	if(strcmp(type, "int")==0)
		new_entry->size = 4;
	else if(strcmp(type, "char")==0)
		new_entry->size = 1;
}

void tempval(char *var, char *val)
{
	tempvals *temp = (tempvals*)malloc(sizeof(tempvals));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->value = (char*)malloc(sizeof(char)*10);
	temp->next = NULL;
	strcpy(temp->name, var);
	strcpy(temp->value, val);
	if(tvhead == NULL)
	{
		tvhead = temp;
	}
	else{
		tempvals *t = tvhead;
		while(t->next!=NULL)
		{
			t =t->next;
		}
		t->next = temp;
	}

}

void deletetempval(tempvals *temp)
{
	if(temp == tvhead)
	{
		tempvals *t = temp;
		tvhead = temp->next;
	}
	else
	{
		tempvals *t = tvhead;
		while(t->next != temp)
			t=t->next;
		t->next = t->next->next;
	}

	free(temp->name);
	free(temp->value);
	free(temp);
}
void display()
{
	symbol_table *temp = st;
	printf("Symbol \t\t Name \t\t Type \t\t Scope \t\t Value\n");
	while(temp!=NULL)
	{
		if(strcmp(temp->name, "keyword")==0)
			printf("%s \t %s \t\t %s \t\t %d \t\t %s\n",temp->symbol, temp->name, temp->type, temp->scope, temp->value);
		else
			printf("%s \t %s \t\t %s \t\t %d \t\t %s\n",temp->symbol, temp->name, temp->type, temp->scope, temp->value);

		temp = temp->next;
	}
}


yyerror(s)
char *s;
{
	fflush(stdout);

		printf("\n%*s\n%*s\n", column, "^", column, s);


}

int main()
{
	yyin = fopen("program.c", "r");
	lookup("char", "NIL", "keyword");
	lookup("int", "NIL", "keyword");
	lookup("float", "NIL", "keyword");
	lookup("short", "NIL", "keyword");
	lookup("long", "NIL", "keyword");
	lookup("double", "NIL", "keyword");
	lookup("void", "NIL", "keyword");
	lookup("if", "NIL", "keyword");
	lookup("else", "NIL", "keyword");
	lookup("continue", "NIL", "keyword");
	lookup("break", "NIL", "keyword");
	lookup("return", "NIL", "keyword");
	yyparse();
	fclose(yyin);
	display(st);
}
