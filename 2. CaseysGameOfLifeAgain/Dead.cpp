#include "Dead.h"

Dead::~Dead() {}

void Dead::Behave() 
{
	if( cell->AliveNeighbors() == 3 )
	{
		for( auto& cell : cell->neighbors )
			if( cell->NextState() == ASLEEP )
				cell->cellState->nextState = DEAD;

		nextState = ALIVE;
	}
	else if( cell->NextStateAliveNeighbors() == 0 )
	{
		nextState = ASLEEP;
	}
}
