#include "BlindSearch.h"

#define CAP_A 3 // capacidade jarro A
#define CAP_B 4 // capacidade jarro B

using namespace std;

#ifndef dfs
#define dfs

	class DFS : public BlindSearch
	{
		
		public:
			
		stack<State> s; 		// pilha para a busca DFS
		
		DFS();

		void search (State);
		
		
	};

#endif
