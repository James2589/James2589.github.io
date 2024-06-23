#include <iomanip>
#include <iostream>
#include <Windows.h>
#include "AirGead.H"
#include "UserInterface.h"
#include "stdexcept"


using namespace std;
//basic welcome message function
void UserInterface::WelcomeMessage(){
	system("Color 03");
	cout << "                              Welcome to AirGead Banking's" << endl;
	cout << "                               Investment Planning tool" << endl;
	Sleep(4000);
	system("cls");
}

//user menu function
void UserInterface::UserMenu(){
	double open;
	double deposit;
	double interest;
	int years;
	char userQuit = 'a';
	AirGead bank;

	//exception handling for user inputs.
	while (userQuit != 'q') {
		try {
			cout << "                              Please enter your values" << endl;
			cout << setfill('*') << setw(80) << '*' << endl;
			cout << endl;

			cout << "Account Opening Amount: ";
			cin >> open;
			this->bank.SetOpeningAmount(open);
			cout << endl;

			cout << "Monthly Deposit Amount: ";
			cin >> deposit;
			this->bank.SetMonthlyDeposit(deposit);
			cout << endl;

			cout << "Annual Interest Amount: ";
			cin >> interest;
			this->bank.SetAnnualInterest(interest);
			cout << endl;

			cout << "Years Account will be open: ";
			cin >> years;
			this->bank.SetTotalYears(years);
			cout << endl;

		}
		catch (runtime_error& excpt) {
			system("cls");
			cout << excpt.what() << endl;
			cout << "Cannot Complete Interest calculations " << endl;
			UserVerification(3);
		}
		UserVerification(1);
		userQuit = 'q';
	}
	
	
}

//function that allows for user to edit, continue, or quit program.
void UserInterface::UserVerification(int t_i) {
	char userDec;
	

	int i = t_i;

	if (i == 1) {
		system("cls");
		cout << "                    Please verify your Inputs" << endl;
		cout << setw(80) << setfill('-') << '-' << endl;
		cout << "Account Opening Amount: " << this->bank.GetOpeningAmount() << endl;
		cout << endl;
		cout << "Monthly Deposit Amount: " << this->bank.GetMonthlyDeposit() << endl;
		cout << endl;
		cout << "Annual Interest Amount: " << this->bank.GetAnnualInterest() << endl;
		cout << endl;
		cout << "Years Account will be open: " << this->bank.GetAnnualInterest() << endl;
		cout << endl;
		cout << "Enter 'y' to continue or 'n' to change values" << endl;
		cin >> userDec;

		switch (userDec) {
		   case 'y':
		   case 'Y':
			   RunInterestCalc();

			   break;
		   case 'n':
		   case 'N':
			   system("cls");
			   UserInterface::UserMenu();
			   break;
		   default:
			   cout << "Invalid entry";
			   break;
		}
	}

	if (i == 2) {
		cout << endl;
		cout << "Enter 'e' to edit your values or 'q' to quit" << endl;
		cin >> userDec;

		switch (userDec) {
		case 'e':
		case 'E':
			UserMenu();
			break;
		case 'q':
		case 'Q':
			system("cls");
			exit(0);
			break;
		default:
			cout << "Invalid entry";
			break;
		}

	}

	if (i == 3) {
		system("cls");
		cout << endl;
		cout << "Enter 'r' to reenter your values or 'q' to quit" << endl;
		cin >> userDec;

		switch (userDec) {
		case 'r':
		case 'R':
			UserMenu();
			break;
		case 'q':
		case 'Q':
			system("cls");
			exit(0);
			break;
		default:
			cout << "Invalid entry";
			break;
		}
	}
}

//function designed to combine classes so all calculations can be properly output in user verification function.
void UserInterface::RunInterestCalc() {
	AirGead bank;
	double open = this->bank.GetOpeningAmount();
	double monthly = this->bank.GetMonthlyDeposit();
	double annualInt = this->bank.GetAnnualInterest();
	int years = this->bank.GetAnnualInterest();
	

	system("cls");
	bank.YearEndBal(open, annualInt, years);
	bank.YearEndBalDep(open, monthly, annualInt, years);
	cout << endl;
	UserVerification(2);
}