#pragma once

#include <vector>
#include "Cell.h"
using namespace std;

class Matrix 
{
public:
	Matrix(int width, int height);
	virtual ~Matrix();

	const int Width() const;
	const int Height() const;
	void Print() const;

	void Clear();
	void SetAlive(int row, int column);
	void SetState(int row, int column, CellState* cellState);
	void Next();

private:
	vector<vector<Cell*>> matrix;
};