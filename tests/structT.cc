#ifdef __GNUG__
#pragma implementation
#endif

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>

#include <iostream>
#include "TestStructure.h"
#include "TestArray.h"
#include "TestInt16.h"
#include "TestStr.h"
#include "util.h"
#include "Pix.h"

using std::cerr ;
using std::endl ;

class structT : public CppUnit::TestFixture {

CPPUNIT_TEST_SUITE( structT ) ;
CPPUNIT_TEST( structT_test ) ;
CPPUNIT_TEST_SUITE_END( ) ;

private:
    /* TEST PRIVATE DATA */

public:
    void setUp()
    {
    }

    void tearDown() 
    {
    }

    void structT_test()
    {
	TestStructure s( "my_structure" ) ;

	BaseType *bt = NewInt16( "name_int16" ) ;
	s.add_var( bt ) ;
	delete bt ; bt = 0 ;

	bt = NewStr( "name_str" ) ;
	s.add_var( bt ) ;
	delete bt ; bt = 0 ;

	Array *abt = NewArray( "name_array", NewInt16( "array_int" ) ) ;
	abt->append_dim( 4, "dim1" ) ;
	abt->append_dim( 3, "dim2" ) ;
	abt->append_dim( 2, "dim3" ) ;
	s.add_var( abt ) ;
	delete abt ; abt = 0 ;

	bt = 0 ;
	bt = s.var( "name_str", true ) ;
	CPPUNIT_ASSERT( bt && bt->name() == "name_str" ) ;

	bt = 0 ;
	bt = s.var( "name_str", false ) ;
	CPPUNIT_ASSERT( bt && bt->name() == "name_str" ) ;

	vector<string> varnames ;
	varnames.push_back( "name_int16" ) ;
	varnames.push_back( "name_str" ) ;
	varnames.push_back( "name_array" ) ;
	typedef vector<string>::const_iterator niter ;

	Pix p = s.first_var() ;
	niter n = varnames.begin() ;
	for( ; p && n != varnames.end(); s.next_var( p ), n++ )
	{
	    CPPUNIT_ASSERT( s.var( p )->name() == *n ) ;
	}
	CPPUNIT_ASSERT( !p && n == varnames.end() ) ;
	if( p && n == varnames.end() )
	{
	    CPPUNIT_FAIL( "Too many variables" ) ;
	}
	else if( !p && n != varnames.end() )
	{
	    CPPUNIT_FAIL( "Too few varialbes" ) ;
	}

	Structure::Vars_iter viter = s.var_begin() ;
	n = varnames.begin() ;
	for( ; viter != s.var_end() && n != varnames.end(); viter++, n++ )
	{
	    CPPUNIT_ASSERT( (*viter)->name() == *n ) ;
	}
	CPPUNIT_ASSERT( viter == s.var_end() && n == varnames.end() ) ;
	if( viter != s.var_end() && n == varnames.end() )
	{
	    CPPUNIT_FAIL( "Too many variables" ) ;
	}
	else if( viter == s.var_end() && n != varnames.end() )
	{
	    CPPUNIT_FAIL( "Too few varialbes" ) ;
	}

	int num_elems = s.element_count( ) ;
	CPPUNIT_ASSERT( num_elems == 3 ) ;

	unsigned int w = s.width() ;
	unsigned int wsb = sizeof(string)
			   + sizeof(dods_int16)
			   + 24*sizeof(dods_int16) ;
	CPPUNIT_ASSERT( w == wsb ) ;

	bool is_read = s.read( "dataset" ) ;
	CPPUNIT_ASSERT( is_read == true ) ;

	//s.print_val( stdout ) ;
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( structT ) ;

/* NOTHING NEEDS TO BE CHANGED BELOW HERE */

int main( int argc, char **argv )
{
    CppUnit::TextUi::TestRunner runner ;
    CppUnit::TestFactoryRegistry &registry =
	CppUnit::TestFactoryRegistry::getRegistry() ;
    runner.addTest( registry.makeTest() ) ;
    runner.setOutputter( CppUnit::CompilerOutputter::defaultOutputter( 
                                                        &runner.result(),
                                                        std::cerr ) );
    bool wasSuccessful = runner.run( "", false ) ;
    return wasSuccessful ? 0 : 1;
}

