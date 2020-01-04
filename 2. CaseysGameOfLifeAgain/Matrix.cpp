#include <iostream>
#include "Matrix.h"
#include "State.h"

/* TODO: Use a 1 dimensional array for optimization and store the width of our matrix. We can then return
a cell via this formula: x + y * width = index */

// Creates a matrix of cells as well as setting each cells' neighbors
Matrix::Matrix(int width, int height) : matrix(height, vector<Cell*>(width)) 
{
	for( auto& row : matrix )
		for( auto& cell : row )
			cell = new Cell();

	for( int y = 0; y < Height(); ++y )
		for( int x = 0; x < Width(); ++x )
			for( int ry = y - 1; ry < Height() && ry <= y + 1; ++ry )
				for( int rx = x - 1; rx < Width() && rx <= x + 1; ++rx )
					if( ry < 0 || rx < 0 )
						continue;
					else if(!(ry == y && rx == x))
						matrix[y][x]->AddNeighbor(matrix[ry][rx]);
}

Matrix::~Matrix() {}

const int Matrix::Width() const {
	return matrix[0].size();
}

const int Matrix::Height() const {
	return matrix.size();
}

// Returns true if every cell is asleep
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

// Exposed to the player and starts counting from 1 for ease of use
void Matrix::SetState(int x, int y, int state)
{
	--x;
	--y;

	SetStatePrivate(y, x, state);
}

// This one is just for fun ^_^
void Matrix::Random(int probability) 
{
	for( int y = 0; y < Height(); ++y )
		for( int x = 0; x < Width(); ++x )
			if( rand() % 100 < probability )
				SetStatePrivate(y, x, ALIVE);
}

// Loop through all cells, let them determine what to do, then loop through all the cells again and do it
void Matrix::Next()
{
	// TODO: Combine these loops by letting cells store a temporary state that's exposed to their 
	// neighbors. This variable could then store a 'previous state' if appropriate.
	for( auto& row : matrix )
		for( auto& cell : row )
			cell->Behave();

	for( auto& row : matrix )
		for( auto& cell : row )
			cell->Next();
}

// Not exposed to the player, starts counting from 0 and checks if the input is valid
void Matrix::SetStatePrivate(int y, int x, int state) 
{
	if( y < 0 || y >= Height()
		|| x < 0 || x >= Width()
		|| state < 0 || state > ALIVE
		|| matrix[y][x] == NULL )
		return;

	matrix[y][x]->SetState(state);
}
