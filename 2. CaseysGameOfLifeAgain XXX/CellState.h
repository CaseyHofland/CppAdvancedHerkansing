#pragma once

class CellState 
{
public:
	virtual ~CellState() {};
	virtual void Behave() const = 0;
	
	virtual const char Symbol() const = 0;
};