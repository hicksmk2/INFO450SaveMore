#include "stdafx.h"
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(int acctNumber, double acctBalance) :BankAccount(acctNumber, acctBalance)
{
	//no interest rate for checking accounts
	interestRate = 0;
}

//function checks if withdrawal is possible and for low balance
int CheckingAccount::withdrawFunds(double withdrawAmount)
{
	if ((accountBalance - withdrawAmount) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount) > 0)
	{
		accountBalance -= withdrawAmount;
		//asses if low balance fee needed
		if (accountBalance < 500)
		{
			accountBalance -= LOWBALANCEFEE;
		}
		return 0;

	}
}

int CheckingAccount::orderChecks()
{
	if (accountBalance > ORDERCHECKFEE)
	{
		accountBalance -= ORDERCHECKFEE;
		//assess if low balance fee needed
		if (accountBalance < 500)
		{
			accountBalance -= LOWBALANCEFEE;
		}
		return 0;
	}
	else if (accountBalance < ORDERCHECKFEE)
	{
		return -1;
	}
}