#pragma once

#include <ostream>
#include <time.h>
#include "TransactionType.h"
using namespace std;

class Transaction {
public:
	Transaction(TransactionType type, double amount);
	virtual ~Transaction();

	const string GetType() const;
	const string GetAmount() const;
	const string GetDate() const;

	friend ostream& operator<<(ostream& ostream, const Transaction& transaction);

private:
	TransactionType type = TransactionType::None;
	double amount = 0;
	time_t date = time(0);
};