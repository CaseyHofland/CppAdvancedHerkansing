#pragma once

#include "CellState.h"

class Dead : public CellState 
{
public:
	Dead(Cell* cell) : CellState(cell, DEAD) {};
	virtual ~Dead();
	virtual void Behave();

	virtual const unsigned char Symbol() const {
		return '.';
	}
	virtual const int State() const {
		return DEAD;
	}
};
