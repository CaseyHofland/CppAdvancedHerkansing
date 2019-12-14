#include "Cell.h"
#include "Alive.h"
#include "Dead.h"
#include "Asleep.h"
#include "State.h"

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
		break;
	case DEAD:
		this->cellState = new Dead();
		break;
	case ALIVE:
		this->cellState = new Alive();
		break;
	}
}

const char Cell::State() const {
	return cellState->Symbol();
}
