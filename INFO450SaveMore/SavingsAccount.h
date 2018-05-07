#pragma once
#include "stdafx.h"
#include "BankAccount.h"

class SavingsAccount :public BankAccount
{
private:
	//Declare constants for APR and withdraw fee
	const double ONEPERCENTAPR = 0.01;
	const double TWOPERCENTAPR = 0.02;
	const double WITHDRAWFEE = 2.00;

public:
	//Constructor for the Savings class
	SavingsAccount(int acctNumber, double acctBalance);

	//Overrides the withdraw function due to withdraw fees
	int withdrawFunds(double withdrawAmount);

	//Overrides deposit to assess interest
	int depositFunds(double depositAmount);
	void assessInterest();


};