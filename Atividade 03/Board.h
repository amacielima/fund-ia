#include <iostream>
#include <cstdlib>
using namespace std;

#define X 3
#define Y 3

#define MIN_X 1
#define MIN_Y 1

#define MAX_X 3
#define MAX_Y 3

#ifndef board
#define board

	class Board
	{
		
		public:
			
		char b[X][Y];						// matriz do jogo
		static const char player = 'O';		// símbolo do jogador
		static const char cpu = 'X';		// símbolo da cpu
		static const char empty = '-';		// símbolo vazio
		
		char winner;
		
		bool over;							// verifica se o jogo foi finalizado
		
		Board ();							// construtor
		
		void print();						// imprime jogo
		
		void insertValue(int, int, char);	// insere o valor na posição x e y
		
		bool isFree(int, int);				// verifica se o bloco está livre
				
		bool isDraw();						// verifica empate (velha)
		
		bool checkPlayerWin(char);			// verifica se o jogador ganhou
		
		int utility();						// calcula função de utilidade
		
	};

#endif
