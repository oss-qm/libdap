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
#define yyparse         ce_exprparse
#define yylex           ce_exprlex
#define yyerror         ce_exprerror
#define yydebug         ce_exprdebug
#define yynerrs         ce_exprnerrs

#define yylval          ce_exprlval
#define yychar          ce_exprchar


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
   by #include "ce_expr.tab.hh".  */
#ifndef YY_CE_EXPR_CE_EXPR_TAB_HH_INCLUDED
# define YY_CE_EXPR_CE_EXPR_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int ce_exprdebug;
#endif
/* "%code requires" blocks.  */
#line 41 "ce_expr.yy" /* yacc.c:352  */


#include "config.h"

#include <cassert>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <sstream>
#include <iterator>
#include <string>
#include <stack>

//#define DODS_DEBUG

#include "debug.h"
#include "escaping.h"

#include "DDS.h"
#include "ConstraintEvaluator.h"

#include "BaseType.h"

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

#include "Error.h"

#include "util.h"
#include "parser.h"
#include "ce_parser.h"
#include "expr.h"
#include "RValue.h"

using std::cerr;
using std::endl;
using namespace libdap ;

#define EVALUATOR(arg) (static_cast<ce_parser_arg*>(arg)->get_eval())
#define DDS(arg) (static_cast<ce_parser_arg*>(arg)->get_dds())

// #define YYPARSE_PARAM arg

int ce_exprlex(void);		/* the scanner; see expr.lex */

void ce_exprerror(ce_parser_arg *arg, const string &s); 
void ce_exprerror(ce_parser_arg *arg, const string &s, const string &s2);
void no_such_func(ce_parser_arg *arg, const string &name);
void no_such_ident(ce_parser_arg *arg, const string &name, const string &word);

int_list *make_array_index(value &i1, value &i2, value &i3);
int_list *make_array_index(value &i1, value &i2);
int_list *make_array_index(value &i1);
int_list_list *make_array_indices(int_list *index);
int_list_list *append_array_index(int_list_list *indices, int_list *index);

void delete_array_indices(int_list_list *indices);
bool bracket_projection(DDS &table, const char *name, int_list_list *indices);

void process_array_indices(BaseType *variable, int_list_list *indices); 
void process_grid_indices(BaseType *variable, int_list_list *indices); 
void process_sequence_indices(BaseType *variable, int_list_list *indices);

/* Replace these with method calls. jhrg 8/31/06 */
bool is_array_t(BaseType *variable);
bool is_grid_t(BaseType *variable);
bool is_sequence_t(BaseType *variable);

BaseType *make_variable(ConstraintEvaluator &eval, const value &val);
bool_func get_function(const ConstraintEvaluator &eval, const char *name);
btp_func get_btp_function(const ConstraintEvaluator &eval, const char *name);
proj_func get_proj_function(const ConstraintEvaluator &eval, const char *name);

template<class arg_list, class arg_type>
arg_list make_fast_arg_list(unsigned long vector_size_hint, arg_type arg_value);

template<class arg_list, class arg_type>
arg_list make_fast_arg_list(arg_list int_values, arg_type arg_value);

template<class t, class T>
rvalue *build_constant_array(vector<t> *values, DDS *dds);


#line 206 "ce_expr.tab.cc" /* yacc.c:352  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SCAN_STR = 258,
    SCAN_WORD = 259,
    SCAN_EQUAL = 260,
    SCAN_NOT_EQUAL = 261,
    SCAN_GREATER = 262,
    SCAN_GREATER_EQL = 263,
    SCAN_LESS = 264,
    SCAN_LESS_EQL = 265,
    SCAN_REGEXP = 266,
    SCAN_STAR = 267,
    SCAN_HASH_BYTE = 268,
    SCAN_HASH_INT16 = 269,
    SCAN_HASH_UINT16 = 270,
    SCAN_HASH_INT32 = 271,
    SCAN_HASH_UINT32 = 272,
    SCAN_HASH_FLOAT32 = 273,
    SCAN_HASH_FLOAT64 = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 145 "ce_expr.yy" /* yacc.c:352  */

    bool boolean;
    int op;
    char id[ID_MAX];
    
    libdap::dods_byte byte_value;
    libdap::dods_int16 int16_value;
    libdap::dods_uint16 uint16_value;
    libdap::dods_int32 int32_value;
    libdap::dods_uint32 uint32_value;
    libdap::dods_float32 float32_value;
    libdap::dods_float64 float64_value;
    
    libdap::byte_arg_list byte_values;
    libdap::int16_arg_list int16_values;
    libdap::uint16_arg_list uint16_values;
    libdap::int32_arg_list int32_values;
    libdap::uint32_arg_list uint32_values;
    libdap::float32_arg_list float32_values;
    libdap::float64_arg_list float64_values;
    
    libdap::value val;               // value is defined in expr.h

    libdap::bool_func b_func;
    libdap::btp_func bt_func;

    libdap::int_list *int_l_ptr;
    libdap::int_list_list *int_ll_ptr;
    
    libdap::rvalue *rval_ptr;
    libdap::rvalue_list *r_val_l_ptr;

#line 271 "ce_expr.tab.cc" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ce_exprlval;

int ce_exprparse (ce_parser_arg *arg);

#endif /* !YY_CE_EXPR_CE_EXPR_TAB_HH_INCLUDED  */


/* Unqualified %code blocks.  */
#line 232 "ce_expr.yy" /* yacc.c:355  */

/* This global is used by the rule 'arg_length_hint' so that the hint can 
   be used during the paraent rule's parse. See fast_int32_arg_list. */
unsigned long arg_length_hint_value = 0;

#line 294 "ce_expr.tab.cc" /* yacc.c:355  */

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
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

#define YYUNDEFTOK  2
#define YYMAXUTOK   274

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
       2,     2,     2,     2,     2,     2,     2,     2,    20,     2,
      22,    24,     2,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   241,   241,   247,   249,   249,   253,   259,   260,   266,
     278,   282,   286,   310,   316,   322,   328,   334,   340,   346,
     355,   366,   370,   377,   384,   388,   395,   402,   406,   413,
     420,   424,   431,   438,   442,   449,   456,   460,   467,   474,
     478,   485,   492,   514,   515,   521,   530,   541,   548,   562,
     563,   573,   577,   583,   590,   599,   604,   609,   647,   671,
     684,   690,   699,   705,   716,   721,   735,   739,   753,   762,
     769,   781,   792,   807,   823,   824,   825,   826,   827,   828,
     829
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SCAN_STR", "SCAN_WORD", "SCAN_EQUAL",
  "SCAN_NOT_EQUAL", "SCAN_GREATER", "SCAN_GREATER_EQL", "SCAN_LESS",
  "SCAN_LESS_EQL", "SCAN_REGEXP", "SCAN_STAR", "SCAN_HASH_BYTE",
  "SCAN_HASH_INT16", "SCAN_HASH_UINT16", "SCAN_HASH_INT32",
  "SCAN_HASH_UINT32", "SCAN_HASH_FLOAT32", "SCAN_HASH_FLOAT64", "'&'",
  "','", "'('", "':'", "')'", "'{'", "'}'", "'['", "']'", "$accept",
  "constraint_expr", "$@1", "projection", "proj_clause",
  "array_const_special_form", "arg_length_hint", "fast_byte_arg_list",
  "fast_byte_arg", "fast_int16_arg_list", "fast_int16_arg",
  "fast_uint16_arg_list", "fast_uint16_arg", "fast_int32_arg_list",
  "fast_int32_arg", "fast_uint32_arg_list", "fast_uint32_arg",
  "fast_float32_arg_list", "fast_float32_arg", "fast_float64_arg_list",
  "fast_float64_arg", "proj_function", "selection", "clause",
  "bool_function", "r_value", "r_value_list", "arg_list", "id_or_const",
  "array_projection_rvalue", "array_projection", "array_proj_clause",
  "name", "array_indices", "array_index", "rel_op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      38,    44,    40,    58,    41,   123,   125,    91,    93
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -66

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,   -57,    -5,    15,    24,    25,    34,    36,    64,   103,
     -57,    28,    12,    60,   -57,   -57,   -57,     6,    -2,    57,
      22,    22,    22,    22,    22,    22,    22,    74,   -57,    74,
      81,   -57,    -2,     9,    -2,   -57,    21,   -15,   -57,   -57,
     101,   102,   -57,   -57,    -2,   -57,   104,   105,   106,   107,
     108,   109,   110,   -11,   114,   -57,   -57,    96,   114,   -57,
      -2,     8,   111,   -57,    57,    57,   -57,    -2,   131,   132,
     133,   134,   136,   137,   138,    57,    74,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,    26,    10,   -57,   -57,   119,   -57,
     -57,    58,   -57,   -57,    59,   -57,   -57,    93,   -57,   -57,
      94,   -57,   -57,    95,   -57,   -57,    99,   -57,   -57,   100,
     -57,   120,   -57,    57,   -57,    27,   117,   -57,   131,   -57,
     132,   -57,   133,   -57,   134,   -57,   136,   -57,   137,   -57,
     138,   -57,     4,    33,    11,   -57,   -57,   -57,   -57,   -57,
     -57,   -57,   -57,   -57,   -57,   118,   121,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    65,    64,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     3,     7,    12,    10,    11,    60,     9,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,    64,    62,     0,    61,    66,    58,    57,    51,    53,
      55,     0,    49,    52,     0,    20,     0,     0,     0,     0,
       0,     0,     0,    57,     5,    43,    47,     0,     6,     8,
      63,     0,     0,    67,    56,     0,    42,    59,     0,     0,
       0,     0,     0,     0,     0,    56,     0,    74,    75,    76,
      77,    78,    79,    80,     0,     0,    68,    69,     0,    54,
      23,     0,    21,    26,     0,    24,    29,     0,    27,    32,
       0,    30,    35,     0,    33,    38,     0,    36,    41,     0,
      39,     0,    44,     0,    46,     0,     0,    50,     0,    13,
       0,    14,     0,    15,     0,    16,     0,    17,     0,    18,
       0,    19,    50,     0,     0,    70,    71,    22,    25,    28,
      31,    34,    37,    40,    45,     0,     0,    72,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -57,   -57,   -57,   122,   -57,     5,    87,   -57,    29,   -57,
      30,   -57,    31,   -57,    32,   -57,    35,   -57,    20,   -57,
      37,   -57,   125,    75,   -57,   -27,    42,   -56,   -57,   -57,
     -57,   -57,     3,   -26,   -33,   -57
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    27,    12,    13,    38,    46,    91,    92,    94,
      95,    97,    98,   100,   101,   103,   104,   106,   107,   109,
     110,    15,    54,    55,    56,    39,    40,    41,    42,    43,
      16,    17,    44,    34,    35,    84
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,    63,    57,    18,   -48,    14,    60,    64,    88,     1,
      31,    75,   -64,    61,   115,   145,   -64,    19,    67,   111,
      32,    62,   116,   146,   -48,    33,    45,    63,    28,    36,
      37,    85,    29,    18,    63,    14,    86,    20,    89,     3,
       4,     5,     6,     7,     8,     9,    21,    22,   -65,    57,
     134,   113,     1,     2,    65,   135,    23,   114,    24,   144,
      36,    37,     3,     4,     5,     6,     7,     8,     9,    10,
       3,     4,     5,     6,     7,     8,     9,    36,    53,   118,
     120,    30,   119,   121,     1,     2,    25,     3,     4,     5,
       6,     7,     8,     9,     3,     4,     5,     6,     7,     8,
       9,    77,    78,    79,    80,    81,    82,    83,    47,    48,
      49,    50,    51,    52,   122,   124,   126,   123,   125,   127,
     128,   130,    65,   129,   131,    26,    66,    68,    69,    70,
      71,    72,    73,    74,    76,    90,    93,    96,    99,    87,
     102,   105,   108,   117,   132,   136,   147,   137,   142,   148,
     138,   112,    59,   139,    58,   133,   140,     0,     0,     0,
       0,   141,     0,     0,     0,     0,     0,   143
};

static const yytype_int16 yycheck[] =
{
      27,    34,    29,     0,     0,     0,    32,    22,    64,     3,
       4,    22,    27,     4,     4,     4,    27,    22,    44,    75,
      17,    12,    12,    12,    20,    27,     4,    60,     0,     3,
       4,    23,    20,    30,    67,    30,    28,    22,    65,    13,
      14,    15,    16,    17,    18,    19,    22,    22,    27,    76,
      23,    25,     3,     4,    21,    28,    22,    84,    22,    26,
       3,     4,    13,    14,    15,    16,    17,    18,    19,    20,
      13,    14,    15,    16,    17,    18,    19,     3,     4,    21,
      21,    21,    24,    24,     3,     4,    22,    13,    14,    15,
      16,    17,    18,    19,    13,    14,    15,    16,    17,    18,
      19,     5,     6,     7,     8,     9,    10,    11,    21,    22,
      23,    24,    25,    26,    21,    21,    21,    24,    24,    24,
      21,    21,    21,    24,    24,    22,    24,    23,    23,    23,
      23,    23,    23,    23,    20,     4,     4,     4,     4,    28,
       4,     4,     4,    24,    24,    28,    28,   118,   128,    28,
     120,    76,    30,   122,    29,   113,   124,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,   130
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    13,    14,    15,    16,    17,    18,    19,
      20,    30,    32,    33,    34,    50,    59,    60,    61,    22,
      22,    22,    22,    22,    22,    22,    22,    31,     0,    20,
      21,     4,    61,    27,    62,    63,     3,     4,    34,    54,
      55,    56,    57,    58,    61,     4,    35,    35,    35,    35,
      35,    35,    35,     4,    51,    52,    53,    54,    51,    32,
      62,     4,    12,    63,    22,    21,    24,    62,    23,    23,
      23,    23,    23,    23,    23,    22,    20,     5,     6,     7,
       8,     9,    10,    11,    64,    23,    28,    28,    56,    54,
       4,    36,    37,     4,    38,    39,     4,    40,    41,     4,
      42,    43,     4,    44,    45,     4,    46,    47,     4,    48,
      49,    56,    52,    25,    54,     4,    12,    24,    21,    24,
      21,    24,    21,    24,    21,    24,    21,    24,    21,    24,
      21,    24,    24,    55,    23,    28,    28,    37,    39,    41,
      43,    45,    47,    49,    26,     4,    12,    28,    28
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    30,    31,    30,    30,    32,    32,    33,
      33,    33,    33,    34,    34,    34,    34,    34,    34,    34,
      35,    36,    36,    37,    38,    38,    39,    40,    40,    41,
      42,    42,    43,    44,    44,    45,    46,    46,    47,    48,
      48,    49,    50,    51,    51,    52,    52,    52,    53,    54,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      59,    60,    60,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    64,    64,    64,    64,    64,    64,
      64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     0,     3,     3,     1,     3,     1,
       1,     1,     1,     6,     6,     6,     6,     6,     6,     6,
       1,     1,     3,     1,     1,     3,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     1,     1,     3,     1,     1,
       3,     1,     4,     1,     3,     5,     3,     1,     4,     1,
       4,     1,     1,     1,     3,     1,     0,     1,     1,     2,
       1,     2,     2,     3,     1,     1,     1,     2,     3,     3,
       5,     5,     7,     7,     1,     1,     1,     1,     1,     1,
       1
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
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, ce_parser_arg *arg)
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, ce_parser_arg *arg)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, ce_parser_arg *arg)
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, ce_parser_arg *arg)
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
yyparse (ce_parser_arg *arg)
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
#line 241 "ce_expr.yy" /* yacc.c:1652  */
    {
             DBG(cerr << "Mark all variables" << endl);
		     DDS(arg)->mark_all(true);
		     (yyval.boolean) = true;
		 }
#line 1487 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 4:
#line 249 "ce_expr.yy" /* yacc.c:1652  */
    { DDS(arg)->mark_all(true); }
#line 1493 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 5:
#line 250 "ce_expr.yy" /* yacc.c:1652  */
    { 
		     (yyval.boolean) = (yyvsp[0].boolean);
		 }
#line 1501 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 6:
#line 254 "ce_expr.yy" /* yacc.c:1652  */
    {
		     (yyval.boolean) = (yyvsp[-2].boolean) && (yyvsp[0].boolean);
		 }
#line 1509 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 8:
#line 261 "ce_expr.yy" /* yacc.c:1652  */
    {
		     (yyval.boolean) = (yyvsp[-2].boolean) && (yyvsp[0].boolean);
		 }
#line 1517 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 9:
#line 267 "ce_expr.yy" /* yacc.c:1652  */
    {
		     BaseType *var = DDS(arg)->var((yyvsp[0].id));
		     if (var) {
			     DBG(cerr << "Marking " << (yyvsp[0].id) << endl);
			     (yyval.boolean) = DDS(arg)->mark((yyvsp[0].id), true);
			     DBG(cerr << "result: " << (yyval.boolean) << endl);
		     }
		     else {
			     no_such_ident(arg, (yyvsp[0].id), "identifier");
		     }
		}
#line 1533 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 10:
#line 279 "ce_expr.yy" /* yacc.c:1652  */
    {
		    (yyval.boolean) = (yyvsp[0].boolean);
		}
#line 1541 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 11:
#line 283 "ce_expr.yy" /* yacc.c:1652  */
    {
		    (yyval.boolean) = (yyvsp[0].boolean);
		}
#line 1549 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 12:
#line 287 "ce_expr.yy" /* yacc.c:1652  */
    {
            Array *array = dynamic_cast<Array*>((yyvsp[0].rval_ptr)->bvalue(*DDS(arg)));
            if (array) { 
                /* When the special form appears here (not as a function argument)
                set send_p so the data will be sent and add it to the DDS. This 
                streamlines testing (and is likely what is intended). */
                
                array->set_send_p(true);
                DDS(arg)->add_var_nocopy(array);
                
                return true;
            }
            else {
                ce_exprerror(arg, "Could not create the anonymous vector using the # special form");
                return false;
            }
        }
#line 1571 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 13:
#line 311 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = build_constant_array<dods_byte, Byte>((yyvsp[-1].byte_values), DDS(arg));
        }
#line 1579 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 14:
#line 317 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = build_constant_array<dods_int16, Int16>((yyvsp[-1].int16_values), DDS(arg));
        }
#line 1587 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 15:
#line 323 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = build_constant_array<dods_uint16, UInt16>((yyvsp[-1].uint16_values), DDS(arg));
        }
#line 1595 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 16:
#line 329 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = build_constant_array<dods_int32, Int32>((yyvsp[-1].int32_values), DDS(arg));
        }
#line 1603 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 17:
#line 335 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = build_constant_array<dods_uint32, UInt32>((yyvsp[-1].uint32_values), DDS(arg));
        }
#line 1611 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 18:
#line 341 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = build_constant_array<dods_float32, Float32>((yyvsp[-1].float32_values), DDS(arg));
        }
#line 1619 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 19:
#line 347 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = build_constant_array<dods_float64, Float64>((yyvsp[-1].float64_values), DDS(arg));
        }
#line 1627 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 20:
#line 356 "ce_expr.yy" /* yacc.c:1652  */
    {
              if (!check_int32((yyvsp[0].id)))
                  throw Error(malformed_expr, "$<type>(hint, value, ...) special form expected hint to be an integer");
                   
              arg_length_hint_value = atoi((yyvsp[0].id));
              (yyval.boolean) = true;
          }
#line 1639 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 21:
#line 367 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.byte_values) = make_fast_arg_list<byte_arg_list, dods_byte>(arg_length_hint_value, (yyvsp[0].byte_value));
          }
#line 1647 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 22:
#line 371 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.byte_values) = make_fast_arg_list<byte_arg_list, dods_byte>((yyvsp[-2].byte_values), (yyvsp[0].byte_value));
          }
#line 1655 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 23:
#line 378 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.byte_value) = strtol((yyvsp[0].id), 0, 0);
          }
#line 1663 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 24:
#line 385 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.int16_values) = make_fast_arg_list<int16_arg_list, dods_int16>(arg_length_hint_value, (yyvsp[0].int16_value));
          }
#line 1671 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 25:
#line 389 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.int16_values) = make_fast_arg_list<int16_arg_list, dods_int16>((yyvsp[-2].int16_values), (yyvsp[0].int16_value));
          }
#line 1679 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 26:
#line 396 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.int16_value) = strtol((yyvsp[0].id), 0, 0);
          }
#line 1687 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 27:
#line 403 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.uint16_values) = make_fast_arg_list<uint16_arg_list, dods_uint16>(arg_length_hint_value, (yyvsp[0].uint16_value));
          }
#line 1695 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 28:
#line 407 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.uint16_values) = make_fast_arg_list<uint16_arg_list, dods_uint16>((yyvsp[-2].uint16_values), (yyvsp[0].uint16_value));
          }
#line 1703 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 29:
#line 414 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.uint16_value) = strtoul((yyvsp[0].id), 0, 0);
          }
#line 1711 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 30:
#line 421 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.int32_values) = make_fast_arg_list<int32_arg_list, dods_int32>(arg_length_hint_value, (yyvsp[0].int32_value));
          }
#line 1719 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 31:
#line 425 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.int32_values) = make_fast_arg_list<int32_arg_list, dods_int32>((yyvsp[-2].int32_values), (yyvsp[0].int32_value));
          }
#line 1727 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 32:
#line 432 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.int32_value) = strtol((yyvsp[0].id), 0, 0);
          }
#line 1735 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 33:
#line 439 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.uint32_values) = make_fast_arg_list<uint32_arg_list, dods_uint32>(arg_length_hint_value, (yyvsp[0].uint32_value));
          }
#line 1743 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 34:
#line 443 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.uint32_values) = make_fast_arg_list<uint32_arg_list, dods_uint32>((yyvsp[-2].uint32_values), (yyvsp[0].uint32_value));
          }
#line 1751 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 35:
#line 450 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.uint32_value) = strtoul((yyvsp[0].id), 0, 0);
          }
#line 1759 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 36:
#line 457 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.float32_values) = make_fast_arg_list<float32_arg_list, dods_float32>(arg_length_hint_value, (yyvsp[0].float32_value));
          }
#line 1767 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 37:
#line 461 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.float32_values) = make_fast_arg_list<float32_arg_list, dods_float32>((yyvsp[-2].float32_values), (yyvsp[0].float32_value));
          }
#line 1775 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 38:
#line 468 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.float32_value) = strtof((yyvsp[0].id), 0);
          }
#line 1783 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 39:
#line 475 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.float64_values) = make_fast_arg_list<float64_arg_list, dods_float64>(arg_length_hint_value, (yyvsp[0].float64_value));
          }
#line 1791 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 40:
#line 479 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.float64_values) = make_fast_arg_list<float64_arg_list, dods_float64>((yyvsp[-2].float64_values), (yyvsp[0].float64_value));
          }
#line 1799 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 41:
#line 486 "ce_expr.yy" /* yacc.c:1652  */
    {
              (yyval.float64_value) = strtod((yyvsp[0].id), 0);
          }
#line 1807 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 42:
#line 493 "ce_expr.yy" /* yacc.c:1652  */
    {
		    proj_func p_f = 0;
		    btp_func f = 0;

		    if ((f = get_btp_function(*(EVALUATOR(arg)), (yyvsp[-3].id)))) {
			    EVALUATOR(arg)->append_clause(f, (yyvsp[-1].r_val_l_ptr));
			    (yyval.boolean) = true;
		    }
		    else if ((p_f = get_proj_function(*(EVALUATOR(arg)), (yyvsp[-3].id)))) { 
		        DDS &dds = dynamic_cast<DDS&>(*(DDS(arg)));
			    BaseType **args = build_btp_args( (yyvsp[-1].r_val_l_ptr), dds );
			    (*p_f)(((yyvsp[-1].r_val_l_ptr)) ? (yyvsp[-1].r_val_l_ptr)->size():0, args, dds, *(EVALUATOR(arg)));
			    delete[] args;
			    (yyval.boolean) = true;
		    }
		    else {
			    no_such_func(arg, (yyvsp[-3].id));
		    }
		}
#line 1831 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 44:
#line 516 "ce_expr.yy" /* yacc.c:1652  */
    {
		    (yyval.boolean) = (yyvsp[-2].boolean) && (yyvsp[0].boolean);
		}
#line 1839 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 45:
#line 522 "ce_expr.yy" /* yacc.c:1652  */
    {
		    if ((yyvsp[-4].rval_ptr)) {
			EVALUATOR(arg)->append_clause((yyvsp[-3].op), (yyvsp[-4].rval_ptr), (yyvsp[-1].r_val_l_ptr));
			(yyval.boolean) = true;
		    }
		    else
			(yyval.boolean) = false;
		}
#line 1852 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 46:
#line 531 "ce_expr.yy" /* yacc.c:1652  */
    {
		    if ((yyvsp[-2].rval_ptr)) {
			rvalue_list *rv = new rvalue_list;
			rv->push_back((yyvsp[0].rval_ptr));
			EVALUATOR(arg)->append_clause((yyvsp[-1].op), (yyvsp[-2].rval_ptr), rv);
			(yyval.boolean) = true;
		    }
		    else
			(yyval.boolean) = false;
		}
#line 1867 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 47:
#line 542 "ce_expr.yy" /* yacc.c:1652  */
    {
		    (yyval.boolean) = (yyvsp[0].boolean);
		}
#line 1875 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 48:
#line 549 "ce_expr.yy" /* yacc.c:1652  */
    {
		   bool_func b_func = get_function((*EVALUATOR(arg)), (yyvsp[-3].id));
		   if (!b_func) {
		       no_such_func(arg, (yyvsp[-3].id));
		   }
		   else {
		       EVALUATOR(arg)->append_clause(b_func, (yyvsp[-1].r_val_l_ptr));
		       (yyval.boolean) = true;
		   }
	       }
#line 1890 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 50:
#line 564 "ce_expr.yy" /* yacc.c:1652  */
    {
		    btp_func func = get_btp_function((*EVALUATOR(arg)), (yyvsp[-3].id));
		    if (func) {
			    (yyval.rval_ptr) = new rvalue(func, (yyvsp[-1].r_val_l_ptr));
		    } 
		    else { 
			    no_such_func(arg, (yyvsp[-3].id));
		    }
		}
#line 1904 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 51:
#line 574 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = (yyvsp[0].rval_ptr);
        }
#line 1912 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 52:
#line 578 "ce_expr.yy" /* yacc.c:1652  */
    {
            (yyval.rval_ptr) = (yyvsp[0].rval_ptr);
        }
#line 1920 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 53:
#line 584 "ce_expr.yy" /* yacc.c:1652  */
    {
		    if ((yyvsp[0].rval_ptr))
			    (yyval.r_val_l_ptr) = make_rvalue_list((yyvsp[0].rval_ptr));
		    else
			    (yyval.r_val_l_ptr) = 0;
		}
#line 1931 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 54:
#line 591 "ce_expr.yy" /* yacc.c:1652  */
    {
		    if ((yyvsp[-2].r_val_l_ptr) && (yyvsp[0].rval_ptr))
			    (yyval.r_val_l_ptr) = append_rvalue_list((yyvsp[-2].r_val_l_ptr), (yyvsp[0].rval_ptr));
		    else
			    (yyval.r_val_l_ptr) = 0;
		}
#line 1942 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 55:
#line 600 "ce_expr.yy" /* yacc.c:1652  */
    {  
		      (yyval.r_val_l_ptr) = (yyvsp[0].r_val_l_ptr);
	      }
#line 1950 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 56:
#line 604 "ce_expr.yy" /* yacc.c:1652  */
    { 
		      (yyval.r_val_l_ptr) = 0; 
	      }
#line 1958 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 57:
#line 610 "ce_expr.yy" /* yacc.c:1652  */
    { 
		    BaseType *btp = DDS(arg)->var(www2id((yyvsp[0].id)));
		    if (btp) {
                btp->set_in_selection(true);
                (yyval.rval_ptr) = new rvalue(btp);
		    }
		    else {
			    value new_val;
			    string name_tmp;
			    if (check_int32((yyvsp[0].id))) {
			        new_val.type = dods_int32_c;
			        new_val.v.i = atoi((yyvsp[0].id));
			    }
			    else if (check_uint32((yyvsp[0].id))) {
			        new_val.type = dods_uint32_c;
			        new_val.v.ui = atoi((yyvsp[0].id));
			    }
			    else if (check_float64((yyvsp[0].id))) {
			        new_val.type = dods_float64_c;
			        new_val.v.f = atof((yyvsp[0].id));
			    }
			    else {
			        new_val.type = dods_str_c;
				// The 'new' here was used because www2id() modifies the
				// std::string arg in place but 'value' holds a string*.
			        // new_val.v.s = new string(www2id($1));
				// I replcaed this with a local tmp to avoid the dynamic
				// allocation and the need to call delete. This was part of
				// the fix for ticket 2240. jhrg 7/30/14
				name_tmp = (yyvsp[0].id);
				name_tmp = www2id(name_tmp);
				new_val.v.s = &name_tmp;
			    }
			    BaseType *btp = make_variable((*EVALUATOR(arg)), new_val);
			    (yyval.rval_ptr) = new rvalue(btp);
		    }
		}
#line 2000 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 58:
#line 648 "ce_expr.yy" /* yacc.c:1652  */
    {
                    if ((yyvsp[0].val).type != dods_str_c || (yyvsp[0].val).v.s == 0 || (yyvsp[0].val).v.s->empty())
                        ce_exprerror(arg, "Malformed string", "");
                        
                    BaseType *var = DDS(arg)->var(www2id(*((yyvsp[0].val).v.s)));
                    if (var) {
                        (yyval.rval_ptr) = new rvalue(var);
                    }
                    else {
                        var = make_variable((*EVALUATOR(arg)), (yyvsp[0].val)); 
                        (yyval.rval_ptr) = new rvalue(var);
                    }
		    // When the scanner (ce_expr.lex) returns the SCAN_STR token type
		    // it makes a local copy of the string in a new std::string object
		    // that we must delete. Fix for a bug report by Aron.Bartle@mechdyne.com
		    // See ticket 2240. jhrg 7/30/14
		    delete (yyvsp[0].val).v.s;
                }
#line 2023 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 59:
#line 672 "ce_expr.yy" /* yacc.c:1652  */
    {
                    if (!bracket_projection((*DDS(arg)), (yyvsp[-1].id), (yyvsp[0].int_ll_ptr)))
                      no_such_ident(arg, (yyvsp[-1].id), "array, grid or sequence");
                    
                    // strncpy($$, $1, ID_MAX-1);
                    // $$[ID_MAX-1] = '\0';

                    DDS(arg)->mark((yyvsp[-1].id), true);
                    (yyval.rval_ptr) = new rvalue(DDS(arg)->var((yyvsp[-1].id)));
                }
#line 2038 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 60:
#line 685 "ce_expr.yy" /* yacc.c:1652  */
    {
                    (yyval.boolean) = (*DDS(arg)).mark((yyvsp[0].id), true);
                }
#line 2046 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 61:
#line 691 "ce_expr.yy" /* yacc.c:1652  */
    {
                    //string name = www2id($1);
                    if (!bracket_projection((*DDS(arg)), (yyvsp[-1].id), (yyvsp[0].int_ll_ptr)))
                      no_such_ident(arg, (yyvsp[-1].id), "array, grid or sequence");
                    
                    strncpy((yyval.id), (yyvsp[-1].id), ID_MAX-1);
                    (yyval.id)[ID_MAX-1] = '\0';
                }
#line 2059 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 62:
#line 700 "ce_expr.yy" /* yacc.c:1652  */
    {
                    string name = string((yyvsp[-1].id)) + string((yyvsp[0].id));
                    strncpy((yyval.id), name.c_str(), ID_MAX-1);
                    (yyval.id)[ID_MAX-1] = '\0';
                }
#line 2069 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 63:
#line 706 "ce_expr.yy" /* yacc.c:1652  */
    {
                    string name = string((yyvsp[-2].id)) + string((yyvsp[-1].id));
                    if (!bracket_projection((*DDS(arg)), name.c_str(), (yyvsp[0].int_ll_ptr)))
                      no_such_ident(arg, name.c_str(), "array, grid or sequence");

                    strncpy((yyval.id), name.c_str(), ID_MAX-1);
                    (yyval.id)[ID_MAX-1] = '\0';
                }
#line 2082 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 64:
#line 717 "ce_expr.yy" /* yacc.c:1652  */
    { 
                    strncpy((yyval.id), www2id((yyvsp[0].id)).c_str(), ID_MAX-1);
                    (yyval.id)[ID_MAX-1] = '\0';
                }
#line 2091 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 65:
#line 722 "ce_expr.yy" /* yacc.c:1652  */
    {
                    if ((yyvsp[0].val).type != dods_str_c || (yyvsp[0].val).v.s == 0 || (yyvsp[0].val).v.s->empty())
                        ce_exprerror(arg, "Malformed string", "");
                        
                    strncpy((yyval.id), www2id(*((yyvsp[0].val).v.s)).c_str(), ID_MAX-1);
		    // See comment about regarding the scanner's behavior WRT SCAN_STR.
		    // jhrg 7/30/14
                    delete (yyvsp[0].val).v.s;

                    (yyval.id)[ID_MAX-1] = '\0';
                }
#line 2107 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 66:
#line 736 "ce_expr.yy" /* yacc.c:1652  */
    {
		    (yyval.int_ll_ptr) = make_array_indices((yyvsp[0].int_l_ptr));
		}
#line 2115 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 67:
#line 740 "ce_expr.yy" /* yacc.c:1652  */
    {
		    (yyval.int_ll_ptr) = append_array_index((yyvsp[-1].int_ll_ptr), (yyvsp[0].int_l_ptr));
		}
#line 2123 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 68:
#line 754 "ce_expr.yy" /* yacc.c:1652  */
    {
    if (!check_uint32((yyvsp[-1].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-1].id)) + "' is not a valid array index.");
    value i;
    i.type = dods_uint32_c;
    i.v.i = atoi((yyvsp[-1].id));
    (yyval.int_l_ptr) = make_array_index(i);
}
#line 2136 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 69:
#line 763 "ce_expr.yy" /* yacc.c:1652  */
    {
    value i;
    i.type = dods_int32_c;
    i.v.i =-1;
    (yyval.int_l_ptr) = make_array_index(i);
}
#line 2147 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 70:
#line 770 "ce_expr.yy" /* yacc.c:1652  */
    {
    if (!check_uint32((yyvsp[-3].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-3].id)) + "' is not a valid array index.");
    if (!check_uint32((yyvsp[-1].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-1].id)) + "' is not a valid array index.");
    value i,j;
    i.type = j.type = dods_uint32_c;
    i.v.i = atoi((yyvsp[-3].id));
    j.v.i = atoi((yyvsp[-1].id));
    (yyval.int_l_ptr) = make_array_index(i, j);
}
#line 2163 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 71:
#line 782 "ce_expr.yy" /* yacc.c:1652  */
    {
    if (!check_uint32((yyvsp[-3].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-3].id)) + "' is not a valid array index.");
    value i,j;
    i.type = dods_uint32_c;
    j.type = dods_int32_c;  /* signed */
    i.v.i = atoi((yyvsp[-3].id));
    j.v.i = -1;
    (yyval.int_l_ptr) = make_array_index(i, j);
}
#line 2178 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 72:
#line 793 "ce_expr.yy" /* yacc.c:1652  */
    {
    if (!check_uint32((yyvsp[-5].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-5].id)) + "' is not a valid array index.");
    if (!check_uint32((yyvsp[-3].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-3].id)) + "' is not a valid array index.");
    if (!check_uint32((yyvsp[-1].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-1].id)) + "' is not a valid array index.");
    value i, j, k;
    i.type = j.type = k.type = dods_uint32_c;
    i.v.i = atoi((yyvsp[-5].id));
    j.v.i = atoi((yyvsp[-3].id));
    k.v.i = atoi((yyvsp[-1].id));
    (yyval.int_l_ptr) = make_array_index(i, j, k);
}
#line 2197 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;

  case 73:
#line 808 "ce_expr.yy" /* yacc.c:1652  */
    {
    if (!check_uint32((yyvsp[-5].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-5].id)) + "' is not a valid array index.");
    if (!check_uint32((yyvsp[-3].id)))
        throw Error(malformed_expr, "The word `" + string((yyvsp[-3].id)) + "' is not a valid array index.");
    value i, j, k;
    i.type = j.type = dods_uint32_c;
    k.type = dods_int32_c;
    i.v.i = atoi((yyvsp[-5].id));
    j.v.i = atoi((yyvsp[-3].id));
    k.v.i = -1;
    (yyval.int_l_ptr) = make_array_index(i, j, k);
}
#line 2215 "ce_expr.tab.cc" /* yacc.c:1652  */
    break;


#line 2219 "ce_expr.tab.cc" /* yacc.c:1652  */
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
#line 832 "ce_expr.yy" /* yacc.c:1918  */


// All these error reporting function now throw instances of Error. The expr
// parser no longer returns an error code to indicate and error. 2/16/2000
// jhrg.

void
ce_exprerror(ce_parser_arg *, const string &s)
{
    string msg = "Constraint expression parse error: " +s;
    throw Error(malformed_expr, msg);
}

void ce_exprerror(ce_parser_arg *, const string &s, const string &s2)
{
    string msg = "Constraint expression parse error: " + s + ": " + s2;
    throw Error(malformed_expr, msg);    
}

void no_such_ident(ce_parser_arg *arg, const string &name, const string &word)
{
#if 0
    string msg = "No such " + word + " in dataset";
    ce_exprerror(arg, msg , name);
#endif
    string msg = "Constraint expression parse error: No such " + word + " in dataset: " + name;
    throw Error(no_such_variable, msg);    
    
}

void no_such_func(ce_parser_arg *arg, const string &name)
{
    ce_exprerror(arg, "Not a registered function", name);
}

/* If we're calling this, assume var is not a Sequence. But assume that the
 name contains a dot and it's a separator. Look for the rightmost dot and
 then look to see if the name to the left is a sequence. Return a pointer
 to the sequence if it is otherwise return null. Uses tail-recursion to
 'walk' back from right to left looking at each dot. This way the sequence
 will be found even if there are structures between the field and the
 Sequence. */
static Sequence *
parent_is_sequence(DDS &table, const string &n)
{
    string::size_type dotpos = n.find_last_of('.');
    if (dotpos == string::npos)
        return 0;

    string s = n.substr(0, dotpos);

    // If the thing returned by table.var is not a Sequence, this cast
    // will yield null.
    Sequence *seq = dynamic_cast<Sequence*> (table.var(s));
    if (seq)
        return seq;
    else
        return parent_is_sequence(table, s);
}

bool bracket_projection(DDS &table, const char *name, int_list_list *indices)
{
    BaseType *var = table.var(name);
    Sequence *seq; // used in last else-if clause
    bool ret_val = true;
    try {
	    if (!var) {
	        ret_val = false;
	    }
	    else if (is_array_t(var)) {
	        /* calls to set_send_p should be replaced with
	         calls to DDS::mark so that arrays of Structures,
	         etc. will be processed correctly when individual
	         elements are projected using short names.
	         9/1/98 jhrg */
	        /* var->set_send_p(true); */
	        //table.mark(name, true);
	        // We don't call mark() here for an array. Instead it is called from
	        // within the parser. jhrg 10/10/08
	        process_array_indices(var, indices); // throws on error
	    }
	    else if (is_grid_t(var)) {
	        process_grid_indices(var, indices);
	        table.mark(name, true);
	    }
	    else if (is_sequence_t(var)) {
	        table.mark(name, true);
	        process_sequence_indices(var, indices);
	    }
	    else if ((seq = parent_is_sequence(table, name))) {
	        process_sequence_indices(seq, indices);
	        table.mark(name, true);
	    }
	    else {
	        ret_val = false;
	    }
	    delete_array_indices(indices);
    }
    catch(...) {
	    delete_array_indices(indices);
	    throw;
    }
    return ret_val;
}

// Given three values (I1, I2, I3), all of which must be integers, build an
// int_list which contains those values.
// 
// Note that we added support for * in the rightmost position of an index
// (i.e., [*], [n:*], [n:m:*]) and indicate that star using -1 as an index value.
// Bescause of this change, the test for the type of the rightmost value in
// the index subexpr was changed to include signed int.
// jhrg 12/20/12
//
// Returns: A pointer to an int_list of three integers or NULL if any of the
// values are not integers.

int_list *
make_array_index(value &i1, value &i2, value &i3)
{
    if (i1.type != dods_uint32_c || i2.type != dods_uint32_c || (i3.type != dods_uint32_c && i3.type != dods_int32_c))
        return (int_list *) 0;

    int_list *index = new int_list;

    index->push_back((int) i1.v.i);
    index->push_back((int) i2.v.i);
    index->push_back((int) i3.v.i);

    DBG(cout << "index: ");
    DBG(copy(index->begin(), index->end(), ostream_iterator<int>(cerr, " ")));
    DBG(cerr << endl);

    return index;
}

int_list *
make_array_index(value &i1, value &i2)
{
    if (i1.type != dods_uint32_c || (i2.type != dods_uint32_c && i2.type != dods_int32_c))
	return (int_list *) 0;

    int_list *index = new int_list;

    index->push_back((int) i1.v.i);
    index->push_back(1);
    index->push_back((int) i2.v.i);

    DBG(cout << "index: ");
    DBG(copy(index->begin(), index->end(), ostream_iterator<int>(cerr, " ")));
    DBG(cerr << endl);

    return index;
}

int_list *
make_array_index(value &i1)
{
    if (i1.type != dods_uint32_c && i1.type != dods_int32_c)
	return (int_list *) 0;

    int_list *index = new int_list;

    // When the CE is Array[*] that means all of the elements, but the value
    // of i1 will be -1. Make the projection triple be 0:1:-1 which is a 
    // pattern that libdap::Array will recognize.
    if (i1.v.i == -1)
        index->push_back(0);
    else
        index->push_back((int) i1.v.i);
    index->push_back(1);
    index->push_back((int) i1.v.i);

    DBG(cout << "index: ");
    DBG(copy(index->begin(), index->end(), ostream_iterator<int>(cerr, " ")));
    DBG(cerr << endl);

    return index;
}

int_list_list *
make_array_indices(int_list *index)
{
    int_list_list *indices = new int_list_list;

    DBG(cout << "index: ");
    DBG(copy(index->begin(), index->end(), ostream_iterator<int>(cerr, " ")));
    DBG(cerr << endl);

    assert(index);
    indices->push_back(index);

    return indices;
}

int_list_list *
append_array_index(int_list_list *indices, int_list *index)
{
    assert(indices);
    assert(index);

    indices->push_back(index);

    return indices;
}

// Delete an array indices list. 

void delete_array_indices(int_list_list *indices)
{
    assert(indices);

    for (int_list_citer i = indices->begin(); i != indices->end(); i++) {
	int_list *il = *i;
	assert(il);
	delete il;
    }

    delete indices;
}

bool is_array_t(BaseType *variable)
{
    assert(variable);

    if (variable->type() != dods_array_c)
	return false;
    else
	return true;
}

bool is_grid_t(BaseType *variable)
{
    assert(variable);

    if (variable->type() != dods_grid_c)
	return false;
    else
	return true;
}

bool is_sequence_t(BaseType *variable)
{
    assert(variable);

    if (variable->type() != dods_sequence_c)
	return false;
    else
	return true;
}

void process_array_indices(BaseType *variable, int_list_list *indices)
{
    assert(variable);

    Array *a = dynamic_cast<Array *>(variable); // replace with dynamic cast
    if (!a)
        throw Error(malformed_expr,
		    string("The constraint expression evaluator expected an array; ") + variable->name() + " is not an array.");

    if (a->dimensions(true) != (unsigned) indices->size())
        throw Error(malformed_expr,
		    string("Error: The number of dimensions in the constraint for ") + variable->name()
                    + " must match the number in the array.");

    DBG(cerr << "Before applying projection to array:" << endl);
    DBG(a->print_decl(cerr, "", true, false, true));

    assert(indices);
    
    int_list_citer p = indices->begin();
    Array::Dim_iter r = a->dim_begin();
    for (; p != indices->end() && r != a->dim_end(); p++, r++) {
        int_list *index = *p;
        assert(index);

        int_citer q = index->begin();
        assert(q != index->end());
        int start = *q;

        q++;
        int stride = *q;

        q++;
        int stop = *q;

        q++;
        if (q != index->end())
            throw Error(malformed_expr, string("Too many values in index list for ") + a->name() + ".");

        DBG(cerr << "process_array_indices: Setting constraint on " 
            << a->name() << "[" << start << ":" << stop << "]"
            << endl);

        // It's possible that an array will appear more than once in a CE
        // (for example, if an array of structures is constrained so that
        // only two fields are projected and there's an associated hyperslab).
        // However, in this case the two hyperslabs must be equal; test for
        // that here.
        //
        // We added '*' to mean 'the last element' in the array and use an index of -1
        // to indicate that. If 'stop' is -1, don't test it here because dimension_stop()
        // won't be -1 but the actual ending index of the array. jhrg 12/20/12

        if (a->send_p() && (a->dimension_start(r, true) != start || (a->dimension_stop(r, true) != stop && stop != -1)
                            || a->dimension_stride(r, true) != stride))
            throw Error(malformed_expr,
                    string("The Array was already projected differently in the constraint expression: ") + a->name() + ".");

        a->add_constraint(r, start, stride, stop);

        DBG(cerr << "Set Constraint: " << a->dimension_size(r, true) << endl);
    }

    DBG(cerr << "After applying projection to array:" << endl);
    DBG(a->print_decl(cerr, "", true, false, true));


    if (p != indices->end() && r == a->dim_end())
        throw Error(malformed_expr, string("Too many indices in constraint for ") + a->name() + ".");
}

void process_grid_indices(BaseType *variable, int_list_list *indices)
{
    assert(variable);
    assert(variable->type() == dods_grid_c);
    Grid *g = dynamic_cast<Grid *>(variable);
    if (!g)
        throw Error(unknown_error, "Expected a Grid variable");

    Array *a = g->get_array();

    if (a->dimensions(true) != (unsigned) indices->size())
        throw Error(malformed_expr,
		    string("Error: The number of dimensions in the constraint for ") + variable->name()
		    + " must match the number in the grid.");

    // First do the constraints on the ARRAY in the grid.
    process_array_indices(g->array_var(), indices);

    // Now process the maps.
    Grid::Map_iter r = g->map_begin();

    // Suppress all maps by default.
    for (; r != g->map_end(); r++) {
        (*r)->set_send_p(false);
    }

    // Add specified maps to the current projection.
    assert(indices);
    int_list_citer p = indices->begin();
    r = g->map_begin();
    for (; p != indices->end() && r != g->map_end(); p++, r++) {
        int_list *index = *p;
        assert(index);

        int_citer q = index->begin();
        assert(q != index->end());
        int start = *q;

        q++;
        int stride = *q;

        q++;
        int stop = *q;

        BaseType *btp = *r;
        assert(btp);
        assert(btp->type() == dods_array_c);
        Array *a = (Array *) btp;
        a->set_send_p(true);
        a->reset_constraint();

        q++;
        if (q != index->end()) {
            throw Error(malformed_expr, string("Too many values in index list for ") + a->name() + ".");
        }

        DBG(cerr << "process_grid_indices: Setting constraint on "
            << a->name() << "[" << start << ":"
            << stop << "]" << endl);
    
        Array::Dim_iter si = a->dim_begin();
        a->add_constraint(si, start, stride, stop);

    }

    DBG(cout << "Grid Constraint: ";
	for (Array::Dim_iter dp = ((Array *) g->array_var())->dim_begin();
	     dp != ((Array *) g->array_var())->dim_end(); dp++)
	    cout << ((Array *) g->array_var())->dimension_size(dp, true) << " ";
	    cout << endl
	);

    if (p != indices->end() && r == g->map_end()) {
        throw Error(malformed_expr,
		    string("Too many indices in constraint for ") + (*r)->name() + ".");
    }
}

void process_sequence_indices(BaseType *variable, int_list_list *indices)
{
    assert(variable);
    assert(variable->type() == dods_sequence_c);
    Sequence *s = dynamic_cast<Sequence *> (variable);
    if (!s)
        throw Error(malformed_expr, "Expected a Sequence variable");

    // Add specified maps to the current projection.
    assert(indices);
    for (int_list_citer p = indices->begin(); p != indices->end(); p++) {
        int_list *index = *p;
        assert(index);

        int_citer q = index->begin();
        assert(q != index->end());
        int start = *q;

        q++;
        int stride = *q;

        q++;
        int stop = *q;

        q++;
        if (q != index->end()) {
            throw Error(malformed_expr, string("Too many values in index list for ") + s->name() + ".");
        }

        s->set_row_number_constraint(start, stop, stride);
    }
}

// Given a value, wrap it up in a BaseType and return a pointer to the same.

BaseType *
make_variable(ConstraintEvaluator &eval, const value &val)
{
    BaseType *var;
    switch (val.type) {
    case dods_int32_c: {
        var = new Int32("dummy");
        var->val2buf((void *) &val.v.i);
        break;
    }

    case dods_uint32_c: {
        var = new UInt32("dummy");
        var->val2buf((void *) &val.v.i);
        break;
    }

    case dods_float64_c: {
        var = new Float64("dummy");
        var->val2buf((void *) &val.v.f);
        break;
    }

    case dods_str_c: {
        var = new Str("dummy");
        var->val2buf((void *) val.v.s);
        break;
    }

    default:
        var = (BaseType *) 0;
        return var;
    }

    var->set_read_p(true); // ...so the evaluator will know it has data
    eval.append_constant(var);

    return var;
}

// Given a string (passed in VAL), consult the DDS CE function lookup table
// to see if a function by that name exists. 
// NB: function arguments are type-checked at run-time.
//
// Returns: A pointer to the function or NULL if not such function exists.

bool_func get_function(const ConstraintEvaluator &eval, const char *name)
{
    bool_func f;

    if (eval.find_function(name, &f))
        return f;
    else
        return 0;
}

btp_func get_btp_function(const ConstraintEvaluator &eval, const char *name)
{
    btp_func f;

    if (eval.find_function(name, &f))
        return f;
    else
        return 0;
}

proj_func get_proj_function(const ConstraintEvaluator &eval, const char *name)
{
    proj_func f;

    if (eval.find_function(name, &f))
        return f;
    else
        return 0;
}

template<class arg_type_list, class arg_type>
arg_type_list
make_fast_arg_list(unsigned long vector_size_hint, arg_type value)
{
    arg_type_list args = new std::vector<arg_type>;
    
    if (vector_size_hint > 0) args->reserve(vector_size_hint);
    
    args->push_back(value);
    return args;
}

template<class arg_type_list, class arg_type>
arg_type_list
make_fast_arg_list(arg_type_list values, arg_type value)
{
    values->push_back(value);
    return values;
}

template<class t, class T>
rvalue *build_constant_array(vector<t> *values, DDS *dds)
{
    //vector<t> *values = $5;
            
    T i("");
    Array *array = new Array("", &i);
    array->append_dim(values->size());
    
    // TODO Make set_value_nocopy() methods so that values' pointers can be copied
    // instead of allocating memory twice. jhrg 7/5/13
            
    array->set_value(*values, values->size());
    delete values;
    array->set_read_p(true);
            
    static unsigned long counter = 1;
    string name;
    do {
        name = "g" + long_to_string(counter++);
    } while (dds->var(name));
    array->set_name(name);
            
    return new rvalue(array);
}

