
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

// jhrg 7/29/94

#include "config.h"

static char rcsid[] not_used ="$Id$";

#include <assert.h>

#include "AttrTable.h"

//#include "Error.h"

#include "util.h"
#include "escaping.h"

#include "debug.h"

using std::cerr;
using std::string;
using std::endl;

#if defined(_MSC_VER) && (_MSC_VER == 1200)  //  VC++ 6.0 only
using std::vector<string>;
#else
using std::vector;
#endif

/** Convert an AttrType to it's string representation. 
    @param at The Attribute Type.
    @return The type's string representation */
string 
AttrType_to_String(const AttrType at)
{
    switch (at) {
      case Attr_container: return "Container";
      case Attr_byte: return "Byte";
      case Attr_int16: return "Int16";
      case Attr_uint16: return "UInt16";
      case Attr_int32: return "Int32";
      case Attr_uint32: return "UInt32";
      case Attr_float32: return "Float32";
      case Attr_float64: return "Float64";
      case Attr_string: return "String";
      case Attr_url: return "Url";
      default: return "";
    }
}

AttrType
String_to_AttrType(const string &s)
{
    string s2 = s;
    downcase(s2);

    if (s2 == "container")
	return Attr_container;
    else if (s2 == "byte")
	return Attr_byte;
    else if (s2 == "int16")
	return Attr_int16;
    else if (s2 == "uint16")
	return Attr_uint16;
    else if (s2 == "int32")
	return Attr_int32;
    else if (s2 == "uint32")
	return Attr_uint32;
    else if (s2 == "float32")
	return Attr_float32;
    else if (s2 == "float64")
	return Attr_float64;
    else if (s2 == "string")
	return Attr_string;
    else if (s2 == "url")
	return Attr_url;
    else 
	return Attr_unknown;
}

/** Clone the given attribute table in <tt>this</tt>. 
    Protected. */
void
AttrTable::clone(const AttrTable &at)
{
    d_name = at.d_name;
    
    Attr_citer i = at.attr_map.begin() ;
    Attr_citer ie = at.attr_map.end() ;
    for( ; i != ie; i++ )
    {
	entry *e = new entry( *(*i) ) ;
	attr_map.push_back( e ) ;
    }
    
    d_parent = at.d_parent;
}

/** @name Instance management functions */

//@{
AttrTable::AttrTable() : d_name(""), d_parent(0)
{
}

AttrTable::AttrTable(const AttrTable &rhs)
{
    clone(rhs);
}

// Private
void
AttrTable::delete_attr_table() 
{
    for (Attr_iter i = attr_map.begin(); i != attr_map.end(); i++) {
	delete *i; *i = 0;
    }
}

AttrTable::~AttrTable()
{
    DBG(cerr << "Entering ~AttrTable (" << this << ")" << endl);
    delete_attr_table();
    DBG(cerr << "Exiting ~AttrTable" << endl);
}

AttrTable &
AttrTable::operator=(const AttrTable &rhs)
{
    if (this != &rhs) {
	delete_attr_table();
	clone(rhs);
    }

    return *this;
}	    
//@}

/** Attributes that are containers count one attribute, as do
    attributes with both scalar and vector values. 
    @return The number of entries. 
    @brief Get the number of entries in this attribute table.
*/
unsigned int
AttrTable::get_size() const
{
    return attr_map.size();
}

/** @brief Get the name of this attribute table. 
    @return A string containing the name. */
string
AttrTable::get_name() const
{
    return d_name;
}

/** @brief Set the name of this attribute table.
    @param n The new name of the attribute table. */
void
AttrTable::set_name(const string &n)
{
    d_name = www2id(n);
}

/** If the given name already refers to an attribute, and the attribute has a
    value, the given value is appended to the attribute vector. Calling this
    function repeatedly is the way to append to an attribute vector.

    The function throws an Error if the attribute is a container,
    or if the type of the input value does not match the existing attribute's
    type. Use <tt>append_container()</tt> to add container attributes.

    This method performs a simple search for <tt>name</tt> in this attribute
    table only; sub-tables are not searched and the dot notation is not
    recognized.

    @brief Add an attribute to the table.
    @return Returns the length of the added attribute value.
    @param name The name of the attribute to add or modify.
    @param type The type of the attribute to add or modify.
    @param attribute The value to add to the attribute table. */
unsigned int
AttrTable::append_attr(const string &name, const string &type, 
		       const string &attribute) throw (Error)
{
    string lname = www2id(name);

    Attr_iter iter = simple_find(lname) ;

    // If the types don't match OR this attribute is a container, calling
    // this mfunc is an error!
    if (iter != attr_map.end() && ((*iter)->type != String_to_AttrType(type)))
	throw Error(string("An attribute called `") + name 
		    + string("' already exists but is of a different type"));
    if (iter != attr_map.end() && (get_type(iter) == "Container"))
	throw Error(string("An attribute called `") + name 
		    + string("' already exists but is a container."));

    if (iter != attr_map.end()) {    // Must be a new attribute value; add it.
        (*iter)->attr->push_back(attribute);
	return (*iter)->attr->size();
    } else {			// Must be a completely new attribute; add it
	entry *e = new entry;

	e->name = lname;
	e->is_alias = false;
	e->type = String_to_AttrType(type); // Record type using standard names.
	e->attr = new vector<string>;
	e->attr->push_back(attribute);

	attr_map.push_back(e);
    
	return e->attr->size();	// return the length of the attr vector
    }
}

/** This version of append_attr() takes a vector<string> of values. 
    If the given name already refers to an attribute, and the attribute has
    values, append the new values to the existing ones.

    The function throws an Error if the attribute is a container,
    or if the type of the input value does not match the existing attribute's
    type. Use <tt>append_container()</tt> to add container attributes.

    This method performs a simple search for <tt>name</tt> in this attribute
    table only; sub-tables are not searched and the dot notation is not
    recognized.

    @brief Add an attribute to the table.
    @return Returns the length of the added attribute value.
    @param name The name of the attribute to add or modify.
    @param type The type of the attribute to add or modify.
    @param values A vector of values. */
unsigned int
AttrTable::append_attr(const string &name, const string &type, 
                       vector<string> *values) throw (Error)
{
    string lname = www2id(name);

    Attr_iter iter = simple_find(lname) ;

    // If the types don't match OR this attribute is a container, calling
    // this mfunc is an error!
    if (iter != attr_map.end() && ((*iter)->type != String_to_AttrType(type)))
        throw Error(string("An attribute called `") + name 
                    + string("' already exists but is of a different type"));
    if (iter != attr_map.end() && (get_type(iter) == "Container"))
        throw Error(string("An attribute called `") + name 
                    + string("' already exists but is a container."));

    if (iter != attr_map.end()) {    // Must be new attribute values; add.
        vector<string>::iterator i = values->begin();
        while (i != values->end()) 
            (*iter)->attr->push_back(*i++);

        return (*iter)->attr->size();
    } 
    else {                    // Must be a completely new attribute; add it
        entry *e = new entry;

        e->name = lname;
        e->is_alias = false;
        e->type = String_to_AttrType(type); // Record type using standard names.
        e->attr = new vector<string>(*values);
        
        attr_map.push_back(e);
    
        return e->attr->size(); // return the length of the attr vector
    }
}

/** Create and append an attribute container to this AttrTable. If this
    attribute table already contains an attribute container called
    <tt>name</tt> an exception is thrown.

    @brief Add a container to the attribute table.
    @return A pointer to the new AttrTable object. 
*/

AttrTable *
AttrTable::append_container(const string &name) throw (Error)
{
    AttrTable *new_at = new AttrTable ;
    AttrTable *ret = NULL ;
    try
    {
	ret = append_container( new_at, name ) ;
    }
    catch( Error &e )
    {
	// an error occurred, attribute with that name already exists
	delete new_at; new_at = 0;
	throw e;
    }
    return ret;
}

/** Append a new attribute container to this attribute table. The new
    container is <tt>at</tt> and its name is set to
    <tt>name</tt>. If this attribute 
    table already contains an attribute container called
    <tt>name</tt> an exception is thrown.

    @note The value of \e name will override the name of \e at set using the 
    set_name() method.
    
    @brief Add a container to the attribute table.
    @return A pointer to the new AttrTable object. 
*/
AttrTable *
AttrTable::append_container(AttrTable *at, const string &name) throw (Error)
{
    string lname = www2id(name);

    if (simple_find(name) != attr_end())
	throw Error(string("There already exists a container called `")
		    + name + string("' in this attribute table."));
    DBG(cerr << "Setting appended attribute container name to: "
        << lname << endl);
    at->set_name(lname);

    entry *e = new entry;
    e->name = lname;
    e->is_alias = false;
    e->type = Attr_container;
    e->attributes = at;

    attr_map.push_back(e);
    
    at->d_parent = this;

    return e->attributes;
}

/** Look for an attribute or an attribute container. If used to search
    for an attribute container, this method returns the container's \e
    parent using the value-result parameter \c at and a reference to the
    container using the iterator value-result parameter \c iter. If used 
    to search for an attribute, the attribute's container is returned using 
    \c at; the attribute itself can be accessed using the iterator \c iter.

    @param target The name (using dot notation) of the attribute or
    container to find.
    @param at A value-result used to return the attribute container in
    which \c target was found. Null if \c target was not found.
    @param iter The itereator which will reference the attribute found.
    Can be used to access \c target from within \c at. References
    dim_end() within \c at if the attribute or container does not exist. */
void
AttrTable::find( const string &target, AttrTable **at, Attr_iter *iter )
{
    string::size_type dotpos = target.rfind('.');
    if (dotpos != string::npos)
    {
	string container = target.substr(0, dotpos);
	string field = target.substr(dotpos+1);

	*at = find_container( container ) ;
	if(*at)
	{
	    *iter = (*at)->simple_find(field) ;
	} else {
	    *iter = attr_map.end() ;
	}
    }
    else {
#if 0
        // Replaced this call to simple_find with the call to recurrsive_find
        // so that older code that assumes that attribute names will not need
        // to be FQNs works. jhrg 2/9/06
	*at = this;
	*iter = simple_find(target);
#endif
        *at = recurrsive_find(target, iter);
    }
}

/** This method scans for attributes using recurrsion to look inside containers
    even when the name of the attribute is not fully qualified. It starts 
    looking in itself and descends into its children depth first. It will find
    attributes and attribute containers.
    
    @param target Look for the attribute with this name.
    @param location A value-result parameter. This returns an iterator to the
    attribute within the returned AttrTable object
    @return Returns a pointer to the AttrTable which holds \e target, or null
    if \e target is not found. In the latter case, the value of \e location is
    attr_end() for this AttrTable. */
AttrTable *
AttrTable::recurrsive_find(const string &target, Attr_iter *location)
{
    //*location = attr_begin();
    Attr_iter i = attr_begin();
    while (i != attr_end()) {
        if (target == (*i)->name) {
            *location = i;
            return this;
        } 
        else if ((*i)->type == Attr_container) {
            AttrTable *at = (*i)->attributes->recurrsive_find(target, location);
            if (at)
                return at;
        }
        
        ++i;
    }

    *location = i;    
    return 0;
}

// Private
/** Look in this AttrTable for the attribute called \c name. If found return
    an Attr_iter which references it, otherwise return the end iterator for
    this AttrTable.
    
    @param target The name of the attribute. 
    @return An Attr_iter which references \c target. */
AttrTable::Attr_iter
AttrTable::simple_find(const string &target)
{
    Attr_iter i ;
    for( i = attr_map.begin(); i != attr_map.end(); i++ )
    {
	if( target == (*i)->name )
	{
	    break ;
	}
    }
    return i ;
}

/** Look in this attribute table for an attribute container named
    <tt>target</tt>. The search starts at this attribute table;
    <tt>target</tt> should
    use the dot notation to name containers held within children of this
    attribute table. 

    To search the entire DAS object, make sure to invoke this method from
    that object.

    @brief Find an attribute with a given name.
    @param target The attribute container to find.
    @return A pointer to the attribute table or null if the container
    cannot be found. */
AttrTable *
AttrTable::find_container(const string &target)
{
    string::size_type dotpos = target.find('.');
    if (dotpos != string::npos) {
	string container = target.substr(0, dotpos);
	string field = target.substr(dotpos+1);
	
	AttrTable *at= simple_find_container(container);
	return (at) ? at->find_container(field) : 0;
    }
    else {
	return simple_find_container(target);
    }
}

// Private
AttrTable *
AttrTable::simple_find_container(const string &target)
{
    if (get_name() == target)
	return this;

    for (Attr_iter i = attr_map.begin(); i != attr_map.end(); i++)
    {
	if (is_container(i) && target == (*i)->name)
	{
	    return (*i)->attributes;
	}
    }

    return 0;
}

/** Each of the following accessors get information using the name of an
    attribute. They perform a simple search for the name in this
    attribute table only; sub-tables are not searched and the dot
    notation is not recognized.

    @name Accessors using an attribute name */
//@{

/** @brief Get an attribute container. */
AttrTable *
AttrTable::get_attr_table(const string &name)
{
    return find_container(name);
}

/** @brief Get the type name of an attribute within this attribute table. */
string
AttrTable::get_type(const string &name)
{
    Attr_iter p = simple_find(name);
    return (p != attr_map.end()) ? get_type(p) : (string)"";
}

/** @brief Get the type of an attribute.
    @return The <tt>AttrType</tt> value describing the attribute. */
AttrType
AttrTable::get_attr_type(const string &name)
{
    Attr_iter p = simple_find(name);
    return (p != attr_map.end()) ? get_attr_type(p) : Attr_unknown;
}

/** If the indicated attribute is a container attribute, this function
    returns the number of attributes in <i>its</i> attribute table. If the
    indicated attribute is not a container, the method returns the number
    of values for the attribute (1 for a scalar attribute, N for a vector
    attribute value). 
    @brief Get the number of attributes in this container.
*/
unsigned int 
AttrTable::get_attr_num(const string &name)
{
    Attr_iter iter = simple_find(name);
    return (iter != attr_map.end()) ?  get_attr_num(iter) : 0;
}

/** Get a pointer to the vector of values associated with the attribute
    referenced by Pix <tt>p</tt> or named <tt>name</tt>.

    Note that all values in an attribute table are stored as string data.
    They may be converted to a more appropriate internal format by the
    calling program.

    @return If the indicated attribute is a container, this function
    returns the null pointer.  Otherwise returns a pointer to the
    the attribute vector value. 
    @brief Get a vector-valued attribute.
*/
vector<string> *
AttrTable::get_attr_vector(const string &name)
{
    Attr_iter p = simple_find(name);
    return (p != attr_map.end()) ? get_attr_vector(p) : 0;
}

/** Delete the attribute named <tt>name</tt>. If <tt>i</tt> is given, and
    the attribute has a vector value, delete the <tt>i</tt>$^th$
    element of the vector.

    You can use this function to delete container attributes, although
    the <tt>i</tt> parameter has no meaning for that operation.

    @brief Deletes an attribute.
    @param name The name of the attribute to delete.  This can be an
    attribute of any type, including containers. However, this method
    looks only in this attribute table and does not recognize the dot
    notation. 
    @param i If the named attribute is a vector, and <tt>i</tt> is
    non-negative, the i-th entry in the vector is deleted, and the
    array is repacked.  If <tt>i</tt> equals -1 (the default), the
    entire attribute is deleted. */
void
AttrTable::del_attr(const string &name, int i)
{
    string lname = www2id(name);

    Attr_iter iter = simple_find(lname) ;
    if ( iter != attr_map.end() ) {
	if (i == -1) {		// Delete the whole attribute
	    entry *e = *iter ;
	    attr_map.erase( iter ) ;
	    delete e ; e = 0;
	}
	else {			// Delete one element from attribute array
	    // Don't try to delete elements from the vector of values if the
	    // map is a container!
	    if ((*iter)->type == Attr_container) 
		return;

	    vector<string> *sxp = (*iter)->attr;
		
	    assert(i >= 0 && i < (int)sxp->size());
	    sxp->erase(sxp->begin() + i); // rm the element
	}
    }
}

//@} Accessors using an attribute name

/** @name get information using an iterator */
//@{
/** Get an iterator to the first entry in this attribute table. 
    @return Attr_iter; references the end of the array if empty list. */
AttrTable::Attr_iter
AttrTable::attr_begin()
{
    return attr_map.begin() ;
}

/** Get an iterator to the end attribute table. Does not point to 
    the last attribute in the table
    @return Attr_iter */
AttrTable::Attr_iter
AttrTable::attr_end()
{
    return attr_map.end() ;
}

/** Given an index \c i, return the \c Attr_iter to the corresponding
    element. This method provides a way to use all the methods that take an
    \c Attr_iter using a simple integer index. Use the get_attr_num() or
    get_size() methods to determine how many items the AttrTable contains.

    @param i The index
    @return The corresponding Attr_iter
    @see get_attr_num, get_size */
AttrTable::Attr_iter
AttrTable::get_attr_iter(int i)
{
    return attr_map.begin() + i;
}

/** Returns the name of the attribute referenced by \e iter. */
string
AttrTable::get_name( Attr_iter iter )
{
    assert( iter != attr_map.end() ) ;

    return (*iter)->name ;
}

/** Returns true if the attribute referenced by \e i is a container. */
bool
AttrTable::is_container( Attr_iter i )
{
    return (*i)->type == Attr_container ;
}

/** Get the attribute container referenced by \e iter. If no
    such container exists, then return a reference to the end of the
    table.
    @param iter Reference to a table contained by this object.
    @return The child attribute table. */
AttrTable *
AttrTable::get_attr_table( Attr_iter iter )
{
    assert( iter != attr_map.end() ) ;
    return (*iter)->type == Attr_container ? (*iter)->attributes : 0 ;
}

/** Delete the iterator.  Since AttrTable stores pointers to AttrTable
    objects, the caller should be sure to delete the AttrTable itself.
    This method does not take care of that operation.
    
    @note calling this method <b>invalidates</b> the iterator \e iter.
    @param iter points to the entry to be deleted.
    @return The Attr_iter for the element following \e iter */
AttrTable::Attr_iter
AttrTable::del_attr_table(Attr_iter iter)
{
    if ((*iter)->type != Attr_container)
        return ++iter;
        
    return attr_map.erase(iter);
}

/** Get the type name of an attribute referenced by \e iter.
    @param iter Reference to the Attribute.
    @return A string with the name of this attribute datatype. */
string
AttrTable::get_type( Attr_iter iter )
{
    assert( iter != attr_map.end() ) ;
    return AttrType_to_String( (*iter)->type ) ;
}

/** Get the type of the attribute referenced by \e iter.
    @param iter
    @return The datatype of this attribute in an instance of AttrType. */
AttrType
AttrTable::get_attr_type( Attr_iter iter )
{
    return (*iter)->type ;
}

/** If the attribute referenced by \e iter is a container attribute, this
    method returns the number of attributes in its attribute table.
    If the indicated attribute is not a container, the method returns the 
    number of values for the attribute (1 for a scalar attribute, N for a 
    vector attribute value).
    @param iter Reference to an attribute
    @return The number of elements in the attribute. */
unsigned int
AttrTable::get_attr_num( Attr_iter iter )
{
    assert( iter != attr_map.end() ) ;
    return ( (*iter)->type == Attr_container )
	? (*iter)->attributes->get_size()
	: (*iter)->attr->size() ;
}

/** Returns the value of an attribute. If the attribute has a vector
    value, you can indicate which is the desired value with the index
    argument, \e i. If the argument is omitted, the first value is
    returned. If the attribute has only a single value, the index
    argument is ignored. If \e i is greater than the number of
    elements in the attribute, an error is produced.

    All values in an attribute table are stored as string data. They may
    be converted to a more appropriate internal format by the calling
    program.

    @param iter Reference to an attribute
    @param i The attribute value index, zero-based.
    @return If the indicated attribute is a container, this function
    returns the string ``None''. If using a name to refer to the attribute
    and the named attribute does not exist, return the empty string. */
string
AttrTable::get_attr(Attr_iter iter, unsigned int i)
{
    assert(iter != attr_map.end());
    return (*iter)->type == Attr_container ? (string)"None" : (*(*iter)->attr)[i];
}

string
AttrTable::get_attr(const string &name, unsigned int i)
{
    Attr_iter p = simple_find(name);
    return (p != attr_map.end()) ? get_attr(p, i) : (string)"";
}

/** Returns a pointer to the vector of values associated with the
    attribute referenced by iterator \e iter.

    Note that all values in an attribute table are stored as string data.
    They may be converted to a more appropriate internal format by the
    calling program.

    @param iter Reference to the Attribute.
    @return If the indicated attribute is a container, this function
    returns the null pointer.  Otherwise returns a pointer to the
    the attribute vector value. */
vector<string> *
AttrTable::get_attr_vector(Attr_iter iter)
{
    assert(iter != attr_map.end());
    return (*iter)->type != Attr_container ? (*iter)->attr : 0;
}

//@} Accessors that use an iterator

// Alias an attribute table. The alias should be added to this object.
/** @brief Add an alias to a container held by this attribute table. 
    @param name The name of the alias. May <i>not</i> use dot notation.
    @param src The existing attribute container to alias.
    @exception Error if an attribute, container or alias called
    <tt>name</tt> already exists in this attribute table. */
void
AttrTable::add_container_alias(const string &name, AttrTable *src) 
    throw (Error)
{
    string lname = www2id(name);

    if (simple_find(lname) != attr_end())
	throw Error(string("There already exists a container called `")
		    + name + string("in this attribute table."));

    entry *e = new entry;
    e->name = lname;
    e->is_alias = true;
    e->aliased_to = src->get_name();
    e->type = Attr_container;

    e->attributes = src;

    attr_map.push_back(e);
}

/** Assume \e source names an attribute value in some container. Add an alias
    \e name for that value in this object.

    @brief Add an alias for an attribute.

    @param das 
    @param name The name of the alias. May <i>not</i> use dot notation.
    @param source The name of the attribute to alias. May use dot
    notation. 
    @exception Error if the attribute table already contains an
    attribute, container or alias called <tt>name</tt> or if an
    attribute called <tt>source</tt> does not exist. */
void
AttrTable::add_value_alias(AttrTable *das, const string &name, 
			   const string &source) throw (Error)
{
    string lname = www2id(name);
    string lsource = www2id(source);

    // find the container that holds source and its (sources's) iterator
    // within that container. Search at the uppermost level of the attribtue
    // object to find values defined `above' the current container.
    AttrTable *at;
    Attr_iter iter;
    das->find(lsource, &at, &iter);

    // If source is not found by looking at the topmost level, look in the
    // current table (i.e., alias z x where x is in the current container
    // won't be found by looking for `x' at the top level). See test case 26
    // in das-testsuite.
    if (!at || (iter == at->attr_end()) || !*iter) {
	find(lsource, &at, &iter);
	if (!at || (iter == at->attr_end()) || !*iter)
	    throw Error(string("Could not find the attribute `")
			+ source + string("' in the attribute object."));
    }
    
    // If we've got a value to alias and it's being added at the top level of
    // the DAS, that's an error.
    if (!at->is_container(iter) && this == das)
	throw Error(string("A value cannot be aliased to the top level of the\
 DAS;\nOnly containers may be present at that level of the DAS."));

    if (simple_find(lname) != attr_end())
	throw Error(string("There already exists a container called `")
		    + name + string("in this attribute table."));

    entry *e = new entry;
    e->name = lname;
    e->is_alias = true;
    e->aliased_to = lsource;
    e->type = get_attr_type(iter);
    if (e->type == Attr_container)
	e->attributes = at->get_attr_table(iter);
    else
	e->attr = (*iter)->attr;

    attr_map.push_back(e);
}

// Deprecated
/** Once an alias is
    inserted into an attribute table, reading the attributes for
    <i>alias</i> will return those stored for <i>name</i>. 

    Two forms for this function exist: one searches for <i>name</i>
    in the AttrTable referenced by <i>at</i> while the other uses
    <tt>this</tt>. You can use <tt>DAS::get_attr_table()</tt> to
    get the attribute table for an arbitrary name.

    @brief Adds an alias to the set of attributes.  
    @see get_attr_table
    @deprecated The current alias design is flawed. It is impossible to map
    this onto the XML implementation where the DAS and DDS information are
    combined in one object.
    @param alias The alias to insert into the attribute table.
    @param name The name of the already-existing attribute to which
    the alias will refer.
    @param at An attribute table in which to insert the alias. */
bool
AttrTable::attr_alias(const string &alias, AttrTable *at, const string &name)
{
    add_value_alias(at, alias, name);
    return true;
}

/** @deprecated The current alias design is flawed. It is impossible to map
    this onto the XML implementation where the DAS and DDS information are
    combined in one object.

    @param alias The alias to insert into the attribute table.
    @param name The name of the already-existing attribute to which
    the alias will refer. */
bool
AttrTable::attr_alias(const string &alias, const string &name)
{
    return attr_alias(alias, this, name);
}

/** Erase the entire attribute table. This returns an AttrTable to the empty
    state that's the same as the object generated by the null constructor.
    @brief Erase the attribute table. */
void
AttrTable::erase()
{
    for (Attr_iter i = attr_map.begin(); i != attr_map.end(); i++) {
	delete *i; *i = 0;
    }

    attr_map.erase(attr_map.begin(), attr_map.end());

    d_name = "";
}


/** A simple printer that does nothing fancy with aliases. 
    Protected. */
void
AttrTable::simple_print(FILE *out, string pad, Attr_iter i,
			bool dereference)
{
    switch ((*i)->type) {
      case Attr_container:
	fprintf( out, "%s%s {\n", pad.c_str(), id2www( get_name(i) ).c_str()) ;

	(*i)->attributes->print(out, pad + "    ", dereference);

	fprintf( out, "%s}\n", pad.c_str() ) ;
	break;

      default: {
	    fprintf( out, "%s%s %s ", pad.c_str(), get_type(i).c_str(),
				      id2www(get_name(i)).c_str() ) ;

	    vector<string> *sxp = (*i)->attr;
	    
	    vector<string>::iterator last = sxp->end()-1;
	    for (vector<string>::iterator i = sxp->begin(); i != last; ++i)
		fprintf( out, "%s, ", (*i).c_str() ) ;
  
	    fprintf( out, "%s;\n", (*(sxp->end()-1)).c_str() ) ;
	}
	break;
    }
}

/** Prints an ASCII representation of the attribute table to the
    indicated FILE pointer. The \c pad argument is prefixed to each
    line of the output to provide control of indentation.

    @brief Prints the attribute table.
    @param out Print to the given output FILE.
    @param pad Indent elements of a table using this string of spaces. By
    default this is a string of four spaces
    @param dereference If true, follow aliases. Default is false. */

void
AttrTable::print(FILE *out, string pad, bool dereference)
{
    for(Attr_iter i = attr_map.begin(); i != attr_map.end(); i++)
    {
	if ((*i)->is_alias) {
	    if (dereference) {
		simple_print(out, pad, i, dereference);
	    }
	    else {
		fprintf( out, "%sAlias %s %s;\n",
			      pad.c_str(),
			      id2www(get_name(i)).c_str(),
			      id2www((*i)->aliased_to).c_str() ) ;
	    }
	} 
	else {
	    simple_print(out, pad, i, dereference);
	}
    }
}

/** Print the attribute table in XML. 
    @param out Destination
    @param pad Indent lines of text/xml this much. Default is four spaces.
    @param constrained The DDX contains attribute inforamtion; is this DDX
    'constrained?' */
void
AttrTable::print_xml(FILE *out, string pad, bool constrained)
{
    // Why this works: AttrTable is really a hacked class that used to
    // implement a single level, not nested, set of attributes. Containers
    // were added several years later by dropping in the 'entry' structure.
    // It's not a class in its own right; instead accessors from AttrTable
    // are used to access information from entry. So... the loop below
    // actually iterates over the entries of *this* (which is an instance of
    // AttrTable). A container is an entry whose sole value is an AttrTable
    // instance. 05/19/03 jhrg
    for (Attr_iter i = attr_begin(); i != attr_end(); ++i) {
	// To handle aliases, if constrained, check to see if the aliased
	// variable is part of the current projection. If so, then the
	// target is going to be sent so just write out the <Alias ...> tag.
	// If not, don't write the alias (we should write out the complete
	// target AttrTable, but that's not what the Java code does)
	if ((*i)->is_alias) {
	    fprintf(out, "%s<Alias name=\"%s\" Attribute=\"%s\">\n",
		    pad.c_str(), id2xml(get_name(i)).c_str(), 
		    (*i)->aliased_to.c_str());

	}
	else if (is_container(i)) {
	    fprintf(out, "%s<Attribute name=\"%s\" type=\"%s\">\n",
		    pad.c_str(), id2xml(get_name(i)).c_str(), 
		    get_type(i).c_str());

	    get_attr_table(i)->print_xml(out, pad + "    ", constrained);

	    fprintf(out, "%s</Attribute>\n", pad.c_str());
	}
	else {
	    fprintf(out, "%s<Attribute name=\"%s\" type=\"%s\">\n",
		pad.c_str(), id2xml(get_name(i)).c_str(), get_type(i).c_str());

	    string value_pad = pad + "    ";
	    for (unsigned j = 0; j < get_attr_num(i); ++j) {
		fprintf(out, "%s<value>%s</value>\n", value_pad.c_str(),
			id2xml(get_attr(i, j)).c_str());
	    }

	    fprintf(out, "%s</Attribute>\n", pad.c_str());
	}
    }
}

