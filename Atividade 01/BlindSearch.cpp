#include "BlindSearch.h"

	bool BlindSearch::exploredState(int a, int b)
	{
		
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
