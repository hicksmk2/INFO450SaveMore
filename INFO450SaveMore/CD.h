#pragma once
#include "stdafx.h"
#include "BankAccount.h"

class CD : public BankAccount
{
private:

	//Declare constants for interest rates and term variable
	const double FIVEYEARRATE = 0.10;
	const double LESSTHANRATE = 0.05;
	int term;

public:
	//Constructor for CDAccount
	CD(int acctNumber, double acctBalance, int term);
	void assessInterest();



};