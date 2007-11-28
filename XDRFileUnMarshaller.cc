// XDRFileUnMarshaller.cc

// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of libdap, A C++ implementation of the OPeNDAP Data
// Access Protocol.

// Copyright (c) 2002,2003 OPeNDAP, Inc.
// Author: Patrick West <pwest@ucar.edu>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// You can contact OPeNDAP, Inc. at PO Box 112, Saunderstown, RI. 02874-0112.

// (c) COPYRIGHT URI/MIT 1994-1999
// Please read the full copyright statement in the file COPYRIGHT_URI.
//
// Authors:
//      pwest       Patrick West <pwest@ucar.edu>

#include "XDRFileUnMarshaller.h"

#include "Vector.h"
#include "util.h"
#include "InternalErr.h"

XDRFileUnMarshaller::XDRFileUnMarshaller( FILE *out )
    : _source( 0 )
{
    _source = new_xdrstdio( out, XDR_DECODE ) ;
}

XDRFileUnMarshaller::XDRFileUnMarshaller()
    : UnMarshaller(),
      _source( 0 )
{
    throw InternalErr( __FILE__, __LINE__, "Default constructor not implemented." ) ;
}

XDRFileUnMarshaller::XDRFileUnMarshaller( const XDRFileUnMarshaller &um )
    : UnMarshaller( um ),
      _source( 0 )
{
    throw InternalErr( __FILE__, __LINE__, "Copy constructor not implemented." ) ;
}

XDRFileUnMarshaller &
XDRFileUnMarshaller::operator=( const XDRFileUnMarshaller & )
{
    throw InternalErr( __FILE__, __LINE__, "Copy operator not implemented." ) ;

    return *this ;
}

XDRFileUnMarshaller::~XDRFileUnMarshaller( )
{
    delete_xdrstdio( _source ) ;
}

void
XDRFileUnMarshaller::get_byte( dods_byte &val )
{
    if( !xdr_char( _source, (char *)&val ) )
        throw Error("Network I/O Error. Could not read byte data. This may be due to a\nbug in DODS or a problem with the network connection.");
}

void
XDRFileUnMarshaller::get_int16( dods_int16 &val )
{
    if( !XDR_INT16( _source, &val ) )
        throw Error("Network I/O Error. Could not read int 16 data. This may be due to a\nbug in libdap or a problem with the network connection.");
}

void
XDRFileUnMarshaller::get_int32( dods_int32 &val )
{
    if( !XDR_INT32( _source, &val ) )
        throw Error("Network I/O Error. Could not read int 32 data. This may be due to a\nbug in libdap or a problem with the network connection.");
}

void
XDRFileUnMarshaller::get_float32( dods_float32 &val )
{
    if( !xdr_float( _source, &val ) )
        throw Error("Network I/O Error. Could not read float 32 data. This may be due to a\nbug in libdap or a problem with the network connection.");
}

void
XDRFileUnMarshaller::get_float64( dods_float64 &val )
{
    if( !xdr_double( _source, &val ) )
        throw Error("Network I/O Error. Could not read float 64 data. This may be due to a\nbug in libdap or a problem with the network connection.");
}

void
XDRFileUnMarshaller::get_uint16( dods_uint16 &val )
{
    if( !XDR_UINT16( _source, &val ) )
        throw Error("Network I/O Error. Could not read uint 16 data. This may be due to a\nbug in libdap or a problem with the network connection.");
}

void
XDRFileUnMarshaller::get_uint32( dods_uint32 &val )
{
    if( !XDR_UINT32( _source, &val ) )
        throw Error("Network I/O Error. Could not read uint 32 data. This may be due to a\nbug in libdap or a problem with the network connection.");
}

void
XDRFileUnMarshaller::get_str( string &val )
{
    char *in_tmp = NULL ;

    if( !xdr_string( _source, &in_tmp, max_str_len ) )
        throw Error("Network I/O Error. Could not read string data.\nThis may be due to a bug in libdap, on the server or a\nproblem with the network connection.");

    val = in_tmp ;

    free( in_tmp ) ;
}

void
XDRFileUnMarshaller::get_url( string &val )
{
    get_str( val ) ;
}

void
XDRFileUnMarshaller::get_opaque( char *val, unsigned int len )
{
    xdr_opaque( _source, val, len ) ;
}

void
XDRFileUnMarshaller::get_int( int &val )
{
    if( !xdr_int( _source, &val ) )
	throw Error("Network I/O Error(1). This may be due to a bug in libdap or a\nproblem with the network connection.");
}

void
XDRFileUnMarshaller::get_vector( char **val, unsigned int &num, Vector & )
{
    if( !xdr_bytes( _source, val, &num, DODS_MAX_ARRAY) )
	throw Error("Network I/O error. Could not read packed array data.\nThis may be due to a bug in libdap or a problem with\nthe network connection.");
}

void
XDRFileUnMarshaller::get_vector( char **val, unsigned int &num, int width, Vector &vec )
{
    BaseType *var = vec.var() ;

    if( !xdr_array( _source, val, &num, DODS_MAX_ARRAY, width,
		    XDRUtils::xdr_coder( var->type() ) ) )
    {
	throw Error("Network I/O error. Could not read packed array data.\nThis may be due to a bug in libdap or a problem with\nthe network connection.");
    }
}

void
XDRFileUnMarshaller::dump(ostream &strm) const
{
    strm << DapIndent::LMarg << "XDRFileUnMarshaller::dump - ("
         << (void *)this << ")" << endl ;
}

