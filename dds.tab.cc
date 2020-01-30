/* A Bison parser, made by GNU Bison 3.3.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         ddsparse
#define yylex           ddslex
#define yyerror         ddserror
#define yydebug         ddsdebug
#define yynerrs         ddsnerrs

#define yylval          ddslval
#define yychar          ddschar


# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
   by #include "dds.tab.hh".  */
#ifndef YY_DDS_DDS_TAB_HH_INCLUDED
# define YY_DDS_DDS_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int ddsdebug;
#endif
/* "%code requires" blocks.  */
#line 47 "dds.yy" /* yacc.c:352  */


#include "config_dap.h"

#include <cstring>
#include <cassert>
#include <iostream>
#include <stack>
#include <sstream>

#include "Byte.h"
#include "Int16.h"
#include "UInt16.h"
#include "Int32.h"
#include "UInt32.h"
#include "Float32.h"
#include "Float64.h"
#include "Str.h"
#include "Url.h"
#include "Array.h"
#include "Structure.h"
#include "Sequence.h"
#include "Grid.h"

#include "DDS.h"
#include "Error.h"
#include "parser.h"
#include "util.h"

using namespace std;
using namespace libdap;

// These macros are used to access the `arguments' passed to the parser. A
// pointer to an error object and a pointer to an integer status variable are
// passed in to the parser within a structure (which itself is passed as a
// pointer). Note that the ERROR macro explicitly casts OBJ to an ERROR *. 
// ERROR is no longer used. These parsers now signal problems by throwing
// exceptions. 5/22/2002 jhrg
#define DDS_OBJ(arg) ((DDS *)((parser_arg *)(arg))->_object)

// #define YYPARSE_PARAM arg

extern int dds_line_num;	/* defined in dds.lex */


#line 156 "dds.tab.cc" /* yacc.c:352  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SCAN_WORD = 258,
    SCAN_DATASET = 259,
    SCAN_LIST = 260,
    SCAN_SEQUENCE = 261,
    SCAN_STRUCTURE = 262,
    SCAN_FUNCTION = 263,
    SCAN_GRID = 264,
    SCAN_BYTE = 265,
    SCAN_INT16 = 266,
    SCAN_UINT16 = 267,
    SCAN_INT32 = 268,
    SCAN_UINT32 = 269,
    SCAN_FLOAT32 = 270,
    SCAN_FLOAT64 = 271,
    SCAN_STRING = 272,
    SCAN_URL = 273
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 131 "dds.yy" /* yacc.c:352  */

    bool boolean;
    char word[ID_MAX];

#line 192 "dds.tab.cc" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ddslval;

int ddsparse (parser_arg *arg);

#endif /* !YY_DDS_DDS_TAB_HH_INCLUDED  */


/* Unqualified %code blocks.  */
#line 93 "dds.yy" /* yacc.c:355  */


// No global static objects in the dap library! 1/24/2000 jhrg
static stack<BaseType *> *ctor;
static BaseType *current;
static string *id;
static Part part = nil;		/* Part is defined in BaseType */

static const char *NO_DDS_MSG =
"The descriptor object returned from the dataset was null.\n\
Check that the URL is correct.";

static const char *BAD_DECLARATION =
"In the dataset descriptor object: Expected a variable declaration\n\
(e.g., Int32 i;). Make sure that the variable name is not the name\n\
of a datatype and that the Array: and Maps: sections of a Grid are\n\
labeled properly.";

int ddslex();
void ddserror(parser_arg *arg, const string &s /*char *s*/);
void error_exit_cleanup();
void add_entry(DDS &table, stack<BaseType *> **ctor, BaseType **current, 
	       Part p);
void invalid_declaration(parser_arg *arg, string semantic_err_msg, 
			 char *type, char *name);


#line 237 "dds.tab.cc" /* yacc.c:355  */

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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  88

#define YYUNDEFTOK  2
#define YYMAXUTOK   273

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,    21,
       2,    25,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,     2,    20,     2,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   160,   160,   160,   176,   177,   180,   184,   193,   196,
     197,   206,   221,   220,   242,   241,   263,   275,   287,   262,
     308,   318,   324,   330,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   347,   348,   351,   351,   351,   351,   351,
     352,   352,   352,   352,   353,   353,   353,   353,   354,   357,
     379,   383,   378,   409,   419,   420,   421
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCAN_WORD", "SCAN_DATASET", "SCAN_LIST",
  "SCAN_SEQUENCE", "SCAN_STRUCTURE", "SCAN_FUNCTION", "SCAN_GRID",
  "SCAN_BYTE", "SCAN_INT16", "SCAN_UINT16", "SCAN_INT32", "SCAN_UINT32",
  "SCAN_FLOAT32", "SCAN_FLOAT64", "SCAN_STRING", "SCAN_URL", "'{'", "'}'",
  "';'", "':'", "'['", "']'", "'='", "$accept", "start", "$@1", "datasets",
  "dataset", "declarations", "declaration", "$@2", "$@3", "$@4", "$@5",
  "$@6", "structure", "sequence", "grid", "base_type", "var", "var_name",
  "array_decl", "$@7", "$@8", "name", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   123,
     125,    59,    58,    91,    93,    61
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -9

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -53,    11,     9,   -53,   -53,    -7,     5,   -53,    52,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,    70,   -53,    -3,    -2,    -1,   176,   142,
     -53,    52,    52,    16,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,     2,   -53,
     -53,   -53,   -53,     0,    88,   106,    12,   -53,   -53,    17,
     -53,   -53,   -53,   -53,   -53,    13,   176,   176,   160,   -53,
      10,     3,     6,    19,    33,   -53,   -53,    18,   -53,   -53,
      14,    52,   -53,   124,   -53,   176,     7,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     7,     0,     0,     4,     0,     5,
      20,    22,    21,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     0,     9,     0,     0,     0,     0,     0,
      10,     0,     0,     0,    35,    48,    46,    45,    47,    36,
      37,    39,    38,    40,    41,    42,    43,    44,     0,    33,
      56,    55,    54,     0,     0,     0,     0,    53,    11,     0,
      34,     6,    12,    14,    16,    50,     0,     0,     0,    49,
       0,     0,     0,     0,     0,    13,    15,     0,    51,    17,
       0,     0,    52,     0,    18,     0,     0,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   -53,    35,   -30,   -23,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,   -53,   -53,   -52,    15,   -53,   -53,
     -53,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    23,    24,    66,    67,    68,
      81,    85,    25,    26,    27,    28,    48,    49,    60,    70,
      80,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    54,    55,    57,    57,    -3,     4,    57,    57,     5,
       4,     3,     8,     5,    71,    72,    31,    32,    33,    56,
      65,    61,    77,    58,    75,    59,    59,    76,    87,    59,
      59,    30,    30,    86,    64,    74,    78,    69,    82,     0,
      79,     9,     0,     0,    52,    73,     0,     0,     0,     0,
       0,    83,     0,    10,     0,     0,     0,     0,    11,    12,
      30,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    10,    -8,     0,     0,     0,    11,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    10,
      29,     0,     0,     0,    11,    12,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    10,    62,     0,
       0,     0,    11,    12,     0,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    10,    63,     0,     0,     0,
      11,    12,     0,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    50,    84,    34,    51,    35,    36,    37,
       0,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    10,     0,     0,     0,     0,    11,    12,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    34,
       0,    35,    36,    37,     0,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47
};

static const yytype_int8 yycheck[] =
{
      23,    31,    32,     1,     1,     0,     1,     1,     1,     4,
       1,     0,    19,     4,    66,    67,    19,    19,    19,     3,
       3,    21,     3,    21,    21,    23,    23,    21,    21,    23,
      23,    54,    55,    85,    22,    25,     3,    24,    24,    -1,
      22,     6,    -1,    -1,    29,    68,    -1,    -1,    -1,    -1,
      -1,    81,    -1,     1,    -1,    -1,    -1,    -1,     6,     7,
      83,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     1,    20,    -1,    -1,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     1,
      20,    -1,    -1,    -1,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     1,    20,    -1,
      -1,    -1,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,     1,    20,    -1,    -1,    -1,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     1,    20,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,     1,    -1,    -1,    -1,    -1,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     3,
      -1,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    27,    28,     0,     1,     4,    29,    30,    19,    30,
       1,     6,     7,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    31,    32,    38,    39,    40,    41,    20,
      32,    19,    19,    19,     3,     5,     6,     7,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    42,    43,
       1,     4,    43,    47,    31,    31,     3,     1,    21,    23,
      44,    21,    20,    20,    22,     3,    33,    34,    35,    24,
      45,    42,    42,    32,    25,    21,    21,     3,     3,    22,
      46,    36,    24,    31,    20,    37,    42,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    26,    28,    27,    29,    29,    30,    30,    31,    31,
      31,    32,    33,    32,    34,    32,    35,    36,    37,    32,
      32,    38,    39,    40,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    44,
      45,    46,    44,    44,    47,    47,    47
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     6,     1,     0,     1,
       2,     3,     0,     7,     0,     7,     0,     0,     0,    14,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     0,     7,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (arg, YY_("syntax error: cannot back up")); \
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
                  Type, Value, arg); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, parser_arg *arg)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (arg);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, parser_arg *arg)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep, arg);
  YYFPRINTF (yyo, ")");
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, parser_arg *arg)
{
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              , arg);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, arg); \
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
            else
              goto append;

          append:
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, parser_arg *arg)
{
  YYUSE (yyvaluep);
  YYUSE (arg);
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
yyparse (parser_arg *arg)
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 160 "dds.yy" /* yacc.c:1652  */
    {
		    /* On entry to the parser, make the BaseType stack. 
		       I use if (!ctor) here because in the tab.cc file,
		       this is a case block in a switch, so it could be
		       run more than once, causing the storage to be
		       overwritten. jhrg 6/26/15 */
		       
		    if (!ctor)
		    	ctor = new stack<BaseType *>;
        }
#line 1404 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 3:
#line 171 "dds.yy" /* yacc.c:1652  */
    {
		    delete ctor; ctor = 0;
		}
#line 1412 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 6:
#line 181 "dds.yy" /* yacc.c:1652  */
    {
		    (yyval.boolean) = (yyvsp[-3].boolean) && (yyvsp[-1].boolean);
		}
#line 1420 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 7:
#line 185 "dds.yy" /* yacc.c:1652  */
    {
		    parse_error((parser_arg *)arg, NO_DDS_MSG, dds_line_num, (yyvsp[0].word));
		    error_exit_cleanup();
		    YYABORT;
		}
#line 1430 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 8:
#line 193 "dds.yy" /* yacc.c:1652  */
    {
		    (yyval.boolean) = true;
		}
#line 1438 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 9:
#line 196 "dds.yy" /* yacc.c:1652  */
    { (yyval.boolean) = true; }
#line 1444 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 10:
#line 197 "dds.yy" /* yacc.c:1652  */
    { (yyval.boolean) = true; }
#line 1450 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 11:
#line 207 "dds.yy" /* yacc.c:1652  */
    { 
		    string smsg;
		    if (current->check_semantics(smsg)) {
			    add_entry(*DDS_OBJ(arg), &ctor, &current, part); 
		    } else {
		      invalid_declaration((parser_arg *)arg, smsg, (yyvsp[-2].word), (yyvsp[-1].word));
		      error_exit_cleanup();
		      YYABORT;
		    }
            strncpy((yyval.word),(yyvsp[-1].word),ID_MAX);
            (yyval.word)[ID_MAX-1] = '\0';
		}
#line 1467 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 12:
#line 221 "dds.yy" /* yacc.c:1652  */
    { 
		    if( current ) delete current ;
		    current = ctor->top(); 
		    ctor->pop();
		}
#line 1477 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 13:
#line 227 "dds.yy" /* yacc.c:1652  */
    { 
		    string smsg;
		    if (current->check_semantics(smsg)) {
			    add_entry(*DDS_OBJ(arg), &ctor, &current, part); 
			}
		    else {
		        invalid_declaration((parser_arg *)arg, smsg, (yyvsp[-6].word), (yyvsp[-1].word));
		        error_exit_cleanup();
		        YYABORT;
		    }
            strncpy((yyval.word),(yyvsp[-1].word),ID_MAX);
            (yyval.word)[ID_MAX-1] = '\0';
		}
#line 1495 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 14:
#line 242 "dds.yy" /* yacc.c:1652  */
    { 
		    if( current ) delete current ;
		    current = ctor->top(); 
		    ctor->pop();
		}
#line 1505 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 15:
#line 248 "dds.yy" /* yacc.c:1652  */
    { 
		    string smsg;
		    if (current->check_semantics(smsg)) {
			    add_entry(*DDS_OBJ(arg), &ctor, &current, part); 
			}
		    else {
		      invalid_declaration((parser_arg *)arg, smsg, (yyvsp[-6].word), (yyvsp[-1].word));
		      error_exit_cleanup();
		      YYABORT;
		    }
            strncpy((yyval.word),(yyvsp[-1].word),ID_MAX);
            (yyval.word)[ID_MAX-1] = '\0';
		}
#line 1523 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 16:
#line 263 "dds.yy" /* yacc.c:1652  */
    { 
		    if (is_keyword(string((yyvsp[-1].word)), "array")) {
			    part = libdap::array;
			}
		    else {
			    ostringstream msg;
			    msg << BAD_DECLARATION;
			    parse_error((parser_arg *)arg, msg.str().c_str(), dds_line_num, (yyvsp[-1].word));
			    YYABORT;
		    }
        }
#line 1539 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 17:
#line 275 "dds.yy" /* yacc.c:1652  */
    { 
		    if (is_keyword(string((yyvsp[-1].word)), "maps")) {
			    part = maps; 
			}
		    else {
			    ostringstream msg;
			    msg << BAD_DECLARATION;
			    parse_error((parser_arg *)arg, msg.str().c_str(), dds_line_num, (yyvsp[-1].word));
			    YYABORT;
		    }
        }
#line 1555 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 18:
#line 287 "dds.yy" /* yacc.c:1652  */
    {
		    if( current ) delete current ;
		    current = ctor->top(); 
		    ctor->pop();
		}
#line 1565 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 19:
#line 293 "dds.yy" /* yacc.c:1652  */
    {
		    string smsg;
		    if (current->check_semantics(smsg)) {
			    part = nil; 
			    add_entry(*DDS_OBJ(arg), &ctor, &current, part); 
		    }
		    else {
		      invalid_declaration((parser_arg *)arg, smsg, (yyvsp[-13].word), (yyvsp[-1].word));
		      error_exit_cleanup();
		      YYABORT;
		    }
        strncpy((yyval.word),(yyvsp[-1].word),ID_MAX);
        (yyval.word)[ID_MAX-1] = '\0';
		}
#line 1584 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 20:
#line 309 "dds.yy" /* yacc.c:1652  */
    {
		    ostringstream msg;
		    msg << BAD_DECLARATION;
		    parse_error((parser_arg *)arg, msg.str().c_str(), dds_line_num, (yyvsp[0].word));
		    YYABORT;
		}
#line 1595 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 21:
#line 319 "dds.yy" /* yacc.c:1652  */
    { 
		    ctor->push(DDS_OBJ(arg)->get_factory()->NewStructure()); 
		}
#line 1603 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 22:
#line 325 "dds.yy" /* yacc.c:1652  */
    { 
		    ctor->push(DDS_OBJ(arg)->get_factory()->NewSequence()); 
		}
#line 1611 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 23:
#line 331 "dds.yy" /* yacc.c:1652  */
    { 
		    ctor->push(DDS_OBJ(arg)->get_factory()->NewGrid()); 
		}
#line 1619 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 24:
#line 336 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewByte(); }
#line 1625 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 25:
#line 337 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewInt16(); }
#line 1631 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 26:
#line 338 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewUInt16(); }
#line 1637 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 27:
#line 339 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewInt32(); }
#line 1643 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 28:
#line 340 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewUInt32(); }
#line 1649 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 29:
#line 341 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewFloat32(); }
#line 1655 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 30:
#line 342 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewFloat64(); }
#line 1661 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 31:
#line 343 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewStr(); }
#line 1667 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 32:
#line 344 "dds.yy" /* yacc.c:1652  */
    { if( current ) delete current ;current = DDS_OBJ(arg)->get_factory()->NewUrl(); }
#line 1673 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 33:
#line 347 "dds.yy" /* yacc.c:1652  */
    { current->set_name((yyvsp[0].word)); }
#line 1679 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 49:
#line 358 "dds.yy" /* yacc.c:1652  */
    { 
		    if (!check_int32((yyvsp[-1].word))) {
			    string msg = "In the dataset descriptor object:\n";
			    msg += "Expected an array subscript.\n";
			    parse_error((parser_arg *)arg, msg.c_str(), dds_line_num, (yyvsp[-1].word));
		    }
		    if (current->type() == dods_array_c && check_int32((yyvsp[-1].word))) {
			    ((Array *)current)->append_dim(atoi((yyvsp[-1].word)));
		    }
		    else {
			    Array *a = DDS_OBJ(arg)->get_factory()->NewArray(); 
			    a->add_var(current); 
			    a->append_dim(atoi((yyvsp[-1].word)));
			    if( current ) delete current ;
			    current = a;
		    }

		    (yyval.boolean) = true;
		 }
#line 1703 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 50:
#line 379 "dds.yy" /* yacc.c:1652  */
    {
		     if (!id) id = new string((yyvsp[0].word));
		 }
#line 1711 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 51:
#line 383 "dds.yy" /* yacc.c:1652  */
    { 
		     if (!check_int32((yyvsp[0].word))) {
			     string msg = "In the dataset descriptor object:\n";
			     msg += "Expected an array subscript.\n";
			     parse_error((parser_arg *)arg, msg.c_str(), dds_line_num, (yyvsp[0].word));
			     error_exit_cleanup();
			     YYABORT;
		     }
		     if (current->type() == dods_array_c) {
			     ((Array *)current)->append_dim(atoi((yyvsp[0].word)), *id);
		     }
		     else {
			     Array *a = DDS_OBJ(arg)->get_factory()->NewArray(); 
			     a->add_var(current); 
			     a->append_dim(atoi((yyvsp[0].word)), *id);
			     if( current ) delete current ;
			     current = a;
		     }

		     delete id; id = 0;
		 }
#line 1737 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 52:
#line 405 "dds.yy" /* yacc.c:1652  */
    {
		     (yyval.boolean) = true;
		 }
#line 1745 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 53:
#line 410 "dds.yy" /* yacc.c:1652  */
    {
		     ostringstream msg;
		     msg << "In the dataset descriptor object:" << endl
			     << "Expected an array subscript." << endl;
		     parse_error((parser_arg *)arg, msg.str().c_str(), dds_line_num, (yyvsp[0].word));
		     YYABORT;
		 }
#line 1757 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 54:
#line 419 "dds.yy" /* yacc.c:1652  */
    { (*DDS_OBJ(arg)).set_dataset_name((yyvsp[0].word)); (yyval.boolean) = true;}
#line 1763 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 55:
#line 420 "dds.yy" /* yacc.c:1652  */
    { (*DDS_OBJ(arg)).set_dataset_name((yyvsp[0].word)); (yyval.boolean) = true; }
#line 1769 "dds.tab.cc" /* yacc.c:1652  */
    break;

  case 56:
#line 422 "dds.yy" /* yacc.c:1652  */
    {
		    ostringstream msg;
		    msg << "Error parsing the dataset name." << endl
		        << "The name may be missing or may contain an illegal character." << endl;
		    parse_error((parser_arg *)arg, msg.str().c_str(), dds_line_num, (yyvsp[0].word));
		    YYABORT;
		}
#line 1781 "dds.tab.cc" /* yacc.c:1652  */
    break;


#line 1785 "dds.tab.cc" /* yacc.c:1652  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
      yyerror (arg, YY_("syntax error"));
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
        yyerror (arg, yymsgp);
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
                      yytoken, &yylval, arg);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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
                  yystos[yystate], yyvsp, arg);
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
  yyerror (arg, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, arg);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, arg);
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
#line 431 "dds.yy" /* yacc.c:1918  */


/* 
 This function must be defined. However, use the error reporting code in
 parser-utils.cc.
 */

void
ddserror(parser_arg *, const string &)
{
}

/*
 Error clean up. Call this before calling YYBORT. Don't call this on a
 normal exit.
 */

void error_exit_cleanup()
{
    delete id;
    id = 0;
    delete current;
    current = 0;
    delete ctor;
    ctor = 0;
}

/*
 Invalid declaration message.
 */

void invalid_declaration(parser_arg *arg, string semantic_err_msg, char *type, char *name)
{
    ostringstream msg;
    msg << "In the dataset descriptor object: `" << type << " " << name << "'" << endl << "is not a valid declaration."
            << endl << semantic_err_msg;
    parse_error((parser_arg *) arg, msg.str().c_str(), dds_line_num);
}

/*
 Add the variable pointed to by CURRENT to either the topmost ctor object on
 the stack CTOR or to the dataset variable table TABLE if CTOR is empty.  If
 it exists, the current ctor object is popped off the stack and assigned to
 CURRENT.

 NB: the ctor stack is popped for arrays because they are ctors which
 contain only a single variable. For other ctor types, several variables may
 be members and the parse rule (see `declaration' above) determines when to
 pop the stack.

 Returns: void 
 */

void add_entry(DDS &table, stack<BaseType *> **ctor, BaseType **current, Part part)
{
    if (!*ctor)
        *ctor = new stack<BaseType *> ;

    if (!(*ctor)->empty()) { /* must be parsing a ctor type */
        (*ctor)->top()->add_var(*current, part);

        const Type &ctor_type = (*ctor)->top()->type();

        if (ctor_type == dods_array_c) {
            if (*current)
                delete *current;
            *current = (*ctor)->top();
            (*ctor)->pop();

            // Return here to avoid deleting the new value of 'current.'
            return;
        }
    }
    else {
        table.add_var(*current);
    }

    if (*current)
        delete *current;
    *current = 0;
}

