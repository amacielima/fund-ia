#include <iostream>
#include <cstdlib>
using namespace std;

#define X 3
#define Y 3

#define MIN_X 0
#define MIN_Y 0

#define MAX_X 2
#define MAX_Y 2

#ifndef board
#define board

	class Board
	{
		
		public:
			
		char b[X][Y];						// matriz do jogo
		static const char player = 'O';		// símbolo do jogador
		static const char cpu = 'X';		// símbolo da cpu
		static const char empty = '-';		// símbolo vazio
		
		char winner;						// variável para indicar o vencedor
		
		bool over;							// verifica se o jogo foi finalizado
		
		Board ();							// construtor
		
		void print();						// imprime jogo
		
		void insertValue(int, int, char);	// insere o valor na posição x e y
		
		bool isFree(int, int);				// verifica se o bloco está livre
				
		bool isDraw();						// verifica empate (velha)
		
		bool checkPlayerWin(char);			// verifica se o jogador ganhou
		
		int utility(char, char, int, int);	// calcula função de utilidade
		
	};

#endif
