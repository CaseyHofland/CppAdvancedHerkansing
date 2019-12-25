#include "Alive.h"
#include <iostream>

Alive::~Alive() {}

void Alive::Behave() 
{
	const int aliveNeighbors = cell->AliveNeighbors();
	if( aliveNeighbors < 2 || aliveNeighbors > 3 )
		nextState = DEAD;
}
