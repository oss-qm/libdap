
dnl -*- autoconf -*-
dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT(libdap, 3.5.0, dods-tech@unidata.ucar.edu)
AC_CONFIG_SRCDIR([AISConnect.cc])
AC_CONFIG_HEADER([config_dap.h dods-datatypes.h regex-0.12/config.h])

AC_DEFINE(CNAME, "libdap", [What sort of HTTP client is this?])
AC_DEFINE_UNQUOTED(CVER, "$PACKAGE_VERSION", [Client version number])
AC_DEFINE_UNQUOTED(DVR, "${CNAME}/${CVER}", [Client name and vesion combined])
AC_SUBST(DVR)

dnl flags for the compilers and linkers - set these before locating the
dnl actual tools since some of the AC_PROG macros set these `flag variables'
dnl to default values otherwise.

AC_CANONICAL_HOST
AC_SUBST(host)

# Until further notice OS X port doesn't get -gstabs because of an
# apparent bug in their gcc 3.3 clone (a beta).  If you see this after
# 1/1/2005, you can probably remove it.
case "${host_cpu}:${host_vendor}:${host_os}" in
     powerpc:apple:netbsd* | alphaev56:dec:osf5.*)
       CFLAGS=${CFLAGS-"-O2 $CFLAGS"}
       CXXFLAGS=${CXXFLAGS-"-O2 $CXXFLAGS"}
       break;;
    *:*:*)
       CFLAGS=${CFLAGS-"-gstabs -O2 $CFLAGS"}
       CXXFLAGS=${CXXFLAGS-"-gstabs -O2 $CXXFLAGS"}
       break;;
esac    

dnl Default to g++

CXX=${CXX-g++}
AC_MSG_RESULT(Setting CXX to $CXX)
AC_SUBST(CXX)

# Checks for programs.
AC_PROG_AWK
AC_PROG_YACC
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LEX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB

dnl DODS_PROG_BISON
dnl AC_CHECK_PROG(YACC,bison,bison)

dnl Find where perl lives on the user's system
DODS_PROG_PERL
dnl Find where GNU tar lives on the user's system
DODS_PROG_GTAR

dnl The command to use to generate dependencies for Makefiles
depend=./depend.sh
AC_SUBST(depend)


AC_CHECK_PROG(VALGRIND, valgrind, [valgrind --logfile=memcheck --tool=memcheck --leak-check=yes])

# Checks for header files.
AC_FUNC_ALLOCA
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([fcntl.h malloc.h memory.h netinet/in.h stddef.h stdlib.h string.h strings.h sys/param.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_MEMBERS([struct stat.st_blksize])
AC_HEADER_TIME
AC_STRUCT_TM
AC_C_VOLATILE
DODS_CHECK_SIZES

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_FUNC_MKTIME
AC_FUNC_REALLOC
AC_FUNC_STAT
AC_FUNC_STRFTIME
AC_FUNC_STRTOD
AC_CHECK_FUNCS([alarm atexit bzero dup2 getcwd getpagesize localtime_r memmove memset pow putenv re_comp regcomp setenv strchr strerror strstr strtol strtoul])
# Added 04/22/05 jhrg
AC_CHECK_FUNCS([timegm mktime])

dnl I wrote these checks because we need the *-config scripts to build, so 
dnl the AC_CHECK_LIB macro is not needed.
AC_MSG_CHECKING([for libcurl])
if curl-config --version > /dev/null 2>&1
then
	version_libcurl=`curl-config --version`
	version_major=`echo $version_libcurl | sed 's@^libcurl \([[0-9]]\)*\.\([[0-9]]*\)\.\([[0-9]]*\)$@\1@'`
	version_minor=`echo $version_libcurl | sed 's@^libcurl \([[0-9]]\)*\.\([[0-9]]*\)\.\([[0-9]]*\)$@\2@'`
	if test $version_major -lt 7 || test $version_minor -lt 12
	then
		AC_MSG_ERROR([must have libcurl 7.12.0 or greater, found $version_libcurl])
	fi

	LIBS="$LIBS `curl-config --libs`"
	INCS="$INCS `curl-config --cflags`"
	AC_MSG_RESULT([yes])
else
	AC_MSG_ERROR([I could not find libcurl])
fi

dnl AC_CHECK_LIB([curl], [curl_version], 
dnl 	[LIBS="$LIBS `curl-config --libs`"
dnl 	 INCS="$INCS `curl-config --cflags`"],
dnl 	[AC_MSG_ERROR([I could not find libcurl])]
dnl 	[`curl-config --libs`])

AC_MSG_CHECKING([for libxml2])
if xml2-config --version > /dev/null 2>&1
then
	LIBS="$LIBS `xml2-config --libs`"
	INCS="$INCS `xml2-config --cflags`"
	AC_MSG_RESULT([yes])
else
	AC_MSG_ERROR([I could not find libxml2])
fi

dnl AC_CHECK_LIB([xml2], [xmlInitGlobals],
dnl 	[LIBS="$LIBS `xml2-config --libs`"
dnl 	 INCS="$INCS `xml2-config --cflags`"],
dnl 	[AC_MSG_ERROR([I could not find libxml2])]
dnl 	[`xml2-config --libs`])

AC_CHECK_LIB([pthread], [pthread_kill], 
	[LIBS="$LIBS -lpthread"],
	[AC_MSG_ERROR([I could not find pthreads])])
dnl LIBS="$LIBS -lpthread"

dnl temporary hack for the librx/regex code. 04/08/04 jhrg.
dnl INCS="-Iregex-0.12 $INCS"
dnl REGEX_C=regex-0.12/regex.c
dnl AC_SUBST(REGEX_C)
dnl echo "Setting $REGEX_C"
dnl REGEX_O=regex-0.12/regex.o
dnl AC_SUBST(REGEX_O)

DODS_DEBUG_OPTION

dnl autoheader macros; tack some text at the top and bottom of config_dap.h.in

AH_TOP([#ifndef _config_dap_h
#define _config_dap_h])

AH_BOTTOM([/* Shorthand for gcc's unused attribute feature */
#if defined(__GNUG__) || defined(__GNUC__)
#define not_used __attribute__ ((unused))
#else
#define not_used 
#endif /* __GNUG__ || __GNUC__ */

#endif /* _config_dap_h */])

dnl Temporary hack; find a home for the deflate program; set it to
dnl prefix/etc/deflate. Seeutil.cc:dods_root()
if test "$prefix" = "NONE"
then
AC_DEFINE([LIBDAP_ROOT], ["/usr/local"], [Set to the prefix directory])
else
AC_DEFINE_UNQUOTED([LIBDAP_ROOT], ["$prefix"], [Set to the prefix directory])
fi

dnl INCS is non-standard...
AC_SUBST(INCS)

AC_CONFIG_FILES([Makefile
                 regex-0.12/Makefile
                 regex-0.12/doc/Makefile
                 regex-0.12/test/Makefile
                 tests/Makefile
		 libdap-config])
AC_OUTPUT


dnl AC_OUTPUT(Makefile tests/Makefile opendap-config)