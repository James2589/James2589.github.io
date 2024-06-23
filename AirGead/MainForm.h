#pragma once
#include "AirGead.h"
#include "vector"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ accountOpenLabel;
	private: System::Windows::Forms::Label^ monthlyDepositLabel;
	private: System::Windows::Forms::Label^ annualInterestLabel;
	private: System::Windows::Forms::Label^ yearsAccountOpenLabel;
	private: System::Windows::Forms::Button^ CalculateInterestButton;
	protected:





	private: System::Windows::Forms::TextBox^ OpenAmountIn;
	private: System::Windows::Forms::TextBox^ monthlyDepIn;
	private: System::Windows::Forms::TextBox^ annualIntRateIn;
	private: System::Windows::Forms::TextBox^ yearsOpenIn;
	private: System::Windows::Forms::Label^ withoutMonthlyContributionsLabel;
	private: System::Windows::Forms::Label^ withMonthlyContributionsLabel;









	private: System::Windows::Forms::Label^ displayWithoutContributions;
	private: System::Windows::Forms::Label^ displayWithContributions;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ resultsComparisonChart;

	private: System::Windows::Forms::Label^ resultsLabel;

	private: System::Windows::Forms::Label^ interestCalculatorLabel;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->accountOpenLabel = (gcnew System::Windows::Forms::Label());
			this->monthlyDepositLabel = (gcnew System::Windows::Forms::Label());
			this->annualInterestLabel = (gcnew System::Windows::Forms::Label());
			this->yearsAccountOpenLabel = (gcnew System::Windows::Forms::Label());
			this->CalculateInterestButton = (gcnew System::Windows::Forms::Button());
			this->OpenAmountIn = (gcnew System::Windows::Forms::TextBox());
			this->monthlyDepIn = (gcnew System::Windows::Forms::TextBox());
			this->annualIntRateIn = (gcnew System::Windows::Forms::TextBox());
			this->yearsOpenIn = (gcnew System::Windows::Forms::TextBox());
			this->withoutMonthlyContributionsLabel = (gcnew System::Windows::Forms::Label());
			this->withMonthlyContributionsLabel = (gcnew System::Windows::Forms::Label());
			this->displayWithoutContributions = (gcnew System::Windows::Forms::Label());
			this->displayWithContributions = (gcnew System::Windows::Forms::Label());
			this->resultsComparisonChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->resultsLabel = (gcnew System::Windows::Forms::Label());
			this->interestCalculatorLabel = (gcnew System::Windows::Forms::Label());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultsComparisonChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// accountOpenLabel
			// 
			this->accountOpenLabel->AutoSize = true;
			this->accountOpenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->accountOpenLabel->Location = System::Drawing::Point(25, 175);
			this->accountOpenLabel->Name = L"accountOpenLabel";
			this->accountOpenLabel->Size = System::Drawing::Size(258, 24);
			this->accountOpenLabel->TabIndex = 0;
			this->accountOpenLabel->Text = L"Account Opening Amount:";
			// 
			// monthlyDepositLabel
			// 
			this->monthlyDepositLabel->AutoSize = true;
			this->monthlyDepositLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->monthlyDepositLabel->Location = System::Drawing::Point(25, 250);
			this->monthlyDepositLabel->Name = L"monthlyDepositLabel";
			this->monthlyDepositLabel->Size = System::Drawing::Size(243, 24);
			this->monthlyDepositLabel->TabIndex = 1;
			this->monthlyDepositLabel->Text = L"Monthly Deposit Amount:";
			// 
			// annualInterestLabel
			// 
			this->annualInterestLabel->AutoSize = true;
			this->annualInterestLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->annualInterestLabel->Location = System::Drawing::Point(25, 325);
			this->annualInterestLabel->Name = L"annualInterestLabel";
			this->annualInterestLabel->Size = System::Drawing::Size(204, 24);
			this->annualInterestLabel->TabIndex = 2;
			this->annualInterestLabel->Text = L"Annual Interest Rate:";
			// 
			// yearsAccountOpenLabel
			// 
			this->yearsAccountOpenLabel->AutoSize = true;
			this->yearsAccountOpenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->yearsAccountOpenLabel->Location = System::Drawing::Point(25, 400);
			this->yearsAccountOpenLabel->Name = L"yearsAccountOpenLabel";
			this->yearsAccountOpenLabel->Size = System::Drawing::Size(210, 24);
			this->yearsAccountOpenLabel->TabIndex = 3;
			this->yearsAccountOpenLabel->Text = L"Years Account Open:";
			// 
			// CalculateInterestButton
			// 
			this->CalculateInterestButton->BackColor = System::Drawing::Color::LightGreen;
			this->CalculateInterestButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->CalculateInterestButton->Location = System::Drawing::Point(100, 475);
			this->CalculateInterestButton->Name = L"CalculateInterestButton";
			this->CalculateInterestButton->Size = System::Drawing::Size(200, 50);
			this->CalculateInterestButton->TabIndex = 4;
			this->CalculateInterestButton->Text = L"Calculate Interest";
			this->CalculateInterestButton->UseVisualStyleBackColor = false;
			this->CalculateInterestButton->Click += gcnew System::EventHandler(this, &MainForm::CalculateInt_Click);
			// 
			// OpenAmountIn
			// 
			this->OpenAmountIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->OpenAmountIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->OpenAmountIn->Location = System::Drawing::Point(300, 175);
			this->OpenAmountIn->Name = L"OpenAmountIn";
			this->OpenAmountIn->Size = System::Drawing::Size(100, 29);
			this->OpenAmountIn->TabIndex = 5;
			// 
			// monthlyDepIn
			// 
			this->monthlyDepIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->monthlyDepIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monthlyDepIn->Location = System::Drawing::Point(300, 250);
			this->monthlyDepIn->Name = L"monthlyDepIn";
			this->monthlyDepIn->Size = System::Drawing::Size(100, 29);
			this->monthlyDepIn->TabIndex = 6;
			// 
			// annualIntRateIn
			// 
			this->annualIntRateIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->annualIntRateIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->annualIntRateIn->Location = System::Drawing::Point(300, 325);
			this->annualIntRateIn->Name = L"annualIntRateIn";
			this->annualIntRateIn->Size = System::Drawing::Size(100, 29);
			this->annualIntRateIn->TabIndex = 7;
			// 
			// yearsOpenIn
			// 
			this->yearsOpenIn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->yearsOpenIn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->yearsOpenIn->Location = System::Drawing::Point(300, 400);
			this->yearsOpenIn->Name = L"yearsOpenIn";
			this->yearsOpenIn->Size = System::Drawing::Size(100, 29);
			this->yearsOpenIn->TabIndex = 8;
			// 
			// withoutMonthlyContributionsLabel
			// 
			this->withoutMonthlyContributionsLabel->AutoSize = true;
			this->withoutMonthlyContributionsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->withoutMonthlyContributionsLabel->Location = System::Drawing::Point(471, 175);
			this->withoutMonthlyContributionsLabel->Name = L"withoutMonthlyContributionsLabel";
			this->withoutMonthlyContributionsLabel->Size = System::Drawing::Size(294, 24);
			this->withoutMonthlyContributionsLabel->TabIndex = 15;
			this->withoutMonthlyContributionsLabel->Text = L"Without Monthly Contributions:";
			// 
			// withMonthlyContributionsLabel
			// 
			this->withMonthlyContributionsLabel->AutoSize = true;
			this->withMonthlyContributionsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->withMonthlyContributionsLabel->Location = System::Drawing::Point(471, 250);
			this->withMonthlyContributionsLabel->Name = L"withMonthlyContributionsLabel";
			this->withMonthlyContributionsLabel->Size = System::Drawing::Size(265, 24);
			this->withMonthlyContributionsLabel->TabIndex = 16;
			this->withMonthlyContributionsLabel->Text = L"With Monthly Contributions:";
			// 
			// displayWithoutContributions
			// 
			this->displayWithoutContributions->AutoSize = true;
			this->displayWithoutContributions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->displayWithoutContributions->Location = System::Drawing::Point(800, 175);
			this->displayWithoutContributions->Name = L"displayWithoutContributions";
			this->displayWithoutContributions->Size = System::Drawing::Size(0, 24);
			this->displayWithoutContributions->TabIndex = 18;
			// 
			// displayWithContributions
			// 
			this->displayWithContributions->AutoSize = true;
			this->displayWithContributions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->displayWithContributions->Location = System::Drawing::Point(800, 250);
			this->displayWithContributions->Name = L"displayWithContributions";
			this->displayWithContributions->Size = System::Drawing::Size(0, 24);
			this->displayWithContributions->TabIndex = 19;
			// 
			// resultsComparisonChart
			// 
			chartArea1->Name = L"ChartArea1";
			this->resultsComparisonChart->ChartAreas->Add(chartArea1);
			this->resultsComparisonChart->Location = System::Drawing::Point(781, 292);
			this->resultsComparisonChart->Name = L"resultsComparisonChart";
			series1->ChartArea = L"ChartArea1";
			series1->Name = L"Funds";
			series1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SeaGreen;
			this->resultsComparisonChart->Series->Add(series1);
			this->resultsComparisonChart->Size = System::Drawing::Size(134, 156);
			this->resultsComparisonChart->TabIndex = 20;
			this->resultsComparisonChart->Text = L"Account Breakdown";
			// 
			// resultsLabel
			// 
			this->resultsLabel->AutoSize = true;
			this->resultsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resultsLabel->Location = System::Drawing::Point(607, 75);
			this->resultsLabel->Name = L"resultsLabel";
			this->resultsLabel->Size = System::Drawing::Size(150, 42);
			this->resultsLabel->TabIndex = 21;
			this->resultsLabel->Text = L"Results";
			// 
			// interestCalculatorLabel
			// 
			this->interestCalculatorLabel->AutoSize = true;
			this->interestCalculatorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->interestCalculatorLabel->Location = System::Drawing::Point(61, 75);
			this->interestCalculatorLabel->Name = L"interestCalculatorLabel";
			this->interestCalculatorLabel->Size = System::Drawing::Size(338, 42);
			this->interestCalculatorLabel->TabIndex = 22;
			this->interestCalculatorLabel->Text = L"Interest Calculator";
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(457, 325);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Legend = L"Legend1";
			series2->Name = L"User";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(300, 300);
			this->chart1->TabIndex = 23;
			this->chart1->Text = L"chart1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(932, 663);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->interestCalculatorLabel);
			this->Controls->Add(this->resultsLabel);
			this->Controls->Add(this->resultsComparisonChart);
			this->Controls->Add(this->displayWithContributions);
			this->Controls->Add(this->displayWithoutContributions);
			this->Controls->Add(this->withMonthlyContributionsLabel);
			this->Controls->Add(this->withoutMonthlyContributionsLabel);
			this->Controls->Add(this->yearsOpenIn);
			this->Controls->Add(this->annualIntRateIn);
			this->Controls->Add(this->monthlyDepIn);
			this->Controls->Add(this->OpenAmountIn);
			this->Controls->Add(this->CalculateInterestButton);
			this->Controls->Add(this->yearsAccountOpenLabel);
			this->Controls->Add(this->annualInterestLabel);
			this->Controls->Add(this->monthlyDepositLabel);
			this->Controls->Add(this->accountOpenLabel);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->resultsComparisonChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void CalculateInt_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->OpenAmountIn->Text->Trim() == "") {
			MessageBox::Show("Please Enter Account Opening Amount", "Validation", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (this->monthlyDepIn->Text->Trim() == "") {
			MessageBox::Show("Please Enter Monthly Deposit Amount", "Validation", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (this->annualIntRateIn->Text->Trim() == "") {
			MessageBox::Show("Please Enter Annual Interest Rate", "Validation", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else if (this->yearsOpenIn->Text->Trim() == "") {
			MessageBox::Show("Please Enter Years Account Open", "Validation", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			try {
				//Convert text from text boxes to appropriate data types for calculations
				double openAmount = System::Convert::ToDouble(OpenAmountIn->Text);
				double monthlyDeposit = System::Convert::ToDouble(monthlyDepIn->Text);
				double annualInterestRate = System::Convert::ToDouble(annualIntRateIn->Text);
				int yearsOpen = System::Convert::ToInt16(yearsOpenIn->Text);

				/*Varibles making calls to airGead
				balanceWithContribution calculates the end balance with monthly contributions
				balanceWithoutContribution calculates the end balance with monthly contributions
				totalMonthlyContributions calculates the amount that comes solely from monthly contributions
				totalInterestAccrued calculates the total amount that comes comes solely from interest*/
				AirGead airGead;
				//vector<AirGead> userFund;

				double balanceWithContribution = airGead.YearEndBal(openAmount, monthlyDeposit, annualInterestRate, yearsOpen);
				double balanceWithoutContribution = airGead.YearEndBal(openAmount, 0, annualInterestRate, yearsOpen);
				double totalMonthlyContributions = airGead.MonthlyContributionsCalc(monthlyDeposit, yearsOpen);
				double totalInterestAccrued = balanceWithContribution - (totalMonthlyContributions + openAmount);
				
				//Displays the year end balances with and without monthly contributions
				displayWithoutContributions->Text = balanceWithoutContribution.ToString("##.00");
				displayWithContributions->Text = balanceWithContribution.ToString("##.00");
				
				/*Populate the bar chart comparing initial investment,
				  monthly contributions, and interest
				  over the duration of specified years.
				*/  
				this->resultsComparisonChart->Series["Funds"]->Points->AddXY("Initial Deposit", openAmount); 
				this->resultsComparisonChart->Series["Funds"]->Points->AddXY("Monthly Contributions", totalMonthlyContributions); 
				this->resultsComparisonChart->Series["Funds"]->Points->AddXY("Interest Accrued", totalInterestAccrued); 

				//this->chart1->Series["User"]->Points->AddXY(openAmount, totalInterestAccrued);
				//this->chart1->Series["User"]->Points->AddXY(openAmount + 500, totalInterestAccrued + 500);
				for (int i = 0; i < yearsOpen; i++) {
					int years = i;
					double annualTotal = airGead.TestBalVec(openAmount, monthlyDeposit, annualInterestRate, yearsOpen);
					//airGead.setter(i, annualTotal);
					AirGead newFund(i, annualTotal);
					airGead.userFund.push_back(newFund);
					this->chart1->Series["User"]->Points->AddXY(airGead.userFund[i].GetTotalYears(), airGead.userFund[i].GetYearEndTotal());
				}
				//this->chart1->Series["User"]->Points->AddXY(, annualTotal);
			}
			catch (Exception^ e) {
				throw e;
			}
		}
	}
};
}
