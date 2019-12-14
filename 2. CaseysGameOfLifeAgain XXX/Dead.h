#pragma once

#include "CellState.h"

class Dead : public CellState 
{
public:
	virtual ~Dead();
	virtual void Behave() const;

	virtual const char Symbol() const {
		return '.';
	}
};
