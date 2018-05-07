#pragma once
#include "stdafx.h"
#include "BankAccount.h"


class CheckingAccount : public BankAccount
{
private:
	//declare constants for fees and low balance
	const double LOWBALANCEFEE = 5.00;
	const double ORDERCHECKFEE = 15.00;
public:
	CheckingAccount(int acctNumber, double acctBalance);
	//override withdraw function to check balance and apply fee
	int withdrawFunds(double withdrawAmount);
	//function will be used to order checks
	int orderChecks();
	//this function will be used to check whether a balance is low
};
