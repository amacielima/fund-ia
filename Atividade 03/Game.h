#include <iostream>

#include "Board.h"
#include "MinMax.h"

using namespace std;

#ifndef game
#define game

	class Game
	{
		private:
			
		int turn;				// varivável para controle do número da jogada
	
		public:
			
		MinMax mm;				// variável do cálculo do algoritmo min_max
		
		Board * b;				// quadro do jogo
			
		Game(Board * );			// construtor
			
		void start();			// inicia jogo
		
		void incrementTurn(); 	// incrementa o número do turno		
		
		void playerTurn();		// função para disponibilizar interface para o turno do jogador
		
	};

#endif
