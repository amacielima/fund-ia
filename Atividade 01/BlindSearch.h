#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>

#include "State.h"

using namespace std;

#ifndef blindsearch
#define blindsearch

	class BlindSearch
	{
		
		public:
			
		vector<State> visited;
			
		BlindSearch() {};
		
		bool exploredState(int, int);
		
		virtual void search (State) = 0;
		
		~BlindSearch() {};
		
	};
	
#endif
