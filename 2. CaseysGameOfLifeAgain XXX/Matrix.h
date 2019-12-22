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
	const bool Empty() const;
	void Print() const;

	void Clear();
	void SetAlive(int x, int y);
	void SetState(int x, int y, int state);
	void Random(int probability = 20);
	void Next();

private:
	void SetStatePrivate(int y, int x, int state);
	vector<vector<Cell*>> matrix;
};