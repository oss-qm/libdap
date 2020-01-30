// A Bison parser, made by GNU Bison 3.3.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "d4_function_parser.tab.hh"


// Unqualified %code blocks.
#line 77 "d4_function_parser.yy" // lalr1.cc:435

    #include "BaseType.h"
    #include "DMR.h"
    #include "D4RValue.h"
    #include "ServerFunctionsList.h"
   
    #include "parser-util.h"

    /* include for all driver functions */
    #include "D4FunctionEvaluator.h"

    using namespace libdap ;
    
    /* this is silly, but I can't figure out a way around it */
    static int yylex(libdap::D4FunctionParser::semantic_type *yylval,
                     libdap::location *loc,
                     libdap::D4FunctionScanner  &scanner,
                     libdap::D4FunctionEvaluator   &evaluator);

#line 65 "d4_function_parser.tab.cc" // lalr1.cc:435


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 34 "d4_function_parser.yy" // lalr1.cc:510
namespace libdap {
#line 160 "d4_function_parser.tab.cc" // lalr1.cc:510

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  D4FunctionParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  D4FunctionParser::D4FunctionParser (D4FunctionScanner  &scanner_yyarg, D4FunctionEvaluator  &evaluator_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      evaluator (evaluator_yyarg)
  {}

  D4FunctionParser::~D4FunctionParser ()
  {}

  D4FunctionParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  D4FunctionParser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 7: // "function name"
      case 44: // fname
        value.move< D4Function > (std::move (that.value));
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        value.move< D4RValue* > (std::move (that.value));
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        value.move< D4RValueList* > (std::move (that.value));
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        value.move< std::string > (std::move (that.value));
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        value.move< std::vector<dods_byte>* > (std::move (that.value));
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        value.move< std::vector<dods_float32>* > (std::move (that.value));
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        value.move< std::vector<dods_float64>* > (std::move (that.value));
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        value.move< std::vector<dods_int16>* > (std::move (that.value));
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        value.move< std::vector<dods_int32>* > (std::move (that.value));
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        value.move< std::vector<dods_int64>* > (std::move (that.value));
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        value.move< std::vector<dods_int8>* > (std::move (that.value));
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        value.move< std::vector<dods_uint16>* > (std::move (that.value));
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        value.move< std::vector<dods_uint32>* > (std::move (that.value));
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        value.move< std::vector<dods_uint64>* > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  D4FunctionParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 7: // "function name"
      case 44: // fname
        value.copy< D4Function > (YY_MOVE (that.value));
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        value.copy< D4RValue* > (YY_MOVE (that.value));
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        value.copy< D4RValueList* > (YY_MOVE (that.value));
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        value.copy< std::vector<dods_byte>* > (YY_MOVE (that.value));
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        value.copy< std::vector<dods_float32>* > (YY_MOVE (that.value));
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        value.copy< std::vector<dods_float64>* > (YY_MOVE (that.value));
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        value.copy< std::vector<dods_int16>* > (YY_MOVE (that.value));
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        value.copy< std::vector<dods_int32>* > (YY_MOVE (that.value));
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        value.copy< std::vector<dods_int64>* > (YY_MOVE (that.value));
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        value.copy< std::vector<dods_int8>* > (YY_MOVE (that.value));
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        value.copy< std::vector<dods_uint16>* > (YY_MOVE (that.value));
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        value.copy< std::vector<dods_uint32>* > (YY_MOVE (that.value));
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        value.copy< std::vector<dods_uint64>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  D4FunctionParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  D4FunctionParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 7: // "function name"
      case 44: // fname
        value.move< D4Function > (YY_MOVE (s.value));
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        value.move< D4RValue* > (YY_MOVE (s.value));
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        value.move< D4RValueList* > (YY_MOVE (s.value));
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        value.move< std::vector<dods_byte>* > (YY_MOVE (s.value));
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        value.move< std::vector<dods_float32>* > (YY_MOVE (s.value));
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        value.move< std::vector<dods_float64>* > (YY_MOVE (s.value));
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        value.move< std::vector<dods_int16>* > (YY_MOVE (s.value));
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        value.move< std::vector<dods_int32>* > (YY_MOVE (s.value));
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        value.move< std::vector<dods_int64>* > (YY_MOVE (s.value));
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        value.move< std::vector<dods_int8>* > (YY_MOVE (s.value));
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        value.move< std::vector<dods_uint16>* > (YY_MOVE (s.value));
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        value.move< std::vector<dods_uint32>* > (YY_MOVE (s.value));
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        value.move< std::vector<dods_uint64>* > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  D4FunctionParser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  D4FunctionParser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  D4FunctionParser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  D4FunctionParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  D4FunctionParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  D4FunctionParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  D4FunctionParser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  D4FunctionParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  D4FunctionParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  D4FunctionParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  D4FunctionParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  D4FunctionParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  D4FunctionParser::symbol_number_type
  D4FunctionParser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  D4FunctionParser::stack_symbol_type::stack_symbol_type ()
  {}

  D4FunctionParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 7: // "function name"
      case 44: // fname
        value.YY_MOVE_OR_COPY< D4Function > (YY_MOVE (that.value));
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        value.YY_MOVE_OR_COPY< D4RValue* > (YY_MOVE (that.value));
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        value.YY_MOVE_OR_COPY< D4RValueList* > (YY_MOVE (that.value));
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_byte>* > (YY_MOVE (that.value));
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_float32>* > (YY_MOVE (that.value));
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_float64>* > (YY_MOVE (that.value));
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_int16>* > (YY_MOVE (that.value));
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_int32>* > (YY_MOVE (that.value));
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_int64>* > (YY_MOVE (that.value));
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_int8>* > (YY_MOVE (that.value));
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_uint16>* > (YY_MOVE (that.value));
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_uint32>* > (YY_MOVE (that.value));
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        value.YY_MOVE_OR_COPY< std::vector<dods_uint64>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  D4FunctionParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 7: // "function name"
      case 44: // fname
        value.move< D4Function > (YY_MOVE (that.value));
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        value.move< D4RValue* > (YY_MOVE (that.value));
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        value.move< D4RValueList* > (YY_MOVE (that.value));
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        value.move< std::vector<dods_byte>* > (YY_MOVE (that.value));
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        value.move< std::vector<dods_float32>* > (YY_MOVE (that.value));
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        value.move< std::vector<dods_float64>* > (YY_MOVE (that.value));
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        value.move< std::vector<dods_int16>* > (YY_MOVE (that.value));
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        value.move< std::vector<dods_int32>* > (YY_MOVE (that.value));
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        value.move< std::vector<dods_int64>* > (YY_MOVE (that.value));
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        value.move< std::vector<dods_int8>* > (YY_MOVE (that.value));
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        value.move< std::vector<dods_uint16>* > (YY_MOVE (that.value));
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        value.move< std::vector<dods_uint32>* > (YY_MOVE (that.value));
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        value.move< std::vector<dods_uint64>* > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  D4FunctionParser::stack_symbol_type&
  D4FunctionParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 7: // "function name"
      case 44: // fname
        value.move< D4Function > (that.value);
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        value.move< D4RValue* > (that.value);
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        value.move< D4RValueList* > (that.value);
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        value.move< std::string > (that.value);
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        value.move< std::vector<dods_byte>* > (that.value);
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        value.move< std::vector<dods_float32>* > (that.value);
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        value.move< std::vector<dods_float64>* > (that.value);
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        value.move< std::vector<dods_int16>* > (that.value);
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        value.move< std::vector<dods_int32>* > (that.value);
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        value.move< std::vector<dods_int64>* > (that.value);
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        value.move< std::vector<dods_int8>* > (that.value);
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        value.move< std::vector<dods_uint16>* > (that.value);
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        value.move< std::vector<dods_uint32>* > (that.value);
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        value.move< std::vector<dods_uint64>* > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  D4FunctionParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  D4FunctionParser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  D4FunctionParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  D4FunctionParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  D4FunctionParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  D4FunctionParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  D4FunctionParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  D4FunctionParser::debug_level_type
  D4FunctionParser::debug_level () const
  {
    return yydebug_;
  }

  void
  D4FunctionParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  D4FunctionParser::state_type
  D4FunctionParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  D4FunctionParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  D4FunctionParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  D4FunctionParser::operator() ()
  {
    return parse ();
  }

  int
  D4FunctionParser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 69 "d4_function_parser.yy" // lalr1.cc:788
{
    // Initialize the initial location. This is printed when the parser builds
    // its own error messages - when the parse fails as opposed to when the 
    // function(s) name(s) a missing variable, ...

    yyla.location.initialize (evaluator.expression());
}

#line 1044 "d4_function_parser.tab.cc" // lalr1.cc:788

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner, evaluator));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 7: // "function name"
      case 44: // fname
        yylhs.value.emplace< D4Function > ();
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        yylhs.value.emplace< D4RValue* > ();
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        yylhs.value.emplace< D4RValueList* > ();
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        yylhs.value.emplace< std::string > ();
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        yylhs.value.emplace< std::vector<dods_byte>* > ();
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        yylhs.value.emplace< std::vector<dods_float32>* > ();
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        yylhs.value.emplace< std::vector<dods_float64>* > ();
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        yylhs.value.emplace< std::vector<dods_int16>* > ();
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        yylhs.value.emplace< std::vector<dods_int32>* > ();
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        yylhs.value.emplace< std::vector<dods_int64>* > ();
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        yylhs.value.emplace< std::vector<dods_int8>* > ();
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        yylhs.value.emplace< std::vector<dods_uint16>* > ();
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        yylhs.value.emplace< std::vector<dods_uint32>* > ();
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        yylhs.value.emplace< std::vector<dods_uint64>* > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 156 "d4_function_parser.yy" // lalr1.cc:919
    { 
    evaluator.set_result(yystack_[0].value.as < D4RValueList* > ()); 
}
#line 1251 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 3:
#line 162 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValueList* > () = new D4RValueList(yystack_[0].value.as < D4RValue* > ()); 
}
#line 1259 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 4:
#line 166 "d4_function_parser.yy" // lalr1.cc:919
    { 
    yystack_[2].value.as < D4RValueList* > ()->add_rvalue(yystack_[0].value.as < D4RValue* > ());
    yylhs.value.as < D4RValueList* > () = yystack_[2].value.as < D4RValueList* > (); 
}
#line 1268 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 5:
#line 173 "d4_function_parser.yy" // lalr1.cc:919
    { 
    yylhs.value.as < D4RValue* > () = new D4RValue(yystack_[3].value.as < D4Function > (), yystack_[1].value.as < D4RValueList* > ()); // Build a D4RValue from a D4Function pointer and a D4RValueList 
}
#line 1276 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 6:
#line 179 "d4_function_parser.yy" // lalr1.cc:919
    { 
    D4Function f;
    if (!evaluator.sf_list()->find_function(yystack_[0].value.as < std::string > (), &f)) {
        // ...cloud use @1.{first,last}_column in these error messages.
        throw Error(malformed_expr, "'" + yystack_[0].value.as < std::string > () + "' is not a registered DAP4 server function.");
    }

    yylhs.value.as < D4Function > () = f;
}
#line 1290 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 7:
#line 191 "d4_function_parser.yy" // lalr1.cc:919
    { 
    yylhs.value.as < D4RValueList* > () = new D4RValueList(yystack_[0].value.as < D4RValue* > ()); // build a D4RValueList from the D4RValue
}
#line 1298 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 8:
#line 195 "d4_function_parser.yy" // lalr1.cc:919
    { 
    yystack_[2].value.as < D4RValueList* > ()->add_rvalue(yystack_[0].value.as < D4RValue* > ());
    yylhs.value.as < D4RValueList* > () = yystack_[2].value.as < D4RValueList* > (); // Append the D4RValue ($3) to the D4RValueList ($1), then return
}
#line 1307 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 9:
#line 202 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = yystack_[0].value.as < D4RValue* > ();
}
#line 1315 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 10:
#line 206 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = yystack_[0].value.as < D4RValue* > ();
}
#line 1323 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 11:
#line 210 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = yystack_[0].value.as < D4RValue* > ();
}
#line 1331 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 12:
#line 216 "d4_function_parser.yy" // lalr1.cc:919
    {
    D4RValue *rvalue = evaluator.build_rvalue(yystack_[0].value.as < std::string > ());
    if (!rvalue) {
        throw Error(malformed_expr, "'" + yystack_[0].value.as < std::string > () + "' is not a variable, number or string.");
    }
    
    yylhs.value.as < D4RValue* > () = rvalue;
}
#line 1344 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 13:
#line 228 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_byte>* > ()));
    delete yystack_[1].value.as < std::vector<dods_byte>* > ();
}
#line 1353 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 14:
#line 234 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_byte>* > ()));
    delete yystack_[1].value.as < std::vector<dods_byte>* > ();
}
#line 1362 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 15:
#line 240 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_int8>* > ()));
    delete yystack_[1].value.as < std::vector<dods_int8>* > ();
}
#line 1371 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 16:
#line 246 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_uint16>* > ()));
    delete yystack_[1].value.as < std::vector<dods_uint16>* > ();
}
#line 1380 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 17:
#line 252 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_int16>* > ()));
    delete yystack_[1].value.as < std::vector<dods_int16>* > ();
}
#line 1389 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 18:
#line 258 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_uint32>* > ()));
    delete yystack_[1].value.as < std::vector<dods_uint32>* > ();
}
#line 1398 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 19:
#line 264 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_int32>* > ()));
    delete yystack_[1].value.as < std::vector<dods_int32>* > ();
}
#line 1407 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 20:
#line 270 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_uint64>* > ()));
    delete yystack_[1].value.as < std::vector<dods_uint64>* > ();
}
#line 1416 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 21:
#line 276 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_int64>* > ()));
    delete yystack_[1].value.as < std::vector<dods_int64>* > ();
}
#line 1425 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 22:
#line 282 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_float32>* > ()));
    delete yystack_[1].value.as < std::vector<dods_float32>* > ();
}
#line 1434 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 23:
#line 288 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < D4RValue* > () = new D4RValue(*(yystack_[1].value.as < std::vector<dods_float64>* > ()));
    delete yystack_[1].value.as < std::vector<dods_float64>* > ();
}
#line 1443 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 24:
#line 300 "d4_function_parser.yy" // lalr1.cc:919
    {
    evaluator.set_arg_length_hint(get_uint64(yystack_[0].value.as < std::string > ().c_str()));
}
#line 1451 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 25:
#line 306 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_byte>* > () = evaluator.init_arg_list(dods_byte(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1459 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 26:
#line 310 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_byte>* > ()->push_back(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_byte>* > () = yystack_[2].value.as < std::vector<dods_byte>* > ();
}
#line 1468 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 27:
#line 317 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_int8>* > () = evaluator.init_arg_list(dods_int8(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1476 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 28:
#line 321 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_int8>* > ()->push_back(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_int8>* > () = yystack_[2].value.as < std::vector<dods_int8>* > ();
}
#line 1485 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 29:
#line 328 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_uint16>* > () = evaluator.init_arg_list(dods_uint16(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1493 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 30:
#line 332 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_uint16>* > ()->push_back(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_uint16>* > () = yystack_[2].value.as < std::vector<dods_uint16>* > ();
}
#line 1502 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 31:
#line 339 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_int16>* > () = evaluator.init_arg_list(dods_int16(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1510 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 32:
#line 343 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_int16>* > ()->push_back(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_int16>* > () = yystack_[2].value.as < std::vector<dods_int16>* > ();
}
#line 1519 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 33:
#line 350 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_uint32>* > () = evaluator.init_arg_list(dods_uint32(strtoul(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1527 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 34:
#line 354 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_uint32>* > ()->push_back(strtoul(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_uint32>* > () = yystack_[2].value.as < std::vector<dods_uint32>* > ();
}
#line 1536 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 35:
#line 360 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_int32>* > () = evaluator.init_arg_list(dods_int32(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1544 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 36:
#line 364 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_int32>* > ()->push_back(strtol(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_int32>* > () = yystack_[2].value.as < std::vector<dods_int32>* > ();
}
#line 1553 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 37:
#line 371 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_uint64>* > () = evaluator.init_arg_list(dods_uint64(strtoull(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1561 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 38:
#line 375 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_uint64>* > ()->push_back(strtoull(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_uint64>* > () = yystack_[2].value.as < std::vector<dods_uint64>* > ();
}
#line 1570 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 39:
#line 382 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_int64>* > () = evaluator.init_arg_list(dods_int64(strtoll(yystack_[0].value.as < std::string > ().c_str(), 0, 0)));
}
#line 1578 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 40:
#line 386 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_int64>* > ()->push_back(strtoll(yystack_[0].value.as < std::string > ().c_str(), 0, 0));
    yylhs.value.as < std::vector<dods_int64>* > () = yystack_[2].value.as < std::vector<dods_int64>* > ();
}
#line 1587 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 41:
#line 396 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_float32>* > () = evaluator.init_arg_list(dods_float32(strtof(yystack_[0].value.as < std::string > ().c_str(), 0)));
}
#line 1595 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 42:
#line 400 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_float32>* > ()->push_back(strtof(yystack_[0].value.as < std::string > ().c_str(), 0));
    yylhs.value.as < std::vector<dods_float32>* > () = yystack_[2].value.as < std::vector<dods_float32>* > ();
}
#line 1604 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 43:
#line 407 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::vector<dods_float64>* > () = evaluator.init_arg_list(dods_float64(strtod(yystack_[0].value.as < std::string > ().c_str(), 0)));
}
#line 1612 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 44:
#line 411 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::vector<dods_float64>* > ()->push_back(strtod(yystack_[0].value.as < std::string > ().c_str(), 0));
    yylhs.value.as < std::vector<dods_float64>* > () = yystack_[2].value.as < std::vector<dods_float64>* > ();
}
#line 1621 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 45:
#line 418 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
}
#line 1629 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 46:
#line 422 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ().append("/");
    yylhs.value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
}
#line 1638 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 47:
#line 427 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::string > ().append("/");
    yystack_[2].value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
}
#line 1648 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 48:
#line 435 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ().append("/");
    yylhs.value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
}
#line 1657 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 49:
#line 440 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::string > ().append(".");
    yystack_[2].value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
}
#line 1667 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 50:
#line 448 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
}
#line 1675 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 51:
#line 452 "d4_function_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::string > ().append(".");
    yystack_[2].value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
}
#line 1685 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 52:
#line 463 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
}
#line 1693 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;

  case 53:
#line 467 "d4_function_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ()=yystack_[0].value.as < std::string > ();
}
#line 1701 "d4_function_parser.tab.cc" // lalr1.cc:919
    break;


#line 1705 "d4_function_parser.tab.cc" // lalr1.cc:919
            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  D4FunctionParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  D4FunctionParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char D4FunctionParser::yypact_ninf_ = -20;

  const signed char D4FunctionParser::yytable_ninf_ = -50;

  const signed char
  D4FunctionParser::yypact_[] =
  {
     -10,   -20,     8,    10,   -20,    12,   -20,   -10,   -18,   -20,
      37,   -20,   -16,    38,    39,    42,    43,    44,    45,    46,
      47,    48,    49,    50,   -20,   -19,   -20,   -20,   -20,   -20,
      51,    52,   -20,   -20,    52,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,   -20,   -18,   -16,
     -16,   -20,    53,    56,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   -20,    52,    68,   -20,    57,    57,    71,
      72,    73,    74,    76,    77,    78,   -16,   -16,   -20,     9,
      16,   -20,    18,   -20,    20,   -20,    22,   -20,    24,   -20,
      26,   -20,    28,   -20,    30,    32,    52,    34,    52,   -20,
      79,   -20,   -20,    80,   -20,    81,   -20,    82,   -20,    83,
     -20,    84,   -20,    86,   -20,    88,   -20,   -16,   -20,   -16,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,    52,    52
  };

  const unsigned char
  D4FunctionParser::yydefact_[] =
  {
       0,     6,     0,     2,     3,     0,     1,     0,     0,     4,
      52,    53,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,     7,    10,    11,    12,
       0,    45,    50,    52,    46,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,    47,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,     0,
       0,    27,     0,    29,     0,    31,     0,    33,     0,    35,
       0,    37,     0,    39,     0,     0,    41,     0,    43,    13,
       0,    14,    15,     0,    16,     0,    17,     0,    18,     0,
      19,     0,    20,     0,    21,     0,    22,     0,    23,     0,
      26,    28,    30,    32,    34,    36,    38,    40,    42,    44
  };

  const signed char
  D4FunctionParser::yypgoto_[] =
  {
     -20,   -20,   -20,    33,   -20,   -20,    69,   -20,   -20,   -15,
      41,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -12,   -11
  };

  const signed char
  D4FunctionParser::yydefgoto_[] =
  {
      -1,     2,     3,    24,     5,    25,    26,    27,    28,    52,
      79,    82,    84,    86,    88,    90,    92,    94,    95,    97,
      29,    30,    31,    32
  };

  const short
  D4FunctionParser::yytable_[] =
  {
      34,    35,    10,    11,    33,    11,    47,    48,     6,    12,
       1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,     7,     4,    99,   100,     8,    64,    65,    66,
       9,   101,   100,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    -6,    36,    37,    96,    98,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    51,    67,    78,    49,    68,
      50,   -48,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    81,    83,    85,    87,   -49,    89,    91,    93,   120,
     121,   122,   123,   124,   125,   128,   126,   129,   127,    80,
       0,     0,     0,     0,     0,     0,     0,    63
  };

  const signed char
  D4FunctionParser::yycheck_[] =
  {
      12,    12,    20,    21,    20,    21,    25,    26,     0,    27,
      20,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    22,     0,    25,    26,    24,    49,    49,    50,
       7,    25,    26,    25,    26,    25,    26,    25,    26,    25,
      26,    25,    26,    25,    26,    25,    26,    25,    26,    25,
      26,    24,    24,    24,    76,    77,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    20,    23,    20,    27,    23,
      28,    27,    23,    23,    23,    23,    23,    23,    23,    23,
      23,    20,    20,    20,    20,    27,    20,    20,    20,    20,
      20,    20,    20,    20,    20,   117,    20,   119,    20,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48
  };

  const unsigned char
  D4FunctionParser::yystos_[] =
  {
       0,    20,    41,    42,    43,    44,     0,    22,    24,    43,
      20,    21,    27,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    43,    45,    46,    47,    48,    60,
      61,    62,    63,    20,    62,    63,    24,    24,    24,    24,
      24,    24,    24,    24,    24,    24,    24,    25,    26,    27,
      28,    20,    49,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    46,    62,    63,    63,    23,    23,    23,
      23,    23,    23,    23,    23,    23,    23,    23,    20,    50,
      50,    20,    51,    20,    52,    20,    53,    20,    54,    20,
      55,    20,    56,    20,    57,    58,    62,    59,    62,    25,
      26,    25,    25,    26,    25,    26,    25,    26,    25,    26,
      25,    26,    25,    26,    25,    26,    25,    26,    25,    26,
      20,    20,    20,    20,    20,    20,    20,    20,    62,    62
  };

  const unsigned char
  D4FunctionParser::yyr1_[] =
  {
       0,    40,    41,    42,    42,    43,    44,    45,    45,    46,
      46,    46,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    60,    61,    61,
      62,    62,    63,    63
  };

  const unsigned char
  D4FunctionParser::yyr2_[] =
  {
       0,     2,     1,     1,     3,     4,     1,     1,     3,     1,
       1,     1,     1,     6,     6,     6,     6,     6,     6,     6,
       6,     6,     6,     6,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     2,     3,     2,     3,
       1,     3,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const D4FunctionParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"functions\"",
  "\"arguments\"", "\"argument\"", "\"function\"", "\"function name\"",
  "\"variable or constant\"", "\"array constant\"",
  "\"fast byte arg list\"", "\"fast int8 arg list\"",
  "\"fast uint16 arg list\"", "\"fast int16 arg list\"",
  "\"fast uint32 arg list\"", "\"fast int32 arg list\"",
  "\"fast uint64 arg list\"", "\"fast int64 arg list\"",
  "\"fast float32 arg list\"", "\"fast float64 arg list\"", "\"word\"",
  "\"string\"", "\";\"", "\":\"", "\"(\"", "\")\"", "\",\"", "\"/\"",
  "\".\"", "\"$Byte\"", "\"$UInt8\"", "\"$Int8\"", "\"$UInt16\"",
  "\"$Int16\"", "\"$UInt32\"", "\"$Int32\"", "\"$UInt64\"", "\"$Int64\"",
  "\"$Float32\"", "\"$Float64\"", "$accept", "program", "functions",
  "function", "fname", "args", "arg", "variable_or_constant",
  "array_constant", "arg_length_hint", "fast_byte_arg_list",
  "fast_int8_arg_list", "fast_uint16_arg_list", "fast_int16_arg_list",
  "fast_uint32_arg_list", "fast_int32_arg_list", "fast_uint64_arg_list",
  "fast_int64_arg_list", "fast_float32_arg_list", "fast_float64_arg_list",
  "id", "group", "path", "name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  D4FunctionParser::yyrline_[] =
  {
       0,   155,   155,   161,   165,   172,   178,   190,   194,   201,
     205,   209,   215,   227,   233,   239,   245,   251,   257,   263,
     269,   275,   281,   287,   299,   305,   309,   316,   320,   327,
     331,   338,   342,   349,   353,   359,   363,   370,   374,   381,
     385,   395,   399,   406,   410,   417,   421,   426,   434,   439,
     447,   451,   462,   466
  };

  // Print the state stack on the debug stream.
  void
  D4FunctionParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  D4FunctionParser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  D4FunctionParser::token_number_type
  D4FunctionParser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
    };
    const unsigned user_token_number_max_ = 294;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 34 "d4_function_parser.yy" // lalr1.cc:1242
} // libdap
#line 2226 "d4_function_parser.tab.cc" // lalr1.cc:1242
#line 472 "d4_function_parser.yy" // lalr1.cc:1243


// Forward the error to the driver for handling. The location parameter
// provides the line number and character position of the error.
void
libdap::D4FunctionParser::error(const location_type &l, const std::string &m)
{
    evaluator.error(l, m);
}

/* include for access to scanner.yylex */
#include "D4FunctionScanner.h"

static int yylex(libdap::D4FunctionParser::semantic_type *yylval,
                 libdap::location *loc,
                 libdap::D4FunctionScanner &scanner,
                 libdap::D4FunctionEvaluator &evaluator)
{
    if (evaluator.trace_scanning())
        scanner.set_debug(true);
    
    return( scanner.yylex(yylval, loc) );
}
