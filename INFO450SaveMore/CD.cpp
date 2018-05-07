#include "stdafx.h"
#include "CD.h"


CD::CD(int acctNumber, double acctBalance, int term) :BankAccount(acctNumber, acctBalance)
{
	if (term < 5)
	{
		interestRate = LESSERRATE;
	}
	else if (term > 4)
	{
		interestRate = FIVEYEARRATE;
	}
	assessInterest();
}

void CD::assessInterest()
{
	//calculates monthly interest
	accountBalance += (accountBalance*(interestRate) / 12);
}