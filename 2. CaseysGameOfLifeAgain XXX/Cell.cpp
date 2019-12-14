#include "Cell.h"
#include "Alive.h"
#include "Dead.h"
#include "Asleep.h"

Cell::Cell() : cellState(new Dead()) {}

Cell::Cell(CellState* cellState) : cellState(cellState) {}

Cell::~Cell() {}

void Cell::Behave() {}

void Cell::SetState(int state) {
	delete this->cellState;

	switch( state )
	{
	case ASLEEP:
		this->cellState = new Asleep();
	case DEAD:
		this->cellState = new Dead();
	case ALIVE:
		this->cellState = new Alive();
	}
}

const char Cell::State() const {
	return cellState->Symbol();
}
