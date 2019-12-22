#include "Cell.h"
#include "Alive.h"
#include "Dead.h"
#include "Asleep.h"
#include "State.h"

Cell::Cell() : cellState(new Dead()) {}

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

void Cell::SetState(int state) {
	delete this->cellState;

	switch( state )
	{
	case ASLEEP:
		this->cellState = new Asleep();
		break;
	case DEAD:
		this->cellState = new Dead();
		break;
	case ALIVE:
		this->cellState = new Alive();
		break;
	}
}

void Cell::AddNeighbor(Cell* neighbor) 
{
	cellState->AddNeighbor(neighbor);
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
