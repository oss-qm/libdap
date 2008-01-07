# include_next.m4 serial 2
dnl Copyright (C) 2006, 2007 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

dnl From Paul Eggert and Derek Price.

AC_DEFUN([gl_INCLUDE_NEXT],
[
  AC_LANG_PREPROC_REQUIRE()
  AC_CACHE_CHECK([whether the preprocessor supports include_next],
    [gl_cv_have_include_next],
    [AC_PREPROC_IFELSE([#include_next <stddef.h>],
       [gl_cv_have_include_next=yes],
       [gl_cv_have_include_next=no])])
  if test $gl_cv_have_include_next = yes; then

    dnl FIXME: Remove HAVE_INCLUDE_NEXT and update everything that uses it
    dnl to use @INCLUDE_NEXT@ instead.
    AC_DEFINE([HAVE_INCLUDE_NEXT], 1,
	      [Define if your compiler supports the #include_next directive.])

    INCLUDE_NEXT=include_next
  else
    INCLUDE_NEXT=include
  fi
  AC_SUBST([INCLUDE_NEXT])
])

# gl_CHECK_NEXT_HEADERS(HEADER1 HEADER2 ...)
# ------------------------------------------
# For each arg foo.h, if #include_next works, define NEXT_FOO_H to be
# '<foo.h>'; otherwise define it to be
# '"///usr/include/foo.h"', or whatever other absolute file name is suitable.
# That way, a header file with the following line:
#	#@INCLUDE_NEXT@ @NEXT_FOO_H@
# behaves (after sed substitution) as if it contained
#	#include_next <foo.h>
# even if the compiler does not support include_next.
# The three "///" are to pacify Sun C 5.8, which otherwise would say
# "warning: #include of /usr/include/... may be non-portable".
# Use `""', not `<>', so that the /// cannot be confused with a C99 comment.
AC_DEFUN([gl_CHECK_NEXT_HEADERS],
[
  AC_REQUIRE([gl_INCLUDE_NEXT])
  AC_CHECK_HEADERS_ONCE([$1])

  AC_FOREACH([gl_HEADER_NAME], [$1],
    [AS_VAR_PUSHDEF([gl_next_header],
		    [gl_cv_next_]m4_quote(m4_defn([gl_HEADER_NAME])))
     AS_VAR_SET([gl_next_header], ['<'gl_HEADER_NAME'>'])
     if test $gl_cv_have_include_next = no; then
       AC_CACHE_CHECK(
	 [absolute name of <]m4_quote(m4_defn([gl_HEADER_NAME]))[>],
	 m4_quote(m4_defn([gl_next_header])),
	 [if test AS_VAR_GET([ac_cv_header_]m4_quote(m4_defn([gl_HEADER_NAME]))) = yes; then
	    AC_LANG_CONFTEST(
	      [AC_LANG_SOURCE(
		 [[#include <]]m4_dquote(m4_defn([gl_HEADER_NAME]))[[>]]
	       )])
	    dnl eval is necessary to expand ac_cpp.
	    dnl Ultrix and Pyramid sh refuse to redirect output of eval,
	    dnl so use subshell.
	    AS_VAR_SET([gl_next_header],
	      ['"'`(eval "$ac_cpp conftest.$ac_ext") 2>&AS_MESSAGE_LOG_FD |
	       sed -n '\#/]m4_quote(m4_defn([gl_HEADER_NAME]))[#{
		 s#.*"\(.*/]m4_quote(m4_defn([gl_HEADER_NAME]))[\)".*#\1#
		 s#^/[^/]#//&#
		 p
		 q
	       }'`'"'])
	  fi])
     fi
     AC_SUBST(
       AS_TR_CPP([NEXT_]m4_quote(m4_defn([gl_HEADER_NAME]))),
       [AS_VAR_GET([gl_next_header])])
     AS_VAR_POPDEF([gl_next_header])])
])