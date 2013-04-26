// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of libdap, A C++ implementation of the OPeNDAP Data
// Access Protocol.

// Copyright (c) 2013 OPeNDAP, Inc.
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

#ifndef D4ENUMDEF_H_
#define D4ENUMDEF_H_

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "BaseType.h"

using namespace std;

namespace libdap {

class D4EnumDef {
    string d_name;
    Type d_type;

    struct tuple {
        string label;
        long long value;

        tuple(const string &l, long long v) : label(l), value(v) {}
    };

    vector<tuple> d_tuples;

    void print_value(XMLWriter &xml, const D4EnumDef::tuple &tuple) const;

public:
    typedef vector<tuple>::iterator D4EnumValueIter;

    D4EnumDef() : d_name(""), d_type(dods_null_c) {}
    D4EnumDef(const string &n, const Type &t) : d_name(n), d_type(t) {}

    string name() const { return d_name; }
    void set_name(const string &n) { d_name = n; }

    Type type() const { return d_type; }
    void set_type(Type t) { d_type = t; }

    bool empty() const { return d_tuples.empty(); }

    void add_value(const string &label, long long value) {
        d_tuples.push_back(tuple(label, value));
    }

    D4EnumValueIter value_begin() { return d_tuples.begin(); }
    D4EnumValueIter value_end() { return d_tuples.end(); }
    string &label(D4EnumValueIter i) { return (*i).label; }
    long long value(D4EnumValueIter i) { return (*i).value; }

    bool is_valid_enum_value(long long value);
    void print_dap4(XMLWriter &xml) const;
};

/** The Enumerations defined for a Group. */
class D4EnumDefs {
    vector<D4EnumDef*> d_enums;

    void m_print_enum(XMLWriter &xml, D4EnumDef *e) const;

    void m_duplicate(const D4EnumDefs &rhs) {
        D4EnumDefCIter i = rhs.d_enums.begin();
        while (i != rhs.d_enums.end()) {
            d_enums.push_back(new D4EnumDef(**i++));    // deep copy
        }
    }

public:
    typedef vector<D4EnumDef*>::iterator D4EnumDefIter;
    typedef vector<D4EnumDef*>::const_iterator D4EnumDefCIter;

    D4EnumDefs() {}
    D4EnumDefs(const D4EnumDefs &rhs) {
        m_duplicate(rhs);
    }

    virtual ~D4EnumDefs() {
        D4EnumDefIter i = d_enums.begin();
        while(i != d_enums.end()) {
            delete *i++;
        }
    }

    D4EnumDefs &operator=(const D4EnumDefs &rhs) {
        if (this == &rhs) return *this;
        m_duplicate(rhs);
        return *this;
    }

    bool empty() const { return d_enums.empty(); }

    /** Append a new D4EnumDef.
     *
     * @param enum_def The enumeration.
     */
    void add_enum(D4EnumDef *enum_def) {
        d_enums.push_back(new D4EnumDef(*enum_def));
    }
    void add_enum_nocopy(D4EnumDef *enum_def) {
        d_enums.push_back(enum_def);
    }

    /// Get an iterator to the start of the enumerations
    D4EnumDefIter enum_begin() { return d_enums.begin(); }

    /// Get an iterator to the end of the enumerations
    D4EnumDefIter enum_end() { return d_enums.end(); }

    //TODO Needed? Aggregation maybe?
#if 1
    /** Insert a D4EnumDef.
     * Insert a D4EnumDef before the position specified by the iterator.
     * @note Calling this method invalidates all iterators that reference this
     * D4EnumDef object.
     * @param enum_def Make a deep copy and insert the enumeration definition
     * @param i iterator
     */
    void insert_enum(D4EnumDef *enum_def, D4EnumDefIter i) {
        d_enums.insert(i, new D4EnumDef(*enum_def));
    }
#endif
    void print_dap4(XMLWriter &xml) const;
};

} /* namespace libdap */
#endif /* D4ENUMDEF_H_ */