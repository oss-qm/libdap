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
#line 47 "dds.yy" /* yacc.c:1921  */


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


#line 94 "dds.tab.hh" /* yacc.c:1921  */

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
#line 131 "dds.yy" /* yacc.c:1921  */

    bool boolean;
    char word[ID_MAX];

#line 130 "dds.tab.hh" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ddslval;

int ddsparse (parser_arg *arg);

#endif /* !YY_DDS_DDS_TAB_HH_INCLUDED  */
