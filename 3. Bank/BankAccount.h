#pragma once

#include <ostream>
#include <vector>
#include "Transaction.h"
using namespace std;

class BankAccount {
public:
	BankAccount();
	BankAccount(double startingBalance);
	virtual ~BankAccount();

	BankAccount operator+(double deposit) const;
	BankAccount& operator+=(double deposit);
	BankAccount operator-(double debit) const;
	BankAccount& operator-=(double debit);

	friend ostream& operator<<(ostream& ostream, const BankAccount& bankAccount);

private:
	BankAccount(double balance, vector<Transaction> transactionHistory);
	double balance = 0;
	vector<Transaction> transactionHistory = vector<Transaction>();
};