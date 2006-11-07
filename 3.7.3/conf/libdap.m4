# -*- mode: autoconf -*-
# Configure macros for Libdap
#
# Code for version detection and comparison comes from freetype2.m4
# Marcelo Magallon 2001-10-26, based on gtk.m4 by Owen Taylor
#
# Copyright 2001, 2003 by
# David Turner, Robert Wilhelm, and Werner Lemberg.
#
# This file is part of the FreeType project, and may only be used, modified,
# and distributed under the terms of the FreeType project license,
# LICENSE.TXT.  By continuing to use, modify, or distribute this file you
# indicate that you have read the license and understand and accept it
# fully.
#
# As a special exception to the FreeType project license, this file may be
# distributed as part of a program that contains a configuration script
# generated by Autoconf, under the same distribution terms as the rest of
# that program.
#
# modified by Patrice Dumas 2005 for libdap
#
# AC_CHECK_DODS is based on code from gdal configure.in

# AC_CHECK_LIBDAP([MINIMUM-VERSION [, ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
# Test for Libdap and define DAP_CFLAGS and DAP_LIBS.
# Check that the version is above MINIMUM-VERSION 
# use when linking with a c++ aware linker, with a c linker you may also
# need -lstdc++

AC_DEFUN([AC_CHECK_LIBDAP],
[
  AC_PATH_PROG([DAP_CONFIG], [dap-config], [no])
  dap_min_version=m4_if([$1], [], [3.5.0], [$1])
  AC_MSG_CHECKING([for libdap version >= $dap_min_version])
  dap_no=""
  if test "$DAP_CONFIG" = "no" ; then
     dap_no=yes
  else
     dap_config_major_version=`$DAP_CONFIG --version | sed 's/^libdap \([[0-9]]\)*\.\([[0-9]]*\)\.\([[0-9]]*\)$/\1/'`
     dap_config_minor_version=`$DAP_CONFIG --version | sed 's/^libdap \([[0-9]]\)*\.\([[0-9]]*\)\.\([[0-9]]*\)$/\2/'`
     dap_config_micro_version=`$DAP_CONFIG --version | sed 's/^libdap \([[0-9]]\)*\.\([[0-9]]*\)\.\([[0-9]]*\)$/\2/'`
     dap_min_major_version=`echo $dap_min_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
     dap_min_minor_version=`echo $dap_min_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
     dap_min_micro_version=`echo $dap_min_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

     dap_config_is_lt=""
     if test $dap_config_major_version -lt $dap_min_major_version ; then
       dap_config_is_lt=yes
     else
       if test $dap_config_major_version -eq $dap_min_major_version ; then
         if test $dap_config_minor_version -lt $dap_min_minor_version ; then
           dap_config_is_lt=yes
         else
           if test $dap_config_minor_version -eq $dap_min_minor_version ; then
             if test $dap_config_micro_version -lt $dap_min_micro_version ; then
               dap_config_is_lt=yes
             fi
           fi
         fi
       fi
     fi
     if test x$dap_config_is_lt = xyes ; then
       dap_no=yes
     else
       DAP_LIBS="`$DAP_CONFIG --libs`"
       if ($DAP_CONFIG --client-libs 2>&1 | grep unknown) >/dev/null 2>&1; then
         DAP_CLIENT_LIBS=$DAP_LIBS
         DAP_SERVER_LIBS=$DAP_LIBS
       else
         DAP_CLIENT_LIBS="`$DAP_CONFIG --client-libs`"
         DAP_SERVER_LIBS="`$DAP_CONFIG --server-libs`"
       fi
       DAP_CFLAGS="`$DAP_CONFIG --cflags`"
     fi
   fi
   if test x$dap_no = x ; then
     AC_MSG_RESULT([yes])
     m4_if([$2], [], [:], [$2])
   else
     AC_MSG_RESULT([no])
     if test "$DAP_CONFIG" = "no" ; then
     AC_MSG_NOTICE([The dap-config script could not be found.])
     else
       if test x$dap_config_is_lt = xyes ; then
         AC_MSG_NOTICE([the installed libdap library is too old.])
       fi
     fi
     DAP_LIBS=""
     DAP_CFLAGS=""
     m4_if([$3], [], [:], [$3])
   fi
   AC_SUBST([DAP_CFLAGS])
   AC_SUBST([DAP_LIBS])
   AC_SUBST([DAP_CLIENT_LIBS])
   AC_SUBST([DAP_SERVER_LIBS])
]) 

# AC_CHECK_DODS([ ACTION-IF-FOUND [, ACTION-IF-NOT-FOUND]]])
# Test for Libdap or older versions. Define DAP_CFLAGS and DAP_LIBS and
# optionnaly DAP_ROOT

AC_DEFUN([AC_CHECK_DODS],
[
  AC_ARG_WITH([dods_root],
    [AS_HELP_STRING([--with-dods-root=ARG],[DODS root fallback])],
    ,,)

  ac_dods_ok='no'
  DAP_ROOT=
  AC_MSG_CHECKING([DODS specific root])
  if test -z "$with_dods_root" -o "$with_dods_root" = "no"; then
    AC_MSG_RESULT([disabled])
  else
    AC_MSG_RESULT([$with_dods_root])
    DODS_ROOT=$with_dods_root
    DODS_LIB=$with_dods_root/lib
    DODS_INC=$with_dods_root/include
    DODS_BIN=$with_dods_root/bin

    dnl Add the DODS libraries to LIBS
    if test -x "$DODS_BIN/opendap-config" ; then 
      dnl OPeNDAP 3.4 and earlier lack opendap-config, but use it if avail.
      DAP_LIBS="`$DODS_BIN/opendap-config --libs`"
      DAP_CFLAGS="`$DODS_BIN/opendap-config --cflags`"
      ac_dods_ok='yes'
    elif test -x "$DODS_BIN/dap-config" ; then
      dnl for OPeNDAP 3.5
      DAP_LIBS="`$DODS_BIN/dap-config --libs`"
      DAP_CFLAGS="`$DODS_BIN/dap-config --cflags`"
      ac_dods_ok='yes'
    else
      dnl Otherwise try to put things together in a more primitive way.
      DAP_LIBS="-L$DODS_LIB -ldap++ -lpthread"
      DAP_CFLAGS="-I$DODS_INC"
    
      ac_dods_curl='yes'
      dnl Add curl to LIBS; it might be local to DODS or generally installed
      AC_MSG_CHECKING([For curl])
      if test -x "$DODS_BIN/curl-config"; then
         DAP_LIBS="$DAP_LIBS  `$DODS_BIN/curl-config --libs`"
      elif which curl-config > /dev/null 2>&1; then
         DAP_LIBS="$DAP_LIBS  `curl-config --libs`"
      else
         ac_dods_curl='no'
      fi
      if test $ac_dods_curl = 'no' ; then
         AC_MSG_RESULT([no]) 
         dnl AC_MSG_WARN([You gave a dods root, but I can't find curl!])
      else
         AC_MSG_RESULT([yes])
      fi 
         
      
      AC_MSG_CHECKING([For libxml2])
      ac_dods_xml2='yes'
      if test -x "$DODS_BIN/xml2-config"; then
         DAP_LIBS="$DAP_LIBS `$DODS_BIN/xml2-config --libs`"
      elif which xml2-config > /dev/null 2>&1; then
         DAP_LIBS="$DAP_LIBS  `xml2-config --libs`"
      else
         ac_dods_xml2='no'
      fi
      if test $ac_dods_xml2 = 'no' ; then
         AC_MSG_RESULT([no]) 
         dnl AC_MSG_WARN([You gave a dods root, but I can't find xml2!])
      else
         AC_MSG_RESULT([yes])
      fi 
         
      AC_LANG_PUSH([C++])
      if test $ac_dods_xml2 = 'yes' -a $ac_dods_curl = 'yes'; then
         dnl We check that linking is succesfull
         ac_save_LIBS=$LIBS
         ac_save_CFLAGS=$CFLAGS
         LIBS="$LIBS $DAP_LIBS"
         CFLAGS="$CFLAGS $DAP_CFLAGS"
         dnl AC_CHECK_LIB is not used because it caches results
         dnl AC_CHECK_LIB([dap++],[main],[ac_dods_ok='yes'],[ac_dods_ok='no'])
         AC_MSG_CHECKING([for DODS with curl and libxml2])
         AC_LINK_IFELSE([AC_LANG_CALL([],[main])],[
           ac_dods_ok='yes'
           AC_MSG_RESULT([yes])
         ],[
           ac_dods_ok='no'
           AC_MSG_RESULT([no])
         ])
         LIBS=$ac_save_LIBS
         CFLAGS=$ac_save_CFLAGS
         if test "z$ac_dods_ok" = "zno"; then
           ac_save_LIBS=$LIBS
           ac_save_CFLAGS=$CFLAGS
           LIBS="$LIBS $DAP_LIBS -lrx"
           CFLAGS="$CFLAGS $DAP_CFLAGS"
           AC_MSG_CHECKING([for DODS with curl, libxml2 and librx])
           AC_LINK_IFELSE([AC_LANG_CALL([],[main])],[
               AC_MSG_RESULT([yes])
               ac_dods_ok='yes'
               DAP_LIBS="$DAP_LIBS -lrx"
           ],[
               ac_dods_ok='no'
               AC_MSG_RESULT([no])
           ])
           LIBS=$ac_save_LIBS
           CFLAGS=$ac_save_CFLAGS
         fi
      fi
      if test $ac_dods_ok = 'no'; then
         dnl assume it is an old version of DODS
         AC_MSG_NOTICE([Checking for DODS with libwww and librx])
         DAP_LIBS="-L$DODS_LIB -ldap++ -lwww -lpthread -lrx"
         DAP_CFLAGS="-I$DODS_INC"
         ac_save_LIBS=$LIBS
         ac_save_CFLAGS=$CFLAGS
         LIBS="$LIBS $DAP_LIBS"
         CFLAGS="$CFLAGS $DAP_CFLAGS"
         AC_CHECK_LIB([dap++],[main],[ac_dods_ok='yes'],[ac_dods_ok='no'])
         LIBS=$ac_save_LIBS
         CFLAGS=$ac_save_CFLAGS
      fi
      AC_LANG_POP
    fi
      
    AC_MSG_CHECKING([for DODS in a specific root])
    if test "z$ac_dods_ok" = "zyes"; then
       AC_MSG_RESULT([yes])
       AC_MSG_NOTICE([setting DAP_ROOT directory to $DODS_ROOT])
       DAP_ROOT=$DODS_ROOT
    else
       AC_MSG_RESULT([no])
    fi
  fi
  if test "z$ac_dods_ok" = "zno" ; then
     AC_CHECK_LIBDAP([],[ac_dods_ok='yes'],[ac_dods_ok='no'])
     if test "z$ac_dods_ok" = "zno" ; then
       AC_PATH_PROG([OPENDAP_CONFIG], [opendap-config], [no])
       AC_MSG_CHECKING([for libdap with opendap-config])
       if test "$OPENDAP_CONFIG" = "no" ; then
         ac_dods_ok='no'
         AC_MSG_RESULT([no])
       else
         DAP_LIBS="`$OPENDAP_CONFIG --libs`"
         DAP_CFLAGS="`$OPENDAP_CONFIG --cflags`"
         ac_dods_ok='yes'
         AC_MSG_RESULT([yes])
       fi
     fi
  fi 
  if test "x$ac_dods_ok" = "xyes" ; then
     if test "z$DAP_CLIENT_LIBS" = 'z' ; then
       DAP_CLIENT_LIBS=$DAP_LIBS
       DAP_SERVER_LIBS=$DAP_LIBS
     fi
     m4_if([$1], [], [:], [$1])
  else
     DAP_LIBS=""
     DAP_CFLAGS=""
     DAP_CLIENT_LIBS=""
     DAP_SERVER_LIBS=""
     m4_if([$2], [], [:], [$2])
  fi
  AC_SUBST([DAP_CFLAGS])
  AC_SUBST([DAP_LIBS])
  AC_SUBST([DAP_CLIENT_LIBS])
  AC_SUBST([DAP_SERVER_LIBS])
  AC_SUBST([DAP_ROOT])
])
