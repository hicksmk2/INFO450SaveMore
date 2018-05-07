#pragma once
#include "stdafx.h"
#include "BankAccount.h"


class CheckingAccount : public BankAccount
{
private:
	//declare constants for fees and low balance
	const double LOWBALANCE = 5.00;
	const double CHECKFEE = 15.00;

public:
	CheckingAccount(int acctNumber, double acctBalance);
	//Overrides the withdraw function, Checks the current balance, and applies necessary fees
	int withdrawFunds(double withdrawAmount);

	//Function will be used to order checks
	int orderChecks();
};
