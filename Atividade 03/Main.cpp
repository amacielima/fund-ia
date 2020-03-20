#include <iostream>

#include "Board.h"
#include "MinMax.h"

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
		
		// cria o objeto do quadro
		Board b;
		
		// insere os valores iniciais
		b.insertValue(x, y, 'O');
		b.print();
		
		// inici algoritmo
		MinMax mm(b);
		
		return 0;
		
	}
