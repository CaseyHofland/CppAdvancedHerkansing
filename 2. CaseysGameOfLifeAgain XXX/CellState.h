#pragma once

class CellState 
{
public:
	virtual ~CellState() {};
	virtual void Behave() const = 0;
	
	virtual const unsigned char Symbol() const = 0;
};