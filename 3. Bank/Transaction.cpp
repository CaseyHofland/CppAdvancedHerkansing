#include "Transaction.h"
#include <string>
#include <sstream>
#include <iomanip>

// Used for storing data about a transaction and logging it

Transaction::Transaction(TransactionType type, double amount) : type(type), amount(amount) {}

Transaction::~Transaction() {}

const string Transaction::GetType() const 
{
	switch( type )
	{
	case TransactionType::None:		return "None";
	case TransactionType::Deposit:	return "Deposit";
	case TransactionType::Debit:	return "Debit";
	}
}

const string Transaction::GetAmount() const
{
	stringstream sstream; 
	sstream << fixed << setprecision(2) << "$" << amount;
	return sstream.str();
}

const string Transaction::GetDate() const 
{
	char transactionDate[128];
	struct tm localTime;
	localtime_s(&localTime, &date);
	strftime(transactionDate, sizeof transactionDate, "%A, %B %d %Y", &localTime);

	return transactionDate;
}

ostream& operator<<(ostream& ostream, const Transaction& transaction) 
{
	ostream << transaction.GetDate() << ": " << transaction.GetType() << "ed " << transaction.GetAmount() << '\n';
	
	return ostream;
}
