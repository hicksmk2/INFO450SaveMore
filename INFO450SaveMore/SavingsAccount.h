#pragma once
#include "stdafx.h"
#include "BankAccount.h"

class SavingsAccount :public BankAccount
{
private:
	//declare constants for apr and fees
	const double FIRSTAPR = 0.01;
	const double SECONDAPR = 0.02;
	const double WITHDRAWFEE = 2.00;
public:
	//constructor for Savings
	SavingsAccount(int acctNumber, double acctBalance);
	//override withdraw function because of withdraw fees
	int withdrawFunds(double withdrawAmount);
	// Override deposit to assess interest
	int depositFunds(double depositAmount);
	void assessInterest();


};