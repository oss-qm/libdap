
// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of libdap, A C++ implementation of the OPeNDAP Data
// Access Protocol.

// Copyright (c) 2002,2003 OPeNDAP, Inc.
// Author: James Gallagher <jgallagher@opendap.org>
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
 
// (c) COPYRIGHT URI/MIT 1998-1999
// Please read the full copyright statement in the file COPYRIGHT_URI.
//
// Authors:
//      jhrg,jimg       James Gallagher <jgallagher@gso.uri.edu>

#ifndef _rvalue_h
#define _rvalue_h

/** Holds the rvalues for the parser, Clause objects and evaluator.

    @see Clause.h
    @see DDS.h
    @see expr.y */

class rvalue {
private:
    BaseType *value;
    btp_func func;		// pointer to a function returning BaseType *
    std::vector<rvalue *> *args;		// arguments to the function

public:
    typedef std::vector<rvalue *>::iterator Args_iter ;
    typedef std::vector<rvalue *>::const_iterator Args_citer ;

    rvalue(BaseType *bt);
    rvalue(btp_func f, vector<rvalue *> *a);
    rvalue();

    virtual ~rvalue();
    string value_name();

    BaseType *bvalue(const string &dataset, DDS &dds);
};

// This type def must come after the class definition above. It is used in
// the Clause and DDS classes.
typedef std::vector<rvalue *> rvalue_list;
typedef std::vector<rvalue *>::const_iterator rvalue_list_citer ;
typedef std::vector<rvalue *>::iterator rvalue_list_iter ;

rvalue_list *make_rvalue_list(rvalue *rv);
rvalue_list *append_rvalue_list(rvalue_list *rvals, rvalue *rv);

BaseType **build_btp_args(rvalue_list *args, DDS &dds);

#endif // _rvalue_h
