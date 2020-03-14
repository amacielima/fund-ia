#include "BlindSearch.h"

#define CAP_A 3 // capacidade jarro A
#define CAP_B 4 // capacidade jarro B

using namespace std;

#ifndef bfs
#define bfs

	class BFS : public BlindSearch
	{
		
		public:
			
		queue<State> q; 		// fila para a busca BFS
		
		BFS();
		
		bool insertQueue(State, queue<State>);

		void search (State);
			
	};

#endif
