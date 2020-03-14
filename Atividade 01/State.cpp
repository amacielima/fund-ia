#include "State.h"

	State::State (int a, int b)
	{
		qtd_a = a;
		qtd_b = b;
		//visited = false;
	}
	
			
	void State::setQtdA(int a)
	{
		qtd_a = a;
	}
		
	int State::getQtdA()
	{
		return qtd_a;
	}

	void State::setQtdB(int b)
	{
		qtd_b = b;
	}
	
	int State::getQtdB()
	{
		return qtd_b;
	}
	
	/*void State::setVisited(bool flag)
	{
		visited = flag;
	}
	
	int State::getVisited()
	{
		return visited;
	}*/
	
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
	
