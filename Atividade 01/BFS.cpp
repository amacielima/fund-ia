#include "BFS.h"

	BFS::BFS()
	{
		
	}
	
	bool BFS::insertQueue(State st, queue<State> q)
	{
		
		queue<State> aux = q;
		
		
		
	}
	
	void BFS::search (State initialState)
	{
		
		visited.clear();
		
		q.push(initialState);
					
		State currentState = q.front();
		State newState = currentState;
		
		int a = currentState.getQtdA();
		int b = currentState.getQtdB();
		
		// enquanto a fila não estiver vazia e o estado atual nao for o objetivo
		while (!q.empty() && !currentState.isGoal())
		{
			
			a = currentState.getQtdA();
			b = currentState.getQtdB();
			newState = currentState;
			
			q.pop();
			
			/*
				ações
				1 - Encher o(s) jarros
				2 - Esvaziar o(s) jarros
				3 - Transferir do jarro A para o jarro B
				4 - Transferir do jarro B para o jarro A
			*/
			
			if (!exploredState(a, b))
			{
				
				cout << "\t |--> Estado (" << a << "," << b << ")" << endl;
				
				// ação 1
				if (a >= 0 && a < CAP_A && !exploredState(CAP_A, b))
				{
					
					newState.qtd_a = CAP_A;
					newState.qtd_b = b;
						
					q.push(newState);
						
					cout << "\t |----> Encheu jarro A (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
					
				}
				
				if (b >= 0 && b < CAP_B && !exploredState(a, CAP_B))
				{
					
					newState.qtd_a = a;
					newState.qtd_b = CAP_B;
					
					q.push(newState);
						
					cout << "\t |----> Encheu jarro B (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
					
				}
				
				// ação 2
				
				if (a > 0 && !exploredState(0, b))
				{
					
					newState.qtd_a = 0;
					newState.qtd_b = b;
						
					q.push(newState);
						
					cout << "\t |----> Esvaziou jarro A (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
					
				}
				
				if (b > 0  && !exploredState(a, 0))
				{
					
					newState.qtd_a = a;
					newState.qtd_b = 0;
					
					q.push(newState);
						
					cout << "\t |----> Esvaziou jarro B (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
					
				}
				
				// ação 3
				
				int a_b_x = max(0, a + b - CAP_B);
				int a_b_y = min(a + b, CAP_B);
							
				if (a_b_x >= 0 && a_b_x != a && a_b_y != b && !exploredState(a_b_x, a_b_y))
				{
					
					newState.qtd_a = a_b_x;
					newState.qtd_b = a_b_y;
					
					q.push(newState);
												
					cout << "\t |----> Transferiu do jarro A para o B (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
	
				}
				
				// ação 4
				
				int b_a_x = min(a + b, CAP_A);
				int b_a_y = max(0, a + b - CAP_A);
				
				if (b_a_y >= 0 && b_a_x != a && b_a_y != b && !exploredState(b_a_x, b_a_y))
				{
					
					newState.qtd_a = b_a_x;
					newState.qtd_b = b_a_y;
					
					q.push(newState);
						
					cout << "\t |----> Transferiu do jarro B para o A (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
	
				}
	
				visited.push_back(currentState);
				
			}
					
			currentState = q.front();
			
		}
	
	}
