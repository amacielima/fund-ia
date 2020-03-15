#include <iostream>
#include <stdlib.h>
#include <queue>
#include <stack>

#include "State.h"

using namespace std;

#ifndef blindsearch
#define blindsearch

#define CAP_A 3 // capacidade jarro A
#define CAP_B 4 // capacidade jarro B

	class BlindSearch
	{
		
		public:
			
		vector<State> visited;					// vetor de n�s visitados na busca
			
		BlindSearch() {};						// construtor
		
		bool exploredState(int, int);			// verifica se o n� j� foi explorado na busca
		
		bool isPossibleState(int, int, int);	// verifica se determinada a��o pode ser realizada
		
		virtual void search (State) = 0;		// m�todo virtual para busca BFS/DFS
		
		~BlindSearch() {};						// destrutor
		
	};
	
#endif
