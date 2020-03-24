#include <iostream>

#include "Board.h"
#include "MinMax.h"

using namespace std;

#ifndef game
#define game

	class Game : public Board
	{
		private:
			
		int turn;
	
		public:
			
		Game();
			
		void start();
		
		void incrementTurn();
		
		int getTurn();
		
		void playerTurn();
		
	};

#endif
