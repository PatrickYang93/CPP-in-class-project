/****************************************
Name:			Qiguang Yang
Date:			9/22/2015
Course:			CSCI240

Properties:		This project could compare the populations of vatious cities betwwen Toledo and Dayton on I-75.

Inputs:			Cities name and their population.

Outputs:		Cities name and population represented by '*'

*****************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {

	int pop;
	int number;
	int asterisk = 2000;
	int highest1 = 0;
	int highest2 = 0;
	string highestcity1;
	string highestcity2;
	string city;
	ifstream inFile("pop.dat");

	cout << "Please enter how many people a asterisk represendt. " << endl;
	cin >> asterisk;

	cout << setw(29) << setfill(' ') << "City Populations" << setw(11) << setfill(' ') << " " << endl;
	cout << setw(39) << setfill('-') << "-" << endl;

	while(getline (inFile, city)){
		inFile >> pop;
		inFile.ignore();
		number = pop / asterisk;

		if (number > highest1){
			highest2 = highest1;
			highestcity2 = highestcity1;
			highest1 = pop;
			highestcity1 = city;
		}
		
		else if (number > highest2){
			highest2 = pop;
			highestcity2 = city;
		}

		cout << setw(15) << setfill(' ') << left << city ;
		cout << setw(number) << setfill('*') << "*" << endl;
		
	}

	cout << setw(39) << setfill('-') << "-" << endl;
	cout << "Key: (*)  -> " << asterisk << " people" << endl;

	cout << endl;
	cout << setw(20) << setfill(' ') << left << "Highest Population: " << "No.1 "<< setw(20) << highestcity1 << highest1 << endl;
	cout << setw(20) << setfill(' ') << " " << "No.2 " << setw(20) << highestcity2 << highest2 << endl;

	cout << endl;
	cout << endl;

	return 0;
}