#include <iostream>

#include "Board.h"
#include "MinMax.h"

using namespace std;

#ifndef game
#define game

	class Game
	{
		private:
			
		int turn;
	
		public:
			
		MinMax mm;
		
		Board * b;
			
		Game(Board * );
			
		void start();
		
		void incrementTurn();
		
		int getTurn();
		
		void playerTurn();
		
	};

#endif
