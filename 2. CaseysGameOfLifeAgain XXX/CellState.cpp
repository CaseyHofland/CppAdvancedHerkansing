#include "CellState.h"
#include <algorithm>

const int CellState::NextState() const {
	return nextState;
}

void CellState::AddNeighbor(Cell* neighbor)
{
	neighbors.push_back(neighbor);
}

int CellState::AliveNeighbors() 
{
	int alives = 0;
	for( const auto& cell : neighbors )
		if( cell->State() == ALIVE )
			alives++;

	return alives;
}

int CellState::NextStateAliveNeighbors() 
{
	int nextAlives = 0;
	for( const auto& cell : neighbors )
		if( cell->NextState() == ALIVE )
			nextAlives++;

	return nextAlives;
}
