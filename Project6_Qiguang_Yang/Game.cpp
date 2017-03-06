/*******************************************************************************
Title:			 Trap Doors & Trampolines
Name:			 Qiguang Yang
Course:			 CSCI240.01
Instructor:		 Jordan Ringenberg

Description:	This file contains the functions to run the game and end the game.

Input:			Input players' name and players' position,

Output:			Output the number of dice, renewed players' position and trap or trampolines message.
				The players' new position will output in the console using an ASCII "grid".
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "Game.h"
#include "Player.h"

Game::Game(){
	turn = 0;
}

void Game::printGameHeader() {
	cout << "+" << setw(31) << setfill('-') << "+" << endl;
	cout << "|" << setw(9) << right << setfill(' ') << " " << "Welcome to " << setw(11);
	cout << setfill(' ') << "|\n" ;
	cout << "|" << setw(31) << setfill(' ') << "|\n" ;
	cout << "|" << "   Trap Doors & Trampolines   " << "|\n" ;
	cout << "|" << setw(31) << setfill(' ') << "|\n" ;
	cout << "+" << setw(31) << setfill('-') << "+\n" ;
	cout << "|" << "   Trap Doors  " << " Trampolines   " << "|\n" ;
	cout << "|" << "   ----------  " << " -----------   " << "|\n" ;
	cout << "|" << "     9 ->   2  " << "    3 ->  59   " << "|\n" ;
	cout << "|" << "    22 ->   8  " << "   16 ->  32   " << "|\n" ;
	cout << "|" << "    30 ->  14  " << "   24 ->  54   " << "|\n" ;
	cout << "|" << "    51 ->  48  " << "   35 ->  41   " << "|\n" ;
	cout << "|" << "    60 ->  42  " << "   56 ->  78   " << "|\n" ;
	cout << "|" << "    88 ->  61  " << "   66 ->  92   " << "|\n" ;
	cout << "|" << "   116 ->  86  " << "   96 -> 110   " << "|\n" ;
	cout << "|" << "   128 -> 108  " << "  109 -> 140   " << "|\n" ;
	cout << "|" << "   135 -> 100  " << "  124 -> 134   " << "|\n" ;
	cout << "+" << setw(31) << setfill('-') << "+\n" ;
}

//check Traps and return a new position
bool Game::checkTraps(int &p) {
	if(p == 9){
		p = 2;
		return true;
	}

	else if(p == 22){
		p = 8;
		return true;
	}

	else if(p == 30){
		p = 14;
		return true;
	}

	else if(p == 51){
		p = 48;
		return true;
	}

	else if(p == 60){
		p = 42;
		return true;
	}

	else if(p == 88){
		p = 61;
		return true;
	}

	else if(p == 116){
		p = 86;
		return true;
	}

	else if(p == 128){
		p = 108;
		return true;
	}

	else if(p == 135){
		p = 100;
		return true;
	}

	else{
		
		return false;
	}
}

//check Trampolines and return a new position
bool Game::checkTrampolines(int &p){
	if(p == 3){
		p = 59;
		return true;
	}

	else if(p == 16){
		p = 32;
		return true;
	}

	else if(p == 24){
		p = 54;
		return true;
	}

	else if(p == 35){
		p = 41;
		return true;
	}

	else if(p == 56){
		p = 78;
		return true;
	}

	else if(p == 66){
		p = 92;
		return true;
	}

	else if(p == 96){
		p = 110;
		return true;
	}

	else if(p == 109){
		p = 140;
		return true;
	}

	else if(p == 124){
		p = 134;
		return true;
	}

	else{
		return false;
	}
}

void Game::printGameBoard(Player P[],int n){                                                         
	//The following will print a 2D ASCII Trap Doors & Trampolines gamebord to the consolle
	for(int i = 0; i < NUMROWS; i++){
		//Each one of these is to set the gameboard out from the left console edge
		cout << "\n    ";

		for(int j = 0; j < NUMCOLS; j++){
			//print out an ASCII "grid"
			for(int p = 0; p < n+1; p++){
				cout << "-";
			}
		}

		//print out the row number (starting with 0)
		cout << "-\n";
		cout << setw(2) << setfill(' ') << right << i << ": ";

		for(int j = 0; j < NUMCOLS; j++){
			cout << "|";

			//the position of current player
			for(int p = 0; p < n; p++){
				int tmpPos = 1 + j + (i * NUMCOLS);

				//represent the trampolines position via cells with plus signs in them
				if(checkTrampolines(tmpPos) == true ){
					cout << "+";
				}
				//represent the traps position via cells with minus signs in them
				else if(checkTraps(tmpPos) == true){
					cout << "-";
				}
				//put the symbol of the player in their respetive game cell
////////////////////////////////////////////////////
				else if(P[p].pos == tmpPos){      // I used P[] as Player array here, the member of Class Player:
					cout << P[p].symbol;          // "pos" and "symbol" were used.
				}                                 //
////////////////////////////////////////////////////
				else{
					cout << " ";
				}
			}
		}

		cout << "|\n";
	}

	//print the bottom border of the grid
	cout << "    ";

	for(int j = 0; j < NUMCOLS; j++){
		for(int p = 0; p < n+1; p++){
			cout << "-";
		}
	}

	cout << "-\n";

	//print out the column numbers (starting with 1)
	cout << "    ";

	for(int j = 0; j < NUMCOLS; j++){
		cout << setw(n+1) << setfill(' ') << right << j+1; 
	}

	cout << endl;
}

//generate two random number from 1-6 as the number of two dices
int Game::rollDice(){
	int dice = 0;
	int dice1 = 0;
	int dice2 = 0;

	dice1 = rand() * 100 % 6 + 1;
	dice2 = rand() * 100 % 6 + 1;
	dice = dice1 + dice2;

	return dice;
}

//change the players' postion, then check the Trampolines and the Traps
void Game::movePlayer(int &p, string &x, int dice){
	p += dice;
	
	if(Game::checkTrampolines(p) == true){
		x = "Trampoline";
	}

	else if(Game::checkTraps(p) == true){
		x = "Trap Door";
	}
}

int  Game::getTurn(){
	return turn;
}

void Game::nextTurn(){
	turn += 1;
}

void Game::printWinner(char name){
	cout << endl;
	cout << name << " win the game!\n";
}

bool Game::noWinner(int p){
	if(p >= 142){
		return false;
	}

	else{
		return true;
	}
}
