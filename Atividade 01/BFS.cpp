#include "BFS.h"

	BFS::BFS() {}
	
	void BFS::search (State initialState)
	{
		
		visited.clear(); 				// limpa vetor de visitados
		
		q.push(initialState); 			// insere estado inicial na fila
					
		State currentState = q.front();	// no atual é o primeiro da fila
		State newState = currentState;	// estado a ser manipulado é o estado atual
		
		int a = currentState.qtd_a; 	// o valor de A é o valor do jarro A no estado inicial
		int b = currentState.qtd_b; 	// o valor de B é o valor do jarro B no estado inicial
		
		// enquanto a fila não estiver vazia e o estado atual não for o objetivo
		while (!q.empty() && !currentState.isGoal())
		{
			
			a = currentState.qtd_a; // captura o novo valor do jarro A
			b = currentState.qtd_b; // captura o novo valor do jarro B
			newState = currentState;	// coloca no estado a ser manipulado o estado atual
			
			q.pop();					// tira o estado da fila
			
			// se o estado atual nao estiver explorado, realizar o tratamento do estado
			if (!exploredState(a, b))
			{
				
				cout << "\t |--> Estado (" << a << "," << b << ")" << endl;
				
				// verifica a possibilidade de execução de cada ação
				
				if (isPossibleState(1, a, b))
				{					
					newState.qtd_a = CAP_A;
					newState.qtd_b = b;
					q.push(newState);	// insere o novo valor na fila
								
					cout << "\t |----> Encheu jarro A (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;					
				}
				
				if (isPossibleState(2, a, b))
				{
					
					newState.qtd_a = a;
					newState.qtd_b = CAP_B;
					q.push(newState); 	// insere o novo valor na fila
						
					cout << "\t |----> Encheu jarro B (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
					
				}

				if (isPossibleState(3, a, b))
				{				
					newState.qtd_a = 0;
					newState.qtd_b = b;
					q.push(newState);	// insere o novo valor na fila
						
					cout << "\t |----> Esvaziou jarro A (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;			
				}
				
				if (isPossibleState(4, a, b))
				{	
					newState.qtd_a = a;
					newState.qtd_b = 0;
					q.push(newState);	// insere o novo valor na fila
						
					cout << "\t |----> Esvaziou jarro B (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;					
				}
							
				if (isPossibleState(5, a, b))
				{
					newState.qtd_a = max(0, a + b - CAP_B);
					newState.qtd_b = min(a + b, CAP_B);
					q.push(newState);	// insere o novo valor na fila
												
					cout << "\t |----> Transferiu do jarro A para o B (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
				}
				
				if (isPossibleState(6, a, b))
				{		
					newState.qtd_a = min(a + b, CAP_A);
					newState.qtd_b = max(0, a + b - CAP_A);
					q.push(newState);	// insere o novo valor na fila
						
					cout << "\t |----> Transferiu do jarro B para o A (" << newState.qtd_a << "," << newState.qtd_b << ")" << endl;
				}
	
				// insere o nó que foi explorado no vetor de visitados
				visited.push_back(currentState);
				
			}
			
			// o próximo valor da fila é o estado atual		
			currentState = q.front();
			
		}
	
	}
