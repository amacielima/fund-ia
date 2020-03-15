#include "BlindSearch.h"

using namespace std;

#ifndef bfs
#define bfs

	class BFS : public BlindSearch
	{
		
		public:
			
		queue<State> q; 		// fila para a busca BFS
		
		BFS();					// construtor

		void search (State);	// método da busca
		
		~BFS() {};
		
	};

#endif
