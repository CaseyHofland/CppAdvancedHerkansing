#pragma once

#include "CellState.h"

class Dead : public CellState 
{
public:
	virtual ~Dead();
	virtual void Behave();

	virtual const unsigned char Symbol() const {
		return '.';
	}
	virtual const int State() const {
		return DEAD;
	}
};
