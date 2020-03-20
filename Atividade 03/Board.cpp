#include "Board.h"

	Board::Board()
	{
		// inicializa a matriz
		for (int i = 0; i < X; i++)
		{
			
			
			for (int j = 0; j < Y; j++)
			{
				b[i][j] = '-';
			}
			
		}
		
	}
	
	void Board::print()
	{
		
		cout << "\t     /     1     2     3" << endl;
			
		for (int i = 0; i < X; i++)
		{
			
			cout << "\t     " << i + 1;
			
			for (int j = 0; j < Y; j++)
			{
				cout << "     " << b[i][j];
			}
			
			cout << endl;
			
		}
		
		cout << "\n\t# # # # # # # # # # # # # # # # #" << endl << endl;
		
	}
	
	void Board::insertValue (int x, int y, char value)
	{
		// insere valor nas posições indicadas
		if (x >= MIN_X && x <= MAX_X && y >= MIN_X && y <= MAX_Y)
		{
			b[x - 1][y -1] = value;
		}

	}
	
	bool Board::isFree(int x, int y)
	{
		// verifica se o bloco está livre	
		if (b[x][y] == '-')
		{
			return true;
		}
		
		else
		{
			return false;
		}
		
	}
	
	bool Board::isTie()
	{
		return false;
	}
	
	bool Board::checkPlayerWin(char player)
	{
		
		for (int i = 0; i < X; i++)
		{
			// verifica se venceu pela horizontal
			if (b[i][0] == player && b[i][1] == player && b[i][2] == player)
			{
				return true;
			}
			
			// verifica se venceu pela vertical
			if (b[0][i] == player && b[1][i] == player && b[2][i] == player)
			{
				return true;
			}
		}
		
		// verifica se venceu por alguma das diagonais
		if ( (b[0][0] == player && b[1][1] == player && b[2][2] == player) || (b[2][0] == player && b[1][1] == player && b[2][0] == player) )
		{
			return true;
		}
				
		return false;
		
	}
