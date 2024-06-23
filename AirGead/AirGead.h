#pragma once
#ifndef AirGead_desktop_CS499_h
#define AirGead_desktop_CS499_h
#include<vector>
//header file declaring public functions and private variables
class AirGead {
public:
	AirGead();
	AirGead(int t_years, double t_yearEndTotal);
	double YearEndBal(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years);
	double MonthlyContributionsCalc(double t_monthlyDep, int t_years);
	void YearEndBalVec(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years);
	double TestBalVec(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years);
	int GetTotalYears()const;
	void setter(int t_years, double t_yearEndTotal);
	double GetYearEndTotal()const;
	vector<double> userFund;

private:
	double m_openingAmount;
	double m_monthlyDeposit;
	double m_annualInterest;
	double m_yearEndTotal;
	int m_totalYears;
	
};

#endif 