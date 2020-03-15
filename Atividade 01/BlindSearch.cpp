#include "BlindSearch.h"

	bool BlindSearch::exploredState(int a, int b)
	{
		
		// percorre o vetor de visitados e verifica se h� a combina��o de A e B
		
		for (std::size_t i = 0; i < visited.size(); i++)
		{
			
			if (visited[i].qtd_a == a && visited[i].qtd_b == b)
			{
				//cout << "\t |---> Visitado (" << a << "," << b << ")" << endl;
				return true;
			}
			
		}
		
		//cout << "\t |---> Nao Visitado (" << a << "," << b << ")" << endl;
		return false;
		
	}
	
	bool BlindSearch::isPossibleState(int action, int a, int b)
	{
		// vari�veis de transfer�ncia de A para B
		int a_b_x = max(0, a + b - CAP_B);
		int a_b_y = min(a + b, CAP_B);
		
		// vari�veis de transfer�ncia de B para A
		int b_a_x = min(a + b, CAP_A);
		int b_a_y = max(0, a + b - CAP_A);

		switch (action)
		{
			
			/*
				A��o 1 e 2 - Encher o(s) jarros
				 	
				Se o valor do jarro A ou B for maior igual a 0 e 
					menor que a capacidade do Jarro	e
					estado n�o foi explorado
				
				Ent�o o valor do jarro A ou B � a sua capacidade m�xima
			*/
			
			case 1:
			
				if (a >= 0 && a < CAP_A && !exploredState(CAP_A, b))
				{
					return true;
				}
				
				else
				{
					return false;
				}
				
				break;
			
			case 2:
				
				if (b >= 0 && b < CAP_B && !exploredState(a, CAP_B))
				{
					return true;
				}
				
				else
				{
					return false;
				}
				
				break;
			
			/*
				A��o 3 e 4 - Esvaziar o(s) jarros
				 	
				Se o valor do jarro A ou B for maior que 0 e 
					estado n�o foi explorado
					
				Ent�o o valor do jarro A ou B � esvaziado
			*/
			
			case 3:
				
				if (a > 0  && !exploredState(0, b))
				{
					return true;
				}
				
				else
				{
					return false;
				}
				
				break;
			
			case 4:
				
				if (b > 0  && !exploredState(a, 0))
				{
					return true;
				}
				
				else
				{
					return false;
				}
				
				break;
			
			/*
				A��o 5 - Transferir do jarro A para o jarro B
				 	
				Se o valor ap�s a transfer�ncia do jarro A for positivo e
					os valores de A e B n�o forem iguais ao estado atual e
					estado n�o foi explorado
					
				Ent�o o valor do jarro A � transferido para o jarro B
			*/
				
			case 5:
				
				if (a_b_x >= 0 && a_b_x != a && a_b_y != b && !exploredState(a_b_x, a_b_y))
				{
					return true;
				}
				
				else
				{
					return false;
				}
				
				break;
			
			/*
				A��o 6 - Transferir do jarro B para o jarro A
				 	
				Se o valor ap�s a transfer�ncia do jarro B for positivo e
					os valores de A e B n�o forem iguais ao estado atual e
					estado n�o foi explorado
					
				Ent�o o valor do jarro B � transferido para o jarro A
			*/
					
			case 6:

				if (b_a_y >= 0 && b_a_x != a && b_a_y != b && !exploredState(b_a_x, b_a_y))
				{
					return true;
				}
				
				else
				{
					return false;
				}
				
				break;
			
		}
		
		return false;
	}
