/*******************************************************************************
Title:			 Maze Solver
Name:			 Qiguang Yang
Date:			 4/21/2016
Discription:	 This program will input a maze from system and find if
				 there is a way that Mario could find princess. 
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "MazeSolver.h"
using namespace std;

MazeSolver::MazeSolver(string input){
	MarioPosY = 0;
	MarioPosX = 0;
	PrincessPosY = 0;
	PrincessPosX = 0;
	height = 0;
	width = 0;
	rescued = false;
	Mario = 'M';
	clear = ' ';
	blocked = '+';
	princess = 'P';
	maybe = '?';
	no = '*';

	inFile.open(input);

	inFile >> width;
	inFile.ignore();
	inFile >> height;
	inFile.ignore();

	if (!inFile) {
		cerr << "\n -- ERROR -- Could not open " << input;
	}

};

MazeSolver::~MazeSolver() {
  inFile.close();
};

void MazeSolver::mark(){
	inFile >> width;
	inFile.ignore();
	inFile >> height;
	inFile.ignore();
	
	for(int i = 0; i < width; i++){
		maze.resize(i);
		for(int j = 0; j < height; j++){
			maze[i].resize(j);
		}
	}

	for(int i = 0; i < height - 1; i ++){
		string s = "";
		getline(inFile,s);

		for(int j = 0; j < width - 1; j++){
			if (s[j] == Mario){ 
				maze[i][j] = Mario; 
				MarioPosY = i;
				MarioPosX = j;
			}
			else if (s[j] == clear){ 
				maze[i][j] = clear; 
			}
			else if	(s[j] == princess){ 
				maze[i][j] = princess; 
				PrincessPosY = i;
				PrincessPosX = j;
			}
			else{ 
				maze[i][j] = '+'; 
			}
		}
	}
};

void MazeSolver::goNorth(bool &rescued){
	if(MarioPosY > 0){
		if(MarioPosY - 1 == PrincessPosY && MarioPosX == PrincessPosX){
			rescued = true;
		}
		else if(maze[MarioPosY - 1][MarioPosX] == ' '){
			MarioPosY -= 1;
			maze[MarioPosY][MarioPosX] = '?';
			goNorth(rescued);
			if(rescued == false){
				goEast(rescued);
			}
			if(rescued == false){
				goWest(rescued);
			}
			if(rescued == false){
				maze[MarioPosY][MarioPosX] = '*';
				MarioPosY += 1;
			}
		}
	}
	else{
			rescued = false;
		}
};

void MazeSolver::goEast(bool &rescued){
	if(MarioPosX < width - 1){
		if(MarioPosX + 1 == PrincessPosX && MarioPosY == PrincessPosY){
			rescued = true;
		}
		else if(maze[MarioPosY][MarioPosX + 1] == ' '){
			MarioPosX += 1;
			maze[MarioPosY][MarioPosX] = '?';
			goEast(rescued);
			if(rescued == false){
				goNorth(rescued);
			}
			if(rescued == false){
				goSouth(rescued);
			}
			if(rescued == false){
				maze[MarioPosY][MarioPosX] = '*';
				MarioPosX -= 1;
			}
		}
	}
	else{
			rescued = false;
		}
};

void MazeSolver::goSouth(bool &rescued){
	if(MarioPosY < height - 1){
		if(MarioPosY + 1 == PrincessPosY && MarioPosX == PrincessPosX){
			rescued = true;
		}
		else if(maze[MarioPosY + 1][MarioPosX] == ' '){
			MarioPosY += 1;
			maze[MarioPosY][MarioPosX] = '?';
			goSouth(rescued);
			if(rescued == false){
				goEast(rescued);
			}
			if(rescued == false){
				goWest(rescued);
			}
			if(rescued == false){
				maze[MarioPosY][MarioPosX] = '*';
				MarioPosY -= 1;
			}
		}
	}
	else{
			rescued = false;
		}
};

void MazeSolver::goWest(bool &rescued){
	if(MarioPosX > 0){
		if(MarioPosX - 1 == PrincessPosX && MarioPosY == PrincessPosY){
			rescued = true;
		}
		else if(maze[MarioPosY][MarioPosX - 1] == ' '){
			MarioPosX -= 1;
			maze[MarioPosY][MarioPosX] = '?';
			goWest(rescued);
			if(rescued == false){
				goNorth(rescued);
			}
			if(rescued == false){
				goSouth(rescued);
			}
			if(rescued == false){
				maze[MarioPosY][MarioPosX] = '*';
				MarioPosX += 1;
			}
		}
	}
	else{
			rescued = false;
		}
};

void MazeSolver::searchForPath(){
	mark();
	goNorth(rescued);
	goEast(rescued);
	goSouth(rescued);
	goWest(rescued);
	print();

	if(rescued == true){
		cout << "The princess has been saved" << endl;
	}
	else{
		cout << "Can not find princess" << endl;
	}
};

void MazeSolver::print(){
	for(int i = 0; i < height - 1; i++ ){
		for(int j = 0; j < width - 1; j++){
			cout << maze[i][j];
		}
		cout << endl;
	}
};