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

// (c) COPYRIGHT URI/MIT 1994-1999
// Please read the full copyright statement in the file COPYRIGHT_URI.
//
// Authors:
//      jhrg,jimg       James Gallagher <jgallagher@gso.uri.edu>

// Provide access to the DDS. This class is used to parse DDS text files, to
// produce a printed representation of the in-memory variable table, and to
// update the table on a per-variable basis.
//
// jhrg 9/8/94

#ifndef _dds_h
#define _dds_h 1

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#ifndef _basetype_h
#include "BaseType.h"
#endif

#ifndef _constructor_h
#include "Constructor.h"
#endif

#ifndef base_type_factory_h
#include "BaseTypeFactory.h"
#endif

#ifndef _das_h
#include "DAS.h"
#endif

#ifndef A_DapObj_h
#include "DapObj.h"
#endif

using std::cout;

namespace libdap
{

/** The DAP2 Data Descriptor Object (DDS) is a data structure used by
    the DAP2 software to describe datasets and subsets of those
    datasets.  The DDS may be thought of as the declarations for the
    data structures that will hold data requested by some DAP2 client.
    Part of the job of a DAP2 server is to build a suitable DDS for a
    specific dataset and to send it to the client.  Depending on the
    data access API in use, this may involve reading part of the
    dataset and inferring the DDS.  Other APIs may require the server
    simply to read some ancillary data file with the DDS in it.

    On the server side, in addition to the data declarations, the DDS
    holds the clauses of any constraint expression that may have
    accompanied the data request from the DAP2 client.  The DDS object
    includes methods for modifying the DDS according to the given
    constraint expression.  It also has methods for directly modifying
    a DDS, and for transmitting it from a server to a client.

    For the client, the DDS object includes methods for reading the
    persistent form of the object sent from a server. This includes parsing
    the ASCII representation of the object and, possibly, reading data
    received from a server into a data object.

    Note that the class DDS is used to instantiate both DDS and DataDDS
    objects. A DDS that is empty (contains no actual data) is used by servers
    to send structural information to the client. The same DDS can becomes a
    DataDDS when data values are bound to the variables it defines.

    For a complete description of the DDS layout and protocol, please
    refer to <i>The OPeNDAP User Guide</i>.

    The DDS has an ASCII representation, which is what is transmitted
    from a DAP2 server to a client.  Here is the DDS representation of
    an entire dataset containing a time series of worldwide grids of
    sea surface temperatures:

    <pre>
    Dataset {
        Float64 lat[lat = 180];
        Float64 lon[lon = 360];
        Float64 time[time = 404];
        Grid {
         ARRAY:
            Int32 sst[time = 404][lat = 180][lon = 360];
         MAPS:
            Float64 time[time = 404];
            Float64 lat[lat = 180];
            Float64 lon[lon = 360];
        } sst;
    } weekly;
    </pre>

    If the data request to this dataset includes a constraint
    expression, the corresponding DDS might be different.  For
    example, if the request was only for northern hemisphere data
    at a specific time, the above DDS might be modified to appear like
    this:

    <pre>
    Dataset {
        Grid {
         ARRAY:
            Int32 sst[time = 1][lat = 90][lon = 360];
         MAPS:
            Float64 time[time = 1];
            Float64 lat[lat = 90];
            Float64 lon[lon = 360];
        } sst;
    } weekly;
    </pre>

    Since the constraint has narrowed the area of interest, the range
    of latitude values has been halved, and there is only one time
    value in the returned array.  Note that the simple arrays (<tt>lat</tt>,
    <tt>lon</tt>, and <tt>time</tt>) described in the dataset are also
    part of the <tt>sst</tt> Grid object.  They can be requested by
    themselves or as part of that larger object.

    See the <i>The OPeNDAP User Guide</i>, or the documentation of the
    BaseType class for descriptions of the DAP2 data types.

    @note Make sure to pass a valid pointer to the DDS constructor or use
    the set_factory() method before actually using the DDS. Also make sure
    that the Factory's lifetime thereafter is the same as the DDS's. Never
    delete the factory until you're done using the DDS.

    @note Update: I removed the DEFAULT_BASETYPE_FACTORY switch because it
    caused more confusion than it avoided. See Trac #130. jhrg

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

    @see BaseType
    @see DAS */

class DDS : public DapObj
{
private:
    BaseTypeFactory *d_factory;

    string name;                // The dataset name
    string d_filename;		// File name (or other OS identifier) for
    string d_container_name;	// name of container structure
    Structure *d_container;	// current container for container name
				// dataset or part of dataset.

    // These are used on the client-side and correspond to the version of the
    // response. The client_dap_major/minor fields hold information sent from
    // a client describing what it would like.

    int d_dap_major;       // The protocol major version number
    int d_dap_minor;       // ... and minor version number
#if 0
    // Get rid of these???
    // TODO
    // These hold the major and minor versions of DAP that the client sent in
    // the XDAP-Accept header. If the header is not sent, these default to 2.0
    int d_client_dap_major;
    int d_client_dap_minor;
#endif
    string d_request_xml_base;

    AttrTable d_attr;           // Global attributes.

    vector<BaseType *> vars;    // Variables at the top level
#if 0
    bool is_global_attr(string name);
    void add_global_attribute(AttrTable::entry *entry);
#endif
    BaseType *find_hdf4_dimension_attribute_home(AttrTable::entry *source);

    int d_timeout;              // alarm time in seconds. If greater than
                                // zero, raise the alarm signal if more than
                                // d_timeout seconds are spent reading data.
    friend class DDSTest;

protected:
    void duplicate(const DDS &dds);
    BaseType *leaf_match(const string &name, BaseType::btp_stack *s = 0);
    BaseType *exact_match(const string &name, BaseType::btp_stack *s = 0);
#if 0
    void transfer_attr(DAS *das, const AttrTable::entry *ep, BaseType *btp,
                       const string &suffix = "");
    void transfer_attr_table(DAS *das, AttrTable *at, BaseType *btp,
                             const string &suffix = "");
    void transfer_attr_table(DAS *das, AttrTable *at, Constructor *c,
                             const string &suffix = "");
#endif
    virtual AttrTable *find_matching_container(AttrTable::entry *source,
            BaseType **dest_variable);

public:
    typedef std::vector<BaseType *>::const_iterator Vars_citer ;
    typedef std::vector<BaseType *>::iterator Vars_iter ;
    typedef std::vector<BaseType *>::reverse_iterator Vars_riter ;

    DDS(BaseTypeFactory *factory, const string &n = "");
    DDS(const DDS &dds);

    virtual ~DDS();

    DDS & operator=(const DDS &rhs);

    virtual void transfer_attributes(DAS *das);

    string get_dataset_name() const;
    void set_dataset_name(const string &n);

    /** Return the factory which makes instances of the Byte, ..., Grid
        type classes. Specialize BaseTypeFactory so that a DDS will be
        populated with your client or server's specialized types.
        @return An instance of BaseTypeFactory. */
    BaseTypeFactory *get_factory() const
    {
        return d_factory;
    }

    /** Set the factory class used to instantiate variables during the
        parse of a DDS.
        @param factory The factory this DDS should use. Caller must free
        factory when done with this DDS.
        @return The old factory.
        @see BaseTypeFactory */
    BaseTypeFactory *set_factory(BaseTypeFactory *factory)
    {
        BaseTypeFactory *t = d_factory;
        d_factory = factory;
        return t;
    }

    virtual AttrTable &get_attr_table();

    string filename();
    void filename(const string &fn);

    /// Get the DAP major version as sent by the client
    int get_dap_major() const { return d_dap_major; }
    /// Get the DAP minor version as sent by the client
    int get_dap_minor() const { return d_dap_minor; }

    /// Set the DAP major version (typically using info from the client)
    void set_dap_major(int p) { d_dap_major = p; }
    /// Set the DAP minor version (typically using info from the client)
    void set_dap_minor(int p) { d_dap_minor = p; }

    void set_dap_version(const string &version_string);
#if 0
    // These are confusing things because having two version numbers, even
    // though the idea is good sounding, is breaking stuff.

    /// Get the DAP major version as sent by the client
    int get_client_dap_major() const { return d_client_dap_major; }
    /// Get the DAP minor version as sent by the client
    int get_client_dap_minor() const { return d_client_dap_minor; }

    /// Set the DAP major version (typically using info from the client)
    void set_client_dap_major(int p) { d_client_dap_major = p; }
    /// Set the DAP minor version (typically using info from the client)
    void set_client_dap_minor(int p) { d_client_dap_minor = p; }

    void set_client_dap_version(const string &version_string);
#endif

    /// Get the URL that will return this DDS/DDX/DataThing
    string get_request_xml_base() const { return d_request_xml_base; }

    /// @see get_request_xml_base
    void set_request_xml_base(const string &xb) { d_request_xml_base = xb; }

    string container_name() ;
    void container_name( const string &cn ) ;
    Structure *container() ;

    void add_var(BaseType *bt);

    /// Removes a variable from the DDS.
    void del_var(const string &n);

    BaseType *var(const string &n, BaseType::btp_stack &s);
    BaseType *var(const string &n, BaseType::btp_stack *s = 0);
    int num_var();

    /// Return an iterator to the first variable
    Vars_iter var_begin();
    /// Return a reverse iterator
    Vars_riter var_rbegin();
    /// Return an iterator
    Vars_iter var_end();
    /// Return a reverse iterator
    Vars_riter var_rend();
    /// Get an iterator
    Vars_iter get_vars_iter(int i);
    /// Get a variable
    BaseType *get_var_index(int i);
    /// Removes a variable from the DDS.
    void del_var(Vars_iter i);
    /// Removes a range of variables from the DDS.
    void del_var(Vars_iter i1, Vars_iter i2);

    void timeout_on();
    void timeout_off();
    void set_timeout(int t);
    int get_timeout();

    void parse(string fname);
    void parse(int fd);
    void parse(FILE *in = stdin);
    //#if FILE_METHODS
    void print(FILE *out);
    //#endif
    void print(ostream &out);
    //#if FILE_METHODS
    void print_constrained(FILE *out);
    //#endif
    void print_constrained(ostream &out);
    //#if FILE_METHODS
    void print_xml(FILE *out, bool constrained, const string &blob = "");
    //#endif
    void print_xml(ostream &out, bool constrained, const string &blob = "");

    void mark_all(bool state);
    bool mark(const string &name, bool state);
    bool check_semantics(bool all = false);

    void tag_nested_sequences();

    virtual void dump(ostream &strm) const ;
};

} // namespace libdap

#endif // _dds_h
