
// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of libdap, A C++ implementation of the OPeNDAP Data
// Access Protocol.

// Copyright (c) 2002,2003 OPeNDAP, Inc.
// Author: James Gallagher <jgallagher@opendap.org>
//         Dan Holloway <dan@hollywood.gso.uri.edu>
//         Reza Nekovei <reza@intcomm.net>
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
 
// (c) COPYRIGHT URI/MIT 1994-1999,2001,2002
// Please first read the full copyright statement in the file COPYRIGHT_URI.
//
// Authors:
//	jhrg,jimg	James Gallagher <jgallagher@gso.uri.edu>
//	dan		Dan Holloway <dholloway@gso.uri.edu>
//	reza		Reza Nekovei <rnekovei@ieee.org>

// Connect objects are used as containers for information pertaining to a
// connection that a user program makes to a dataset. The dataset may be
// either local (i.e., a file on the user's own computer) or a remote
// dataset. In the later case a DAP2 URL will be used to reference the
// dataset. 
//
// Connect contains methods which can be used to read the DOS DAS and DDS
// objects from the remote dataset as well as reading reading data. The class
// understands in a rudimentary way how DAP2 constraint expressions are
// formed and how to manage the CEs generated by a API to request specific
// variables with the URL initially presented to the class when the object
// was instantiated.
//
// Connect also provides additional services such as error processing.
//
// Connect is not intended for use on the server-side.
//
// jhrg 9/29/94

#ifndef _connect_h
#define _connect_h


#include <stdio.h>

#include <string>

#ifndef _das_h
#include "DAS.h"
#endif

#ifndef _dds_h
#include "DDS.h"
#endif

#ifndef _error_h
#include "Error.h"
#endif

#ifndef _util_h
#include "util.h"
#endif

#ifndef _datadds_h
#include "DataDDS.h"
#endif

#ifndef _httpconnect_h
#include "HTTPConnect.h"
#endif

#ifndef response_h
#include "Response.h"
#endif

using std::string;

/** Connect objects are used as containers for information pertaining
    to the connection a user program makes to a dataset. The
    dataset may be either local (for example, a file on the user's own
    computer) or a remote dataset. In the latter case a DAP2 URL will
    be used to reference the dataset, instead of a filename.

    Connect contains methods which can be used to read the DAP2 DAS and
    DDS objects from the remote dataset as well as reading 
    data. The class understands in a rudimentary way how DAP2
    constraint expressions are formed and how to manage them.

    Connect also provides additional services such as automatic
    decompression of compressed data, transmission progress reports
    and error processing.  Refer to the Gui and Error classes for more
    information about these features. See the DODSFilter class for
    information on servers that compress data.

    @note Update: I removed the DEFAULT_BASETYPE_FACTORY switch because it
    caused more confusion than it avoided. See Trac #130.

    @note The compile-time symbol DEFAULT_BASETYPE_FACTORY controls whether
    the old (3.4 and earlier) DDS and DataDDS constructors are supported.
    These constructors now use a default factory class (BaseTypeFactory,
    implemented by this library) to instantiate Byte, ..., Grid variables. To
    use the default ctor in your code you must also define this symbol. If
    you \e do choose to define this and fail to provide a specialization of
    BaseTypeFactory when your software needs one, you code may not link or
    may fail at run time. In addition to the older ctors for DDS and DataDDS,
    defining the symbol also makes some of the older methods in Connect
    available (because those methods require the older DDS and DataDDS ctors.

    @brief Holds information about the link from a DAP2 client to a
    dataset.
    @see DDS
    @see DAS
    @see DODSFilter
    @see Error
    @author jhrg */

class Connect {
private:
    bool _local;		// Is this a local connection?

    HTTPConnect *d_http;
    string _URL;		// URL to remote dataset (minus CE)
    string _proj;		// Projection part of initial CE.
    string _sel;		// Selection of initial CE

    string d_version;           // Server implementation information
    string d_protocol;          // DAP protocol from the server

    void process_data(DataDDS &data, Response *rs);
    
    // Use when you cannot use libwww/libcurl. Reads HTTP response. 
    void parse_mime(Response *rs);

protected:
    /** @name Suppress the C++ defaults for these. */
    //@{
    Connect() { }
    Connect(const Connect &) { }
    Connect &operator=(const Connect &) {
	throw InternalErr(__FILE__, __LINE__, "Unimplemented assignment");
    }
    //@}

public:
    Connect(const string &name, string uname = "", string password = "") 
	throw (Error, InternalErr); 

    virtual ~Connect();

    bool is_local();

    // *** Add get_* versions of accessors. 02/27/03 jhrg
    virtual string URL(bool CE = true);
    virtual string CE();
    
    void set_credentials(string u, string p);
    void set_accept_deflate(bool deflate);

    void set_cache_enabled(bool enabled);
    bool is_cache_enabled();

    /** Return the protocol/implementation version of the most recent
	response. This is a poorly designed method, but it returns
	information that is useful when used correctly. Before a response is
	made, this contains the string "unknown." This should ultimately hold
	the \e protocol version; it currently holds the \e implementation
	version. 
        
        @see get_protocol()
        @deprecated */
    string get_version() { return d_version; }

    /** Return the DAP protocol version of the most recent
        response. Before a response is made, this contains the string "2.0."
        */
    string get_protocol() { return d_protocol; }

    
    virtual string request_version();
    virtual string request_protocol();

    virtual void request_das(DAS &das);
    virtual void request_das_url(DAS &das);

    virtual void request_dds(DDS &dds, string expr = "");
    virtual void request_dds_url(DDS &dds);

    virtual void request_ddx(DDS &dds, string expr = "");
    virtual void request_ddx_url(DDS &dds);

    virtual void request_data(DataDDS &data, string expr = "");
    virtual void request_data_url(DataDDS &data);

    virtual void read_data(DataDDS &data, Response *rs);
    virtual void read_data_no_mime(DataDDS &data, Response *rs);
};

#endif // _connect_h
