/****************************************
Name:			Qiguang Yang
Date:			9/10/2015
Course:			CSCI240

Properties:		Calculating federal taxes for an individual 

Inputs:			Name, SSN, income

Outputs:		Name, SSN, income, income tax and tax rate.

*****************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
	
	string Name;
	int SSN;
	double Income;
	double Tax;
	double rate;
	double Taxrate;
	ifstream inFile("tax_statement.txt");
	ofstream outFile("tax_data.txt");

	//Declear tax rate in 2015
	const double rate1 = 0.10;
	const double rate2 = 0.15;
	const double rate3 = 0.25;
	const double rate4 = 0.28;
	const double rate5 = 0.33;
	const double rate6 = 0.35;
	const double rate7 = 0.396;

	//Declear Single Filers' income brackets in 2015
	const double level1 = 9225;
	const double level2 = 37450;
	const double level3 = 90750;
	const double level4 = 189300;
	const double level5 = 411500;
	const double level6 = 413200;

	//Declear upper limit of tax due in each brackets
	const double taxLevel1 = 922.5;
	const double taxLevel2 = 5156.25;
	const double taxLevel3 = 18481.25;
	const double taxLevel4 = 46075.25;
	const double taxLevel5 = 119401.25;
	const double taxLevel6 = 119996.25;

	//Read tax statements from document
	getline(inFile, Name); 
	inFile >> SSN;
	inFile.ignore();
	inFile >> Income;

	//Evaluate tax due
	if( Income <= level1 ){
		Tax = Income * rate1;
		rate = rate1;
	}

	else if( Income > level1 & Income <= level2){
		Tax = (Income - level1) * rate2 + taxLevel1;
		rate = rate2;
	}

	else if( Income > level2 & Income <= level3){
		Tax = (Income - level2) * rate3 + taxLevel2;
		rate = rate3;
	}

	else if( Income > level3 & Income <= level4){
		Tax = (Income - level3) * rate4 + taxLevel3;
		rate = rate4;
	}
	
	else if( Income > level4 & Income <= level5){
		Tax = (Income - level4) * rate5 + taxLevel4;
		rate = rate5;
	}

	else if( Income > level5 & Income <= level6){
		Tax = (Income - level5) * rate6 + taxLevel5;
		rate = rate6;
	}

	else {
		Tax = (Income - level6) * rate7 + taxLevel6;
		rate = rate7;
	}

	//Calculate tax due in percentage of total income
	Taxrate = Tax / Income * 100;
	
	//Output tax data and save in an document
	outFile << setw(50) << setfill('-') << "-" << endl;

	outFile << "|Name:" << setw(43) << setfill('.');
	outFile << Name << "|" << endl;
	
	outFile << "|SSN:"  << setw(35) << setfill('.') << ".";
	outFile << setw(9) << setfill('0') << SSN << "|" << endl;
	
	outFile << "|Income:" << setw(41) << setfill('.');
	outFile << fixed << setprecision(2) << Income << "|" << endl;
	
	outFile << setw(50) << setfill('-') << "-" << endl;
	outFile << endl;
	
	outFile << "Federal Income Tax Due: $" << fixed << setprecision(2) << Tax;
	outFile << " (" << setprecision(1) << Taxrate << "% of income)" << endl;
	
	outFile << setw(50) << setfill('-') << "-" << endl;
	outFile << endl;

	inFile.close();
	outFile.close();

return 0;
}

