#include "Cell.h"
#include "Alive.h"
#include "Dead.h"
#include "Asleep.h"
#include "State.h"
#include <algorithm>

/* The Cell hold information about its state and its neighbors. It communicates with its neighbors to 
decide what state to transition to. I would implement shared pointers here if I were smarter (pun intended) */

Cell::Cell() : cellState(new Dead(this)) {}

Cell::Cell(CellState* cellState) : cellState(cellState) {}

Cell::~Cell() {}

void Cell::Behave() const
{
	cellState->Behave();
}

void Cell::Next() 
{
	SetState(cellState->nextState);
}

// Switches to a new CellState by deleting the old one and creating a new one
void Cell::SetState(int state) {
	delete this->cellState;

	switch( state )
	{
	case ASLEEP:
		this->cellState = new Asleep(this);
		break;
	case DEAD:
		this->cellState = new Dead(this);
		break;
	case ALIVE:
		this->cellState = new Alive(this);
		break;
	}
}

void Cell::AddNeighbor(Cell* neighbor) {
	neighbors.push_back(neighbor);
}

// Counts the Alive Neighbors for checking what state the cell should transition into
int Cell::AliveNeighbors() 
{
	int alives = 0;
	for( const auto& cell : neighbors )
		if( cell->State() == ALIVE )
			alives++;

	return alives;
}

// Counts the neighbors that will be alive next loop to determine if the state should sleep if the state is dead
int Cell::NextStateAliveNeighbors() 
{
	int nextAlives = 0;
	for( const auto& cell : neighbors )
		if( cell->NextState() == ALIVE )
			nextAlives++;

	return nextAlives;
}

const char Cell::Symbol() const {
	return cellState->Symbol();
}

const int Cell::State() const {
	return cellState->State();
}

const int Cell::NextState() const {
	return cellState->NextState();
}
