#include <iostream>
#include <stdlib.h>

using namespace std;

#ifndef state
#define state

	class State
	{
		public:
			
		int qtd_a; 		// quantidade atual jarro A
		int qtd_b; 		// quantidade atual jarro B
		
		State(int, int); // construtor
		
		bool isGoal();	// verifica se o estado é o objetivo
		
		~State() {};
		
	};
	
#endif
