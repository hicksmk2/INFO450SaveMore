// INFO450SaveMore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BankAccount.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CD.h"
 

void displayGreeting();

int main()
{
	//allocating memory for inputs
	int inputAcctNumber = NULL;
	char type = 'a';
	double inputAcctBalance = NULL;
	double inputDeposit = NULL;
	double inputWithdraw = NULL;
	char transaction = 'b';

	//term needed for certificates
	int term = NULL;
	char answer;

	//base class pointers for run-time polymorphism
	BankAccount *savingAccount = NULL;
	BankAccount *checkingAccount = NULL;
	BankAccount *cdAccount = NULL;

	//Calls the function for instructions
	displayGreeting();
	
	while (type != 'q' && type != 'Q')
	{

		cout << "===============================================" << endl;
		cout << "What type of account would you like to access?\n(C)hecking, (S)avings, Certificate(D) or (Q)uit" << endl;
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
			cout << "\t\t*********" << endl;
			cout << "\t\t*WARNING*" << endl;
			cout << "\t******************************" << endl;
			cout << "\tIf the balance is below $500,\n\ta $5 fee will incur " << endl;
			cout << "\t******************************" << endl;

			//Initiates check order process
			cout << "===============================================" << endl;
			cout << "*There is a $15 fee when ordering checks*\nWould you like to order checks? (Y/N): " << endl;
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				checkingAccount->orderChecks();
			}

			do
			{
				cout << "===============================================" << endl;
				cout << "Do you wish to (D)eposit, (W)ithdraw, (Q)uit" << endl;
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
				cout << "Do you wish to (D)eposit, (W)ithdraw, (Q)uit" << endl;
				cin >> transaction;
				if (transaction == 'd' || transaction == 'D')
				{
					cout << "===============================================" << endl;
					cout << "Savings Account:\nHow much do you wish to deposit? $" << endl;
					cin >> inputDeposit;

					//Allocates deposit object dynamically with membership operator
					savingAccount->depositFunds(inputDeposit);
					cout << endl;

				}
				else if (transaction == 'w' || transaction == 'W')
				{
					cout << "===============================================" << endl;
					cout << "*Automatic fee of $2 will be applied*";
					cout << "Savings Account:\nHow much do you wish to withdraw? $" << endl;
					cin >> inputWithdraw;
					savingAccount->withdrawFunds(inputWithdraw);
					cout << endl;

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
			cout << "What is the term (in years) for the certificate: ";
			cin >> term;
			cdAccount = new CD(inputAcctNumber, inputAcctBalance, term);
			cout << endl;

			do
			{
				cout << "===============================================" << endl;
				cout << "Do you wish to (D)eposit, (W)ithdraw, (Q)uit" << endl;
				cin >> transaction;
				if (transaction == 'd' || transaction == 'D')
				{
					cout << "Certificate Account:\nHow much do you wish to deposit? $" << endl;
					cin >> inputDeposit;

					//Allocates the deposit object dynamically with membership operator
					cdAccount->depositFunds(inputDeposit);

				}
				else if (transaction == 'w' || transaction == 'W')
				{
					cout << "===============================================" << endl;
					cout << "Certificate Account:\nHow much do you wish to deposit? $" << endl;
					cout << "Please enter withdrawal amount Certifcate: ";
					cin >> inputWithdraw;
					cdAccount->withdrawFunds(inputWithdraw);
					cout << endl;

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

	cout << endl;

	//Displays the account information to the user

	cout << "==================================" << endl;
	cout << "Summary: Checking Account" << endl;
	checkingAccount -> displayAccountInfo();
	cout << "==================================" << endl;
	cout << endl;

	cout << "==================================" << endl;
	cout << "Summary: Savings Account" << endl;
	savingAccount -> displayAccountInfo();
	cout << "==================================" << endl;
	cout << endl;

	cout << "==================================" << endl;
	cout << "Summary: Certificate of Deposit" << endl;
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
	cout << "\t\t*     Please begin your transaction by following    *" << endl;
	cout << "\t\t*          the instructions provided below.         *" << endl;
	cout << "\t\t*              Press Enter to begin! ^.^            *" << endl;
	cout << "\t\t*****************************************************" << endl;
}



