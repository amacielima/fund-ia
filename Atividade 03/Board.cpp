#include "Board.h"

	Board::Board()
	{
		
		winner = '*';
		
		// inicializa a matriz
		for (int i = 0; i < X; i++)
		{
			
			
			for (int j = 0; j < Y; j++)
			{
				b[i][j] = empty;
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
			b[x][y] = value;
		}
		
		else
		{
			cout << "Movimento inválido!" << endl << endl;
		}

	}
	
	bool Board::isFree(int x, int y)
	{
		// verifica se o bloco está livre	
		if (b[x][y] == empty)
		{
			return true;
		}
		
		else
		{
			return false;
		}
		
	}
	
	bool Board::isDraw()
	{
		// verifica se não há casas vazias
		for (int i = 0; i < X; i++)
		{
			
			cout << "\t     " << i + 1;
			
			for (int j = 0; j < Y; j++)
			{
				
				if(b[i][j] == empty)
				{
					return false;
				}
				
			}
			
		}
		
		return true;
					
	}
	
	bool Board::checkPlayerWin(char player)
	{
		
		for (int i = 0; i < X; i++)
		{
			// verifica se venceu pela horizontal
			if (b[i][0] == player && b[i][1] == player && b[i][2] == player)
			{
				winner = player;
				return true;
			}
			
			// verifica se venceu pela vertical
			if (b[0][i] == player && b[1][i] == player && b[2][i] == player)
			{
				winner = player;
				return true;
			}
		}
		
		// verifica se venceu por alguma das diagonais
		if ( (b[0][0] == player && b[1][1] == player && b[2][2] == player) || (b[2][0] == player && b[1][1] == player && b[2][0] == player) )
		{
			winner = player;
			return true;
		}
				
		return false;
		
	}
	
	int Board::utility()
	{
		int value = 0;
		
		return value;
	}
