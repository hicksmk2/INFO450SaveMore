#include "stdafx.h"
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int acctNumber, double acctBalance) : BankAccount(acctNumber, acctBalance)
{
	interestRate = 0;											//There is no interest rate for Checking accounts
}

//Function checks if withdrawal is possible and for low balance
int CheckingAccount::withdrawFunds(double withdrawAmount)
{
	if ((accountBalance - withdrawAmount) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount) > 0)
	{
		accountBalance -= withdrawAmount;

		//Checks to see if the low balance fee is necessary 
		if (accountBalance < 500)
		{
			accountBalance -= LOWBALANCE;
		}
		return 0;

	}
}

int CheckingAccount::orderChecks()
{
	if (accountBalance > CHECKFEE)
	{
		accountBalance -= CHECKFEE;

		//Checks to see if low balance fee needed when applying checks
		if (accountBalance < 500)
		{
			accountBalance -= LOWBALANCE;
		}
		return 0;
	}
	else if (accountBalance < CHECKFEE)
	{
		return -1;
	}
}