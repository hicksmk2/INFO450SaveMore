#include "stdafx.h"
#include "CD.h"


CD::CD(int acctNumber, double acctBalance, int term) : BankAccount(acctNumber, acctBalance)
{
	if (term < 5)
	{
		interestRate = LESSTHANRATE;
	}
	else if (term > 4)
	{
		interestRate = FIVEYEARRATE;
	}
	assessInterest();
}

void CD::assessInterest()
{
	//Calculates interest on a monthly basis
	accountBalance += (accountBalance*(interestRate) / 12);
}