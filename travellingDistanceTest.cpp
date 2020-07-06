#include <windows.h>
#include "CppUnitTest.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <filesystem>
#include "program.h"

namespace travellingDistance
{
	TEST_CLASS( travellingDistanceTest )
	{

	protected:

		bool substringExists( const vector<string> list, const string& search )
		{
			// a function to see if a sub string exists within a vector of strings
			//
			// eg if my list contains
			//		red_flowers
			//		blue_water
			//      green_leaves
			//
			// then 
			//		substringExists( list, "een_lea" ) 
			//
			// would return true 
			//

			return
				any_of(
					list.cbegin(),
					list.cend(),
					[search]( const string& s )
					{
						return s.find( search ) != std::string::npos ;
					}) ;
		}

	public:	

        TEST_METHOD( pwd )
        {
            auto path = std::filesystem::current_path() ;

            Logger::WriteMessage( path.c_str() ) ;
        }

		TEST_METHOD( helloWorldTest )
		{
			program m ;

			m.helloWorld() ; // check plumbing
		}

		TEST_METHOD( combinationsTest1 )
		{
			vector<int> v { 50, 55, 57, 58, 60 } ;

			program m ;
			auto list = m.combinations( v ) ;

			// check total number of rows expected
			Assert::AreEqual( 206, (int) list.size() ) ;
		}

		TEST_METHOD( travellerTest1 )
		{
			vector<int> v{ 50, 55, 57, 58, 60 };

			program m ;
			auto result = m.traveller( v, 174, 3 ) ;

			// check distance
			Assert::AreEqual( 173, result ) ;
		}

		TEST_METHOD( combinationsTest2 )
		{
			vector<int> v { 50, 55, 56, 57, 58 } ;

			program m ;
			auto list = m.combinations( v ) ;

			// check total number of rows expected
			Assert::AreEqual( 206, (int) list.size() ) ;
		}

		TEST_METHOD( travellerTest2 )
		{
			vector<int> v { 50, 55, 56, 57, 58 } ;

			program m ;
			auto distance = m.traveller( v, 163, 3 ) ;

			// check distance
			Assert::AreEqual( 163, distance ) ;
		}

		TEST_METHOD( travellerTest2a )
		{
			vector<int> v { 58, 57, 56, 55, 50 } ;

			program m ;
			auto distance = m.traveller( v, 170, 3 ) ;

			// check distance
			Assert::AreEqual( 170, distance ) ;
		}

		TEST_METHOD( combinationsTest3 )
		{
			vector<int> v { 50 } ;

			program m ;
			auto list = m.combinations( v ) ;

			// check total number of rows expected
			Assert::AreEqual( 1, (int) list.size() ) ;
		}

		TEST_METHOD( travellerTest3 )
		{
			vector<int> v { 50 } ;

			program m ;
			auto distance = m.traveller( v, 163, 3 ) ;

			// check distance
			Assert::AreEqual( -1, distance ) ;
		}

		TEST_METHOD( combinationsTest4 )
		{
			vector<int> v { 91, 74, 73, 85, 73, 81, 87 } ;

			program m ;
			auto list = m.combinations( v ) ;

			// check total number of rows expected
			Assert::AreEqual( 8660, (int) list.size() ) ;
		}

		TEST_METHOD( travellerTest4 ) // this unit test helped me to find a bug around duplicates !!!
		{
			vector<int> v { 91, 74, 73, 85, 73, 81, 87 } ; // has a duplicate 73  !!!

			program m ;
			auto distance = m.traveller( v, 230, 3 ) ;

			// check distance
			Assert::AreEqual( 228, distance ) ; // 73, 74, 81
		}

		TEST_METHOD( travellerTest4a )
		{
			vector<int> v { 91, 74, 73, 85, 73, 81 } ; // does not have duplicate 73 

			program m ;
			auto distance = m.traveller( v, 230, 3 ) ;

			// check distance
			Assert::AreEqual( 228, distance ) ; 
		}

		TEST_METHOD( combinationsTest5 )
		{
			vector<int> v { 1, 2, 3 } ;

			program m ;
			auto list = m.combinations( v ) ;

			// check total number of rows expected
			Assert::AreEqual( 10, (int) list.size() ) ;

			// check a few rows that we expect
			Assert::IsTrue( substringExists( list, "[ 1, 2, 3 ]" ) ) ;
			Assert::IsTrue( substringExists( list, "[ 2, 3 ]" ) ) ;
			Assert::IsTrue( substringExists( list, "[ 1, 3 ]" ) ) ;
			Assert::IsTrue( substringExists( list, "[ 1, 2 ]" ) ) ;
			Assert::IsTrue( substringExists( list, "[ 1 ]" ));
			Assert::IsTrue( substringExists( list, "[ 2 ]" ));
			Assert::IsTrue( substringExists( list, "[ 3 ]" ));
		}

		TEST_METHOD( combinationsTest6 )
		{
			vector<int> v { 1, 2, 3, 1 } ; // check duplicate of 1 is handled properly

			program m ;
			auto list = m.combinations( v ) ;

			// check total number of rows expected
			Assert::AreEqual( 41, (int) list.size() ) ;

			// check a few rows that we expect
			Assert::IsTrue( substringExists( list, "[ 1, 2, 3, 1 ]" ) ) ;
			Assert::IsTrue( substringExists( list, "[ 2, 3, 1 ]"    ) ) ;
			Assert::IsTrue( substringExists( list, "[ 1, 3, 1 ]"    ) ) ;
			Assert::IsTrue( substringExists( list, "[ 1, 2, 1 ]"    ) ) ;
			Assert::IsTrue( substringExists( list, "[ 1, 2, 3 ]"    ) ) ;
		}

	} ; // end test class
}
