// A Bison parser, made by GNU Bison 3.3.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file d4_function_parser.tab.hh
 ** Define the libdap::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_D4_FUNCTION_PARSER_TAB_HH_INCLUDED
# define YY_YY_D4_FUNCTION_PARSER_TAB_HH_INCLUDED
// //                    "%code requires" blocks.
#line 47 "d4_function_parser.yy" // lalr1.cc:401


#include "D4FunctionEvaluator.h"
#include "D4RValue.h"
#include "dods-datatypes.h"

namespace libdap {
    class D4FunctionScanner;
}


#line 60 "d4_function_parser.tab.hh" // lalr1.cc:401

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 34 "d4_function_parser.yy" // lalr1.cc:401
namespace libdap {
#line 176 "d4_function_parser.tab.hh" // lalr1.cc:401



  /// A Bison parser.
  class D4FunctionParser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {
      YYASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YYASSERT (!yytypeid_);
      YYASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == typeid (T));
      YYASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YYASSERT (yytypeid_);
      YYASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // "function name"
      // fname
      char dummy1[sizeof (D4Function)];

      // "argument"
      // "function"
      // "variable or constant"
      // "array constant"
      // function
      // arg
      // variable_or_constant
      // array_constant
      char dummy2[sizeof (D4RValue*)];

      // "functions"
      // "arguments"
      // functions
      // args
      char dummy3[sizeof (D4RValueList*)];

      // "word"
      // "string"
      // id
      // group
      // path
      // name
      char dummy4[sizeof (std::string)];

      // "fast byte arg list"
      // fast_byte_arg_list
      char dummy5[sizeof (std::vector<dods_byte>*)];

      // "fast float32 arg list"
      // fast_float32_arg_list
      char dummy6[sizeof (std::vector<dods_float32>*)];

      // "fast float64 arg list"
      // fast_float64_arg_list
      char dummy7[sizeof (std::vector<dods_float64>*)];

      // "fast int16 arg list"
      // fast_int16_arg_list
      char dummy8[sizeof (std::vector<dods_int16>*)];

      // "fast int32 arg list"
      // fast_int32_arg_list
      char dummy9[sizeof (std::vector<dods_int32>*)];

      // "fast int64 arg list"
      // fast_int64_arg_list
      char dummy10[sizeof (std::vector<dods_int64>*)];

      // "fast int8 arg list"
      // fast_int8_arg_list
      char dummy11[sizeof (std::vector<dods_int8>*)];

      // "fast uint16 arg list"
      // fast_uint16_arg_list
      char dummy12[sizeof (std::vector<dods_uint16>*)];

      // "fast uint32 arg list"
      // fast_uint32_arg_list
      char dummy13[sizeof (std::vector<dods_uint32>*)];

      // "fast uint64 arg list"
      // fast_uint64_arg_list
      char dummy14[sizeof (std::vector<dods_uint64>*)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        WORD = 275,
        STRING = 276,
        SEMICOLON = 277,
        COLON = 278,
        LPAREN = 279,
        RPAREN = 280,
        COMMA = 281,
        GROUP_SEP = 282,
        PATH_SEP = 283,
        DOLLAR_BYTE = 284,
        DOLLAR_UINT8 = 285,
        DOLLAR_INT8 = 286,
        DOLLAR_UINT16 = 287,
        DOLLAR_INT16 = 288,
        DOLLAR_UINT32 = 289,
        DOLLAR_INT32 = 290,
        DOLLAR_UINT64 = 291,
        DOLLAR_INT64 = 292,
        DOLLAR_FLOAT32 = 293,
        DOLLAR_FLOAT64 = 294
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, D4Function&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const D4Function& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, D4RValue*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const D4RValue*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, D4RValueList*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const D4RValueList*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_byte>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_byte>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_float32>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_float32>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_float64>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_float64>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_int16>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_int16>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_int32>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_int32>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_int64>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_int64>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_int8>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_int8>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_uint16>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_uint16>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_uint32>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_uint32>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<dods_uint64>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<dods_uint64>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 7: // "function name"
      case 44: // fname
        value.template destroy< D4Function > ();
        break;

      case 5: // "argument"
      case 6: // "function"
      case 8: // "variable or constant"
      case 9: // "array constant"
      case 43: // function
      case 46: // arg
      case 47: // variable_or_constant
      case 48: // array_constant
        value.template destroy< D4RValue* > ();
        break;

      case 3: // "functions"
      case 4: // "arguments"
      case 42: // functions
      case 45: // args
        value.template destroy< D4RValueList* > ();
        break;

      case 20: // "word"
      case 21: // "string"
      case 60: // id
      case 61: // group
      case 62: // path
      case 63: // name
        value.template destroy< std::string > ();
        break;

      case 10: // "fast byte arg list"
      case 50: // fast_byte_arg_list
        value.template destroy< std::vector<dods_byte>* > ();
        break;

      case 18: // "fast float32 arg list"
      case 58: // fast_float32_arg_list
        value.template destroy< std::vector<dods_float32>* > ();
        break;

      case 19: // "fast float64 arg list"
      case 59: // fast_float64_arg_list
        value.template destroy< std::vector<dods_float64>* > ();
        break;

      case 13: // "fast int16 arg list"
      case 53: // fast_int16_arg_list
        value.template destroy< std::vector<dods_int16>* > ();
        break;

      case 15: // "fast int32 arg list"
      case 55: // fast_int32_arg_list
        value.template destroy< std::vector<dods_int32>* > ();
        break;

      case 17: // "fast int64 arg list"
      case 57: // fast_int64_arg_list
        value.template destroy< std::vector<dods_int64>* > ();
        break;

      case 11: // "fast int8 arg list"
      case 51: // fast_int8_arg_list
        value.template destroy< std::vector<dods_int8>* > ();
        break;

      case 12: // "fast uint16 arg list"
      case 52: // fast_uint16_arg_list
        value.template destroy< std::vector<dods_uint16>* > ();
        break;

      case 14: // "fast uint32 arg list"
      case 54: // fast_uint32_arg_list
        value.template destroy< std::vector<dods_uint32>* > ();
        break;

      case 16: // "fast uint64 arg list"
      case 56: // fast_uint64_arg_list
        value.template destroy< std::vector<dods_uint64>* > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YYASSERT (tok == token::END || tok == token::SEMICOLON || tok == token::COLON || tok == token::LPAREN || tok == token::RPAREN || tok == token::COMMA || tok == token::GROUP_SEP || tok == token::PATH_SEP || tok == token::DOLLAR_BYTE || tok == token::DOLLAR_UINT8 || tok == token::DOLLAR_INT8 || tok == token::DOLLAR_UINT16 || tok == token::DOLLAR_INT16 || tok == token::DOLLAR_UINT32 || tok == token::DOLLAR_INT32 || tok == token::DOLLAR_UINT64 || tok == token::DOLLAR_INT64 || tok == token::DOLLAR_FLOAT32 || tok == token::DOLLAR_FLOAT64);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YYASSERT (tok == token::END || tok == token::SEMICOLON || tok == token::COLON || tok == token::LPAREN || tok == token::RPAREN || tok == token::COMMA || tok == token::GROUP_SEP || tok == token::PATH_SEP || tok == token::DOLLAR_BYTE || tok == token::DOLLAR_UINT8 || tok == token::DOLLAR_INT8 || tok == token::DOLLAR_UINT16 || tok == token::DOLLAR_INT16 || tok == token::DOLLAR_UINT32 || tok == token::DOLLAR_INT32 || tok == token::DOLLAR_UINT64 || tok == token::DOLLAR_INT64 || tok == token::DOLLAR_FLOAT32 || tok == token::DOLLAR_FLOAT64);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, D4Function v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 262);
      }
#else
      symbol_type (int tok, const D4Function& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 262);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, D4RValue* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 260 || tok == 261 || tok == 263 || tok == 264);
      }
#else
      symbol_type (int tok, const D4RValue*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 260 || tok == 261 || tok == 263 || tok == 264);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, D4RValueList* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 258 || tok == 259);
      }
#else
      symbol_type (int tok, const D4RValueList*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 258 || tok == 259);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::WORD || tok == token::STRING);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::WORD || tok == token::STRING);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_byte>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 265);
      }
#else
      symbol_type (int tok, const std::vector<dods_byte>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 265);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_float32>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 273);
      }
#else
      symbol_type (int tok, const std::vector<dods_float32>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 273);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_float64>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 274);
      }
#else
      symbol_type (int tok, const std::vector<dods_float64>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 274);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_int16>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 268);
      }
#else
      symbol_type (int tok, const std::vector<dods_int16>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 268);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_int32>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 270);
      }
#else
      symbol_type (int tok, const std::vector<dods_int32>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 270);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_int64>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 272);
      }
#else
      symbol_type (int tok, const std::vector<dods_int64>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 272);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_int8>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 266);
      }
#else
      symbol_type (int tok, const std::vector<dods_int8>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 266);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_uint16>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 267);
      }
#else
      symbol_type (int tok, const std::vector<dods_uint16>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 267);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_uint32>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 269);
      }
#else
      symbol_type (int tok, const std::vector<dods_uint32>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 269);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::vector<dods_uint64>* v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == 271);
      }
#else
      symbol_type (int tok, const std::vector<dods_uint64>*& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == 271);
      }
#endif
    };

    /// Build a parser object.
    D4FunctionParser (D4FunctionScanner  &scanner_yyarg, D4FunctionEvaluator  &evaluator_yyarg);
    virtual ~D4FunctionParser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WORD (std::string v, location_type l)
      {
        return symbol_type (token::WORD, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_WORD (const std::string& v, const location_type& l)
      {
        return symbol_type (token::WORD, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMICOLON (location_type l)
      {
        return symbol_type (token::SEMICOLON, std::move (l));
      }
#else
      static
      symbol_type
      make_SEMICOLON (const location_type& l)
      {
        return symbol_type (token::SEMICOLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON (location_type l)
      {
        return symbol_type (token::COLON, std::move (l));
      }
#else
      static
      symbol_type
      make_COLON (const location_type& l)
      {
        return symbol_type (token::COLON, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPAREN (location_type l)
      {
        return symbol_type (token::LPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_LPAREN (const location_type& l)
      {
        return symbol_type (token::LPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPAREN (location_type l)
      {
        return symbol_type (token::RPAREN, std::move (l));
      }
#else
      static
      symbol_type
      make_RPAREN (const location_type& l)
      {
        return symbol_type (token::RPAREN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (location_type l)
      {
        return symbol_type (token::COMMA, std::move (l));
      }
#else
      static
      symbol_type
      make_COMMA (const location_type& l)
      {
        return symbol_type (token::COMMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GROUP_SEP (location_type l)
      {
        return symbol_type (token::GROUP_SEP, std::move (l));
      }
#else
      static
      symbol_type
      make_GROUP_SEP (const location_type& l)
      {
        return symbol_type (token::GROUP_SEP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PATH_SEP (location_type l)
      {
        return symbol_type (token::PATH_SEP, std::move (l));
      }
#else
      static
      symbol_type
      make_PATH_SEP (const location_type& l)
      {
        return symbol_type (token::PATH_SEP, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_BYTE (location_type l)
      {
        return symbol_type (token::DOLLAR_BYTE, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_BYTE (const location_type& l)
      {
        return symbol_type (token::DOLLAR_BYTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_UINT8 (location_type l)
      {
        return symbol_type (token::DOLLAR_UINT8, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_UINT8 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_UINT8, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_INT8 (location_type l)
      {
        return symbol_type (token::DOLLAR_INT8, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_INT8 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_INT8, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_UINT16 (location_type l)
      {
        return symbol_type (token::DOLLAR_UINT16, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_UINT16 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_UINT16, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_INT16 (location_type l)
      {
        return symbol_type (token::DOLLAR_INT16, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_INT16 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_INT16, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_UINT32 (location_type l)
      {
        return symbol_type (token::DOLLAR_UINT32, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_UINT32 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_UINT32, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_INT32 (location_type l)
      {
        return symbol_type (token::DOLLAR_INT32, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_INT32 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_INT32, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_UINT64 (location_type l)
      {
        return symbol_type (token::DOLLAR_UINT64, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_UINT64 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_UINT64, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_INT64 (location_type l)
      {
        return symbol_type (token::DOLLAR_INT64, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_INT64 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_INT64, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_FLOAT32 (location_type l)
      {
        return symbol_type (token::DOLLAR_FLOAT32, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_FLOAT32 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_FLOAT32, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR_FLOAT64 (location_type l)
      {
        return symbol_type (token::DOLLAR_FLOAT64, std::move (l));
      }
#else
      static
      symbol_type
      make_DOLLAR_FLOAT64 (const location_type& l)
      {
        return symbol_type (token::DOLLAR_FLOAT64, l);
      }
#endif


  private:
    /// This class is not copyable.
    D4FunctionParser (const D4FunctionParser&);
    D4FunctionParser& operator= (const D4FunctionParser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const signed char yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const signed char yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const signed char yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const signed char yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 117,     ///< Last index in yytable_.
      yynnts_ = 24,  ///< Number of nonterminal symbols.
      yyfinal_ = 6, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 40  ///< Number of tokens.
    };


    // User arguments.
    D4FunctionScanner  &scanner;
    D4FunctionEvaluator  &evaluator;
  };


#line 34 "d4_function_parser.yy" // lalr1.cc:401
} // libdap
#line 1799 "d4_function_parser.tab.hh" // lalr1.cc:401




#endif // !YY_YY_D4_FUNCTION_PARSER_TAB_HH_INCLUDED
