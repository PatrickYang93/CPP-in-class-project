/*******************************************************************************
Title:			 Arcade Leaderboard
Name:			 Qiguang Yang
Course:			 CSCI241.01
Instructor:		 Jordan Ringenberg
Date:			 2/17/2016

Description:	This program allows users to input their names and
				scores. Then, users can sort the highscore board or
				search a person's score. The program will out put a
				leaderboard.
*******************************************************************************/

#include "Leaderboard.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


int main(){

	int entry;
	LeaderBoard n;

	n.ReadScoresFromFile("PacManHighScores.dat");

	n.PrintScores();

	entry = n.printMenu();

	while (entry != 0){

		switch(entry){

		case 0:
			break;

		case 1:
			
			n.EnterNewScore();

			entry = n.printMenu();

			break;

		case 2:

			n.SortScoreValues();

			n.UpdateScoreRanks();

			n.PrintScores();

			entry = n.printMenu();

			break;

		case 3:

			n.SortScoreValues();

			n.UpdateScoreRanks();

			n.SortScoreNamesAndValues();

			n.PrintScores();

			entry = n.printMenu();

			break;

		case 4:

			n.SortScoreValues();

			n.UpdateScoreRanks();

			n.SortScoreNamesAndValues();

			n.SearchForScoresByName();

			entry = n.printMenu();

			break;

		default: 

			entry = n.printMenu();

			break;

		}

	}

	n.WriteScoresToFile("PacManHighScores.dat");

	//n.Destructor();

	return 0;
}

