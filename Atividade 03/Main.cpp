#include <iostream>

#include "Board.h"
#include "MinMax.h"
#include "Game.h"

#define MIN_X 1
#define MIN_Y 1

#define MAX_X 3
#define MAX_Y 3

using namespace std;

	int main() 
	{

		int x = 0, y = 0;
		
		cout << "\n\t# # # # # # # # # # # # # # # # #" << endl;
		cout << "\t# # # # # Jogo da Velha # # # # #" << endl;
		cout << "\t# # # # # # # # # # # # # # # # #" << endl << endl;
		
		while (!(x >= MIN_X && x <= MAX_X && y >= MIN_X && y <= MAX_Y))
		{
			cout << "\tInsira o ID da linha: ";
			cin >> x;
		
			cout << "\tInsira o ID da coluna: ";
			cin >> y;
			
			cout << "\n\t# # # # # # # # # # # # # # # # #" << endl << endl;
		}
		
		// inicia o jogo
		Game g;
		g.insertValue(x - 1, y - 1, 'O');
		g.print();
		
		return 0;
		
	}
