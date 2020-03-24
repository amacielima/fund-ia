#include <iostream>

#include "Board.h"

#define INF 100
#define ERROR 404

using namespace std;

#ifndef minmax
#define minmax

	class MinMax : public Board
	{
	
		public:
		
		MinMax() {};
		
		int min(Board);
		
		int max(Board);
		
	};

#endif
