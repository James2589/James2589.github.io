#include <iomanip>
#include <iostream>
#include <Windows.h>
#include "AirGead.H"
#include "UserInterface.h"

using namespace std;

//setter functions
void AirGead::SetOpeningAmount(double t_initDeposit) {
	if (t_initDeposit < 0) {
		system("cls");
		throw runtime_error("Invalid Opening Amount");
	}
	else {
		m_openingAmount = t_initDeposit;
	}
	
}

void AirGead::SetMonthlyDeposit(double t_monthlyDep) {
	if (t_monthlyDep < 0) {
		
		throw runtime_error("Invalid Monthly Deposit");
	}
	else {
		m_monthlyDeposit = t_monthlyDep;
	}
	
}
void AirGead::SetAnnualInterest(double t_annualInt) {
	if (t_annualInt < 0) {
		
		throw runtime_error("Invalid Annual Interest");
	}
	else {
		m_annualInterest = t_annualInt;
	}
	
}
void AirGead::SetTotalYears(int t_years) {
	if (t_years < 1) {
		
		throw runtime_error("Invalid Years");
	}
	else {
		m_totalYears = t_years;
	}
	
}

//getter functions
double AirGead::GetOpeningAmount() const{
	return m_openingAmount;
}

double AirGead::GetMonthlyDeposit() const{
	return m_monthlyDeposit;
}

double AirGead::GetAnnualInterest() const{
	return m_annualInterest;
}

int AirGead::GetTotalYears() const{
	return m_totalYears;
}


//function to calculate  year end balance without monthly deposits.
void AirGead::YearEndBal(double t_openAmt, double t_annualInt, int t_years) {
	int totalMonths = t_years * 12;
	int i;
	int j;
	double yearEndBal = t_openAmt;
	double monthInt;
	double monthlyInt = 0;

	PrintYearEndBal(1);

	for (i = 1; i <= t_years; ++i) {
		monthlyInt = 0;
		for (j = 1; j <= 12; ++j) {
			monthInt = t_openAmt * ((t_annualInt / 100) / 12);
			monthlyInt += monthInt;
			t_openAmt += monthInt;
			 
		}
		yearEndBal += monthlyInt;
		PrintFormat(i, yearEndBal, monthlyInt);
	}

	 
}

//function to calculate Year end balance with additional monthly deposits
void AirGead::YearEndBalDep(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years) {
	int totalMonths = t_years * 12;
	int i;
	int j;
	double yearEndBal;
	double monthInt;
	double monthlyInt = 0;
	UserInterface menu;

	PrintYearEndBal(2);

	for (i = 1; i <= t_years; ++i) {
		monthlyInt = 0;
		yearEndBal = 0;
		for (j = 1; j <= 12; ++j) {
			monthInt = (t_openAmt + t_monthlyDep) * ((t_annualInt / 100) / 12);
			monthlyInt += monthInt;
			t_openAmt += monthInt + t_monthlyDep;

		}
		yearEndBal += t_openAmt;
		PrintFormat(i, yearEndBal, monthlyInt);
	}

}

//function to print the values properly formatted.
void AirGead::PrintFormat(int t_year, double t_balance, double t_interest) {
	cout << right;
	cout << "  " << t_year << fixed << setprecision(2) << setfill(' ') << setw(35) << "$" << t_balance << setw(30) << "$" << t_interest << endl;
	cout << endl;
}

//function that formats the outputs in color and appropriately spaced.
void AirGead::PrintYearEndBal(int t_i) {
	system("Color 03");
	cout << setw(80) << setfill('*') << '*' << endl;
	if (t_i == 1) {
		cout << "            Balance and Interest Without Additional Monthly Deposits" << endl;
	}
	if (t_i == 2) {
		cout << "            Balance and Interest With Additional Monthly Deposits" << endl;
	}
	cout << setw(80) << setfill('*') << '*' << endl;
	cout << setfill(' ') << " Year" << setw(37) << "Year End Balance" << setw(38) << "Yearly Accumulated Interest" << endl;
	
	cout << setw(80) << setfill('*') << '*' << endl;
	cout << endl;
	cout << endl;
}