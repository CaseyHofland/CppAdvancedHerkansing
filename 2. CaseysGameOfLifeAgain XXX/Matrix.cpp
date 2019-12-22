#include <iostream>
#include "Matrix.h"
#include "State.h"

Matrix::Matrix(int width, int height) : matrix(height, vector<Cell*>(width)) 
{
	for( auto& row : matrix )
		for( auto& cell : row )
			cell = new Cell();

	for( int y = 0; y < Height(); ++y )
		for( int x = 0; x < Width(); ++x )
			for( int ry = y - 1; ry >= 0 && ry < Height() && ry <= y + 1; ++ry )
				for( int rx = x - 1; rx >= 0 && rx < Width() && rx <= x + 1; ++rx )
					matrix[y][x]->AddNeighbor(matrix[ry][rx]);
}

Matrix::~Matrix() {}

const int Matrix::Width() const {
	return matrix[0].size();
}

const int Matrix::Height() const {
	return matrix.size();
}

const bool Matrix::Empty() const 
{
	for( auto const& row : matrix )
		for( auto const& cell : row )
			if( cell->State() != ASLEEP )
				return false;

	return true;
}

void Matrix::Print() const 
{
	for( auto const& row : matrix )
	{
		for( auto const& cell : row )
			cout << cell->Symbol();
		cout << '\n';
	}
	cout << endl;
}

void Matrix::Clear() 
{
	for( int y = 0; y < Height(); ++y )
		for( int x = 0; x < Width(); ++x )
			SetStatePrivate(y, x, DEAD);
}

void Matrix::SetAlive(int x, int y) 
{
	SetState(x, y, ALIVE);
}

void Matrix::SetState(int x, int y, int state)
{
	--x;
	--y;

	SetStatePrivate(y, x, state);
}

void Matrix::Random(int probability) 
{
	for( int y = 0; y < Height(); ++y )
		for( int x = 0; x < Width(); ++x )
			if( rand() % 100 < probability )
				SetStatePrivate(y, x, ALIVE);
}

void Matrix::Next()
{
	// loop through all cells and let THEM decide if they should stay alive or not
	for( auto& row : matrix )
		for( auto& cell : row )
			cell->Behave();

	for( auto& row : matrix )
		for( auto& cell : row )
			cell->Next();
}

void Matrix::SetStatePrivate(int y, int x, int state) 
{
	if( y < 0 || y >= Height()
		|| x < 0 || x >= Width()
		|| state < 0 || state > ALIVE
		|| matrix[y][x] == NULL )
		return;

	matrix[y][x]->SetState(state);
}
