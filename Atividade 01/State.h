#include <iostream>
#include <stdlib.h>

#define CAP_A 3 // capacidade jarro A
#define CAP_B 4 // capacidade jarro B

using namespace std;

#ifndef state
#define state

	class State
	{
		public:
		int qtd_a; // quantidade atual jarro A
		int qtd_b; // quantidade atual jarro B
		
		// construtor
		State(int, int);
		
		// get e set - Quantidade A		
		void setQtdA(int);		
		int getQtdA();

		// get e set - Quantidade B	
		void setQtdB(int);
		int getQtdB();
		
		// get e set - flag busca
		void setVisited(bool);
		int getVisited();
		
		// verifica se o estado é o objetivo
		bool isGoal();
		
	};
	
#endif
