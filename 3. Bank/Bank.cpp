// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "BankAccount.h"
using namespace std;

int main()
{
	BankAccount bankAccount = BankAccount(500);
	bankAccount -= 200;
	bankAccount += 800;
	bankAccount + 400;	// Note: there shouldn't be a history of this transaction.
	bankAccount = bankAccount - 700;
	
	cout << bankAccount << endl;

	return 0;
}
