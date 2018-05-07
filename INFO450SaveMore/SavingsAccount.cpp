#include "stdafx.h"
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(int acctNumber, double acctBalance) : BankAccount(acctNumber, acctBalance)
{
	//asses the interest rate of beginning balance
	assessInterest();
}

int SavingsAccount::withdrawFunds(double withdrawAmount)
{
	if ((accountBalance - withdrawAmount - WITHDRAWFEE) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount - WITHDRAWFEE) > 0)
	{
		accountBalance -= withdrawAmount;
		accountBalance -= WITHDRAWFEE;
		//Check interest rate after withdrawl
		assessInterest();

		return 0;
	}
}

int SavingsAccount::depositFunds(double depositAmount)
{
	if (depositAmount >= 0)
	{
		accountBalance += depositAmount;
		//check interest rate after deposit
		assessInterest();
	}
	else if (depositAmount < 0)
	{
		return -1;
	}
}

void SavingsAccount::assessInterest()
{
	if (accountBalance <= 10000)
	{
		interestRate = ONEPERCENTAPR;
	}
	else if (accountBalance >= 10000)
	{
		interestRate = TWOPERCENTAPR;
	}

	//calculate compunded interest
	accountBalance += (accountBalance*(interestRate / 12));
}