
// -*- C++ -*-

// (c) COPYRIGHT URI/MIT 1998
// Please read the full copyright statement in the file COPYRIGH.  
//
// Authors:
//      jhrg,jimg       James Gallagher (jgallagher@gso.uri.edu)

#ifndef rvalue_h
#define rvalue_h

// $Log: RValue.h,v $
// Revision 1.1  1998/10/21 16:14:17  jimg
// Added. Based on code that used to be in expr.h/cc
//

/** Holds the rvalues for the parser, Clause objects and evaluator.

    @see Clause.h
    @see DDS.h
    @see expr.y */

class rvalue {
private:
    BaseType *value;
    btp_func func;		// pointer to a function returning BaseType *
    SLList<rvalue *> *args;		// arguments to the function

public:
    rvalue(BaseType *bt);
    rvalue(btp_func f, SLList<rvalue *> *a);
    rvalue();

    ~rvalue();

    String value_name();

    // Return the BaseType * that contains a value for a given rvalue. If the
    // rvalue is a BaseType *, ensures that the read mfunc has been
    // called. If the rvalue is a func_rvalue, evaluates the func_rvalue and
    // returns the result.
    // NB: The functions referenced by func_rvalues must encapsulate their
    // return values in BaseType *s.
    BaseType *bvalue(const String &dataset, DDS &dds);
};

// This type def must come after the class definition above. It is used in
// the Clause and DDS classes.
typedef SLList<rvalue *> rvalue_list;

/** Build an argument list suitable for calling a btp_func, bool_func, etc.
    Since this takes an rvalue_list and not an rvalue, I've made it a
    function rather than a class member. */
BaseType **build_btp_args(rvalue_list *args, DDS &dds);

#endif // rvalue_h
