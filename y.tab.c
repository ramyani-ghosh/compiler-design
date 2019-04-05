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
#define COUNT 10
int curr_scope = 0;
int insideloop = 0;
int opening_brackets = 0;
int closing_brackets = 0;
int nesting = 0;

typedef struct Node{
	struct Node *left;
	struct Node *right;
	char token[100];
	struct Node *val;
	int level;
}Node;

typedef struct tree_stack{
	Node *node;
	struct tree_stack *next;
}tree_stack;

typedef struct symbol_table
{
	char *name;		//name of the token	(in case of keywords, the name is the "keyword" itself)
	char *symbol;
	char *type;		//type of token (in case of keywords, the type is the name of the keyword)
	char value[30][30]; 	//saving value as a string
	int lno;		//line number where token is declared (default 0)
	int *lno_used;	//line number where token is first used (defult 0)
	int size;		//size of the token
	int var_size;
	int scope;
	int isarray;
	struct symbol_table *next;	//symbol table is LL
}symbol_table;

typedef struct tempvals
{
	char *name;
	char value[30][30];
	int isarray;
	int size;
	struct tempvals *next;
}tempvals;

typedef struct scope_stack
{
	int scope;
	struct scope_stack *next;
}scope_stack;

typedef struct quad
{
		char op;
		char arg1;
		char arg2;
		char res;
}quad;


int get_levels(Node *root, int level);
void push_scope(int);
void pop_scope();
int peep_scope();
void create_node(char *token, int leaf);
void push_tree(Node *newnode);
Node* pop_tree();
Node* pop_tree_2();
void modify_top(char *s);
int lookup(char *s, char *type, char*);
symbol_table* initialize();
void insert(char *s, char *type, char*);
void deletetempval(tempvals *temp);
void tempval(char *var, char *val, int, int);
void check_scope(char *s, char *type, char *token_type);
void addval(char *var, char *val, int scope);
char * get_val(char *var, int scope);
void add_lines_used(char *s);
void exists(char *s);
void set_arr();
void unset_arr();
void printtree(Node *tree);
void displaytree(Node *tree);
int getmaxlevel(Node *root);
void printGivenLevel(Node* root, int level, int h);
void printICG(quad *q);

extern char yytext[];
extern int line_number;
extern int column;
extern FILE *yyin;

//Global variables
tree_stack *tree_top = NULL;
scope_stack *scope_top = NULL;
tempvals *tvhead =NULL;
symbol_table *st = NULL;
int scope_error= 0;
char *wrong_symbol;



#line 172 "y.tab.c" /* yacc.c:339  */

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
    CHAR_CONSTANT = 260,
    INT_CONSTANT = 261,
    FLOAT_CONSTANT = 262,
    STRING_LITERAL = 263,
    SIZEOF = 264,
    INC_OP = 265,
    DEC_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    H = 271,
    AND_OP = 272,
    OR_OP = 273,
    MUL_ASSIGN = 274,
    DIV_ASSIGN = 275,
    MOD_ASSIGN = 276,
    ADD_ASSIGN = 277,
    SUB_ASSIGN = 278,
    CHAR = 279,
    SHORT = 280,
    INT = 281,
    LONG = 282,
    FLOAT = 283,
    DOUBLE = 284,
    VOID = 285,
    IF = 286,
    ELSE = 287,
    WHILE = 288,
    DO = 289,
    CONTINUE = 290,
    BREAK = 291,
    RETURN = 292,
    HASH = 293,
    INCLUDE = 294,
    LIBRARY = 295
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define CHAR_CONSTANT 260
#define INT_CONSTANT 261
#define FLOAT_CONSTANT 262
#define STRING_LITERAL 263
#define SIZEOF 264
#define INC_OP 265
#define DEC_OP 266
#define LE_OP 267
#define GE_OP 268
#define EQ_OP 269
#define NE_OP 270
#define H 271
#define AND_OP 272
#define OR_OP 273
#define MUL_ASSIGN 274
#define DIV_ASSIGN 275
#define MOD_ASSIGN 276
#define ADD_ASSIGN 277
#define SUB_ASSIGN 278
#define CHAR 279
#define SHORT 280
#define INT 281
#define LONG 282
#define FLOAT 283
#define DOUBLE 284
#define VOID 285
#define IF 286
#define ELSE 287
#define WHILE 288
#define DO 289
#define CONTINUE 290
#define BREAK 291
#define RETURN 292
#define HASH 293
#define INCLUDE 294
#define LIBRARY 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 108 "proj.y" /* yacc.c:355  */

	int ival;
	char string[128];

#line 297 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 314 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   486

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,     2,     2,    54,    47,     2,
      41,    42,    48,    49,    46,    50,    45,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    62,
      55,    59,    56,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    61,    51,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   131,   132,   133,   134,   135,   136,   140,
     141,   153,   154,   155,   156,   177,   201,   202,   206,   207,
     228,   248,   249,   250,   254,   255,   256,   257,   258,   259,
     263,   264,   290,   316,   345,   346,   372,   401,   402,   428,
     453,   478,   506,   507,   532,   560,   561,   589,   590,   618,
     619,   623,   624,   631,   632,   633,   634,   635,   636,   641,
     642,   649,   650,   654,   655,   659,   662,   667,   668,   682,
     692,   693,   703,   704,   705,   706,   707,   708,   713,   713,
     717,   718,   722,   735,   736,   744,   745,   768,   769,   770,
     771,   772,   773,   774,   778,   780,   789,   790,   791,   795,
     796,   800,   801,   805,   806,   810,   810,   811,   811,   816,
     817,   824,   825,   831,   832,   836,   837,   841,   842,   846,
     846,   847,   848
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "CHAR_CONSTANT", "INT_CONSTANT", "FLOAT_CONSTANT", "STRING_LITERAL",
  "SIZEOF", "INC_OP", "DEC_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "H",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "CHAR", "SHORT", "INT", "LONG", "FLOAT",
  "DOUBLE", "VOID", "IF", "ELSE", "WHILE", "DO", "CONTINUE", "BREAK",
  "RETURN", "HASH", "INCLUDE", "LIBRARY", "'('", "')'", "'['", "']'",
  "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'?'", "':'", "'='", "'{'", "'}'", "';'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "relational_expression", "equality_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "parameter_list", "parameter_declaration",
  "identifier_list", "initializer", "initializer_list", "statement",
  "compound_statement", "$@1", "compound_statement_types", "declaration",
  "init_declarator_list", "init_declarator", "type_specifier",
  "declarator", "statement_list", "expression_statement",
  "selection_statement", "iteration_statement", "$@2", "$@3",
  "jump_statement", "hashinclude", "translation_unit",
  "external_declaration", "function_definition", "$@4", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    63,    58,    61,
     123,   125,    59
};
# endif

#define YYPACT_NINF -61

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-61)))

#define YYTABLE_NINF -79

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     423,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -61,   -19,
     -61,    26,   135,    31,   192,   -61,   -61,   -14,   -35,   -61,
      82,   108,    49,   -61,     0,   -61,    26,   -61,   -61,    60,
      26,   -61,   298,   -61,   -61,   -61,   -27,   -61,    19,    26,
      40,   163,   -61,   -61,   -25,    63,   -61,   -61,   -61,   -61,
     -61,   -61,   -61,   384,   434,   434,   434,   -61,   -61,   -61,
     -61,   -61,   -61,   298,   -61,    -5,    24,   434,     3,    78,
      -3,   137,    75,   -15,   -61,   -61,   -61,   -61,   -61,   211,
     -61,   111,   104,   -61,    83,   115,   -61,    77,    87,    69,
     -61,   -61,   -61,   -34,   -61,   -61,   -61,   223,   -61,   -61,
     -61,   -61,   141,   356,   -61,   -61,   -61,    20,   -61,   -39,
     -61,   -61,   368,   434,   172,   -61,   -61,   -61,   -61,   -61,
     -61,   434,   -61,   434,   434,   434,   434,   434,   434,   434,
     434,   434,   434,   434,   434,   434,   434,   -61,   -61,   434,
     434,   -61,   -61,   -61,   -61,     2,   434,   -61,   -61,   -61,
     125,   140,   -61,   283,   -61,   -61,    45,   -61,   102,   -61,
     -61,   -61,   -61,   -61,   -61,     3,     3,    78,    78,    78,
      78,    -3,    -3,   137,    75,   -32,    67,    84,   150,   -61,
     -61,   423,   -61,   -61,   -61,   -61,   434,   -61,   434,   -61,
     -61,   144,   -61,   -61,   -61,   169,   -61,   434,   -61,   -61,
      98,   -61,   143,   -61
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    94,    88,    89,    90,    91,    92,    93,    87,     0,
     118,     0,    78,     0,   114,   115,   117,     0,     0,    83,
      85,     0,     0,   122,     0,    78,     0,     1,   116,     0,
       0,    82,     0,   119,    65,    98,     0,    61,     0,    64,
       0,    78,    79,   121,    85,     0,    84,     2,     5,     3,
       6,     4,     7,     0,     0,     0,     0,    24,    25,    26,
      27,    28,    29,     0,     9,    18,    30,     0,    34,    37,
      42,    45,    47,    49,    51,    67,    86,   120,    96,     0,
      97,     0,    63,    95,     0,     0,   107,     0,     0,     0,
      80,   101,    59,     0,    99,    72,    77,    78,    73,    74,
      75,    76,     0,     0,    22,    19,    20,     0,    70,     0,
      14,    15,     0,     0,     0,    54,    55,    56,    57,    58,
      53,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    62,    66,     0,
       0,    78,   109,   110,   111,     0,     0,   102,    81,   100,
       0,     0,     8,     0,    68,    11,     0,    16,     0,    13,
      52,    31,    32,    33,    30,    35,    36,    40,    41,    38,
      39,    43,    44,    46,    48,     0,     0,     0,     0,   112,
      60,     0,    23,    69,    71,    12,     0,    10,     0,    78,
     105,     0,   113,    17,    50,   103,    78,     0,    78,   106,
       0,   104,     0,   108
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -61,   -61,   -61,   -61,   -30,   -61,    27,   -60,    47,    68,
      71,   -61,    15,   -31,   -61,   -54,   -61,   128,   -61,   -46,
     -61,   112,   -12,   -61,   -61,    -8,   -61,   178,     9,    28,
     -61,   -61,   -61,   -61,   -61,   -61,   -61,    42,   -61,   228,
     -61,   -61
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    64,    65,   156,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    92,   121,    93,    36,    37,    38,    76,
     109,    94,    95,    24,    42,    10,    18,    19,    11,    12,
      97,    98,    99,   100,   196,   141,   101,    13,    14,    15,
      16,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    75,   107,   135,    25,   110,   111,   153,    33,   128,
     129,    30,   146,    43,   146,    78,    21,   108,    22,    79,
      17,    26,   154,   104,   105,   106,   188,    31,   147,     1,
      39,    27,    75,    96,    32,   145,   112,   122,   113,    20,
     114,    29,   136,   115,   116,   117,   118,   119,   146,   107,
      26,   123,   130,   131,    44,    40,   124,   125,    44,   158,
      41,    80,   152,    45,   179,    81,   146,    82,   167,   168,
     169,   170,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   157,   175,   120,    83,   176,   177,   185,    39,    96,
     160,   186,   134,   161,   162,   163,   164,   164,   164,   164,
     164,   164,   164,   164,   164,   164,    26,   184,   102,   189,
      56,    34,   151,   146,   138,   180,    57,    58,    59,    60,
      61,    62,    75,    21,   139,    22,   190,   126,   127,   178,
     146,   144,     2,     3,     4,     5,     6,     7,     8,   142,
     202,    32,   -78,   200,   146,    21,   187,    22,   146,   143,
      35,   132,   133,   165,   166,   193,   140,   150,   164,     2,
       3,     4,     5,     6,     7,     8,    47,    48,    49,    50,
      51,    52,    53,    54,    55,   159,    21,   195,    22,   171,
     172,   181,   182,   191,   199,   197,   201,     2,     3,     4,
       5,     6,     7,     8,    84,     1,    85,    86,    87,    88,
      89,   198,   173,   194,    56,   203,   174,   137,    46,   149,
      57,    58,    59,    60,    61,    62,     2,     3,     4,     5,
       6,     7,     8,   192,    90,    91,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     2,     3,     4,     5,     6,
       7,     8,    28,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,    84,     0,    85,    86,    87,    88,
      89,     0,     0,     0,    56,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,   148,    91,    47,    48,    49,    50,
      51,    52,    53,    54,    55,     0,     0,     0,     0,     0,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    56,     0,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,     0,     0,     0,    56,
       0,     0,     0,    63,   183,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    63,    47,
      48,    49,    50,    51,    52,    53,    54,    55,     0,     0,
       0,    47,    48,    49,    50,    51,    52,    53,    54,    55,
       2,     3,     4,     5,     6,     7,     8,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,    56,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    56,
     155,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,     0,     0,     0,     0,   103,     1,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    47,    48,    49,
      50,    51,    52,    53,    54,    55,     0,     2,     3,     4,
       5,     6,     7,     8,     0,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62
};

static const yytype_int16 yycheck[] =
{
      12,    32,    56,    18,    12,    10,    11,    46,    20,    12,
      13,    46,    46,    25,    46,    42,    41,    63,    43,    46,
      39,    12,    61,    53,    54,    55,    58,    62,    62,     3,
      21,     0,    63,    41,    59,    89,    41,    67,    43,    11,
      45,    55,    57,    19,    20,    21,    22,    23,    46,   103,
      41,    48,    55,    56,    26,     6,    53,    54,    30,   113,
      60,    42,    42,     3,    62,    46,    46,    39,   128,   129,
     130,   131,     3,     4,     5,     6,     7,     8,     9,    10,
      11,   112,   136,    59,    44,   139,   140,    42,    79,    97,
     121,    46,    17,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    97,   153,    45,    42,
      41,     3,   103,    46,     3,   146,    47,    48,    49,    50,
      51,    52,   153,    41,    41,    43,    42,    49,    50,   141,
      46,    62,    24,    25,    26,    27,    28,    29,    30,    62,
      42,    59,    60,   197,    46,    41,    44,    43,    46,    62,
      42,    14,    15,   126,   127,   186,    41,    16,   188,    24,
      25,    26,    27,    28,    29,    30,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     3,    41,   189,    43,   132,
     133,    56,    42,    33,   196,    41,   198,    24,    25,    26,
      27,    28,    29,    30,    31,     3,    33,    34,    35,    36,
      37,    32,   134,   188,    41,    62,   135,    79,    30,    97,
      47,    48,    49,    50,    51,    52,    24,    25,    26,    27,
      28,    29,    30,   181,    61,    62,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    24,    25,    26,    27,    28,
      29,    30,    14,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      47,    48,    49,    50,    51,    52,    -1,    -1,    -1,    41,
      -1,    -1,    -1,    60,    61,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      24,    25,    26,    27,    28,    29,    30,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    47,    48,    49,    50,    51,    52,    41,
      42,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    41,     3,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    48,    49,    50,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    24,    25,    26,    27,    28,    29,    30,    38,
      88,    91,    92,   100,   101,   102,   103,    39,    89,    90,
      92,    41,    43,    85,    86,    88,    91,     0,   102,    55,
      46,    62,    59,    85,     3,    42,    79,    80,    81,    91,
       6,    60,    87,    85,    92,     3,    90,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    41,    47,    48,    49,
      50,    51,    52,    60,    64,    65,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    82,   104,    42,    46,
      42,    46,    92,    44,    31,    33,    34,    35,    36,    37,
      61,    62,    76,    78,    84,    85,    88,    93,    94,    95,
      96,    99,    45,    41,    67,    67,    67,    78,    82,    83,
      10,    11,    41,    43,    45,    19,    20,    21,    22,    23,
      59,    77,    67,    48,    53,    54,    49,    50,    12,    13,
      55,    56,    14,    15,    17,    18,    57,    80,     3,    41,
      41,    98,    62,    62,    62,    78,    46,    62,    61,    84,
      16,    91,    42,    46,    61,    42,    66,    76,    78,     3,
      76,    67,    67,    67,    67,    69,    69,    70,    70,    70,
      70,    71,    71,    72,    73,    78,    78,    78,    85,    62,
      76,    56,    42,    61,    82,    42,    46,    44,    58,    42,
      42,    33,   100,    76,    75,    85,    97,    41,    32,    85,
      78,    85,    42,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    68,    68,    68,    68,    68,    68,
      69,    69,    69,    69,    70,    70,    70,    71,    71,    71,
      71,    71,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    77,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    82,
      83,    83,    84,    84,    84,    84,    84,    84,    86,    85,
      87,    87,    88,    89,    89,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    92,    92,    92,    92,    92,    93,
      93,    94,    94,    95,    95,    97,    96,    98,    96,    99,
      99,    99,    99,   100,   100,   101,   101,   102,   102,   104,
     103,   103,   103
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     3,     4,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     2,     1,     1,     3,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     0,     2,
       2,     3,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     3,     1,
       2,     1,     2,     5,     7,     0,     6,     0,     8,     2,
       2,     2,     3,     8,     1,     1,     2,     1,     1,     0,
       4,     3,     2
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
#line 130 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); create_node((yyvsp[0].string), 1);exists((yyvsp[0].string));}
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 131 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); create_node((yyvsp[0].string), 1);}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 132 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); create_node((yyvsp[0].string), 1);}
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 133 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); create_node((yyvsp[0].string), 1);}
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 134 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); create_node((yyvsp[0].string), 1);}
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 135 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); create_node((yyvsp[0].string), 1);}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 136 "proj.y" /* yacc.c:1646  */
    {}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 140 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 141 "proj.y" /* yacc.c:1646  */
    {
												pop_tree();
												pop_tree();
												char s[30];
												strcpy(s, (yyvsp[-3].string));
												strcat(s, "[");
												strcat(s, (yyvsp[-1].string));
												strcat(s, "]");
												create_node(s, 1);
												strcpy((yyval.string), s);

											}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 153 "proj.y" /* yacc.c:1646  */
    {}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 154 "proj.y" /* yacc.c:1646  */
    {}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 155 "proj.y" /* yacc.c:1646  */
    { exists((yyvsp[0].string));}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 156 "proj.y" /* yacc.c:1646  */
    {

		int d1 = (yyvsp[-1].string)[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val((yyvsp[-1].string), curr_scope)) + 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval((yyvsp[-1].string), str, curr_scope);
		}

		create_node("1",1);
		create_node("+", 0);

	}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 177 "proj.y" /* yacc.c:1646  */
    {

		int d1 = (yyvsp[-1].string)[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val((yyvsp[-1].string), curr_scope)) - 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval((yyvsp[-1].string), str, curr_scope);
		}

		create_node("1",1);
		create_node("-", 0);

	}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 201 "proj.y" /* yacc.c:1646  */
    {}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "proj.y" /* yacc.c:1646  */
    {}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 206 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 207 "proj.y" /* yacc.c:1646  */
    {

		int d1 = (yyvsp[0].string)[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val((yyvsp[0].string), curr_scope)) + 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval((yyvsp[0].string), str, curr_scope);
		}

		create_node("1",1);
		create_node("+", 0);

	}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 228 "proj.y" /* yacc.c:1646  */
    {

		int d1 = (yyvsp[0].string)[0] - '0';
		if(d1>=0 && d1 <= 9)
		{
			printf("\n%*s\n%*s   <--- invalid operation \n", column, "^", column, wrong_symbol);
			exit(0);
		}
		else
		{
			int s = atoi(get_val((yyvsp[0].string), curr_scope)) - 1;
			char str[10];
			// printf("%d", s);
			snprintf(str, 10, "%d", s);
			addval((yyvsp[0].string), str, curr_scope);
		}
		create_node("1",1);
		create_node("-", 0);

	}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 248 "proj.y" /* yacc.c:1646  */
    {}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 249 "proj.y" /* yacc.c:1646  */
    {}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 250 "proj.y" /* yacc.c:1646  */
    {}
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 254 "proj.y" /* yacc.c:1646  */
    {}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 255 "proj.y" /* yacc.c:1646  */
    {}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 256 "proj.y" /* yacc.c:1646  */
    {}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 257 "proj.y" /* yacc.c:1646  */
    {}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 258 "proj.y" /* yacc.c:1646  */
    {}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 259 "proj.y" /* yacc.c:1646  */
    {}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 263 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 264 "proj.y" /* yacc.c:1646  */
    {
															create_node("*", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) * atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) * atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) * atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) * atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}

														}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 290 "proj.y" /* yacc.c:1646  */
    {
															create_node("/", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) / atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) / atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) / atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) / atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}

														}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 316 "proj.y" /* yacc.c:1646  */
    {
															create_node("%", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) % atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) % atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) % atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) % atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}

														}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 345 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 346 "proj.y" /* yacc.c:1646  */
    {
															create_node("+", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) + atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) + atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) + atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) + atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}

														}
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 372 "proj.y" /* yacc.c:1646  */
    {
															create_node("-", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) - atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) - atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) - atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) - atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}

														}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 401 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 402 "proj.y" /* yacc.c:1646  */
    {

															create_node("<", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) < atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) < atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) < atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) < atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
														}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 428 "proj.y" /* yacc.c:1646  */
    {
															create_node(">", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) > atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) > atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) > atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) > atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
														}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 453 "proj.y" /* yacc.c:1646  */
    {
															create_node("<=", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) <= atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) <= atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) <= atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) <= atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
														}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 478 "proj.y" /* yacc.c:1646  */
    {
															create_node(">=", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) >= atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) >= atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) >= atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) >= atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
														}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 506 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 507 "proj.y" /* yacc.c:1646  */
    {
															create_node("==", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) == atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) == atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) == atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) == atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
														}
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 532 "proj.y" /* yacc.c:1646  */
    {
															create_node("!=", 0);
															int d1 = (yyvsp[-2].string)[0] - '0';
															int d2 = (yyvsp[0].string)[0] - '0';
															if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
															{
																int s = atoi((yyvsp[-2].string)) != atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d1>=0 && d1<=9)
															{
																int s = atoi((yyvsp[-2].string)) != atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
															else if(d2>=0 && d2<=9)
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) != atoi((yyvsp[0].string));
																snprintf((yyval.string), 10, "%d", s);
															}
															else
															{
																int s = atoi(get_val((yyvsp[-2].string), curr_scope)) != atoi(get_val((yyvsp[0].string), curr_scope));
																snprintf((yyval.string), 10, "%d", s);
															}
														}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 560 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 561 "proj.y" /* yacc.c:1646  */
    {
																create_node("&&", 0);
																int d1 = (yyvsp[-2].string)[0] - '0';
																int d2 = (yyvsp[0].string)[0] - '0';
																if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
																{
																	int s = atoi((yyvsp[-2].string)) && atoi((yyvsp[0].string));
																	snprintf((yyval.string), 10, "%d", s);
																}
																else if(d1>=0 && d1<=9)
																{
																	int s = atoi((yyvsp[-2].string)) && atoi(get_val((yyvsp[0].string), curr_scope));
																	snprintf((yyval.string), 10, "%d", s);
																}
																else if(d2>=0 && d2<=9)
																{
																	int s = atoi(get_val((yyvsp[-2].string), curr_scope)) && atoi((yyvsp[0].string));
																	snprintf((yyval.string), 10, "%d", s);
																}
																else
																{
																	int s = atoi(get_val((yyvsp[-2].string), curr_scope)) && atoi(get_val((yyvsp[0].string), curr_scope));
																	snprintf((yyval.string), 10, "%d", s);
																}
															}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 589 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 590 "proj.y" /* yacc.c:1646  */
    {
																create_node("||", 0);
																int d1 = (yyvsp[-2].string)[0] - '0';
																int d2 = (yyvsp[0].string)[0] - '0';
																if(d1>=0 && d1 <= 9 && d2>=0 && d2<=9)
																{
																	int s = atoi((yyvsp[-2].string)) || atoi((yyvsp[0].string));
																	snprintf((yyval.string), 10, "%d", s);
																}
																else if(d1>=0 && d1<=9)
																{
																	int s = atoi((yyvsp[-2].string)) || atoi(get_val((yyvsp[0].string), curr_scope));
																	snprintf((yyval.string), 10, "%d", s);
																}
																else if(d2>=0 && d2<=9)
																{
																	int s = atoi(get_val((yyvsp[-2].string), curr_scope)) || atoi((yyvsp[0].string));
																	snprintf((yyval.string), 10, "%d", s);
																}
																else
																{
																	int s = atoi(get_val((yyvsp[-2].string), curr_scope)) || atoi(get_val((yyvsp[0].string), curr_scope));
																	snprintf((yyval.string), 10, "%d", s);
																}
															}
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 618 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 619 "proj.y" /* yacc.c:1646  */
    {}
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 623 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 624 "proj.y" /* yacc.c:1646  */
    {
																		addval((yyvsp[-2].string), (yyvsp[0].string), curr_scope);
																		create_node("=", 0);
																	}
#line 2320 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 631 "proj.y" /* yacc.c:1646  */
    {}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 632 "proj.y" /* yacc.c:1646  */
    {}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 633 "proj.y" /* yacc.c:1646  */
    {}
#line 2338 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 634 "proj.y" /* yacc.c:1646  */
    {}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 635 "proj.y" /* yacc.c:1646  */
    {}
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 636 "proj.y" /* yacc.c:1646  */
    {}
#line 2356 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 641 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 642 "proj.y" /* yacc.c:1646  */
    {}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 649 "proj.y" /* yacc.c:1646  */
    {}
#line 2374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 650 "proj.y" /* yacc.c:1646  */
    {}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 654 "proj.y" /* yacc.c:1646  */
    {}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 655 "proj.y" /* yacc.c:1646  */
    {}
#line 2392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 659 "proj.y" /* yacc.c:1646  */
    {
		exists((yyvsp[0].string));
	}
#line 2400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 662 "proj.y" /* yacc.c:1646  */
    {	exists((yyvsp[0].string)); }
#line 2406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 667 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 668 "proj.y" /* yacc.c:1646  */
    {
									char s[20] = "{";
									strcat(s, (yyvsp[-1].string));
									strcat(s, "}");
									strcpy((yyval.string), s);
									for(int i=0; s[i]!='}'; i++)
									{
										Node *n;
										if(s[i]==',')
											n=pop_tree();
									}
									pop_tree();
									create_node(s, 1);
								}
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 682 "proj.y" /* yacc.c:1646  */
    {
										char s[20] = "{";
										strcat(s, (yyvsp[-2].string));
										strcat(s, ",}");
										strcpy((yyval.string), s);
										create_node(s, 1);
									}
#line 2443 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 692 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string));}
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 693 "proj.y" /* yacc.c:1646  */
    {
											char s[100] = "";
											strcat(s, (yyvsp[-2].string));
										 	strcat(s, ", ");
											strcat(s, (yyvsp[0].string));
											strcpy((yyval.string), s);
										}
#line 2461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 704 "proj.y" /* yacc.c:1646  */
    {}
#line 2467 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 705 "proj.y" /* yacc.c:1646  */
    {}
#line 2473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 706 "proj.y" /* yacc.c:1646  */
    {}
#line 2479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 707 "proj.y" /* yacc.c:1646  */
    {}
#line 2485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 708 "proj.y" /* yacc.c:1646  */
    {}
#line 2491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 713 "proj.y" /* yacc.c:1646  */
    {opening_brackets++; curr_scope = opening_brackets; push_scope(curr_scope);}
#line 2497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 713 "proj.y" /* yacc.c:1646  */
    { pop_scope(); curr_scope =  peep_scope(); }
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 722 "proj.y" /* yacc.c:1646  */
    {
								// printf("%s %s", $1, $2);
								char *p = strtok((yyvsp[-1].string), ",");
								while(p!=NULL)
								{
									lookup(p, (yyvsp[-2].string), "identifier");
									p=strtok(NULL, ",");
								}

							}
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 735 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 736 "proj.y" /* yacc.c:1646  */
    {
														strcpy((yyval.string),(yyvsp[0].string));
														strcat((yyval.string), ",");
														strcat((yyval.string), (yyvsp[-2].string));
													}
#line 2534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 744 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 745 "proj.y" /* yacc.c:1646  */
    {
										create_node("=", 0);
										char val[20];
										strcpy(val, (yyvsp[0].string));
										if((0<= (yyvsp[0].string)[0]-'0' && 9>=(yyvsp[0].string)[0]-'0') || (yyvsp[0].string)[0]=='\'')
										{
											tempval((yyvsp[-2].string), val, 0, 1);
											strcpy((yyval.string),(yyvsp[-2].string));
										}
										else if((yyvsp[0].string)[0]=='{')
										{
											tempval((yyvsp[-2].string), (yyvsp[0].string), 1, 0);
										}
										else
										{
											strcpy(val,get_val((yyvsp[0].string), curr_scope));
											tempval((yyvsp[-2].string), val, 0, 1);
											strcpy((yyval.string),(yyvsp[-2].string));
										}
									}
#line 2565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 768 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 769 "proj.y" /* yacc.c:1646  */
    {}
#line 2577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 770 "proj.y" /* yacc.c:1646  */
    {}
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 771 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 772 "proj.y" /* yacc.c:1646  */
    {}
#line 2595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 773 "proj.y" /* yacc.c:1646  */
    {}
#line 2601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 774 "proj.y" /* yacc.c:1646  */
    {}
#line 2607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 778 "proj.y" /* yacc.c:1646  */
    { create_node((yyvsp[0].string), 1); strcpy((yyval.string),(yyvsp[0].string));}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 780 "proj.y" /* yacc.c:1646  */
    {
										Node * n= pop_tree();
										char s[30] = "";
										strcat(s, (yyvsp[-3].string));
										strcat(s,"[");
										strcat(s, (yyvsp[-1].string));
										strcat(s, "]");
										create_node(s, 1);
										tempval((yyvsp[-3].string), "{0}", 1, atoi((yyvsp[-1].string))); strcpy((yyval.string), (yyvsp[-3].string)); }
#line 2627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 789 "proj.y" /* yacc.c:1646  */
    {}
#line 2633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 790 "proj.y" /* yacc.c:1646  */
    {}
#line 2639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 791 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string), (yyvsp[-2].string)); }
#line 2645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 795 "proj.y" /* yacc.c:1646  */
    {}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 796 "proj.y" /* yacc.c:1646  */
    { create_node("stmt", 0);}
#line 2657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 800 "proj.y" /* yacc.c:1646  */
    {}
#line 2663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 801 "proj.y" /* yacc.c:1646  */
    {}
#line 2669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 805 "proj.y" /* yacc.c:1646  */
    { create_node("if", 0);}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 806 "proj.y" /* yacc.c:1646  */
    {create_node("else", 0); create_node("if", 0);}
#line 2681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 810 "proj.y" /* yacc.c:1646  */
    {insideloop = 1; }
#line 2687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 810 "proj.y" /* yacc.c:1646  */
    { insideloop = 0; create_node("while", 0);}
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 811 "proj.y" /* yacc.c:1646  */
    {insideloop = 1; }
#line 2699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 811 "proj.y" /* yacc.c:1646  */
    {insideloop = 0; create_node("do-while", 0);}
#line 2705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 816 "proj.y" /* yacc.c:1646  */
    {}
#line 2711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 817 "proj.y" /* yacc.c:1646  */
    {
						if(!insideloop)
						{
							printf("\n%*s\n%*s   <--- break statement not within loop \n", column, "^", column, wrong_symbol);
							exit(0);
						}
					}
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 824 "proj.y" /* yacc.c:1646  */
    { create_node("return",1);}
#line 2729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 825 "proj.y" /* yacc.c:1646  */
    { char s[20] = "return ";
							  strcat(s, (yyvsp[-1].string));
							  modify_top(s);}
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 831 "proj.y" /* yacc.c:1646  */
    {}
#line 2743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 832 "proj.y" /* yacc.c:1646  */
    {}
#line 2749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 836 "proj.y" /* yacc.c:1646  */
    {}
#line 2755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 837 "proj.y" /* yacc.c:1646  */
    {}
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 841 "proj.y" /* yacc.c:1646  */
    {}
#line 2767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 842 "proj.y" /* yacc.c:1646  */
    {}
#line 2773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 846 "proj.y" /* yacc.c:1646  */
    {}
#line 2779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 846 "proj.y" /* yacc.c:1646  */
    { lookup((yyvsp[-2].string), (yyvsp[-3].string), "function"); }
#line 2785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 847 "proj.y" /* yacc.c:1646  */
    {}
#line 2791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 848 "proj.y" /* yacc.c:1646  */
    {}
#line 2797 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2801 "y.tab.c" /* yacc.c:1646  */
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
#line 851 "proj.y" /* yacc.c:1906  */


int scopeinstack(int scope)
{
	scope_stack *temp = scope_top;
	while(temp!=NULL)
	{
		if(temp->scope == scope)
			return 1;
		temp = temp->next;
	}
	return 0;
}
void push_scope(int scope)
{
	scope_stack *temp= (scope_stack*)malloc(sizeof(scope_stack));
	temp->scope = scope;
	temp->next = scope_top;
	scope_top = temp;
}

void pop_scope()
{
	scope_stack *temp = scope_top;
	scope_top = scope_top->next;
	free(temp);
}

int peep_scope()
{
	return scope_top->scope;
}

void create_node(char *token, int leaf)
{
	Node *l;
	Node *r;
	if(leaf==0)
	{
		r = pop_tree();
		l = pop_tree();
	}
	else if(leaf ==1)
	{
		l = NULL;
		r = NULL;
	}
	else
	{
		l = pop_tree();
		r = NULL;
	}
	Node *newnode = (Node*)malloc(sizeof(Node));
	strcpy(newnode->token, token);
	newnode->left = l;
	newnode->right = r;
	push_tree(newnode);
}
void push_tree(Node *newnode)
{
	tree_stack *temp= (tree_stack*)malloc(sizeof(tree_stack));
	temp->node = newnode;
	temp->next = tree_top;
	tree_top = temp;
}
void modify_top(char *s)
{
	strcpy(tree_top->node->token, s);
}

Node* pop_tree()
{
	if(tree_top==NULL)
		return NULL;
	tree_stack *temp = tree_top;
	tree_top = tree_top->next;
	Node *retnode = temp->node;
	free(temp);
	return retnode;
}
Node* pop_tree_2()
{
	if(tree_top==NULL)
		return NULL;
	tree_stack *temp = tree_top->next;
	tree_top->next = tree_top->next->next;
	Node *retnode = temp->node;
	free(temp);
	return retnode;
}
void printtree(Node *tree)
{
	int i;
	if (tree->left || tree->right)
 		printf("(");
	printf(" %s ", tree->token);
	if (tree->left)
		printtree(tree->left);
	if (tree->right)
		printtree(tree->right);
	if (tree->left || tree->right)
		printf(")");
}
int get_levels(Node *root, int level)
{
	root->level = level;
	if(root->left == NULL && root->right == NULL)
	{
		return level;
	}
	int m, m1, m2;
	if(root->left == NULL)
	{
		m = get_levels(root->right, level+1);
	}
	else if(root->right == NULL)
	{
		m = get_levels(root->left, level+1);
	}
	else
	{
		m1 = get_levels(root->left, level+1);
		m2 = get_levels(root->right, level+1);
		if(m1>m2)
			m = m1;
		else
			m=m2;
	}
	return m;
}

int getmaxlevel(Node *root)
{
	return get_levels(root, 1);
}
void displaytree(Node* root)
{
    int h = getmaxlevel(root)+2;
	printf("\n max lev= %d\n",h);
    int i;

		printf("\n\n ͟A͟b͟s͟t͟r͟a͟c͟t͟ ͟S͟y͟n͟t͟a͟x͟ ͟T͟r͟e͟e͟ \n\n");
    for (i=1; i<=h; i++)
    {
			  printf("");
				for(int j=0;j<=h+1-i;j++)
				{
					printf("     ");
				}
        printGivenLevel(root, i,h);
        printf("\n\n\n");

    }
}

void printICG(quad *q)
{
	printf("\n\n ͟I͟n͟t͟e͟r͟m͟e͟d͟i͟a͟t͟e͟ ͟C͟o͟d͟e͟\n\n");
	printf("\t  op");
	printf("\t    arg1");
	printf("\t    arg2");
	printf("\t    result");
	printf("\n\t ____________________________________________________\n\n");
}


void printGivenLevel(Node* root, int level, int h)
{
    if (root == NULL)
        return;
    if (level == 1)
		{
			for(int j=0;j<h-4-level;j++)
			{
					printf(" ");
			}
	        printf("%s", root->token);
		}
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1,h);
				for(int j=0;j<h-4-level;j++)
				{
						printf(" ");
				}
        printGivenLevel(root->right, level-1,h);
    }
}

symbol_table* initialize()
{
	symbol_table *temp = (symbol_table*)malloc(sizeof(symbol_table));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->type = (char*)malloc(sizeof(char)*10);
	temp->symbol = (char*)malloc(sizeof(char)*11);
	strcpy(temp->value[0], "0");
	temp->lno = 0;
	temp->lno_used = (int*)malloc(sizeof(int)*100);
	temp->size = 0;
	temp->var_size = 0;
	temp->next = NULL;
	temp->scope = curr_scope;
	temp->isarray = 0;
	return temp;
}


void addval(char *var, char *val, int scope)
{
	symbol_table *temp = st;
	if((0<= val[0]-'0' && 9>=val[0]-'0') || val[0]=='\'')
	{
		int k;
	}
	else
	{
		strcpy(val,get_val(val, curr_scope));
	}
	while(temp!=NULL)
	{
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope == scope && temp->isarray!=1)
			{
				strcpy(temp->value[0], val);
			}
			else if(temp->isarray)
			{
				// if(val[0]!=)
				printf("\n%*s\n%*s   <--- Assignment to expression with array type \n", column, "^", column, wrong_symbol);
				exit(0);
			}
		}
		else if(temp->name[0]==var[0])
		{
			int i=0;
			int flag = 0;
			for(i=0; temp->name[i]!= '\0';i++)
			{
				if(var[i]!=temp->name[i])
				{
					flag = 1;
					break;
				}
			}
			//val is the value to be stored
			//temp->name and var is the name of the variable
			if(flag)
				break;
			i = i+1;
			char size[10]="";
			int pos = i;
			while(var[i]!=']')
			{
				size[i-pos] = var[i];
				i++;
			}
			int index = atoi(size);
			strcpy(temp->value[index], val);
		}
		temp=temp->next;
	}
	add_lines_used(var);
}

char * get_val(char *var, int scope)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		// printf("%s ", temp->name, var);
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope <= scope)
			{
				return temp->value[0];
			}
		}
		else if(temp->name[0]==var[0])
		{
			int i=0;
			int flag = 0;
			for(i=0; temp->name[i]!= '\0';i++)
			{
				if(var[i]!=temp->name[i])
				{
					flag = 1;
					break;
				}
			}
			if(flag)
			{
				temp=temp->next;
				continue;
			}
			i = i+1;
			char size[10]="";
			int pos = i;
			while(var[i]!=']')
			{
				size[i-pos] = var[i];
				i++;
			}
			int index = atoi(size);
			return temp->value[index];
		}
		temp=temp->next;
	}
	return "0";
}

void add_lines_used(char *s)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, s)==0)
		{
			if(temp->scope == curr_scope)
			{
				temp->size +=1;
				temp->lno_used[temp->size-1] = line_number;
			}
		}
		temp=temp->next;
	}
}

void exists(char *s)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, s)==0)
		{
			// if(temp->scope <= curr_scope)
			if(scopeinstack(temp->scope))
			{
				return;
			}
		}
		temp=temp->next;
	}
	printf("\n%*s\n%*s   <--- undeclared variable \n", column, "^", column, wrong_symbol);
	exit(0);
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
		if(strcmp(st->name, s)==0 && st->scope == curr_scope) //strcmp(st->type,type)==0
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
	int isarray = 0;
	int arrsize = 0;
	while(temp!=NULL)
	{
		if(strcmp(new_entry->name, temp->name)==0)
		{
			for(int i=0; i<temp->size; i++)
			{
				strcpy(new_entry->value[i], temp->value[i]);
				// printf("%s", temp->value[i]);
			}

			new_entry->isarray = temp ->isarray;
			arrsize = temp->size;
			deletetempval(temp);
		}
		temp = temp->next;
	}
	strcpy(new_entry->type, type);
	strcpy(new_entry->symbol, token_type);
	new_entry->lno = line_number;
	new_entry->size = 1;
	new_entry->lno_used[0] = line_number;
	if(strcmp(type, "int")==0)
		new_entry->var_size = 4;
	else if(strcmp(type, "char")==0)
		new_entry->var_size = 1;
	else if(strcmp(type, "float")==0)
		new_entry->var_size = 4;
	if(new_entry->isarray == 1)
	{
		new_entry->var_size *= arrsize;
	}

}


void tempval(char *var, char *val, int isarray, int size)
{

	tempvals *temp = (tempvals*)malloc(sizeof(tempvals));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->next = NULL;
	strcpy(temp->name, var);
	strcpy(temp->value[0], val);
	temp->isarray = isarray;
	temp->size = size;
	tempvals *t =tvhead;
	while(t!=NULL)
	{
		if(strcmp(t->name, temp->name)==0)
		{

			if(isarray)
			{
				int pos = 0;
				int i=1;
				int index = 0;
				while(val[i]!='}')
				{
					char num[30]="";
					pos = i;
					while(val[i]!=',' &&val[i]!='}' &&val[i]!=' ')
					{
						num[i-pos] = val[i];
						i++;
					}
					if(strcmp(num, "")!=0)
						strcpy(t->value[index++], num);
					if(val[i]=='}')
						break;
					i++;
				}
				return;
			}
		}
		t=t->next;
	}

	if(tvhead == NULL)
	{
		tvhead = temp;
	}
	else
	{
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
	free(temp);
}
void display()
{
	symbol_table *temp = st;
	printf("\n ͟S͟y͟m͟b͟o͟l͟ ͟T͟a͟b͟l͟e͟ \n\n");
	printf("Symbol \t\t     Name \t\t Array \t\t Type \t\t Scope \t Size \t Line Number \t Lines Used \t Value \n");
	printf("------------------------------------------------------------------------------------------------------------------------------------\n");
	while(temp!=NULL)
	{
		if(strcmp(temp->name, "keyword")==0)
		{
			printf("%s \t %8s \t\t %d \t\t %s \t\t %d \t %d \t %d \t\t [ ",temp->symbol, temp->name, temp->isarray, temp->type, temp->scope, temp->var_size, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if((temp->lno_used[i])!=0)
					printf("%d ", temp->lno_used[i]);
			}
			printf("]\t\t");
			for(int i=0; i<30; i++)
			{
				printf("%s ", temp->value[i]);
			}
			printf("\n");
		}
		else
		{
			printf("%s \t %8s \t\t %d \t\t %s \t\t %d \t %d \t %d \t\t [ ",temp->symbol, temp->name, temp->isarray, temp->type, temp->scope, temp->var_size, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if((temp->lno_used[i])!=0)
					printf("%d ", temp->lno_used[i]);
			}
			printf("]\t\t");
			for(int i=0; i<30; i++)
			{
				printf("%s ", temp->value[i]);
			}
			printf("\n");
		}

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
	lookup("while", "NIL", "keyword");
	lookup("do", "NIL", "keyword");
	lookup("continue", "NIL", "keyword");
	lookup("break", "NIL", "keyword");
	lookup("return", "NIL", "keyword");
	lookup("printf", "NIL", "function");

	scope_top = (scope_stack*)malloc(sizeof(scope_stack));
	scope_top->scope = 0;
	scope_top->next=NULL;
	tree_top = (tree_stack*)malloc(sizeof(tree_stack));
	tree_top->node = NULL;
	tree_top->next = NULL;
	struct Node *root;
	yyparse();
	root = pop_tree();
	quad *q;

	//Display symbol table
	display(st);
	//Display AST
	printtree(root);
	displaytree(root);
	//Display IC
	printICG(q);
	fclose(yyin);

}
