#include <iostream>

#include "State.h"
#include "BFS.h"
#include "DFS.h"

using namespace std;

	char selectSearch ()
	{
		cout << endl << "\t- ~ - ~ - ~ - ~  -----------------  ~ - ~ - ~ - ~ -" << endl;
		cout << "\t- ~ - ~ - ~ - ~ | Atividade Jarro | ~ - ~ - ~ - ~ -" 		<< endl;
		cout << "\t- ~ - ~ - ~ - ~  -----------------  ~ - ~ - ~ - ~ -" << endl << endl;
		
		cout << "\t\t Selecione o tipo de busca desejada:	" << endl;
		cout << "\t\t\t (1) - BFS" << endl;
		cout << "\t\t\t (2) - DFS" << endl;
		
		cout << endl << "\t- ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ -  ~ - ~ - ~ - ~ -" << endl << endl;
		
		char choice = 0;
		
		while (choice != '1' && choice != '2')
		{
			cout << "\t>  ";
			cin  >> choice;			
		}
		
		return choice;
	}

	char redoSearch ()
	{
		char choice = 0;
		
		cout << endl << "\t- ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ -  ~ - ~ - ~ - ~ -" << endl << endl;
		cout << "\t\t Refazer busca? (Y/N)" << endl;
		cout << "\t- ~ - ~ - ~ - ~ - ~ - ~ - ~ - ~ -  ~ - ~ - ~ - ~ -" << endl << endl;
		
		cout << "\t>  ";
		cin  >> choice;
		
		while (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n')
		{
			cout << "\t>  ";
			cin  >> choice;
		}
		
		if	(choice == 'Y' || choice == 'y')
		{
			return '1';
		}

		if (choice == 'N' || choice == 'n')
		{
			return '0';
		}
		
	}

	int main() 
	{
		
		State initialState(0,0);
		BFS * b = new BFS();
		DFS * d = new DFS();

		char choice = selectSearch();
		
		if (choice == '1')
		{
			
			b->search(initialState);
			
			if (redoSearch() == '1')
			{
				system("cls");
				choice = selectSearch();
				
				if (choice == '1')
				{
					b->search(initialState);
				}
				
				else if (choice == '2')
				{
					d->search(initialState);
				}
				
			}
			
			else
			{
				system("pause");
			}
			
		}
			
		else if (choice == '2')
		{
			
			d->search(initialState);
			
			if (redoSearch() == '1')
			{
				system("cls");
				choice = selectSearch();
				
				if (choice == '1')
				{
					b->search(initialState);
				}
				
				else if (choice == '2')
				{
					d->search(initialState);
				}
				
			}
			
			else
			{
				system("pause");
			}
			
		}
		
		return 0;
		
	}
