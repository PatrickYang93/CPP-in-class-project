#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
	const int elementCounter = 20;
	int scores[elementCounter];
	int tallies[elementCounter];
	int counter = 0;
	
	int i = 0;
	int j = 0;
	int k = 0;
	int reverse = 0;

	int input[elementCounter];

	ifstream inFile("input.txt");

	cout << "Scores : ";
	while(inFile >> scores[counter]){
		cout << scores[counter] << " ";
		counter ++;
	}

	cout << endl;
	cout << endl;

	inFile.close();

	for(i = 0; i < counter; i++){
		tallies[i] = scores[i];
	}

	for(j = 0; j < counter; j++){
		for(k = 0; k < counter; k++){
			if(tallies[k] < tallies[k+1]){
				reverse = tallies[k];
				tallies[k] = tallies[k+1];
				tallies[k+1] = reverse;
			} 
		}
	}

	cout << setw(7) << setfill(' ') << left << "Scores" << ": ";
	for(i = 0; i < counter; i++){
		cout << scores[i] << " ";
	}

	cout << endl;
	cout << setw(7) << setfill(' ') << left << "Tallies" << ": ";
	for(i = 0; i < counter; i++){
		cout << tallies[i] << " ";
	}
	cout << endl;
	cout << endl;

	int high;
	int low;
	int highIndex;
	int lowIndex;
	int n = 0;
	int m = 0;

	for(n = 0; n < counter; n++)	
		if (scores[m] > scores[n]){
			low = scores[n];
			m = n;
		}

		else{
			low = scores[m];
		}
		lowIndex = m;

	
	for(n = 0; n < counter; n++)
		if (scores[m] < scores[n]){
			high = scores[n];
			m = n;
		}

		else{
			high = scores[m];
		}
		highIndex = m;
	
	cout << setw(15) << setfill(' ') << left << "Scores low: "<< low << " at index " << lowIndex << endl;
	cout << setw(15) << setfill(' ') << left << "Scores high: " << high << " at index " << highIndex << endl;

	int total = 0;
	double avg = 0;

	cout << endl;

	for(i = 0; i < counter; i++)
		total += scores[i];

	avg = total / counter;

	cout << "Scores: " << avg << " average" << endl;

	for(j = 0; j < counter; j++)
		for(k = 0; k < counter; k++){
			if(scores[k] < scores[k+1]){
				reverse = scores[k];
				scores[k] = scores[k+1];
				scores[k+1] = reverse;
			} 
		}
	
	cout << endl;
	cout << setw(7) << setfill(' ') << left << "Scores" << ": ";

	for(i = 0; i < counter; i++)
		cout << scores[i] << " ";
	

	cout << endl;
	cout << setw(7) << setfill(' ') << left << "Tallies" << ": ";

	for(i = 0; i < counter; i++)
		cout << tallies[i] << " ";
	

	int number;
	bool search = 0;
	cout << endl;
	cout << endl;
	cout << "Please enter a number to search: " << endl;
	cin >> number;

	for(i = 0; i < counter; i++)
		if(scores[i] == number){
			cout << setw(10) << setfill(' ') << left << "Scores: " << number << " is in the array" << endl;
			cout << endl;
			search = 1;
			break;
		} 

	if(search == 0){
		cout << setw(10) << setfill(' ') << left << "Scores: " << number << " is not in the array" << endl;
	}

	cout << endl;
	cout << "Please enter some numbers to store in the array input (8 numbers are required): " << endl;

	for(i = 0; i < counter; i++)
		cin >> input[i];
	

	for(j = 0; j < counter; j++)
		for(k = 0; k < counter -1; k++){
			if(input[k] > input[k+1]){
				reverse = input[k];
				input[k] = input[k+1];
				input[k+1] = reverse;
			} 
		}

	for(i = 0; i < counter; i++)
		cout << input[i] << " ";

	return 0;
}
