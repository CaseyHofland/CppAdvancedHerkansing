#include "BankAccount.h"

// TODO: find a plugin for decimal and use that in place of double

// Used for storing data about a bankaccount and keeping a history of all past transactions

BankAccount::BankAccount() {}

BankAccount::BankAccount(double startingBalance) 
{
	*this += startingBalance;
}

BankAccount::BankAccount(double balance, vector<Transaction> transactionHistory)
	: balance(balance), transactionHistory(transactionHistory) {}

BankAccount::~BankAccount() {}

BankAccount BankAccount::operator+(double deposit) const 
{
	BankAccount bankAccount = BankAccount(balance + deposit, transactionHistory);
	bankAccount.transactionHistory.push_back(Transaction(TransactionType::Deposit, deposit));
	return bankAccount;
}

BankAccount& BankAccount::operator+=(double deposit) 
{
	balance += deposit;
	transactionHistory.push_back(Transaction(TransactionType::Deposit, deposit));
	return *this;
}

BankAccount BankAccount::operator-(double debit) const 
{
	BankAccount bankAccount = BankAccount(balance - debit, transactionHistory);
	bankAccount.transactionHistory.push_back(Transaction(TransactionType::Debit, debit));
	return bankAccount;
}

BankAccount& BankAccount::operator-=(double debit) 
{
	balance -= debit;
	transactionHistory.push_back(Transaction(TransactionType::Debit, debit));
	return *this;
}

ostream& operator<<(ostream& ostream, const BankAccount& bankAccount) 
{
	ostream << "Balance: " << bankAccount.balance << '\n';
	ostream << "History: " << '\n';
	for( const auto& transaction : bankAccount.transactionHistory )
		ostream << '\t' << transaction;

	return ostream;
}