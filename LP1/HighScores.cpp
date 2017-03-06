/*******************************************************************************
Title:			 Arcade Leaderboard
Name:			 Qiguang Yang
Course:			 CSCI241.01
Instructor:		 Jordan Ringenberg
Date:			 2/1/2016

Description:	This program allows users to input their names and
				scores. Then, users can sort the highscore board or
				search a person's score. The program will out put a
				leaderboard.
*******************************************************************************/

#include "Score.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int	 printMenu();
void newScore(const int,Score[],int &);
void sortValue(Score[],int);
void sortName(Score[],int);
void searchName(Score[],int);
void inputData(int &, string &);
void addData(int,string,Score[],int);
void addRank(Score[],int);
void printName(bool,int,string,Score[],int);
void printBoard(int,Score[]);

int main(){
	const int MAXNUM = 500;
	Score HighScores[MAXNUM];

	int NumHighScores = 0;
	int entry = -1;

	Score n;

	entry = printMenu();

	while (entry != 0){

		switch(entry){

		case 0:
			break;

		case 1:

			newScore(MAXNUM,HighScores,NumHighScores);

			entry = printMenu();

			break;

		case 2:

			sortValue(HighScores,NumHighScores);

			addRank(HighScores,NumHighScores);

			printBoard(NumHighScores,HighScores);

			entry = printMenu();

			break;

		case 3:

			sortValue(HighScores,NumHighScores);

			addRank(HighScores,NumHighScores);

			sortName(HighScores,NumHighScores);

			addRank(HighScores,NumHighScores);

			printBoard(NumHighScores,HighScores);

			entry = printMenu();

			break;

		case 4:

			sortValue(HighScores,NumHighScores);

			addRank(HighScores,NumHighScores);

			sortName(HighScores,NumHighScores);

			addRank(HighScores,NumHighScores);

			searchName(HighScores,NumHighScores);

			entry = printMenu();

			break;

		default: 

			entry = printMenu();

			break;

		}

	}

	return 0;
}

int printMenu(){
	int entry;

	cout << endl;
	cout << "***************** Menu *****************" << endl;
	cout << setw(39) << setfill(' ') << left << "   1.Enter New Score"					<< " " << endl;
	cout << setw(39) << setfill(' ') << left << "   2. Print Scores Ordered by Value"	<< " " << endl;
	cout << setw(39) << setfill(' ') << left << "   3. Print Scores Ordered by Name"	<< " " << endl;
	cout << setw(39) << setfill(' ') << left << "   4. Search for Name"					<< " " << endl;
	cout << setw(39) << setfill(' ') << left << "   0. Exit"							<< " " << endl;
	cout << setw(40) << setfill('*')													<< "*" << endl;

	cout << endl << "Please select a number to continue: " << endl;
	cin >> entry;

	return entry;
}

//Entry1 function
void newScore(const int Max,Score HighScores[] ,int &NumHighScores){
	int score;
	string name;

	if(NumHighScores < Max){

		inputData(score,name);

		addData(score,name,HighScores,NumHighScores);

		NumHighScores ++;
	}

	else{
		cout << endl;
		cout << setw(50) << setfill('*')					 << "*" << endl;
		cout << "Failed to record new data! No available spaces!"	<< endl;
		cout << setw(50) << setfill('*')			   		 << "*" << endl;
	}
}

void inputData(int &score,string &name){
	cout << "Please enter a score: " << endl;
	cin  >> score;

	cout << "Please enter a name: " << endl;
	cin  >> name;
}

void addData(int score,string name,Score HighScores[],int NumHighScores){
	HighScores[NumHighScores].setValue(score);
	HighScores[NumHighScores].setName(name);

	cout << endl;
	cout << setw(40)	    << setfill('*') << "*" << endl;
	cout << "Data has been successfully recorded!" << endl;
	cout << setw(40)		<< setfill('*') << "*" << endl;
}

//Entry2 function
void sortValue(Score HighScores[],int NumHighScores){
	int loc = 0; 
	int key = 0;

	for(int i = NumHighScores; i > 0; i--){
		for(int i = NumHighScores; i > 0; i--){

			key = HighScores[i].getValue();
			loc = i - 1;

			while((loc >= 0) && (HighScores[loc].getValue() < key)){
				HighScores[loc+1].setValue(HighScores[loc].getValue());
				HighScores[loc+1].setName(HighScores[loc].getName());
				loc--;
			}

			HighScores[loc+1].setValue(key);
		}
	}
}

void addRank(Score HighScores[],int NumHighScores){

	for(int i = 1; i <= NumHighScores; i++){
		HighScores[i-1].setRank(i);
	}
}

//Entry3 function
void sortName(Score HighScores[],int NumHighScores){
	int loc = 0;
	int value = 0;
	string key;

	for(int i = 1; i < NumHighScores; i++){

		key = HighScores[i].getName();
		value = HighScores[i].getValue();
		loc = i - 1;

		while((loc >= 0) && (HighScores[loc].getName() > key)){
			HighScores[loc+1].setName(HighScores[loc].getName());
			HighScores[loc+1].setValue(HighScores[loc].getValue());
			HighScores[loc+1].setRank(HighScores[loc].getRank());
			loc--;
		}

		HighScores[loc+1].setName(key);
		HighScores[loc+1].setValue(value);
	}
}

//Entry4 function
void searchName(Score HighScores[],int NumHighScores){
	int  lowerLim  = 0;
	int  upperLim  = NumHighScores - 1;
	string  target ;
	int  index     = 0;
	bool found     = false;

	cout << endl << "Please enter a name to search: ";
	cin >> target;
	cout << endl;

	while (lowerLim <= upperLim && !found){

		index = (lowerLim + upperLim) / 2;

		if (HighScores[index].getName() < target){
			lowerLim = index + 1;
		}
		
		else if (HighScores[index].getName() > target){
			upperLim = index - 1;
		}

		else {
			found = true;
		}
	}

	printName(found,index,target,HighScores,NumHighScores);
}

//Display search result
void printName(bool found,int index,string target,
			   Score HighScores[],int NumHighScores){
				   
				   int firstMatch;

				   if(!found){
					   cout << endl << "Cannot find the name!" << endl;
				   }

				   else{

					   for(int i = index - 1; i > 0; i--){

						   if(HighScores[i].getName() != target){
							   firstMatch = i+1;
							   break;
						   }

					   }

					   for(int i = firstMatch; i < NumHighScores; i++){

						   if(HighScores[i].getName() != target){
							  break;
						   }

						   HighScores[i].print();
					   }
				   }

}

//Display leaderboard
void printBoard(int NumHighScores,Score HighScores[]){

	cout << endl     << setw(60)     << setfill('*') << "*" << endl;
	cout << setw(8)  << setfill(' ') << right << "Rank";
	cout << setw(20) << setfill(' ') << right << "Score";
	cout << setw(20) << setfill(' ') << right << "Name";

	for(int i = 0; i < NumHighScores; i++ ){
		cout << endl;
		cout << setw(8)  <<setfill(' ') << right << HighScores[i].getRank();
		cout << setw(20) <<setfill(' ') << right << HighScores[i].getValue();
		cout << setw(20) <<setfill(' ') << right << HighScores[i].getName();
	}

	cout << endl << setw(60) << setfill('*') << "*" << endl;
}

