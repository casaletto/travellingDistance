#include <windows.h>
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "program.h"

namespace travellingDistance
{
	program::program() 
	{
	}

	void program::helloWorld()
	{
		string str = "hello world from some function, bro" ;

		Logger::WriteMessage( str.c_str() ) ; 
	}

	void program::combinations( vector<int>& v )
	{
		int row = 0 ;

		combinations( v, row, 0 ) ;
	}

	void program::combinations( vector<int>& v, int& row, int indent )
	{
		if ( v.empty() ) return ;

		row++ ;
		dump( v, row, indent ) ;

		for ( size_t i = 0 ; i < v.size() ; i++ )
		{
			auto v2 = v ;

			v2.erase( v2.begin() + i ) ;

			combinations( v2, row, indent+1 ) ;
		}
	}

	int program::traveller( vector<int>& v, int t, int k )
	{
		int row = 0  ;
		int max = -1 ;

		traveller( v, t, k, max, row, 0 ) ;

		string str = "### result = " ;
		str += to_string( max ) ;
		Logger::WriteMessage( str.c_str() ) ;

		return max ;
	}

	void program::traveller( vector<int>& v, int t, int k, int& max, int& row, int indent )
	{
		if ( v.empty() ) return ;

		int sum = 0 ;
		if ( v.size() != k )
		{
			sum = -1 ;
		}
		else
		{
			 for ( auto x : v )
			  	   sum += x ;
		}

		row++ ;
		dump( v, row, indent ) ;

		if ( sum > t )
		{
			Logger::WriteMessage( "@@@ too big @@@" ) ;
		}
		else
		if ( sum <= t
			 &&
			 sum > max )
		{
			max = sum ;
			Logger::WriteMessage( "!!! new biggest distance !!!" ) ;
		}

		for ( size_t i = 0 ; i < v.size() ; i++ )
		{
			auto v2 = v ;

			v2.erase( v2.begin() + i ) ;

			traveller( v2, t, k, max, row, indent + 1 ) ;
		}
	}

	void program::dump( vector<int>& v, int row, int indent )
	{
		int  t = 0 ;
		auto k = v.size() ;

		auto str = string( indent * 3, ' ' ) ;
		str += "#" + to_string( row ) ;
		str += " [ " ;

		auto start = true ;

		for ( auto x : v )
		{
			t += x ;

			if ( ! start )
				   str += ", " ;

			str += to_string( x ) ;

			start = false ;
		}

		str += " ] ===> t = " ;
		str += to_string( t ) ;
		str += ", k = ";
		str += to_string( k ) ;

		Logger::WriteMessage( str.c_str() ) ;
	}

} // end namespace
