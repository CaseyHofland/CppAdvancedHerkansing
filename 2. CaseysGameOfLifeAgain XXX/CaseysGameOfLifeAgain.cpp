// CaseysGameOfLifeAgain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include <wtypes.h>
#include "Matrix.h"
using namespace std;

int main()
{
	srand((signed)time(NULL));

	// Move the console
	const HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, 1280, 720, TRUE);

	Matrix* matrix = new Matrix(40, 40);

	// ==========================
	//         GLIDER GUN
	// ==========================

	// Left Block
	matrix->SetAlive(2, 5);
	matrix->SetAlive(3, 5);
	matrix->SetAlive(2, 6);
	matrix->SetAlive(3, 6);

	// Left Ship
	matrix->SetAlive(12, 5);
	matrix->SetAlive(12, 6);
	matrix->SetAlive(12, 7);
	matrix->SetAlive(13, 4);
	matrix->SetAlive(14, 3);
	matrix->SetAlive(15, 3);
	matrix->SetAlive(13, 8);
	matrix->SetAlive(14, 9);
	matrix->SetAlive(15, 9);
	matrix->SetAlive(16, 6);
	matrix->SetAlive(17, 4);
	matrix->SetAlive(18, 5);
	matrix->SetAlive(18, 6);
	matrix->SetAlive(18, 7);
	matrix->SetAlive(17, 8);
	matrix->SetAlive(19, 6);

	/*
	cells.push_back( Cell( 12 , 5 ) );
	cells.push_back( Cell( 12 , 6 ) );
	cells.push_back( Cell( 12 , 7 ) );
	cells.push_back( Cell( 13 , 4 ) );
	cells.push_back( Cell( 14 , 3 ) );
	cells.push_back( Cell( 15 , 3 ) );
	cells.push_back( Cell( 13 , 8 ) );
	cells.push_back( Cell( 14 , 9 ) );
	cells.push_back( Cell( 15 , 9 ) );
	cells.push_back( Cell( 16 , 6 ) );
	cells.push_back( Cell( 17 , 4 ) );
	cells.push_back( Cell( 18 , 5 ) );
	cells.push_back( Cell( 18 , 6 ) );
	cells.push_back( Cell( 18 , 7 ) );
	cells.push_back( Cell( 17 , 8 ) );
	cells.push_back( Cell( 19 , 6 ) );

	// Right Block
	cells.push_back( Cell( 36 , 3 ) );
	cells.push_back( Cell( 37 , 3 ) );
	cells.push_back( Cell( 36 , 4 ) );
	cells.push_back( Cell( 37 , 4 ) );

	// Right Ship
	cells.push_back( Cell( 22 , 3 ) );
	cells.push_back( Cell( 22 , 4 ) );
	cells.push_back( Cell( 22 , 5 ) );
	cells.push_back( Cell( 23 , 3 ) );
	cells.push_back( Cell( 23 , 4 ) );
	cells.push_back( Cell( 23 , 5 ) );
	cells.push_back( Cell( 24 , 2 ) );
	cells.push_back( Cell( 24 , 6 ) );
	cells.push_back( Cell( 26 , 1 ) );
	cells.push_back( Cell( 26 , 2 ) );
	cells.push_back( Cell( 26 , 6 ) );
	cells.push_back( Cell( 26 , 7 ) );
	*/

	matrix->Print();

	while( !matrix->Empty() )
	{
		matrix->Next();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 1));
		system("cls");
		matrix->Print();
	}

	return 0;
}
