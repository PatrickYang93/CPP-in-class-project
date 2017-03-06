//Author:	Qiguang Yang
//course:	CSCI241.01
//Data:		2/1/2016

#include <string>
#include <iostream>
using namespace std;

class Score{

private:
	string	name;
	int		value;
	int		rank;

public:
	Score();
	Score(string,int,int);

	void	setName(string);
	void	setValue(int);
	void	setRank(int);
	void	setScore(string,int,int);

	string	getName();
	int		getValue();
	int		getRank();

	void	print();
};

