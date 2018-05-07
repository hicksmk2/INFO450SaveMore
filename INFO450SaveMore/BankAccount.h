#pragma once
#include "stdafx.h"
#include <ctime>
#include <string>
#include <iostream>
using namespace std;

class BankAccount
{
protected:
	int accountNumber;
	double interestRate;
	double accountBalance;
	char accountDate;

public:
	//Constructor for Bank Account
	BankAccount(int acctNumber, double acctBalance);

	//Virtual function because some accounts require redefining
	virtual int withdrawFunds(double withdrawAmount);
	virtual int depositFunds(double depositAmount);

	//Virtual function needed by checking account
	virtual int orderChecks();

	//Function needed by savings and certificate classes
	virtual void assessInterest();

	void displayAccountInfo();

};