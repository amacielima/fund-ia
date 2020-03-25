#include "Game.h"

	Game::Game(Board * b)
	{
		this->b = b;	// inicializa jogo com o quadro
		turn = 0;		// inicializa turno
		start();		// inicia o jogo
	}
	
	void Game::incrementTurn()
	{
		turn = turn + 1;
	}
	
	void Game::playerTurn()
	{
		
		int x = 0, y = 0;
		bool flag = false;
		
		while (!flag)
		{
			
			cout << "\tInsira o ID da linha: ";
			cin >> x;
		
			cout << "\tInsira o ID da coluna: ";
			cin >> y;
			
			cout << "\n\t# # # # # # # # # # # # # # # # #" << endl << endl;
			
			// verifica se os valores digitados estão dentro do quadro
			if ((x >= (MIN_X + 1) && x <= (MAX_X + 1) && y >= (MIN_Y + 1) && y <= (MAX_Y + 1)))
			{
				
				// se os valores corresponderem a um valor livre, inserir tag do jogador no bloco
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
		
		// flags para indicar a vitória para cada jogador
		bool p_over = false, c_over = false;
		
		// incrementa turno
		incrementTurn();
		
		while (!b->isDraw() && b->winner == '*')
		{
			
			// se o turno for par, é a vez do jogador
			if ((turn % 2) == 0)
			{
				playerTurn();
			}
		
			// senão é a vez da cpu
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
		
		// se a interação acabar, verificar se houve vencedor ou velha
		if(!b->isDraw())
		{
			cout << "\n\tJogador " << b->winner << " venceu!" << endl;
		}
		
		else
		{
			cout << "\n\tVelha!" << endl;
		}
		
	}
