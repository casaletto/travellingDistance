#pragma once

namespace travellingDistance
{
	class program
	{
		public:
			program() ;

			void           helloWorld() ;
			vector<string> combinations( vector<int>& v ) ;
			int            traveller( vector<int>& v, int t, int k ) ;

		protected:
			string dump( vector<int>& v, int i, int indent ) ;
			void   combinations( vector<int>& v, int& row, int indent, vector<string>& list ) ;
			void   traveller( vector<int>& v, int t, int k, int& max, int& row, int indent ) ;
	} ;

} ; // end namespace
