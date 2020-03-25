#include "Game.h"

	Game::Game(Board * b)
	{
		this->b = b;
		turn = 0;		
		start();	
	}
	
	void Game::incrementTurn()
	{
		turn = turn + 1;
	}
	
	int Game::getTurn()
	{
		return turn;
	}
	
	void Game::playerTurn()
	{
		
		int x = 0, y = 0;
		bool flag = false;
		
		b->print();
		
		while (!flag)
		{
			cout << "\tInsira o ID da linha: ";
			cin >> x;
		
			cout << "\tInsira o ID da coluna: ";
			cin >> y;
			
			cout << "\n\t# # # # # # # # # # # # # # # # #" << endl << endl;
			
			if ((x >= (MIN_X + 1) && x <= (MAX_X + 1) && y >= (MIN_Y + 1) && y <= (MAX_Y + 1)))
			{
				
				if (b->isFree(x - 1, y - 1))
				{
					b->insertValue(x - 1, y - 1, b->player);
					flag = true;
				}
		
				else
				{
					cout << "\n\tBloco ocupado." << endl << endl;
				}
				
			}
			
			else
			{
				cout << "\n\tMovimento invalido!" << endl << endl;
			}
			
		}

	}
	
	void Game::start()
	{
		
		bool p_over = false, c_over = false;
		incrementTurn();
		
		while (!b->isDraw() && b->winner == '*')
		{
			
			if ((turn % 2) == 0)
			{
				playerTurn();
			}
		
			else
			{
				mm.max(b);
			}
			
			// verifica se algum jogador ganhou	
			p_over = b->checkPlayerWin(b->player);
			c_over = b->checkPlayerWin(b->cpu);
			
			if (p_over == true)
			{
				b->winner = b->player;
			}
			
			else if (c_over == true)
			{
				b->winner = b->cpu;
			}
			
			incrementTurn();
			
			// imprime jogo
			b->print();
	
		}	
		
		if(!b->isDraw())
		{
			cout << "\n\tJogador " << b->winner << " venceu!" << endl;
		}
		
		else
		{
			cout << "\n\tVelha!" << endl;
		}
		
	}
