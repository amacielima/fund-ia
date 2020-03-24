#include "Game.h"

	Game::Game()
	{
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
		
		cout << "\n\t# # # # # # # # # # # # # # # # #" << endl;
		cout << "\t# # # # # Jogo da Velha # # # # #" << endl;
		cout << "\t# # # # # # # # # # # # # # # # #" << endl << endl;
		
		print();
		
		while (!flag)
		{
			cout << "\tInsira o ID da linha: ";
			cin >> x;
		
			cout << "\tInsira o ID da coluna: ";
			cin >> y;
			
			cout << "\n\t# # # # # # # # # # # # # # # # #" << endl << endl;
			
			if (x >= MIN_X && x <= MAX_X && y >= MIN_X && y <= MAX_Y)
			{
				
				if (isFree(x,y))
				{
					insertValue(x, y, player);
					flag = true;
				}
		
				else
				{
					cout << "\n\tBloco ocupado." << endl << endl;
				}
				
			}
			
			else
			{
				cout << "\n\tMovimento inválido!" << endl << endl;
			}
			
		}
		
		system("cls");
		
	}
	
	void Game::start()
	{
		bool over = false;
		incrementTurn();
		
		while (!isDraw() && winner != '*')
		{
			
			if (turn % 2 == 0)
			{
				playerTurn();
			}
		
			else
			{
				
			}
			
			// verifica se algum jogador ganhou
			over = checkPlayerWin(player);
			over = checkPlayerWin(cpu);
			
			incrementTurn();
			
		}
		
		// imprime jogo
		print(); 	
		
		cout << "\n\tJogador " << winner << " venceu!" << endl;
		
	}
