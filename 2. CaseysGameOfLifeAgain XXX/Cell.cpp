#include "Cell.h"
#include "Alive.h"
#include "Dead.h"
#include "Asleep.h"

Cell::Cell() : cellState(new Dead()) {}

Cell::Cell(CellState* cellState) : cellState(cellState) {}

Cell::~Cell() {}

void Cell::Behave() {}

void Cell::SetState(CellState* cellState) {
	delete this->cellState;
	this->cellState = cellState;
}

const char Cell::State() const {
	return cellState->Symbol();
}
