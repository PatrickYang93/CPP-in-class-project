/*******************************************************************************
Title:			 Arcade Leaderboard
Name:			 Qiguang Yang
Course:			 CSCI241.01
Instructor:		 Jordan Ringenberg
Date:			 2/17/2016

Description:	This file contains the functions to record and load user's name and score.

Input:			Input players' name and score.

Output:			Output players' name and score.
*******************************************************************************/

#include "Leaderboard.h"
#include "Score.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

LeaderBoard::LeaderBoard(){
	setScores(8,0);
}

LeaderBoard::LeaderBoard(int MAXSCORES,int NumHighScores){
	setScores(MAXSCORES,NumHighScores);
}

void  LeaderBoard::setScores(int max,int num){
	NumHighScores = num;
	MAXSCORES = max;
}

int LeaderBoard::getMax(){
	return MAXSCORES;
}

int LeaderBoard::getNumHighScores(){
	return NumHighScores;
}


int LeaderBoard::printMenu(){
	int entry;

	cout << endl;
	cout << "***************** Menu *****************" << endl;
	cout << setw(39) << setfill(' ') << left << "   1. Enter New Score"					<< " " << endl;
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
void LeaderBoard::EnterNewScore(){
	int score;
	string name;

	Score *Scores;
	Scores = new Score [MAXSCORES];

	UpdateMaxScores(*Scores); 

	inputData(score,name);

	name = StrTruncate(name);

	addData(score,name);

	NumHighScores ++;
}

void LeaderBoard::inputData(int &score,string &name){
	cout << "Please enter a score: " << endl;
	cin  >> score;

	cout << "Please enter a name: " << endl;
	cin  >> name;
}

void LeaderBoard::addData(int score,string name){

	Scores[NumHighScores].setValue(score);
	Scores[NumHighScores].setName(name);

	cout << endl;
	cout << setw(40)	    << setfill('*') << "*" << endl;
	cout << "Data has been successfully recorded!" << endl;
	cout << setw(40)		<< setfill('*') << "*" << endl;


}

//Entry2 function
void LeaderBoard::SortScoreValues(){
	int loc = 0; 
	int key = 0;
	string name;

	for(int i = NumHighScores; i > 0; i--){
		for(int i = NumHighScores; i > 0; i--){

			key = Scores[i]->getValue();
			name = Scores[i]->getName();
			loc = i - 1;

			while((loc >= 0) && (Scores[loc].getValue() < key)){
				Scores[loc+1].setValue(Scores[loc].getValue());
				Scores[loc+1].setName(Scores[loc].getName());
				loc--;
			}

			Scores[loc+1].setValue(key);
			Scores[loc+1].setName(name);
		}
	}
}

void LeaderBoard::UpdateScoreRanks(){

	for(int i = 1; i <= NumHighScores; i++){
		Scores[i-1].setRank(i);
	}
}

//Entry3 function
void LeaderBoard::SortScoreNamesAndValues(){
	int loc = 0;
	int value = 0;
	int rank;
	string key;

	for(int i = 1; i < NumHighScores; i++){

		key = Scores[i].getName();
		value = Scores[i].getValue();
		rank = Scores[i].getRank();
		loc = i - 1;

		while((loc >= 0) && (Scores[loc].getName() > key)){
			Scores[loc+1].setName(Scores[loc].getName());
			Scores[loc+1].setValue(Scores[loc].getValue());
			Scores[loc+1].setRank(Scores[loc].getRank());
			loc--;
		}

		Scores[loc+1].setName(key);
		Scores[loc+1].setValue(value);
		Scores[loc+1].setRank(rank);
	}
}

//Entry4 function																			
void LeaderBoard::SearchForScoresByName(){
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

		if (Scores[index].getName() < target){
			lowerLim = index + 1;
		}
		
		else if (Scores[index].getName() > target){
			upperLim = index - 1;
		}

		else {
			found = true;
		}
	}

	printName(found,index,target);
}

//Display search result
void LeaderBoard::printName(bool found,int index,string target){

	int firstMatch = 0;
	char Yy;
	bool remove = false;

	if(!found){
		cout << endl << "Cannot find the name!" << endl;
	}

	else{

		for(int i = index - 1; i > 0; i--){

			if(Scores[i].getName() != target){

				firstMatch = i+1;

				break;
			}

		}

		for(int i = firstMatch; i < NumHighScores; i++){

			if(Scores[i].getName() != target){
				break;
			}

			cout << endl;
			cout << setw(8)  <<setfill(' ') << right << Scores[i].getRank();
			cout << setw(20) <<setfill(' ') << right << Scores[i].getValue();
			cout << setw(20) <<setfill(' ') << right << Scores[i].getName();
		}

		cout << "Remove this player from the Leaderboard? [Y]/[N]" << endl;

		cin >> Yy;

		if(Yy == 'Y' || Yy == 'y'){
			removeData(firstMatch,target);
			UpdateMaxScores(*Scores);
		}
	}

}

//Display leaderboard
void LeaderBoard::PrintScores(){

	cout << endl     << setw(60)     << setfill('*') << "*" << endl;
	cout << setw(8)  << setfill(' ') << right << "Rank";
	cout << setw(20) << setfill(' ') << right << "Score";
	cout << setw(20) << setfill(' ') << right << "Name";

	for(int i = 0; i < NumHighScores; i++ ){
		cout << endl;
		cout << setw(8)  <<setfill(' ') << right << Scores[i].getRank();
		cout << setw(20) <<setfill(' ') << right << Scores[i].getValue();
		cout << setw(20) <<setfill(' ') << right << Scores[i].getName();
	}

	cout << endl << setw(60) << setfill('*') << "*" << endl;
}

void LeaderBoard::UpdateMaxScores(Score *Scores){

	if(NumHighScores <= (MAXSCORES/4) && MAXSCORES > 8){
		Score *Temp;
		Temp = new Score[MAXSCORES];

		for(int i = 0;i < MAXSCORES;i++){
			Temp[i] = Scores[i];
		}

		delete[] Scores;

		MAXSCORES /= 2;

		Score *Scores;
		Scores = new Score[MAXSCORES];

		for(int i = 0;i < (MAXSCORES/2);i++){
			Scores[i] = Temp[i];
		}

		delete[] Temp;
	}

	if(NumHighScores > MAXSCORES){

		Score *Temp;
		Temp = new Score[MAXSCORES];

		for(int i = 0;i < MAXSCORES;i++){
			Temp[i] = Scores[i];
		}

		delete[] Scores;

		MAXSCORES *= 2;

		Score *Scores;
		Scores = new Score[MAXSCORES];

		for(int i = 0;i < (MAXSCORES/2);i++){
			Scores[i] = Temp[i];
		}

		delete[] Temp;
	}

}


void LeaderBoard::WriteScoresToFile(string filename){
	ofstream output;
	output.open("PacManHighScores.dat");

	for(int i = 0; i < NumHighScores; i++ ){
		output << Scores[i].getRank() << endl;
		output << Scores[i].getValue() << endl;
		output << Scores[i].getName() << endl;
	}

	output.close();
}

void LeaderBoard::ReadScoresFromFile(string filename){
	ifstream input;
	input.open("PacManHighScores.dat");

	int i = 0;
	int rank;
	int value;
	string name;

	while(input >> rank){
		if(NumHighScores < MAXSCORES){

			Scores[i].setRank(rank);
			input.ignore();

			input >> value;
			Scores[i].setValue(value);
			input.ignore();

			input >> name;
			Scores[i].setName(name);
			input.ignore();
		}

	  
		else{

			UpdateMaxScores(Scores);

			Scores[i].setRank(rank);
			input.ignore();

			input >> value;
			Scores[i].setValue(value);
			input.ignore();

			input >> name;
			Scores[i].setName(name);
			input.ignore();
		}
		
	}

	input.close();
}

void LeaderBoard::removeData(int firstMatch,string target){

	for(int i = firstMatch; i < NumHighScores; i++){

			if(Scores[i].getName() != target){
				break;
			}

			delete[i] Scores;
	}
}

string LeaderBoard::StrTruncate(string name){

	if(name.size() > 3){
		name.resize(3);
	}

	return name;
}


void LeaderBoard::Destructor(){
	delete[] Scores;
}
