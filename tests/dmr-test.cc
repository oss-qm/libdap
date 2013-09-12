// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of libdap, A C++ implementation of the OPeNDAP Data
// Access Protocol.

// Copyright (c) 2002,2003,2013 OPeNDAP, Inc.
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

// Test the DMR parser

#include "config.h"

#include <fstream>
// #include <tr1/memory>

#include <GetOpt.h>

#include "DMR.h"
#include "D4StreamUnMarshaller.h"
#include "chunked_ostream.h"

#include "util.h"
#include "Error.h"

#include "ResponseBuilder.h"	// clone of code defined by the BES
#include "ConstraintEvaluator.h"

#include "D4ParserSax2.h"
#include "D4TestTypeFactory.h"
#include "TestCommon.h"

#include "util.h"
#include "mime_util.h"
#include "debug.h"

int test_variable_sleep_interval = 0;   // Used in Test* classes for testing timeouts.

using namespace libdap;

/**
 * Open the named XML file and parse it, assuming that it contains a DMR.
 * @param name The name of the DMR XML file (or '-' for stdin)
 * @param debug True if the debug mode of the parse should be used
 * @param print Once parsed, should the DMR object be printed?
 * @return true if the parse worked, false otherwise
 */
DMR *
test_dap4_parser(const string &name, bool debug, bool print)
{
    D4TestTypeFactory *factory = new D4TestTypeFactory;
    DMR *table = new DMR(factory, path_to_filename(name));

    try {
        D4ParserSax2 parser;
        if (name == "-") {
            parser.intern(cin, table, debug);
        }
        else {
            fstream in(name.c_str(), ios_base::in);
            parser.intern(in, table, debug);
        }
    }
    catch(...) {
        delete factory;
        delete table;
        throw;
    }

    cout << "Parse successful" << endl;

    if (print) {
        XMLWriter xml("    ");
        table->print_dap4(xml, false);
        cout << xml.get_doc() << endl;
    }

    return table;
}

/**
 * Should the changing values - meant to mimic the DTS - be used?
 * @param dmr Set for this DMR
 * @param state True to use the DTS-like values, false otherwise
 */
void
set_series_values(DMR *dmr, bool state)
{
	TestCommon *tc = dynamic_cast<TestCommon*>(dmr->root());
	if (tc)
		tc->set_series_values(state);
	else
		cerr << "Could not cast root group to TestCommon (" << dmr->root()->type_name() << ", " << dmr->root()->name() << ")" << endl;
}

/**
 * Call the parser and then serialize the resulting DMR after applying the
 * constraint. The persistent representation is written to a file. The file
 * is name '<name>_data.bin'.
 *
 * @param name The name of the XML file that holds the dataset DMR
 * @param debug Turn on parser debugging
 * @param print Use libdap to print the in-memory DMR/DDS object
 * @param constraint The constraint expression to apply.
 * @param series_values Use the Test* classes' series values?
 * @return The name of the file that hods the response.
 */
string
send_data(DMR *server, const string &constraint, bool series_values, bool multipart)
{
    set_series_values(server, series_values);

    ConstraintEvaluator eval;	// This is a place holder. jhrg 9/6/13
    ResponseBuilder rb;
    rb.set_ce(constraint);
    rb.set_dataset_name(server->name());

    // TODO Remove once real CE evaluator is written. jhrg 9/6/13
    // Mark all variables to be sent in their entirety.
    server->root()->set_send_p(true);

    string file_name = server->name() + "_data.bin";
    ofstream out(file_name.c_str(), ios::out|ios::trunc|ios::binary);
    if (multipart)
    	rb.send_data_dmr_multipart(out, *server, eval, "start", "boundary", true);
    else
    	rb.send_data_dmr(out, *server, eval, true);
    out.close();

    return file_name;
}

DMR *
read_data_multipart(const string &file_name, bool debug)
{
    D4BaseTypeFactory *factory = new D4BaseTypeFactory;
    DMR *dmr = new DMR(factory, "Test_data");

    fstream in(file_name.c_str(), ios::in|ios::binary);

    // Gobble up the response's initial set of MIME headers. Normally
    // a client would extract the boundary and start information from
    // these headers.
    remove_mime_header(in);

    // Read the MPM boundary. dmr-test uses 'boundary' for the boundary
    // marker and 'start' for the CID.
    string boundary = read_multipart_boundary(in, "boundary");
    DBG(cerr << "MPM Boundary: " << boundary << endl);

    // Not passing the fourth param skips testing hte CID header's value
    read_multipart_headers(in, "text/xml", dap4_ddx /*, "start"*/);

    // parse the DMR, stopping when the boundary is found.
    try {
    	D4ParserSax2 parser;
    	parser.intern(in, dmr, "boundary", debug);
    }
    catch(...) {
    	delete factory;
    	delete dmr;
    	throw;
    }

    // If we knew the value of the CID header, we could test for it here by passing
    // it as the fourth parameter.
    read_multipart_headers(in, "application/octet-stream", dap4_data);

    D4StreamUnMarshaller um(in);
    um.set_twiddle_bytes(false);

    dmr->root()->deserialize(um, *dmr);

    return dmr;
}

DMR *
read_data_plain(const string &file_name, bool debug)
{
    D4BaseTypeFactory *factory = new D4BaseTypeFactory;
    DMR *dmr = new DMR(factory, "Test_data");

    fstream in(file_name.c_str(), ios::in|ios::binary);

    // Gobble up the response's initial set of MIME headers. Normally
    // a client would extract information from these headers.
    remove_mime_header(in);

    // FIXME
    // Read the byte-order byte

    // get a chunked input stream

    // parse the DMR, stopping when the boundary is found.
    try {
    	D4ParserSax2 parser;
    	parser.intern(in, dmr, debug);
    }
    catch(...) {
    	delete factory;
    	delete dmr;
    	throw;
    }

    D4StreamUnMarshaller um(in);
    um.set_twiddle_bytes(false);

    dmr->root()->deserialize(um, *dmr);

    return dmr;
}

void
write_chunked_data(const string &file)
{
	fstream infile(file.c_str(), ios::in|ios::binary);
	if (!infile.good())
		cerr << "File not open" << endl;

	string out = file + ".out";
	fstream outfile(out.c_str(), ios::out|ios::binary);

	chunked_ostream chunked_outfile(outfile, 32);
#if 0
	char c;
	infile.get(c);
	int num = infile.gcount();
	while (infile.good()) {
		chunked_outfile.write(&c, num);
		infile.get(c);
		num = infile.gcount();
	}
#endif

	char str[128];
	infile.read(str, 128);
	int num = infile.gcount();
	cerr << "read " << num << " chars" << endl;
	while (infile.good()) {
		chunked_outfile.write(str, num);
		infile.read(str, 128);
		num = infile.gcount();
		cerr << "read " << num << " chars" << endl;
	}
}


void usage()
{
    cerr << "Usage: dmr-test -p|s <file> [-d -x]" << endl
            << "p: parse a file (use "-" for stdin)" << endl
            << "s: parse and then 'send' a response to a file" << endl
            << "t: parse, send and then read the response file" << endl
            << "d: turn on detailed parser debugging" << endl
            << "x: print the binary object(s) built by the parse, send or trans operations." << endl
            << "m: use multipart MIME for the response (default is to follow the spec)." << endl;
}

int
main(int argc, char *argv[])
{
    GetOpt getopt(argc, argv, "p:s:t:xdmc:");
    int option_char;
    bool parse = false;
    bool debug = false;
    bool print = false;
    bool send = false;
    bool trans = false;
    bool multipart = false;
    bool chunked_output = false;
    string name = "";

    // process options

    while ((option_char = getopt()) != EOF)
        switch (option_char) {
        case 'p':
            parse = true;
            name = getopt.optarg;
            break;

        case 's':
        	send = true;
        	name = getopt.optarg;
        	break;

        case 't':
        	trans = true;
        	name = getopt.optarg;
        	break;

        case 'd':
            debug = true;
            break;

        case 'x':
            print = true;
            break;

        case 'm':
        	multipart = true;
        	break;

        case 'c':
        	chunked_output = true;
        	name = getopt.optarg;
        	break;

        case '?':
        case 'h':
            usage();
            return 0;

        default:
            cerr << "Error: ";
            usage();
            return 1;
        }

    if (! (parse || send || trans || chunked_output)) {
        cerr << "Error: ";
        usage();
        return 1;
    }

    try {
        if (parse) {
            DMR *dmr = test_dap4_parser(name, debug, print);
            delete dmr;
        }
        // Add constraint and series values when ready
        if (send) {
        	DMR *server = test_dap4_parser(name, debug, print);
        	string file_name = send_data(server, "", false, multipart);
        	if (print)
        		cout << "Response file:" << file_name << endl;
        	delete server;
        }

        if (trans) {
        	DMR *server = test_dap4_parser(name, debug, print);
        	string file_name = send_data(server, "", false, multipart);
        	if (print)
        		cout << "Response file:" << file_name << endl;
        	delete server;

        	DMR *client = read_data_multipart(file_name, debug);

        	if (print) {
        		XMLWriter xml;
        		client->print_dap4(xml, false /*constrained*/);
        		cout << xml.get_doc() << endl;

				cout << "The data:" << endl;
        	}

        	// if trans is used, the data are printed regardless of print's value
    		client->root()->print_val(cout, "", false);
    		cout << endl;

        	delete client;
        }

        if (chunked_output) {
        	write_chunked_data(name);
        }
    }
    catch (Error &e) {
        cerr << e.get_error_message() << endl;
        return 1;
    }

    return 0;
}

