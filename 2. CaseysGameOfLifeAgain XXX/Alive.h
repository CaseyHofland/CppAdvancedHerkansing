#pragma once

#include "CellState.h"

class Alive : public CellState 
{
public:
	virtual ~Alive();
	virtual void Behave() const;

	virtual const char Symbol() const {
		return 254;
	}
};