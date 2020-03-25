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
		if ((x >= MIN_X && x <= MAX_X && y >= MIN_Y && y <= MAX_Y))
		{
			b[x][y] = value;
		}
		
		else
		{
			cout << "\n\tPosicao invalida!" << endl << endl;
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
			
			for (int j = 0; j < Y; j++)
			{

				if (isFree(i,j))
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
				return true;
			}
			
			// verifica se venceu pela vertical
			if (b[0][i] == player && b[1][i] == player && b[2][i] == player)
			{
				return true;
			}
			
		}
		
		// verifica se venceu por alguma das diagonais
		if ( (b[0][0] == player && b[1][1] == player && b[2][2] == player) || (b[2][0] == player && b[1][1] == player && b[0][2] == player) )
		{
			return true;
		}
				
		return false;
		
	}
	
	int Board::utility(char player, char oponent, int i, int j)
	{
		// verifica se a cpu ganha na jogada
		if (checkPlayerWin(player))
		{
			return 10;
		}
		
		// verifica se o oponente irá vencer nessa posição
		insertValue(i, j, oponent);
		
		// se nessa posição o oponente ganhar na posição
		if(checkPlayerWin(oponent))
		{
			// retira jogada do oponente
			insertValue(i, j, oponent);
			return 7;
		}
		
		// retira jogada do oponente
		insertValue(i, j, oponent);
		
		// verifica se é centro/diagonal
		if (i == j)
		{
			return 5;
		}
		
		// verifica se é algum canto
		else if (i == 0 || i == 2 || j == 0 || j == 2)
		{
			return 1;
		}
		
		// caso não se enquadre em nenhuma das condições
		else
		{
			return 0;
		}
	
	}
