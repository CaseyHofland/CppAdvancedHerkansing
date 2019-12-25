#pragma once

#include <vector>
#include "Cell.h"
#include "State.h"
using namespace std;

class Cell;

class CellState 
{
public:
	CellState(Cell* cell) : cell(cell) {};
	virtual ~CellState() {};
	virtual void Behave() = 0;
	
	virtual const unsigned char Symbol() const = 0;
	virtual const int State() const = 0;
	const int CellState::NextState() const {
		return nextState;
	}

	int nextState = DEAD;

protected:
	CellState(Cell* cell, int nextState) : cell(cell), nextState(nextState) {};
	Cell* cell;
};