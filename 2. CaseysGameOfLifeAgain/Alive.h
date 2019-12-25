#pragma once

#include "CellState.h"

class Alive : public CellState 
{
public:
	Alive(Cell* cell) : CellState(cell, ALIVE) {};
	virtual ~Alive();
	virtual void Behave();

	virtual const unsigned char Symbol() const {
		return 254;
	}
	virtual const int State() const {
		return ALIVE;
	}
};