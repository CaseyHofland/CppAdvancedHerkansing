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
	for( int y = 0; y < matrix.size(); ++y )
	{
		for( int x = 0; x < matrix[y].size(); ++x )
		{
			delete matrix[y][x];
			matrix[y][x] = new Cell();
		}
	}
}

void Matrix::SetAlive(int row, int column) 
{
	SetState(row, column, new Alive());
}

void Matrix::SetState(int row, int column, CellState* cellState) 
{
	cout << "After this it should say Something: " << '\n';

	if( column >= Height() || row >= Width() || matrix[column][row] == NULL )
		return;

	cout << "Something" << '\n';

	matrix[column][row]->SetState(cellState);
}

void Matrix::Next()
{
	// loop through all cells and let THEM decide if they should stay alive or not
	for( auto& row : matrix )
		for( auto& cell : row )
			cell->Behave();
}
