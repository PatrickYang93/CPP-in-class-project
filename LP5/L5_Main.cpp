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

int main(){
  MazeSolver Maze("mazeMed.txt");
  Maze.searchForPath();
    
  cout << endl;
  return 0;
}
