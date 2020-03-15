#include "BlindSearch.h"

using namespace std;

#ifndef dfs
#define dfs

	class DFS : public BlindSearch
	{
		
		public:
			
		stack<State> s; 		// pilha para a busca DFS
		
		DFS();					// construtor

		void search (State);	// método de busca
		
		~DFS() {};
	};

#endif
