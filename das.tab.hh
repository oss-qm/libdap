/* A Bison parser, made by GNU Bison 3.3.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_DAS_DAS_TAB_HH_INCLUDED
# define YY_DAS_DAS_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int dasdebug;
#endif
/* "%code requires" blocks.  */
#line 40 "das.yy" /* yacc.c:1921  */


#define YYSTYPE char *
#define ATTR_STRING_QUOTE_FIX

#include "config.h"

#include <string>

#include <vector>

#include "DAS.h"
#include "Error.h"
#include "util.h"
#include "escaping.h"
#include "debug.h"
#include "parser.h"
#include "util.h"
// #include "das.tab.hh"

#ifdef TRACE_NEW
#include "trace_new.h"
#endif

#define yylex daslex
#define yyerror daserror 

using namespace std;
using namespace libdap ;

// These macros are used to access the `arguments' passed to the parser. A
// pointer to an error object and a pointer to an integer status variable are
// passed in to the parser within a structure (which itself is passed as a
// pointer). Note that the ERROR macro explicitly casts OBJ to an ERROR *. 
// The parser now throws an exception when it encounters an error. 5/23/2002
// jhrg 

#define DAS_OBJ(arg) ((DAS *)((parser_arg *)(arg))->_object)

//#define YYPARSE_PARAM arg

extern int das_line_num;	/* defined in das.lex */


#line 93 "das.tab.hh" /* yacc.c:1921  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SCAN_ATTR = 258,
    SCAN_WORD = 259,
    SCAN_ALIAS = 260,
    SCAN_BYTE = 261,
    SCAN_INT16 = 262,
    SCAN_UINT16 = 263,
    SCAN_INT32 = 264,
    SCAN_UINT32 = 265,
    SCAN_FLOAT32 = 266,
    SCAN_FLOAT64 = 267,
    SCAN_STRING = 268,
    SCAN_URL = 269,
    SCAN_XML = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE daslval;

int dasparse (parser_arg *arg);

#endif /* !YY_DAS_DAS_TAB_HH_INCLUDED  */
