#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void correcr_A_T_Input(int &,int &);
int qualifyStatus(int,int);
void timeFormat(int &,int &);

int main(){
	const int maxSize = 50;
	int age[maxSize];
	int time[maxSize];
	int under30 = 0;
	int between3050 = 0;
	int over50 = 0;
	int notQualify = 0;
	int numReturn = 0;
	int counter = 0;

	ifstream inFile("race.dat");

	cout << "    Age   " << "Time" << endl;

	while(inFile >> age[counter]){
		inFile >> time[counter];
		correcr_A_T_Input(age[counter],time[counter]);
		numReturn = qualifyStatus(age[counter],time[counter]);
		timeFormat(age[counter],time[counter]);
		
		if(numReturn == 0){
			notQualify ++;
		}

		else if(numReturn == 1){
			under30 ++;
		}

		else if(numReturn == 2){
			between3050 ++;
		}

		else if(numReturn == 3){
			over50 ++;
		}

		counter ++;
	}

		
	cout << setw(40) << setfill('-') << "-" << endl;
	cout << "  Amount  " << "Category" << endl;
	cout << setw(40) << setfill('-') << "-" << endl;
	cout << setw(6) << setfill(' ') << right << under30 << "    ";
	cout << "Under 30" << endl;
	cout << setw(6) << setfill(' ') << right << between3050  << "    ";
	cout << "30 to 50" << endl;
	cout << setw(6) << setfill(' ') << right << over50 << "    ";
	cout << "Over 50" << endl;
	cout << setw(6) << setfill(' ') << right << notQualify << "    ";
	cout << "Didn't Qualify" << endl;
	cout << setw(40) << setfill('-') << "-" << endl;

	return 0;

}

void correcr_A_T_Input(int &age,int &time){
	int temp;

	if(age > time){
		temp = age;
		age = time;
		time = temp;
	}
}

int qualifyStatus(int age, int time){
	
	if(age < 30){
		if(time < 300){
			return 1;
		}

		else{
			return 0;
		}
	}

	else if(age >= 30 && age <= 50){
		if(time < 360){
			return 2;
		}

		else{
			return 0;
		}
	}

	else if(age > 50){
		if(time < 420){
			return 3;
		}

		else{
			return 0;
		}
	}

}

void timeFormat(int &age, int&time){
	int minutes = 0;
	int seconds = 0;

	minutes = time / 60;
	seconds = time % 60;

	cout << setw(6) << setfill(' ') << right << age << "    ";
	cout << minutes << "minutes " << seconds << "seconds" << endl;

}