
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
 
#ifndef event_handler_h
#define event_handler_h

#include <stdio.h>

#include <iostream>

#include "Error.h"
#include "cgi_util.h"

/** An abstract class which provides a hook method used by SignalHandler.

    Based on "Applying Design Patterns to Simplify Signal Handling", Douglas
    C. Schmidt, 1998, http://www.cs.wustl.edu/~schmidt/signal-patterns.html.

    @see SignalHandler
    @see AlarmHandler
    @author James Gallagher <jgallagher@opendap.org> */
class EventHandler
{
public:
    /** Hook method for SignalHandler. If a concrete instance of this class
	is registered with SignalHandler, this method will be called when \c
	signum is received. */
    virtual void handle_signal (int signum) = 0;

    /** We don't need a destructor, but including one might stave off an
	error later on... */
    virtual ~EventHandler() {}
};

/** Test Handler. This is used with the SignalHandlerTest unit tests. */
class TestHandler : public EventHandler {
public:
    int flag;

    TestHandler() : flag(0) {}

    virtual void handle_signal(int signum) {
	std::cerr << "Got signal: " << signum << std::endl;
	flag = 1;
    }
};

// $Log: EventHandler.h,v $
// Revision 1.3  2004/02/19 19:42:52  jimg
// Merged with release-3-4-2FCS and resolved conflicts.
//
// Revision 1.1.2.3  2004/02/10 21:06:44  jimg
// I removed AlarmHandler from this class and put it in its own header.
//
// Revision 1.2  2003/12/08 18:02:29  edavis
// Merge release-3-4 into trunk
//
// Revision 1.1.2.2  2003/07/23 23:56:36  jimg
// Now supports a simple timeout system.
//
// Revision 1.1.2.1  2003/07/19 01:48:37  jimg
// Added.
//

#endif // event_handler_h