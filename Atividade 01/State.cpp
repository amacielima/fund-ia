#include "State.h"

	State::State (int a, int b)
	{
		qtd_a = a;
		qtd_b = b;
	}
	
	bool State::isGoal()
	{
		
		if (qtd_b == 2)
		{
			return true;
		}
		
		else
		{
			return false;
		}
		
	}
