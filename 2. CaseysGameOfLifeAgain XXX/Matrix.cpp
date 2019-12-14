#include <iostream>
#include "Matrix.h"
#include "Alive.h"

Matrix::Matrix(int width, int height) : matrix(height, vector<Cell*>(width, new Cell())) {}

Matrix::~Matrix() {}

const int Matrix::Width() const {
	return matrix[0].size();
}

const int Matrix::Height() const {
	return matrix.size();
}

void Matrix::Print() const 
{
	for( auto const& row : matrix )
	{
		for( auto const& cell : row )
			cout << cell->State();
		cout << '\n';
	}
	cout << endl;
}

void Matrix::Clear() 
{
	for( int y = 0; y < (signed)matrix.size(); ++y )
		for( int x = 0; x < (signed)matrix[y].size(); ++x )
			SetState(x, y, DEAD);
}

void Matrix::SetAlive(int row, int column) 
{
	SetState(row, column, ALIVE);
}

void Matrix::SetState(int row, int column, int cellState) 
{
	if( column >= Height() || row >= Width() || matrix[column][row] == NULL )
		return;

	matrix[column][row]->SetState(cellState);
}

void Matrix::Random() 
{
	for( int y = 0; y < (signed)matrix.size(); ++y )
		for( int x = 0; x < (signed)matrix[y].size(); ++x )
			SetState(x, y, static_cast<State>( rand() % (ALIVE + 1) ));
}

void Matrix::Next()
{
	// loop through all cells and let THEM decide if they should stay alive or not
	for( auto& row : matrix )
		for( auto& cell : row )
			cell->Behave();
}
