#include "Dead.h"

Dead::~Dead() {}

void Dead::Behave() 
{
	if( AliveNeighbors() == 3 )
	{
		for( auto& cell : neighbors )
			if( cell->NextState() == ASLEEP )
				cell->cellState->nextState = DEAD;
	}
	else if( NextStateAliveNeighbors() == 0 )
	{
		nextState = ASLEEP;
	}
}
