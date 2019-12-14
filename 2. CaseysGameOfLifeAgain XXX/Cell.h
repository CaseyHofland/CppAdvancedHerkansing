#pragma once

#include <string>
#include "CellState.h"
using namespace std;

class Cell 
{
public:
	Cell();
	Cell(CellState* cellState);
	virtual ~Cell();

	const char State() const;

	void Behave();
	void SetState(int state);

private:
	CellState* cellState;
};