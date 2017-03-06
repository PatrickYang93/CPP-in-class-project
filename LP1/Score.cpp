/*******************************************************************************
Title:			 Arcade Leaderboard
Name:			 Qiguang Yang
Course:			 CSCI241.01
Instructor:		 Jordan Ringenberg
Date:			 2/1/2016

Description:	This file contains the functions to record and load user's name and score.

Input:			Input players' name and score.

Output:			Output players' name and score.
*******************************************************************************/

#include "Score.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Score::Score(){
	setScore("---",0,999999);
}

Score::Score(string name, int value, int rank){
	setScore(name,value,rank);
}

void Score::setName(string n)		{name = n;}

void Score::setValue(int v)			{value = v;}

void Score::setRank(int r)			{rank = r;}

void Score::setScore(string n, int v, int r){
	name	=	n;
	value	=	v;
	rank	=	r;
}

string Score::getName()				{return name;}

int Score::getValue()				{return value;}

int Score::getRank()				{return rank;}

void Score::print(){
	cout << endl;
	cout << setw(8)		<< setfill(' ') << right << rank;
	cout << setw(20)	<< setfill(' ') << right << value;
	cout << setw(20)	<< setfill(' ') << right << name;
	cout << endl;
}