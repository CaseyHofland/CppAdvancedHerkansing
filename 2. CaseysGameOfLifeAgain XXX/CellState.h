#pragma once

#include <vector>
#include "Cell.h"
#include "State.h"
using namespace std;

class Cell;

class CellState 
{
public:
	virtual ~CellState() {};
	virtual void Behave() = 0;
	
	virtual const unsigned char Symbol() const = 0;
	virtual const int State() const = 0;
	virtual const int NextState() const;

	void AddNeighbor(Cell* neighbor);
	
	int nextState;

protected:
	vector<Cell*> neighbors;
	int AliveNeighbors();
	int NextStateAliveNeighbors();
};