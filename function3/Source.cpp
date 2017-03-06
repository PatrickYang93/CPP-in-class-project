#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void	popArrFromFile(fstream &, string [], double [], int &);
string	getConvFrom();
string	getConvFrom();
string	getConvTo();
double	getConvAmt();
void	showConversion(string from, string to, double amt, string curType, double curRate, int numElements);

int main(){
	fstream inFile("data.txt");
	const int Max_Currency = 200;
	string	curType[Max_Currency];
	double	curRate[Max_Currency];
	int		numItems = 0;

	string	convFrom;
	string	convTo;
	double	convAmt;

	popArrFromFile(inFile, curType, curRate, numItems); 

	convFrom	= getConvFrom();
	convTo		= getConvTo();

	convAmt		= getConvAmt();

	showConversion(convFrom, convTo, convAmt, curType, curRate, numItems);

	cout << endl;

	inFile.close();

	return 0;
}


//populate the currency array from input file
void popArrFromFile(fstream &inFile, string curType[], double curRate[],
				int &numItems){
		while (inFile >> curType[numItems]){
					inFile >> curRate[numItems];
					numItems ++;
		}

}

//get currency type from which to be converted from user
string getConvFrom(){
	string from = "";
	cout << "What currency do you want to convert?" << endl;
	cin >> from;

	return from;
}

//get currency type to convert to from user
string getConvTo(){
	string to = "";
	cout << "What currency do you want to convert?" << endl;
	cin >> to;

	return to;
}

//get currency amount to convert from user
double getConvAmt(){
	double amt = 0.0;

	cout << "How much would you like to convert?" << endl;
	return amt;
}

//Show the result of the conversion
void showConversion(string from, string to, double amt, string curType[], double curRate[], int numElements){
	double fromRate = -1.0;
	double toRate = -1.0;
	double result;

	for(int i = 0; i < numElements; i++){
		if(curType[i] == from){
			fromRate = curRate[i];
		}

		if(curType[i] == to){
			toRate = curRate[i];
		}
	}

	result = amt / (fromRate/toRate);

	cout << amt << " " << from << " to " << to << " is " << result << endl;
}
