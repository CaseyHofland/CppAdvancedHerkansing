#pragma once

#include "CellState.h"

class Asleep : public CellState 
{
public:
	virtual ~Asleep() {};
	virtual void Behave() const {};

	virtual const char Symbol() const {
		return ' ';
	}
};
