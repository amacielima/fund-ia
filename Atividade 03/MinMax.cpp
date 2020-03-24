#include "MinMax.h"

	int MinMax::min (Board b)
	{
		
		// inicia a vari�vel de score com valor positivo
		int score = + INF;
		
		// retornar 0 se estiver empatado
		if (b.isDraw())
		{
			return ERROR;
		}
		
		else
		{
			
			// percorre o quadro
			for (int i = 0; i < MAX_X; i++)
			{
			
				for (int j = 0; j < MAX_Y; j++)
				{
					
					if (b.isFree(i,j))
					{
						
						// insere o valor do jogador no local vazio
						b.insertValue(i,j, player);
						
						// calcula fun��o de utilidade
						int min;
						
						// se o valor da vari�vel atual for maior que o valor da utilidade 
						if (min < score)
						{
							// a vari�vel atual fica com o valor m�nimo encontrado at� a itera��o
							score = min;
						}
						
						// insere vazio na posi��o que foi calculada
						b.insertValue(i,j, empty);
						
					}
					
				}
				
			}
			
		}
		
		return score;
	}
	
	int MinMax::max (Board b)
	{
		
		// inicia a vari�vel de score com valor negativo
		int score = - INF;
		
		// retornar 0 se estiver empatado
		if (b.isDraw())
		{
			return ERROR;
		}
		
		else
		{
			
			for (int i = 0; i < MAX_X; i++)
			{
			
				for (int j = 0; j < MAX_Y; j++)
				{
					
					if (b.isFree(i,j))
					{
						
						// insere o valor do jogador no local vazio
						b.insertValue(i,j, cpu);
						
						// calcula a fun��o de utilidade
						int max;
						
						// se o valor da vari�vel atual for menor que o valor da utilidade 
						if (max > score)
						{
							// o valor da vari�vel atual fica com o valor m�ximo encontrado at� a itera��o
							score = max;
						}
						
						// insere vazio na posi��o que foi calculada
						b.insertValue(i,j, empty);
						
					}
					
				}                                                                             
				
			}
			
		}

		return score;
		
	}
