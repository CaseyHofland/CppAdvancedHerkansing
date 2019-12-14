// CaseysGameOfLifeAgain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <time.h>
#include "Matrix.h"
using namespace std;

int main()
{
	srand(time(NULL));

	Matrix* matrix = new Matrix(5, 4);
	matrix->Print();

	cout << "Width:  " << matrix->Width() << '\n';
	cout << "Height: " << matrix->Height() << '\n';
	cout << endl;

	matrix->SetAlive(1, 2);
	matrix->SetAlive(4, 3);
	matrix->SetAlive(2, 4);
	matrix->Print();

	matrix->Clear();
	matrix->Print();

	cout << "Test Random: " << '\n';
	cout << endl;

	for( int i = 0; i < 5; ++i )
	{
		matrix->Random();
		matrix->Print();
	}

	cout << "End" << '\n';
	cout << endl;

	return 0;
}
