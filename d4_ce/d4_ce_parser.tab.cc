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





#include "d4_ce_parser.tab.hh"


// Unqualified %code blocks.
#line 76 "d4_ce_parser.yy" // lalr1.cc:435

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   #include "BaseType.h"
   #include "DMR.h"
   #include "D4Group.h"

   /* include for all driver functions */
   #include "D4ConstraintEvaluator.h"

   /* this is silly, but I can't figure out a way around it */
   static int yylex(libdap::D4CEParser::semantic_type *yylval,
                    libdap::location *loc,
                    libdap::D4CEScanner  &scanner,
                    libdap::D4ConstraintEvaluator   &driver);


#line 65 "d4_ce_parser.tab.cc" // lalr1.cc:435


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

#line 35 "d4_ce_parser.yy" // lalr1.cc:510
namespace libdap {
#line 160 "d4_ce_parser.tab.cc" // lalr1.cc:510

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  D4CEParser::yytnamerr_ (const char *yystr)
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
  D4CEParser::D4CEParser (D4CEScanner  &scanner_yyarg, D4ConstraintEvaluator  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  D4CEParser::~D4CEParser ()
  {}

  D4CEParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  D4CEParser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 29: // dimensions
      case 30: // dimension
      case 31: // clauses
      case 32: // clause
      case 33: // subset
      case 36: // indexes
      case 39: // fields
      case 40: // filter
      case 41: // predicate
        value.move< bool > (std::move (that.value));
        break;

      case 38: // index
        value.move< libdap::D4ConstraintEvaluator::index > (std::move (that.value));
        break;

      case 3: // "word"
      case 4: // "string"
      case 42: // op
      case 43: // id
      case 44: // group
      case 45: // path
      case 46: // name
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  D4CEParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 29: // dimensions
      case 30: // dimension
      case 31: // clauses
      case 32: // clause
      case 33: // subset
      case 36: // indexes
      case 39: // fields
      case 40: // filter
      case 41: // predicate
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case 38: // index
        value.copy< libdap::D4ConstraintEvaluator::index > (YY_MOVE (that.value));
        break;

      case 3: // "word"
      case 4: // "string"
      case 42: // op
      case 43: // id
      case 44: // group
      case 45: // path
      case 46: // name
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  D4CEParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  D4CEParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 29: // dimensions
      case 30: // dimension
      case 31: // clauses
      case 32: // clause
      case 33: // subset
      case 36: // indexes
      case 39: // fields
      case 40: // filter
      case 41: // predicate
        value.move< bool > (YY_MOVE (s.value));
        break;

      case 38: // index
        value.move< libdap::D4ConstraintEvaluator::index > (YY_MOVE (s.value));
        break;

      case 3: // "word"
      case 4: // "string"
      case 42: // op
      case 43: // id
      case 44: // group
      case 45: // path
      case 46: // name
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  D4CEParser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  D4CEParser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  D4CEParser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  D4CEParser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  D4CEParser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  D4CEParser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  D4CEParser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }


  // by_state.
  D4CEParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  D4CEParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  D4CEParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  D4CEParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  D4CEParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  D4CEParser::symbol_number_type
  D4CEParser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  D4CEParser::stack_symbol_type::stack_symbol_type ()
  {}

  D4CEParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 29: // dimensions
      case 30: // dimension
      case 31: // clauses
      case 32: // clause
      case 33: // subset
      case 36: // indexes
      case 39: // fields
      case 40: // filter
      case 41: // predicate
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case 38: // index
        value.YY_MOVE_OR_COPY< libdap::D4ConstraintEvaluator::index > (YY_MOVE (that.value));
        break;

      case 3: // "word"
      case 4: // "string"
      case 42: // op
      case 43: // id
      case 44: // group
      case 45: // path
      case 46: // name
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  D4CEParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 29: // dimensions
      case 30: // dimension
      case 31: // clauses
      case 32: // clause
      case 33: // subset
      case 36: // indexes
      case 39: // fields
      case 40: // filter
      case 41: // predicate
        value.move< bool > (YY_MOVE (that.value));
        break;

      case 38: // index
        value.move< libdap::D4ConstraintEvaluator::index > (YY_MOVE (that.value));
        break;

      case 3: // "word"
      case 4: // "string"
      case 42: // op
      case 43: // id
      case 44: // group
      case 45: // path
      case 46: // name
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  D4CEParser::stack_symbol_type&
  D4CEParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 29: // dimensions
      case 30: // dimension
      case 31: // clauses
      case 32: // clause
      case 33: // subset
      case 36: // indexes
      case 39: // fields
      case 40: // filter
      case 41: // predicate
        value.move< bool > (that.value);
        break;

      case 38: // index
        value.move< libdap::D4ConstraintEvaluator::index > (that.value);
        break;

      case 3: // "word"
      case 4: // "string"
      case 42: // op
      case 43: // id
      case 44: // group
      case 45: // path
      case 46: // name
        value.move< std::string > (that.value);
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
  D4CEParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  D4CEParser::yy_print_ (std::ostream& yyo,
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
  D4CEParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  D4CEParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  D4CEParser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  D4CEParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  D4CEParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  D4CEParser::debug_level_type
  D4CEParser::debug_level () const
  {
    return yydebug_;
  }

  void
  D4CEParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  D4CEParser::state_type
  D4CEParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  D4CEParser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  D4CEParser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  D4CEParser::operator() ()
  {
    return parse ();
  }

  int
  D4CEParser::parse ()
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
#line 68 "d4_ce_parser.yy" // lalr1.cc:788
{
    // Initialize the initial location. This is printed when the parser builds
    // its own error messages - when the parse fails as opposed to when the 
    // CE names a missing variables, ...

    yyla.location.initialize (driver.expression());
}

#line 708 "d4_ce_parser.tab.cc" // lalr1.cc:788

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
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, scanner, driver));
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
      case 29: // dimensions
      case 30: // dimension
      case 31: // clauses
      case 32: // clause
      case 33: // subset
      case 36: // indexes
      case 39: // fields
      case 40: // filter
      case 41: // predicate
        yylhs.value.emplace< bool > ();
        break;

      case 38: // index
        yylhs.value.emplace< libdap::D4ConstraintEvaluator::index > ();
        break;

      case 3: // "word"
      case 4: // "string"
      case 42: // op
      case 43: // id
      case 44: // group
      case 45: // path
      case 46: // name
        yylhs.value.emplace< std::string > ();
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
#line 147 "d4_ce_parser.yy" // lalr1.cc:919
    { driver.set_result(yystack_[0].value.as < bool > ()); }
#line 857 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 3:
#line 148 "d4_ce_parser.yy" // lalr1.cc:919
    { driver.set_result(yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > ()); }
#line 863 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 4:
#line 151 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 869 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 5:
#line 152 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 875 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 6:
#line 156 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < bool > () = driver.slice_dimension(yystack_[2].value.as < std::string > (), yystack_[0].value.as < libdap::D4ConstraintEvaluator::index > ());
}
#line 883 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 7:
#line 161 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 889 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 8:
#line 162 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 895 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 9:
#line 172 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); driver.pop_basetype(); }
#line 901 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 10:
#line 176 "d4_ce_parser.yy" // lalr1.cc:919
    { driver.pop_basetype(); yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 907 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 11:
#line 184 "d4_ce_parser.yy" // lalr1.cc:919
    {
    BaseType *btp = 0;
    if (driver.top_basetype()) {
        btp = driver.top_basetype()->var(yystack_[0].value.as < std::string > ());
    }
    else {
        btp = driver.dmr()->root()->find_var(yystack_[0].value.as < std::string > ());
    }
    
    if (!btp)
        driver.throw_not_found(yystack_[0].value.as < std::string > (), "id");

    yylhs.value.as < bool > () = driver.mark_variable(btp);
    
    // push the basetype so that it is
    // accessible if/while filters are parsed
    driver.push_basetype(btp);
}
#line 930 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 12:
#line 204 "d4_ce_parser.yy" // lalr1.cc:919
    {
    BaseType *btp = 0;
    if (driver.top_basetype()) {
        btp = driver.top_basetype()->var(yystack_[1].value.as < std::string > ());
    }
    else {
        btp = driver.dmr()->root()->find_var(yystack_[1].value.as < std::string > ());
    }
    
    if (!btp)
        driver.throw_not_found(yystack_[1].value.as < std::string > (), "id indexes");
        
    if (btp->type() != dods_array_c)
        driver.throw_not_array(yystack_[1].value.as < std::string > (), "id indexes");
        
    yylhs.value.as < bool > () = driver.mark_variable(btp);
    
    // push the basetype so that it is
    // accessible if/while filters are parsed
    driver.push_basetype(btp);
}
#line 956 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 13:
#line 228 "d4_ce_parser.yy" // lalr1.cc:919
    {
    BaseType *btp = 0;
    if (driver.top_basetype()) {
        btp = driver.top_basetype()->var(yystack_[0].value.as < std::string > ());
    }
    else {
        btp = driver.dmr()->root()->find_var(yystack_[0].value.as < std::string > ());
    }

    if (!btp)
        driver.throw_not_found(yystack_[0].value.as < std::string > (), "id fields");
    
    if (btp->type() == dods_array_c) {
        if (btp->var() && !btp->var()->is_constructor_type())
            throw Error(no_such_variable, "The variable " + yystack_[0].value.as < std::string > () + " must be a Structure or Sequence to be used with {}.");
            
        // This call also tests the btp to make sure it's an array
        driver.mark_array_variable(btp);
    }
    else {
        // Don't mark the variable here because only some fields are to be sent and those
        // will be marked when the fields are parsed
        if (!btp->is_constructor_type())
            throw Error(no_such_variable, "The variable " + yystack_[0].value.as < std::string > () + " must be a Structure or Sequence to be used with {}.");
    }
    
    // push the basetype so that it is
    // accessible when fields and if/while filters are parsed
    driver.push_basetype(btp);
}
#line 991 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 14:
#line 259 "d4_ce_parser.yy" // lalr1.cc:919
    { 
    //driver.pop_basetype(); 
    yylhs.value.as < bool > () = true; 
}
#line 1000 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 15:
#line 267 "d4_ce_parser.yy" // lalr1.cc:919
    {
    BaseType *btp = 0;
    if (driver.top_basetype()) {
        btp = driver.top_basetype()->var(yystack_[1].value.as < std::string > ());
    }
    else {
        btp = driver.dmr()->root()->find_var(yystack_[1].value.as < std::string > ());
    }

    if (!btp)
        driver.throw_not_found(yystack_[1].value.as < std::string > (), "id indexes fields");
    
    if (btp->type() != dods_array_c)
        driver.throw_not_array(yystack_[1].value.as < std::string > (), "id indexes fields");

    // This call also tests the btp to make sure it's an array
    driver.mark_array_variable(btp);
    
    if (!btp->var()->is_constructor_type())
        throw Error(no_such_variable, "The variable " + yystack_[1].value.as < std::string > () + " must be a Structure or Sequence to be used with {}.");
      
    driver.push_basetype(btp->var());       
}
#line 1028 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 16:
#line 291 "d4_ce_parser.yy" // lalr1.cc:919
    { 
    //driver.pop_basetype();
    yylhs.value.as < bool > () = true; 
}
#line 1037 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 17:
#line 302 "d4_ce_parser.yy" // lalr1.cc:919
    { 
    driver.push_index(yystack_[0].value.as < libdap::D4ConstraintEvaluator::index > ()); 
    yylhs.value.as < bool > () = true; 
}
#line 1046 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 18:
#line 306 "d4_ce_parser.yy" // lalr1.cc:919
    { driver.push_index(yystack_[0].value.as < libdap::D4ConstraintEvaluator::index > ()); }
#line 1052 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 19:
#line 306 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[0].value.as < bool > (); }
#line 1058 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 20:
#line 311 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < libdap::D4ConstraintEvaluator::index > () = driver.make_index(); }
#line 1064 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 21:
#line 312 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < libdap::D4ConstraintEvaluator::index > () = driver.make_index(yystack_[1].value.as < std::string > ()); }
#line 1070 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 22:
#line 313 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < libdap::D4ConstraintEvaluator::index > () = driver.make_index(yystack_[3].value.as < std::string > (), 1, yystack_[1].value.as < std::string > ()); }
#line 1076 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 23:
#line 314 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < libdap::D4ConstraintEvaluator::index > () = driver.make_index(yystack_[5].value.as < std::string > (), yystack_[3].value.as < std::string > (), yystack_[1].value.as < std::string > ()); }
#line 1082 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 24:
#line 315 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < libdap::D4ConstraintEvaluator::index > () = driver.make_index(yystack_[2].value.as < std::string > (), 1); }
#line 1088 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 25:
#line 316 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < libdap::D4ConstraintEvaluator::index > () = driver.make_index(yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > ()); }
#line 1094 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 26:
#line 319 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[1].value.as < bool > (); }
#line 1100 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 27:
#line 325 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = true; }
#line 1106 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 28:
#line 326 "d4_ce_parser.yy" // lalr1.cc:919
    { yylhs.value.as < bool > () = yystack_[2].value.as < bool > () && yystack_[0].value.as < bool > (); }
#line 1112 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 29:
#line 338 "d4_ce_parser.yy" // lalr1.cc:919
    { driver.add_filter_clause(yystack_[1].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); yylhs.value.as < bool > () = true; }
#line 1118 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 30:
#line 341 "d4_ce_parser.yy" // lalr1.cc:919
    { 
    driver.add_filter_clause(yystack_[3].value.as < std::string > (), yystack_[4].value.as < std::string > (), yystack_[2].value.as < std::string > ()); 
    driver.add_filter_clause(yystack_[1].value.as < std::string > (), yystack_[2].value.as < std::string > (), yystack_[0].value.as < std::string > ()); 
    yylhs.value.as < bool > () = true; 

}
#line 1129 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 31:
#line 347 "d4_ce_parser.yy" // lalr1.cc:919
    { throw Error(malformed_expr, "The 'ND' operator is not currently supported."); }
#line 1135 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 32:
#line 355 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = "<";}
#line 1141 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 33:
#line 356 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = ">";}
#line 1147 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 34:
#line 357 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = "<=";}
#line 1153 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 35:
#line 358 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = ">=";}
#line 1159 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 36:
#line 359 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = "==";}
#line 1165 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 37:
#line 360 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = "!=";}
#line 1171 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 38:
#line 361 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = "~=";}
#line 1177 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 39:
#line 363 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = "<<";}
#line 1183 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 40:
#line 364 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = ">>";}
#line 1189 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 41:
#line 366 "d4_ce_parser.yy" // lalr1.cc:919
    {yylhs.value.as < std::string > () = "@=";}
#line 1195 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 42:
#line 370 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
}
#line 1203 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 43:
#line 374 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ().append("/");
    yylhs.value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
}
#line 1212 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 44:
#line 379 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::string > ().append("/");
    yystack_[2].value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
}
#line 1222 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 45:
#line 387 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ().append("/");
    yylhs.value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
}
#line 1231 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 46:
#line 392 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::string > ().append("/");
    yystack_[2].value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
}
#line 1241 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 47:
#line 400 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > ();
}
#line 1249 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 48:
#line 404 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yystack_[2].value.as < std::string > ().append(".");
    yystack_[2].value.as < std::string > ().append(yystack_[0].value.as < std::string > ());
    yylhs.value.as < std::string > () = yystack_[2].value.as < std::string > ();
}
#line 1259 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 49:
#line 421 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ()=www2id(yystack_[0].value.as < std::string > ());
}
#line 1267 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;

  case 50:
#line 425 "d4_ce_parser.yy" // lalr1.cc:919
    {
    yylhs.value.as < std::string > ()=driver.remove_quotes(yystack_[0].value.as < std::string > ());
}
#line 1275 "d4_ce_parser.tab.cc" // lalr1.cc:919
    break;


#line 1279 "d4_ce_parser.tab.cc" // lalr1.cc:919
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
  D4CEParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  D4CEParser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
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


  const signed char D4CEParser::yypact_ninf_ = -19;

  const signed char D4CEParser::yytable_ninf_ = -47;

  const signed char
  D4CEParser::yypact_[] =
  {
       4,   -19,   -19,    10,    15,     5,   -19,    16,   -19,    30,
       9,    31,     8,   -19,     8,    32,   -19,     4,     4,     1,
      14,    51,    49,    50,    54,    10,    10,   -19,    16,   -19,
      -4,    38,    40,   -19,    28,    29,   -19,   -19,     4,   -19,
      49,    51,     8,    39,   -19,     4,     1,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,     4,   -19,    27,
       7,   -19,   -19,   -19,   -19,    28,    44,   -19,   -19,     4,
     -19,    47,   -19,    46,   -19,   -19
  };

  const unsigned char
  D4CEParser::yydefact_[] =
  {
       0,    49,    50,     0,     0,     0,     4,     2,     7,     9,
      11,     0,    42,    47,    43,    47,     1,     0,     0,     0,
       0,     0,     0,    12,    17,     0,     0,     5,     3,     8,
      11,     0,    10,    27,     0,     0,    20,     6,     0,    14,
       0,     0,    44,    47,    48,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    21,     0,
       0,    16,    19,    31,    28,    29,     0,    24,    26,     0,
      22,     0,    30,     0,    25,    23
  };

  const signed char
  D4CEParser::yypgoto_[] =
  {
     -19,   -19,   -19,    48,    -6,    52,   -19,   -19,   -19,    25,
     -19,    53,    33,   -19,    21,     3,   -18,   -19,     6,    -1
  };

  const signed char
  D4CEParser::yydefgoto_[] =
  {
      -1,     4,     5,     6,     7,     8,     9,    22,    40,    23,
      41,    24,    39,    32,    33,    57,    10,    11,    12,    13
  };

  const signed char
  D4CEParser::yytable_[] =
  {
      30,    34,    15,    20,     1,     2,   -13,     1,     2,    14,
      17,    28,    18,     1,     2,    16,    20,    35,    68,   -13,
      30,    18,    36,    31,    43,    44,     3,    63,    34,     3,
      66,    42,    60,    21,    26,    67,    19,    58,    59,    65,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      73,    72,    70,    71,    75,    74,    25,   -45,    20,    38,
     -15,   -18,    45,    46,   -46,    27,    62,    64,    69,     0,
      29,     0,     0,    61,    37
  };

  const signed char
  D4CEParser::yycheck_[] =
  {
      18,    19,     3,     7,     3,     4,    10,     3,     4,     3,
       5,    17,     5,     3,     4,     0,     7,     3,    11,    10,
      38,     5,     8,    22,    25,    26,    25,    45,    46,    25,
       3,    25,    38,    24,    26,     8,     6,     8,     9,    57,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       3,    69,     8,     9,     8,     8,    25,    25,     7,    10,
      10,     7,    24,    23,    25,    17,    41,    46,    65,    -1,
      18,    -1,    -1,    40,    21
  };

  const unsigned char
  D4CEParser::yystos_[] =
  {
       0,     3,     4,    25,    28,    29,    30,    31,    32,    33,
      43,    44,    45,    46,    45,    46,     0,     5,     5,     6,
       7,    24,    34,    36,    38,    25,    26,    30,    31,    32,
      43,    22,    40,    41,    43,     3,     8,    38,    10,    39,
      35,    37,    45,    46,    46,    24,    23,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    42,     8,     9,
      31,    39,    36,    43,    41,    43,     3,     8,    11,    42,
       8,     9,    43,     3,     8,     8
  };

  const unsigned char
  D4CEParser::yyr1_[] =
  {
       0,    27,    28,    28,    29,    29,    30,    31,    31,    32,
      32,    33,    33,    34,    33,    35,    33,    36,    37,    36,
      38,    38,    38,    38,    38,    38,    39,    40,    40,    41,
      41,    41,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    43,    43,    43,    44,    44,    45,    45,    46,
      46
  };

  const unsigned char
  D4CEParser::yyr2_[] =
  {
       0,     2,     1,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     2,     0,     3,     0,     4,     1,     0,     3,
       2,     3,     5,     7,     4,     6,     3,     1,     3,     3,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     3,     2,     3,     1,     3,     1,
       1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const D4CEParser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"word\"", "\"string\"",
  "\";\"", "\"|\"", "\"[\"", "\"]\"", "\":\"", "\"{\"", "\"}\"", "\"<\"",
  "\">\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "\"~=\"", "\"<<\"",
  "\">>\"", "\"@=\"", "\"ND\"", "\",\"", "\"=\"", "\"/\"", "\".\"",
  "$accept", "expression", "dimensions", "dimension", "clauses", "clause",
  "subset", "$@1", "$@2", "indexes", "$@3", "index", "fields", "filter",
  "predicate", "op", "id", "group", "path", "name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  D4CEParser::yyrline_[] =
  {
       0,   147,   147,   148,   151,   152,   155,   161,   162,   172,
     176,   183,   203,   228,   227,   267,   266,   301,   306,   306,
     311,   312,   313,   314,   315,   316,   319,   325,   326,   337,
     340,   347,   355,   356,   357,   358,   359,   360,   361,   363,
     364,   366,   369,   373,   378,   386,   391,   399,   403,   420,
     424
  };

  // Print the state stack on the debug stream.
  void
  D4CEParser::yystack_print_ ()
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
  D4CEParser::yy_reduce_print_ (int yyrule)
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

  D4CEParser::token_number_type
  D4CEParser::yytranslate_ (int t)
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
      25,    26
    };
    const unsigned user_token_number_max_ = 281;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 35 "d4_ce_parser.yy" // lalr1.cc:1242
} // libdap
#line 1763 "d4_ce_parser.tab.cc" // lalr1.cc:1242
#line 430 "d4_ce_parser.yy" // lalr1.cc:1243


// Forward the error to the driver for handling. The location parameter
// provides the line number and character position of the error.
void
libdap::D4CEParser::error(const location_type &l, const std::string &m)
{
    driver.error(l, m);
}

/* include for access to scanner.yylex */
#include "D4CEScanner.h"

static int yylex(libdap::D4CEParser::semantic_type *yylval,
                 libdap::location *loc,
                 libdap::D4CEScanner &scanner,
                 libdap::D4ConstraintEvaluator &driver)
{
    if (driver.trace_scanning())
        scanner.set_debug(true);
    
    return( scanner.yylex(yylval, loc) );
}
