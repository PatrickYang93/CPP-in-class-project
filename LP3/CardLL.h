/*******************************************************************************
Title:			 Go Fish
Name:			 Qiguang Yang
Course:			 CSCI241.01
Instructor:		 Jordan Ringenberg
Date:			 2/25/2016
*******************************************************************************/
#ifndef CARDLL_H
#define CARDLL_H
#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

class CardLL{

private:
	Card* first;
	string name;

public:
	CardLL();

	void insertOne(int,char);
	void removeOne(int);
	bool hasCard(int,char &);
	bool isEmpty();
	void checkSet();
	void print();
	void setName(string);
	string getName();
};

#endif

