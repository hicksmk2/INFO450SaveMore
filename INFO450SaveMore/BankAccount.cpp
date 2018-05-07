#include "stdafx.h"
#include "BankAccount.h"

BankAccount::BankAccount(int acctNumber, double acctBalance)
{
	//Declare variables
	accountNumber = acctNumber;
	accountBalance = acctBalance;
	
}

int BankAccount::withdrawFunds(double withdrawAmount)
{
	//Checks for a negative balance, if negative then it returns false
	if ((accountBalance - withdrawAmount) < 0)
	{
		return -1;
	}
	else if ((accountBalance - withdrawAmount) > 0)
	{
		accountBalance -= withdrawAmount;
		return 0;
	}
}

int BankAccount::depositFunds(double depositAmount)				//Function used to deposit funds for each class
{
	if (depositAmount >= 0)
	{
		accountBalance += depositAmount;
		return 0;
	}
	else if (depositAmount < 0)
	{
		return -1;
	}
}


int BankAccount::orderChecks()					//Only applies to the Checking Account
{
	return 0;
}

void BankAccount::assessInterest()							//Only applies to the Savings and CD Account
{

}

void BankAccount::displayAccountInfo()					//Serves as the basic display for each account
{
	cout << "Account Number: " << accountNumber << endl;
	cout << "Account Balance: " << accountBalance << endl;
	cout << "Interest Rate: " << interestRate << endl;
}