#include "Dead.h"

Dead::~Dead() {}

void Dead::Behave() 
{
	if( cell->AliveNeighbors() == 3 )
	{
		nextState = ALIVE;

		for( auto& cell : cell->neighbors )
			if( cell->NextState() == ASLEEP )
				cell->cellState->nextState = DEAD;
	}
	else if( cell->NextStateAliveNeighbors() == 0 )
	{
		nextState = ASLEEP;
	}
}
