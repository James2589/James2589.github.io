#ifndef AirGead_desktop_CS210_h
#define AirGead_desktop_CS210_h

//header file declaring public functions and private variables
class AirGead {
public:
	void YearEndBal(double t_openAmt, double t_annualInt, int t_years);
	void YearEndBalDep(double t_openAmt, double t_monthlyDep, double t_annualInt, int t_years);
	void SetOpeningAmount(double t_initDeposit);
	void SetMonthlyDeposit(double t_monthlyDep);
	void SetAnnualInterest(double t_annualInt);
	void SetTotalYears(int t_years);
	double GetOpeningAmount()const;
	double GetMonthlyDeposit()const;
	double GetAnnualInterest()const;
	int GetTotalYears()const;
	void PrintFormat(int year, double balance, double interest);
	void PrintYearEndBal(int i);

private:
	double m_openingAmount;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_totalYears;
	
};

#endif 