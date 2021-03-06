/* 
   INFO450SaveMore.cpp : Defines the entry point for the console application.
   Program Author: Malik Hicks
   Description: Save-More is a small community bank that offers its customers 3 types of Bank Accounts.
*/

#include "stdafx.h"
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CD.h"
 

void displayGreeting();

int main()
{
	//Allocates memory for inputs
	int inputAcctNumber = NULL;
	double inputAcctBalance = NULL;
	double inputDeposit = NULL;
	double inputWithdraw = NULL;

	char type = 'a';
	char transaction = 'b';

	//Attaches the current date to the transaction
	char accountDate[9];
	_strdate_s(accountDate);

	//Term needed for certificates
	int term = NULL;
	char answer;

	//Base class pointers for run-time polymorphism
	BankAccount *savingAccount = NULL;
	BankAccount *checkingAccount = NULL;
	BankAccount *cdAccount = NULL;

	//Calls the function for instructions
	displayGreeting();
	
	while (type != 'q' && type != 'Q')
	{

		cout << "===============================================" << endl;
		cout << "What type of account would you like to access?\n(C)hecking, (S)avings, Certificate(D):   ";
		cin >> type;
		if (type == 'C' || type == 'c')
		{
			cout << "===============================================" << endl;

			//Prompts the user for the beginning info and stores it for use later
			cout << "Checking Account:\nAccount Number: ";
			cin >> inputAcctNumber;
			do
			{
				cout << "Starting balance? $";
				cin >> inputAcctBalance;
				if (inputAcctBalance < 0)
				{
					cout << "Your balance must be greater than 0" << endl;
				}
			} while (inputAcctBalance < 0);

			//Allocates memory for the Checking account
			checkingAccount = new CheckingAccount(inputAcctNumber, inputAcctBalance);
			cout << endl;
			cout << "\t\t  *********" << endl;
			cout << "\t\t  *WARNING*" << endl;
			cout << "\t******************************" << endl;
			cout << "\t*If the balance is below $500*\n\t*    a $5 fee will incur    *" << endl;
			cout << "\t******************************" << endl;
			cout << "\t\t  *WARNING*" << endl;
			cout << "\t\t  *********" << endl;

			//Initiates the check order process
			cout << "===============================================" << endl;
			cout << "Checking Account:\n*There is a $15 fee when ordering checks*\nWould you like to order checks? (Y/N): ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				checkingAccount->orderChecks();
			}

			do
			{
				cout << "===============================================" << endl;
				cout << "Checking Account:\nDo you wish to (D)eposit, (W)ithdraw, (Q)uit: ";
				cin >> transaction;
				if (transaction == 'd' || transaction == 'D')
				{
					cout << "===============================================" << endl;
					cout << "Checking Account:\nHow much do you wish to deposit? $";
					cin >> inputDeposit;
					
					//Allocates deposit object dynamically with membership operator
					checkingAccount->depositFunds(inputDeposit);

				}
				else if (transaction == 'w' || transaction == 'W')
				{
					cout << "===============================================" << endl;
					cout << "Checking Account:\nHow much do you wish to withdraw? $";
					cin >> inputWithdraw;
					checkingAccount->withdrawFunds(inputWithdraw);

				}
				else if (transaction != 'q' && transaction != 'Q')
				{
					cout << "Invalid entry." << endl;
				}
				cout << "===============================================" << endl;
			} while (transaction != 'q' && transaction != 'Q');


		}
		else if (type == 'S' || type == 's')
		{
			cout << "===============================================" << endl;
			cout << "Savings Account:\nAccount Number: ";
			cin >> inputAcctNumber;
			do
			{
				cout << "Starting balance? $";
				cin >> inputAcctBalance;
				if (inputAcctBalance < 0)
				{
					cout << "Your balance must be greater than 0" << endl;
				}
			} while (inputAcctBalance < 0);

			//Allocates memory for the Savings account
			savingAccount = new SavingsAccount(inputAcctNumber, inputAcctBalance);
			cout << endl;

			do
			{
				cout << "===============================================" << endl;
				cout << "Savings Account:\nDo you wish to (D)eposit, (W)ithdraw, (Q)uit: ";
				cin >> transaction;
				if (transaction == 'd' || transaction == 'D')
				{
					cout << "===============================================" << endl;
					cout << "Savings Account:\nHow much do you wish to deposit? $";
					cin >> inputDeposit;

					//Allocates deposit object dynamically with membership operator
					savingAccount->depositFunds(inputDeposit);

				}
				else if (transaction == 'w' || transaction == 'W')
				{
					cout << "===============================================" << endl;
					cout << "Savings Account:\n*Automatic fee of $2 will be applied*\nHow much do you wish to withdraw? $";
					cin >> inputWithdraw;
					savingAccount->withdrawFunds(inputWithdraw);
				}
				else if (transaction != 'q' && transaction != 'Q')
				{
					cout << "Invalid entry." << endl;
				}
				cout << "===============================================" << endl;
			} while (transaction != 'q' && transaction != 'Q');
		}
		else if (type == 'D' || type == 'd')
		{
			cout << "===============================================" << endl;
			cout << "Certificate Account:\nAccount Number: ";
			cin >> inputAcctNumber;
			do
			{
				cout << "Starting balance? $";
				cin >> inputAcctBalance;
				if (inputAcctBalance < 0)
				{
					cout << "Your balance must be greater than 0" << endl;
				}
			} while (inputAcctBalance < 0);

			//Prompts the user for term input and assess interest
			cout << "What is the term (years) for the certificate: ";
			cin >> term;
			cdAccount = new CD(inputAcctNumber, inputAcctBalance, term);

			do
			{
				cout << "===============================================" << endl;
				cout << "Certificate Account:\nDo you wish to (D)eposit, (W)ithdraw, (Q)uit: ";
				cin >> transaction;
				if (transaction == 'd' || transaction == 'D')
				{
					cout << "===============================================" << endl;
					cout << "Certificate Account:\nHow much do you wish to deposit? $";
					cin >> inputDeposit;

					//Allocates the deposit object dynamically with membership operator
					cdAccount->depositFunds(inputDeposit);

				}
				else if (transaction == 'w' || transaction == 'W')
				{
					cout << "===============================================" << endl;
					cout << "Certificate Account:\nHow much do you wish to withdraw? $";
					cin >> inputWithdraw;
					cdAccount->withdrawFunds(inputWithdraw);

				}
				else if (transaction != 'q' && transaction != 'Q')
				{
					cout << "Invalid entry." << endl;
				}
				cout << "===============================================" << endl;
			} while (transaction != 'q' && transaction != 'Q');
			
		}
		else if (type != 'Q' && type != 'q')
		{
			cout << "Invalid choice." << endl;
			break;
		}
	}
	cout << "===============================================" << endl << endl;
	//Displays the account information to the user

	cout << "==================================" << endl;
	cout << "Summary: Checking Account" << endl;
	cout << "Account Created On: " << accountDate << endl;		//Outputs the systems date to the user as the account creation date
	checkingAccount -> displayAccountInfo();
	cout << "==================================" << endl;
	cout << endl;

	cout << "==================================" << endl;
	cout << "Summary: Savings Account" << endl;
	cout << "Account Created On: " << accountDate << endl;
	savingAccount -> displayAccountInfo();
	cout << "==================================" << endl;
	cout << endl;

	cout << "==================================" << endl;
	cout << "Summary: Certificate of Deposit" << endl;
	cout << "Account Created On: " << accountDate << endl;
	cdAccount -> displayAccountInfo();
	cout << "==================================" << endl;

	//Deletes the keyword used to free memory and avoid garbage
	delete savingAccount;
	delete checkingAccount;
	delete cdAccount;
	
	
	return 0;
}

//Creates the function to print the instructions to the user
void displayGreeting()
{
	cout << "\t\t*****************************************************" << endl;				// Outputs the instructions to the user
	cout << "\t\t*                 Greetings User!                   *" << endl;
	cout << "\t\t*          Welcome to the Greater Banks             *" << endl;
	cout << "\t\t*  --------------------*****------------------------*" << endl;
	cout << "\t\t*     Please begin your transaction and ensure      *" << endl;
	cout << "\t\t*           to create an account for each.          *" << endl;
	cout << "\t\t*              Press Enter to begin! ^.^            *" << endl;
	cout << "\t\t*****************************************************" << endl;
}




