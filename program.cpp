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
		// a test just to show that the testing and logging plumbing is working lol

		string str = "hello world from some function, bro" ;

		Logger::WriteMessage( str.c_str() ) ; 
	}

	vector<string> program::combinations( vector<int>& v )
	{
		// just a counter for printing each set
		int row = 0 ; 

		// do the recursion to find all combinations of the set passed in 
		// all combinations of all subsets of v
		vector<string> list ;

		combinations( v, row, 0, list ) ;

		return list ;
	}

	void program::combinations( vector<int>& v, int& row, int indent, vector<string>& list )
	{
		// nothing to do, we are at the end of the recursion
		if ( v.empty() ) return ;

		// print this new set 
		row++ ;
		auto str = dump( v, row, indent ) ; 
		list.push_back( str ) ;

		// remove each element 
		// one at on time from the current set
		// to form a new sub set,
		// and recurse each of these new sub sets

		for ( size_t i = 0 ; i < v.size() ; i++ )
		{
			// deep copy the set 
			auto v2 = v ; 

			// remove element at position i (starts at 0)
			v2.erase( v2.begin() + i ) ; 

			// recurse downwards with the new set
			// and increase the indentation for printing
			combinations( v2, row, indent+1, list ) ; 
		}
	}

	int program::traveller( vector<int>& v, int t, int k )
	{
		int row = 0  ; 
		int max = -1 ; // the answer, there is only one of these

		// do the recursion to find all valid combinations 
		// that have a maximum of t kilometers travelled
		// and visiting exactly k cities

		traveller( v, t, k, max, row, 0 ) ;

		// print the answer
		string str = "### result = " ;
		str += to_string( max ) ;
		Logger::WriteMessage( str.c_str() ) ;

		return max ;
	}

	void program::traveller( vector<int>& v, int t, int k, int& max, int& row, int indent )
	{
		// nothing to do, we are at the end of the recursion
		if ( v.empty() ) return ;

		// find the sum of the kilometers in the current set
		// we only care if it's the required k (ie the numbers of stops)

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

		// print this new set 
		row++ ;
		dump( v, row, indent ) ;

		// see if the sum of the kilometers in the current set
		// is closer to the maximum allowed t 
		// than we have seen before

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

		// remove each element 
		// one at on time from the current set
		// to form a new sub set,
		// and recurse each of these new sub sets

		for ( size_t i = 0 ; i < v.size() ; i++ )
		{
			auto v2 = v ;
			v2.erase( v2.begin() + i ) ;

			traveller( v2, t, k, max, row, indent + 1 ) ;
		}
	}

	string program::dump( vector<int>& v, int row, int indent )
	{
		// just a function to print out a set of integers
		// eg 
		//
		// #1 [91, 74, 73, 85, 73, 81] === > t = 477, k = 6

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

		return str ; 
	}

} // end namespace
