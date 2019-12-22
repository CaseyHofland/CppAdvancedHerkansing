#include "Alive.h"

Alive::~Alive() {}

void Alive::Behave() 
{
	const int aliveNeighbors = AliveNeighbors();
	if( aliveNeighbors < 2 || aliveNeighbors > 3 )
		nextState = DEAD;
}
