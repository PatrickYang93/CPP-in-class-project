//Author:	Qiguang Yang
//course:	CSCI241.01
//Data:		2/17/2016

#include <string>
#include <iostream>
using namespace std;

class LeaderBoard{
	
private: 
	int MAXSCORES;
	int NumHighScores;
	Score *Scores;

	string StrTruncate(string);

public:
	LeaderBoard();
	LeaderBoard(int,int);

	void  setScores(int,int);

	int   getNumHighScores();
	int	  getMax();

	int	 printMenu();
	void EnterNewScore();
	void SortScoreValues();
	void SortScoreNamesAndValues();
	void SearchForScoresByName();
	void inputData(int &, string &);
	void addData(int,string);
	void removeData(int,string);
	void UpdateScoreRanks();
	void printName(bool,int,string);
	void UpdateMaxScores(Score *);
	void PrintScores();
	void WriteScoresToFile(string);
	void ReadScoresFromFile(string);
	void Destructor(); 
};
