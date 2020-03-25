#include "MinMax.h"

	void MinMax::min (Board * b)
	{
		
		// inicia a vari�vel de score com valor positivo
		int score = + INF;
		int x = 0, y = 0;
		
		// retornar 0 se estiver empatado
		if (!b->isDraw())
		{
			
			// percorre o quadro
			for (int i = 0; i < MAX_X; i++)
			{
			
				for (int j = 0; j < MAX_Y; j++)
				{
					
					if (b->isFree(i,j))
					{
						
						// insere o valor do jogador no local vazio
						b->insertValue(i, j, b->player);
						
						// calcula fun��o de utilidade
						int min = b->utility(b->player, b->cpu, i, j);
						
						// se o valor da vari�vel atual for maior que o valor da utilidade 
						if (min < score)
						{
							// a vari�vel atual fica com o valor m�nimo encontrado at� a itera��o
							score = min;
							x = i;
							y = j;
						}
						
						// insere vazio na posi��o que foi calculada
						b->insertValue(i, j, b->empty);
						
					}
					
				}
				
			}
			
			b->insertValue(x, y, b->player);
			
		}

	}
	
	void MinMax::max (Board * b)
	{
		
		// inicia a vari�vel de score com valor negativo
		int score = - INF;
		int x = -1, y = -1;
		
		// retornar 0 se estiver empatado
		if (!b->isDraw())
		{
			
			for (int i = 0; i < (MAX_X + 1); i++)
			{
			
				for (int j = 0; j < (MAX_Y + 1); j++)
				{
					
					if (b->isFree(i,j))
					{
						
						// insere o valor do jogador no local vazio
						b->insertValue(i,j, b->cpu);
						
						// calcula a fun��o de utilidade
						int max = b->utility(b->cpu, b->player, i, j);
						
						// se o valor da vari�vel atual for menor que o valor da utilidade 
						if (max > score)
						{
							// o valor da vari�vel atual fica com o valor m�ximo encontrado at� a itera��o
							score = max;
							
							// armazena posi��es da melhor jogada
							x = i;
							y = j;
						}
						
						// insere vazio na posi��o que foi calculada
						b->insertValue(i,j, b->empty);
						
					}
					
				}                                                                             
				
			}
			
			if (x != -1 && y != -1)
			{
				b->insertValue(x, y, b->cpu);
			}
			
		}

	}
