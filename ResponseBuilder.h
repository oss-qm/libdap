
// -*- mode: c++; c-basic-offset:4 -*-

// This file is part of libdap, A C++ implementation of the OPeNDAP Data
// Access Protocol.

// Copyright (c) 2011 OPeNDAP, Inc.
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
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
// You can contact OPeNDAP, Inc. at PO Box 112, Saunderstown, RI. 02874-0112.

#ifndef _response_builder_h
#define _response_builder_h

#include <string>

#ifndef _object_type_h
#include "ObjectType.h"
#endif

#ifndef _encodingtype_h
#include "EncodingType.h"
#endif

namespace libdap
{

class ResponseCache;
class ConstraintEvaluator;
class DDS;
class DAS;

/**
 * This class is used to build responses for/by the BES. This class replaces
 * DODSFilter (although DODSFilter is still included in the library, its use
 * is deprecated). and it does not have a provision for command line arguments.
 * @author jhrg 1/28/2011
 */

class ResponseBuilder
{
public:
    friend class ResponseBuilderTest;

protected:
    std::string d_dataset;  		/// Name of the dataset/database
    std::string d_ce;  		    /// Constraint expression
    std::string d_btp_func_ce;   /// The BTP functions, extracted from the CE
    int d_timeout;  		/// Response timeout after N seconds
    std::string d_default_protocol;	/// Version std::string for the library's default protocol version

    ResponseCache *d_response_cache;

    void initialize();

public:

    /** Make an empty instance. Use the set_*() methods to load with needed
        values. You must call at least set_dataset_name() or be requesting
        version information. */
    ResponseBuilder() {
        initialize();
    }

    virtual ~ResponseBuilder();

    virtual std::string get_ce() const;
    virtual void set_ce(std::string _ce);

    virtual std::string get_btp_func_ce() const { return d_btp_func_ce; }
    virtual void set_btp_func_ce(std::string _ce) { d_btp_func_ce = _ce; }

    virtual std::string get_dataset_name() const;
    virtual void set_dataset_name(const std::string _dataset);

    void set_timeout(int timeout = 0);
    int get_timeout() const;

    virtual void establish_timeout(std::ostream &stream) const;

    virtual void split_ce(ConstraintEvaluator &eval, const std::string &expr = "");

    virtual ResponseCache *responseCache();

    virtual void send_das(std::ostream &out, DAS &das, bool with_mime_headers = true) const;
    virtual void send_das(std::ostream &out, DDS &dds, ConstraintEvaluator &eval,
                          bool constrained = false, bool with_mime_headers = true);

    virtual void send_dds(std::ostream &out, DDS &dds, ConstraintEvaluator &eval,
                          bool constrained = false,  bool with_mime_headers = true);

    virtual void dataset_constraint(std::ostream &out, DDS &dds, ConstraintEvaluator &eval, bool ce_eval = true);
    virtual void send_data(std::ostream &data_stream, DDS &dds, ConstraintEvaluator &eval, bool with_mime_headers = true);

    virtual void send_ddx(std::ostream &out, DDS &dds, ConstraintEvaluator &eval,
                          bool with_mime_headers = true);

    virtual void dataset_constraint_ddx(std::ostream &out, DDS & dds, ConstraintEvaluator & eval,
                                   const std::string &boundary, const std::string &start,
                                   bool ce_eval = true);

    virtual void send_data_ddx(std::ostream &data_stream, DDS &dds, ConstraintEvaluator &eval,
                           const std::string &start, const std::string &boundary,
                           bool with_mime_headers = true);
#if 0
    virtual void cache_data_ddx(const std::string &cache_file_name, DDS &dds);
#endif
#if 0
    void set_mime_ddx_boundary(std::ostream &out, const std::string &boundary,
        const std::string &start) const;
#endif
    // These functions are used both by the methods above and by other code.
    // However, Hyrax uses the OLFS to send the HTTP headers, so these functions
    // are never used in Hyrax. The BES may uses these in other contexts.
#if 0
    void set_mime_text(std::ostream &out, ObjectType type = unknown_type,
                       EncodingType enc = x_plain,
                       const time_t last_modified = 0,
                       const std::string &protocol = "") const;
#endif
#if 0
    void set_mime_html(std::ostream &out, ObjectType type = unknown_type,
                       EncodingType enc = x_plain,
                       const time_t last_modified = 0,
                       const std::string &protocol = "") const;
#endif
#if 0
    void set_mime_binary(std::ostream &out, ObjectType type = unknown_type,
                         EncodingType enc = x_plain,
                         const time_t last_modified = 0,
                         const std::string &protocol = "") const;
#endif
#if 0
    void set_mime_multipart(std::ostream &out, const std::string &boundary,
    	const std::string &start, ObjectType type = unknown_type, EncodingType enc = x_plain,
    	const time_t last_modified = 0, const std::string &protocol = "",
    	const std::string &url = "") const;
#endif
#if 0
    void set_mime_error(std::ostream &out, int code = 404,
                        const std::string &reason = "Dataset not found",
                        const std::string &protocol = "") const;
#endif
};

} // namespace libdap

#endif // _response_builder_h
