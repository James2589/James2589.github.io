#include <iomanip>
#include <iostream>
#include <Windows.h>
#include "AirGead.H"
#include "MainForm.h"
#include "vector"



using namespace std;
//vector<AirGead> userFund;
AirGead airGead;

void AirGead::setter(int t_years, double t_yearEndTotal) {
	m_totalYears = t_years;
	m_yearEndTotal = t_yearEndTotal;
}
AirGead::AirGead() {

}
AirGead::AirGead(int t_years, double t_yearEndTotal) {
	m_totalYears = t_years;
	m_yearEndTotal = t_yearEndTotal;
}

int AirGead::GetTotalYears() const {
	return m_totalYears;
}
double AirGead::GetYearEndTotal() const {
	return m_yearEndTotal;
}

double AirGead::YearEndBal(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years) {
	int totalMonths = t_years * 12;
	int i;
	int j;
	double yearEndBal{};
	double monthInt;
	double monthlyInt = 0;
	//AirGead airGead;
	Project2::MainForm menu;
	

	for (i = 1; i <= t_years; ++i) {
		monthlyInt = 0;
		yearEndBal = 0;
		for (j = 1; j <= 12; ++j) {
			monthInt = (t_openAmt + t_monthlyDep) * ((t_annualInt / 100) / 12);
			monthlyInt += monthInt;
			t_openAmt += monthInt + t_monthlyDep;

		}
		yearEndBal += t_openAmt;
	}
	return yearEndBal;
}

double AirGead::MonthlyContributionsCalc(double t_monthlyDep, int t_years) {
	double monthlyDep = t_monthlyDep;
	int totalMonths = t_years * 12;

	return monthlyDep * totalMonths;
}
void AirGead::YearEndBalVec(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years) {
	//m_openingAmount = t_openAmt;
	//m_monthlyDeposit = t_monthlyDep;
	//m_annualInterest = t_annualInt;
	//m_totalYears = t_years;
	double t_yearEndTotal = 0;
	userFund.resize(t_years);
	std::vector<AirGead>::size_type vectorSize = userFund.size();
	for (vector<AirGead>::size_type i = 0; i < vectorSize; i++) {
		//AirGead user = new AirGead();
		//AirGead user = airGead(t_years, t_yearEndTotal);
		AirGead user;
		t_yearEndTotal += 100;
		//user.m_totalYears = t_years;
		//user.m_yearEndTotal = t_yearEndTotal;
		user.setter(t_years, t_yearEndTotal);
		userFund.push_back(user);
		//userFund.push_back(user);
		
	}

}

double AirGead::TestBalVec(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years) {
	t_annualInt += 100;
	return t_annualInt;
}