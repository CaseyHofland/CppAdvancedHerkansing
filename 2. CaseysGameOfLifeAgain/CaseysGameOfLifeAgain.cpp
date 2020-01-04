// CaseysGameOfLifeAgain.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <chrono>
#include <thread>
#include <time.h>
#include <wtypes.h>
#include "Matrix.h"
using namespace std;

Matrix* matrix;

void CreateGliderGun();

int main()
{
	srand((signed)time(NULL)); // Set a new random seed

	// Enlarge the console so that the whole glider gun is visible
	const HWND console = GetConsoleWindow();
	MoveWindow(console, 0, 0, 1280, 720, TRUE);

	// Hide the cursor (in my tests it was blinking all over the place and distracted from the game of life)
	const HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);

	matrix = new Matrix(38, 30);
	matrix->Random(60);
	//CreateGliderGun();
	
	// TODO: create a double buffer for smooth drawing to the console
	// Prints at least once and then until every cell has fallen asleep
	matrix->Print();
	while( !matrix->Empty() )
	{
		matrix->Next();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000 / 24));
		system("cls");
		matrix->Print();
	}

	return 0;
}

void CreateGliderGun() 
{
	// ==========================
	//         GLIDER GUN
	// ==========================

	matrix->Clear();

	// Left Block
	matrix->SetAlive(2, 6);
	matrix->SetAlive(3, 6);
	matrix->SetAlive(2, 7);
	matrix->SetAlive(3, 7);

	// Left Ship
	matrix->SetAlive(12, 6);
	matrix->SetAlive(12, 7);
	matrix->SetAlive(12, 8);
	matrix->SetAlive(13, 5);
	matrix->SetAlive(14, 4);
	matrix->SetAlive(15, 4);
	matrix->SetAlive(13, 9);
	matrix->SetAlive(14, 10);
	matrix->SetAlive(15, 10);
	matrix->SetAlive(16, 7);
	matrix->SetAlive(17, 5);
	matrix->SetAlive(18, 6);
	matrix->SetAlive(18, 7);
	matrix->SetAlive(18, 8);
	matrix->SetAlive(17, 9);
	matrix->SetAlive(19, 7);

	// Right Block
	matrix->SetAlive(36, 4);
	matrix->SetAlive(37, 4);
	matrix->SetAlive(36, 5);
	matrix->SetAlive(37, 5);

	// Right Ship
	matrix->SetAlive(22, 4);
	matrix->SetAlive(22, 5);
	matrix->SetAlive(22, 6);
	matrix->SetAlive(23, 4);
	matrix->SetAlive(23, 5);
	matrix->SetAlive(23, 6);
	matrix->SetAlive(24, 3);
	matrix->SetAlive(24, 7);
	matrix->SetAlive(26, 2);
	matrix->SetAlive(26, 3);
	matrix->SetAlive(26, 7);
	matrix->SetAlive(26, 8);

	// ==========================
	//         GLIDER GUN
	// ==========================
}
