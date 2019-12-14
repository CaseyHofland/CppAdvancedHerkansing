#pragma once

#include <string>
#include "CellState.h"
using namespace std;

enum State {
	ASLEEP, DEAD, ALIVE
};

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