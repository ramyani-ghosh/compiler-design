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
void addval(char *var, char *val, int scope);
char * get_val(char *var, int scope);
void add_lines_used(char *s);
extern char yytext[];
extern int line_number;
extern int column;
extern FILE *yyin;
int scope_error= 0;
char *wrong_symbol;



#line 113 "y.tab.c" /* yacc.c:339  */

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
#line 49 "proj.y" /* yacc.c:355  */

	int ival;
	char string[128];

#line 228 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 245 "y.tab.c" /* yacc.c:358  */

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
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

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
       0,    71,    71,    72,    73,    74,    78,    79,    80,    81,
      82,    83,    84,    88,    89,    93,    94,    95,    96,    97,
      98,   102,   103,   104,   105,   106,   107,   111,   112,   137,
     162,   190,   191,   216,   244,   245,   246,   247,   248,   252,
     253,   254,   258,   259,   263,   264,   268,   269,   273,   274,
     280,   281,   282,   283,   284,   285,   290,   291,   296,   309,
     310,   318,   319,   338,   339,   340,   341,   342,   343,   344,
     348,   351,   352,   353,   357,   358,   362,   363,   367,   368,
     373,   374,   375,   379,   380,   384,   384,   385,   386,   387,
     392,   393,   394,   395,   399,   400,   404,   405,   409,   410,
     414,   415,   416,   417,   422,   423,   424,   425,   429,   430,
     434,   435,   439,   440,   444,   444,   444,   445,   445,   445,
     445,   446,   446,   446,   447,   447,   447
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

#define YYTABLE_NINF -118

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     115,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -24,
     -74,    13,   129,    18,   200,   -74,   -74,    15,   -34,   -74,
     108,    34,   -74,    13,   245,    19,   -74,   -74,    85,    13,
     -74,   359,   245,    19,   -74,   -74,    13,     6,   -74,     9,
     -13,   -74,    19,   163,   -74,    55,   -74,   -74,   -74,   -74,
     565,   578,   578,   578,   -74,   -74,   -74,   -74,   -74,   -74,
     359,   -74,    32,    10,   578,   194,    42,     3,    33,    83,
     -10,   -74,   -74,   -74,    19,   -74,    63,   -74,   245,   -74,
     120,   -74,    91,    88,    90,   508,   -74,   -74,   -74,    39,
     -74,    19,   208,   253,   -74,   -74,   -74,   -74,   133,   553,
     -74,   -74,   -74,    36,   -74,    26,   -74,   -74,   377,   578,
     144,   -74,   -74,   -74,   -74,   -74,   -74,   578,   -74,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   -74,   -74,   -74,   -74,   -74,   578,   -74,
     -74,   -74,    43,   578,   -74,   -74,   -74,   298,   -74,   -74,
      98,   122,   -74,   314,   -74,   -74,    41,   -74,   -30,   -74,
     -74,   -74,   -74,   -74,   -74,   194,   194,    42,    42,    42,
      42,     3,     3,    33,    83,   -22,   -74,   -74,    52,   -74,
     -74,   -74,   115,   -74,   -74,   -74,   -74,   578,   -74,   578,
     494,   -74,   -74,   -74,   404,   494,   -74,   449,   449,   -74,
     -74,   449,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    70,    64,    65,    66,    67,    68,    69,    63,     0,
     113,     0,   124,     0,   109,   110,   112,     0,     0,    59,
      61,     0,    94,     0,   121,     0,     1,   111,     0,     0,
      58,     0,   114,     0,    78,    73,    77,     0,    74,     0,
      61,    95,     0,    85,   125,     0,    60,     2,     3,     4,
       0,     0,     0,     0,    21,    22,    23,    24,    25,    26,
       0,     6,    15,    27,     0,    31,    34,    39,    42,    44,
      46,    48,    80,    62,     0,   118,    76,    71,     0,    72,
       0,   122,     0,     0,     0,     0,    98,    90,    56,     0,
      96,     0,    85,    85,    87,    88,    89,   126,     0,     0,
      19,    16,    17,     0,    83,     0,    11,    12,     0,     0,
       0,    51,    52,    53,    54,    55,    50,     0,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   115,   119,    75,    79,   123,     0,   104,
     105,   106,     0,     0,    99,    86,    92,    85,    91,    97,
       0,     0,     5,     0,    81,     8,     0,    13,     0,    10,
      49,    28,    29,    30,    27,    32,    33,    37,    38,    35,
      36,    40,    41,    43,    45,     0,   116,   120,     0,   107,
      57,    93,     0,    20,    82,    84,     9,     0,     7,     0,
      85,   108,    14,    47,    85,    85,   100,    85,    85,   101,
     102,    85,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   -74,   -16,   -74,   -21,   121,    -9,    27,
      30,   -74,   -31,   -27,   -74,   -47,     0,   -74,   134,     1,
      40,   -74,    94,   -74,   -57,   -74,   -73,   -74,   -25,   -18,
      82,   -74,   -74,   -74,    -7,   -74,   164,   -74,   -74,   -74,
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
     172,   196,   198,   136,   199,   200,    72,   138,   202,     2,
       3,     4,     5,     6,     7,     8,     2,     3,     4,     5,
       6,     7,     8,   139,    21,   140,   150,   159,     9,   182,
       2,     3,     4,     5,     6,     7,     8,   173,   193,   183,
     192,   174,    31,    46,  -117,    21,    47,    48,    49,    50,
      51,    52,   135,   164,   147,   191,   197,     0,    27,     0,
     201,     0,    10,    11,     2,     3,     4,     5,     6,     7,
       8,    82,     0,    83,    84,    85,     0,    41,     0,    53,
       0,    41,     0,     1,     0,    54,    55,    56,    57,    58,
      59,    47,    48,    49,    50,    51,    52,     0,    86,     0,
      87,     2,     3,     4,     5,     6,     7,     8,     0,     2,
       3,     4,     5,     6,     7,     8,    82,   119,    83,    84,
      85,     0,   120,   121,    53,   167,   168,   169,   170,     0,
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
     129,   194,   195,     3,   197,   198,   153,    36,   201,    21,
      22,    23,    24,    25,    26,    27,    21,    22,    23,    24,
      25,    26,    27,    55,    36,    55,    13,     3,    33,    51,
      21,    22,    23,    24,    25,    26,    27,   130,   189,    37,
     187,   131,    54,    29,    56,    36,     3,     4,     5,     6,
       7,     8,    78,   189,    92,   182,   194,    -1,    14,    -1,
     198,    -1,   182,   182,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    31,    32,    -1,   197,    -1,    36,
      -1,   201,    -1,     3,    -1,    42,    43,    44,    45,    46,
      47,     3,     4,     5,     6,     7,     8,    -1,    55,    -1,
      57,    21,    22,    23,    24,    25,    26,    27,    -1,    21,
      22,    23,    24,    25,    26,    27,    28,    43,    30,    31,
      32,    -1,    48,    49,    36,   124,   125,   126,   127,    -1,
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
      84,    87,    84
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
      90,    90,    90,    90,    91,    91,    91,    91,    92,    92,
      93,    93,    94,    94,    96,    97,    95,    98,    99,   100,
      95,   101,   102,    95,   103,   104,    95
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
       6,     7,     8,     9,     2,     2,     2,     3,     8,     1,
       1,     2,     1,     1,     0,     0,     6,     0,     0,     0,
       6,     0,     0,     5,     0,     0,     4
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
#line 71 "proj.y" /* yacc.c:1646  */
    { }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string));}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "proj.y" /* yacc.c:1646  */
    {}
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "proj.y" /* yacc.c:1646  */
    {}
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 78 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 79 "proj.y" /* yacc.c:1646  */
    {}
#line 1596 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 80 "proj.y" /* yacc.c:1646  */
    {}
#line 1602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 81 "proj.y" /* yacc.c:1646  */
    {}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 82 "proj.y" /* yacc.c:1646  */
    {}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 83 "proj.y" /* yacc.c:1646  */
    {}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 84 "proj.y" /* yacc.c:1646  */
    {}
#line 1626 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 88 "proj.y" /* yacc.c:1646  */
    {}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 89 "proj.y" /* yacc.c:1646  */
    {}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 93 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 94 "proj.y" /* yacc.c:1646  */
    {}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 95 "proj.y" /* yacc.c:1646  */
    {}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 96 "proj.y" /* yacc.c:1646  */
    {}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 97 "proj.y" /* yacc.c:1646  */
    {}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 98 "proj.y" /* yacc.c:1646  */
    {}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 102 "proj.y" /* yacc.c:1646  */
    {}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 103 "proj.y" /* yacc.c:1646  */
    {}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 104 "proj.y" /* yacc.c:1646  */
    {}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 105 "proj.y" /* yacc.c:1646  */
    {}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 106 "proj.y" /* yacc.c:1646  */
    {}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 107 "proj.y" /* yacc.c:1646  */
    {}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 111 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 112 "proj.y" /* yacc.c:1646  */
    {
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
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 137 "proj.y" /* yacc.c:1646  */
    {
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
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 162 "proj.y" /* yacc.c:1646  */
    {
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
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 190 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 191 "proj.y" /* yacc.c:1646  */
    {
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
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 216 "proj.y" /* yacc.c:1646  */
    {
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
#line 1872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 244 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 245 "proj.y" /* yacc.c:1646  */
    {}
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 246 "proj.y" /* yacc.c:1646  */
    {}
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 247 "proj.y" /* yacc.c:1646  */
    {}
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 248 "proj.y" /* yacc.c:1646  */
    {}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 252 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 253 "proj.y" /* yacc.c:1646  */
    {}
#line 1914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 254 "proj.y" /* yacc.c:1646  */
    {}
#line 1920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 258 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 259 "proj.y" /* yacc.c:1646  */
    {}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 263 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 264 "proj.y" /* yacc.c:1646  */
    {}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 268 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 269 "proj.y" /* yacc.c:1646  */
    {}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 273 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 274 "proj.y" /* yacc.c:1646  */
    {
																		addval((yyvsp[-2].string), (yyvsp[0].string), curr_scope);
																	}
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 280 "proj.y" /* yacc.c:1646  */
    {}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 281 "proj.y" /* yacc.c:1646  */
    {}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 282 "proj.y" /* yacc.c:1646  */
    {}
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 283 "proj.y" /* yacc.c:1646  */
    {}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 284 "proj.y" /* yacc.c:1646  */
    {}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 285 "proj.y" /* yacc.c:1646  */
    {}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 290 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 291 "proj.y" /* yacc.c:1646  */
    {}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 296 "proj.y" /* yacc.c:1646  */
    {
								// printf("%s %s", $1, $2);
								char *p = strtok((yyvsp[-1].string), ",");
								while(p!=NULL)
								{
									lookup(p, (yyvsp[-2].string), "identifier");
									p=strtok(NULL, ",");
								}

							}
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 309 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 310 "proj.y" /* yacc.c:1646  */
    {
														strcpy((yyval.string),(yyvsp[0].string));
														strcat((yyval.string), ",");
														strcat((yyval.string), (yyvsp[-2].string));
													}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 318 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2055 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 319 "proj.y" /* yacc.c:1646  */
    {
										char val[10];
										strcpy(val, (yyvsp[0].string));
										if((0<= (yyvsp[0].string)[0]-'0' && 9>=(yyvsp[0].string)[0]-'0') || (yyvsp[0].string)[0]=='\'')
										{
											tempval((yyvsp[-2].string), val);
											strcpy((yyval.string),(yyvsp[-2].string));
										}
										else
										{
											strcpy(val,get_val((yyvsp[0].string), curr_scope));
											tempval((yyvsp[-2].string), val);
											strcpy((yyval.string),(yyvsp[-2].string));
										}
									}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 338 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 339 "proj.y" /* yacc.c:1646  */
    {}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 340 "proj.y" /* yacc.c:1646  */
    {}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 341 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 342 "proj.y" /* yacc.c:1646  */
    {}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 343 "proj.y" /* yacc.c:1646  */
    {}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 344 "proj.y" /* yacc.c:1646  */
    {}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 348 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string),(yyvsp[0].string));}
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 351 "proj.y" /* yacc.c:1646  */
    {}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 352 "proj.y" /* yacc.c:1646  */
    {}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 353 "proj.y" /* yacc.c:1646  */
    {strcpy((yyval.string), (yyvsp[-2].string));}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 357 "proj.y" /* yacc.c:1646  */
    {}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 358 "proj.y" /* yacc.c:1646  */
    {}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 362 "proj.y" /* yacc.c:1646  */
    {}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 363 "proj.y" /* yacc.c:1646  */
    {}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 367 "proj.y" /* yacc.c:1646  */
    {}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 368 "proj.y" /* yacc.c:1646  */
    {}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 373 "proj.y" /* yacc.c:1646  */
    { strcpy((yyval.string), (yyvsp[0].string)); }
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 374 "proj.y" /* yacc.c:1646  */
    {}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 375 "proj.y" /* yacc.c:1646  */
    {}
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 379 "proj.y" /* yacc.c:1646  */
    {}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 380 "proj.y" /* yacc.c:1646  */
    {}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 384 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 384 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 385 "proj.y" /* yacc.c:1646  */
    {}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 386 "proj.y" /* yacc.c:1646  */
    {}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 387 "proj.y" /* yacc.c:1646  */
    {}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 393 "proj.y" /* yacc.c:1646  */
    {}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 394 "proj.y" /* yacc.c:1646  */
    {}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 395 "proj.y" /* yacc.c:1646  */
    {}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 399 "proj.y" /* yacc.c:1646  */
    {}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 400 "proj.y" /* yacc.c:1646  */
    {}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 404 "proj.y" /* yacc.c:1646  */
    {}
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 405 "proj.y" /* yacc.c:1646  */
    {}
#line 2279 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 409 "proj.y" /* yacc.c:1646  */
    {}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 410 "proj.y" /* yacc.c:1646  */
    {}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 414 "proj.y" /* yacc.c:1646  */
    {}
#line 2297 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 415 "proj.y" /* yacc.c:1646  */
    {}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 416 "proj.y" /* yacc.c:1646  */
    {}
#line 2309 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 417 "proj.y" /* yacc.c:1646  */
    {}
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 422 "proj.y" /* yacc.c:1646  */
    {}
#line 2321 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 423 "proj.y" /* yacc.c:1646  */
    {}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 424 "proj.y" /* yacc.c:1646  */
    {}
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 425 "proj.y" /* yacc.c:1646  */
    {}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 429 "proj.y" /* yacc.c:1646  */
    {}
#line 2345 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 430 "proj.y" /* yacc.c:1646  */
    {}
#line 2351 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 434 "proj.y" /* yacc.c:1646  */
    {}
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 435 "proj.y" /* yacc.c:1646  */
    {}
#line 2363 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 439 "proj.y" /* yacc.c:1646  */
    {}
#line 2369 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 440 "proj.y" /* yacc.c:1646  */
    {}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 444 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2381 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 444 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2387 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 444 "proj.y" /* yacc.c:1646  */
    { lookup((yyvsp[-4].string), (yyvsp[-5].string), "function");}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 445 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2399 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 445 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 445 "proj.y" /* yacc.c:1646  */
    {}
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 445 "proj.y" /* yacc.c:1646  */
    { lookup((yyvsp[-4].string), (yyvsp[-5].string), "function");}
#line 2417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 446 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 446 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2429 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 446 "proj.y" /* yacc.c:1646  */
    {}
#line 2435 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 447 "proj.y" /* yacc.c:1646  */
    {curr_scope++;}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 447 "proj.y" /* yacc.c:1646  */
    {curr_scope--;}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 447 "proj.y" /* yacc.c:1646  */
    {}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2457 "y.tab.c" /* yacc.c:1646  */
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
#line 450 "proj.y" /* yacc.c:1906  */



symbol_table* initialize()
{
	symbol_table *temp = (symbol_table*)malloc(sizeof(symbol_table));
	temp->name = (char*)malloc(sizeof(char)*128);
	temp->type = (char*)malloc(sizeof(char)*10);
	temp->symbol = (char*)malloc(sizeof(char)*11);
	temp->value = (char*)malloc(sizeof(char)*10);
	strcpy(temp->value, "0");
	temp->lno = 0;
	temp->lno_used = (int*)malloc(sizeof(int)*100);
	temp->size = 0;
	temp->next = NULL;
	temp->scope = curr_scope;
	return temp;
}

void addval(char *var, char *val, int scope)
{
	symbol_table *temp = st;
	while(temp!=NULL)
	{
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope == scope)
			{
				strcpy(temp->value, val);
			}
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
		if(strcmp(temp->name, var)==0)
		{
			if(temp->scope == scope)
			{
				return temp->value;
			}
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
	new_entry->lno = line_number;
	new_entry->size = 1;
	new_entry->lno_used[0] = line_number;
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
	printf("\nSYMBOL TABLE\n");
	printf("Symbol \t\t     Name \t\t Type \t\t Scope \t Value \t Line Number \t Lines Used\n");
	printf("-----------------------------------------------------------------------------------------------------------------\n");
	while(temp!=NULL)
	{
		if(strcmp(temp->name, "keyword")==0)
		{
			printf("%s \t %8s \t\t %s \t\t %d \t %s \t %d \t\t [ ",temp->symbol, temp->name, temp->type, temp->scope, temp->value, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if((temp->lno_used[i])!=0)
					printf("%d ", temp->lno_used[i]);
			}

			printf("]\n");
		}
		else
		{
			printf("%s \t %8s \t\t %s \t\t %d \t %s \t %d \t\t [ ",temp->symbol, temp->name, temp->type, temp->scope, temp->value, temp->lno);
			for(int i=0; i<temp->size; i++)
			{
				if(temp->lno_used[i]!=0)
					printf("%d ", temp->lno_used[i]);
			}
			printf("]\n");
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
	lookup("continue", "NIL", "keyword");
	lookup("break", "NIL", "keyword");
	lookup("return", "NIL", "keyword");
	lookup("printf", "NIL", "function");

	yyparse();
	fclose(yyin);
	display(st);
}
