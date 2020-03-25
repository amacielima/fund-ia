#include <iostream>

#include "Board.h"
#include "MinMax.h"

using namespace std;

#ifndef game
#define game

	class Game
	{
		private:
			
		int turn;				// variv�vel para controle do n�mero da jogada
	
		public:
			
		MinMax mm;				// vari�vel do c�lculo do algoritmo min_max
		
		Board * b;				// quadro do jogo
			
		Game(Board * );			// construtor
			
		void start();			// inicia jogo
		
		void incrementTurn(); 	// incrementa o n�mero do turno		
		
		void playerTurn();		// fun��o para disponibilizar interface para o turno do jogador
		
	};

#endif
