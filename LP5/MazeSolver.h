/*******************************************************************************
Title:			 Maze Solver
Name:			 Qiguang Yang
Date:			 4/21/2016
Discription:	 This program will input a maze from system and find if
				 there is a way that Mario could find princess. 
*******************************************************************************/
#ifndef MazeSolver_H
#define MazeSolver_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class MazeSolver{
private:
	int MarioPosY;
	int MarioPosX;
	int PrincessPosY;
	int PrincessPosX;
	int height;
	int width;
	bool rescued;
	char Mario;
	char clear ;
	char blocked;
	char princess;
	char maybe;
	char no;
	vector<vector<char> > maze;

public:
	ifstream inFile;

	MazeSolver(string);
	~MazeSolver();
	void mark();
	void goNorth(bool &);
	void goSouth(bool &);
	void goEast(bool &);
	void goWest(bool &);
	void print();
	void searchForPath();
};

#endif