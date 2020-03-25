#include <iostream>

#include "Board.h"
#include "MinMax.h"
#include "Game.h"

using namespace std;

	int main() 
	{

		int x = 0, y = 0;
		
		cout << "\n\t# # # # # # # # # # # # # # # # #" << endl;
		cout << "\t# # # # # Jogo da Velha # # # # #" << endl;
		cout << "\t# # # # # # # # # # # # # # # # #" << endl << endl;
		
		cout << "\t     O - Jogador   X - CPU\n" << endl;
		
		cout << "\t# # # # # # # # # # # # # # # # #" << endl << endl;
		
		// inicia o quadro do jogo
		Board * b = new Board();
		b->print();
		
		while (!(x >= (MIN_X + 1) && x <= (MAX_X + 1) && y >= (MIN_Y + 1) && y <= (MAX_Y + 1)))
		{
			cout << "\tInsira o ID da linha: ";
			cin >> x;
		
			cout << "\tInsira o ID da coluna: ";
			cin >> y;
			
			cout << "\n\t# # # # # # # # # # # # # # # # #" << endl << endl;
		}
	
		b->insertValue(x - 1, y - 1, b->player);
		
		// inicializa jogo
		Game g(b);
		
		return 0;
		
	}
