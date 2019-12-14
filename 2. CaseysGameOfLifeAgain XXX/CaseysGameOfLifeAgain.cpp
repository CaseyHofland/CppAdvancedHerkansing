// CaseysGameOfLifeAgain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
	Matrix* matrix = new Matrix(5, 4);
	matrix->Print();

	cout << "Width:  " << matrix->Width() << '\n';
	cout << "Height: " << matrix->Height() << '\n';
	cout << endl;

	matrix->SetAlive(1, 2);
	matrix->Print();

	return 0;
}
