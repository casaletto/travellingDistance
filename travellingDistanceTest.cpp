#include <windows.h>
#include "CppUnitTest.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "program.h"

namespace travellingDistance
{
	TEST_CLASS( travellingDistanceTest )
	{
	public:	

		TEST_METHOD( helloWorldTest )
		{
			program m ;

			m.helloWorld() ;
		}

		TEST_METHOD( combinationsTest1 )
		{
			vector<int> v { 50, 55, 57, 58, 60 } ;

			program m ;
			m.combinations( v ) ;
		}

		TEST_METHOD( travellerTest1 )
		{
			vector<int> v{ 50, 55, 57, 58, 60 };

			program m ;
			auto result = m.traveller( v, 174, 3 ) ;

			Assert::AreEqual( 173, result ) ;
		}

		TEST_METHOD( combinationsTest2 )
		{
			vector<int> v { 50, 55, 56, 57, 58 } ;

			program m ;
			m.combinations( v ) ;
		}

		TEST_METHOD( travellerTest2 )
		{
			vector<int> v { 50, 55, 56, 57, 58 } ;

			program m;
			auto distance = m.traveller( v, 163, 3 ) ;

			Assert::AreEqual( 163, distance) ;
		}

		TEST_METHOD( travellerTest2a )
		{
			vector<int> v { 58, 57, 56, 55, 50 } ;

			program m;
			auto distance = m.traveller( v, 170, 3 ) ;

			Assert::AreEqual( 170, distance) ;
		}

		TEST_METHOD( combinationsTest3 )
		{
			vector<int> v { 50 } ;

			program m ;
			m.combinations( v ) ;
		}

		TEST_METHOD( travellerTest3 )
		{
			vector<int> v { 50 } ;

			program m;
			auto distance = m.traveller( v, 163, 3 ) ;

			Assert::AreEqual( -1, distance ) ;
		}

		TEST_METHOD( combinationsTest4 )
		{
			vector<int> v { 91, 74, 73, 85, 73, 81, 87 } ;

			program m ;
			m.combinations( v ) ;
		}

		TEST_METHOD( travellerTest4 ) // this unit test helped me to find a bug around duplicates !!!
		{
			vector<int> v { 91, 74, 73, 85, 73, 81, 87 } ; // has a duplicate 73  !!!

			program m;
			auto distance = m.traveller( v, 230, 3 ) ;

			Assert::AreEqual( 228, distance ) ; // 73, 74, 81
		}

		TEST_METHOD( travellerTest4a )
		{
			vector<int> v { 91, 74, 73, 85, 73, 81 } ; // does not have duplicate 73 

			program m;
			auto distance = m.traveller( v, 230, 3 ) ;

			Assert::AreEqual( 228, distance ) ; 
		}

		TEST_METHOD(combinationsTest5)
		{
			vector<int> v { 1, 2, 3, 1 } ;

			program m;
			m.combinations(v);
		}

		TEST_METHOD( combinationsTest6 )
		{
			vector<int> v { 1, 2, 3 } ;

			program m;
			m.combinations(v);
		}

	}; // end test class
}
