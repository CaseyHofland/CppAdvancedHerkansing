#pragma once

#include <string>
#include "CellState.h"
using namespace std;

class CellState;

class Cell 
{
public:
	Cell();
	Cell(CellState* cellState);
	virtual ~Cell();

	const char Symbol() const;
	const int State() const;
	const int NextState() const;

	void Behave() const;
	void Next();
	void SetState(int state);
	void AddNeighbor(Cell* neighbor);
	int AliveNeighbors();
	int NextStateAliveNeighbors();

	CellState* cellState;
	vector<Cell*> neighbors;
};