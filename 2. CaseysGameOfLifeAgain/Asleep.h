#pragma once

#include "CellState.h"

class Asleep : public CellState 
{
public:
	Asleep(Cell* cell) : CellState(cell, ASLEEP) {};
	virtual ~Asleep() {};
	virtual void Behave() {};

	virtual const unsigned char Symbol() const {
		return ' ';
	}
	virtual const int State() const {
		return ASLEEP;
	}
};
