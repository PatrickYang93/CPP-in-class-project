/*******************************************************************************
Title:			 Trap Doors & Trampolines
Name:			 Qiguang Yang
Course:			 CSCI240.01
Instructor:		 Jordan Ringenberg

Description:	This is the driver/client file for a program which simulates a 
				game called "Trap Doors & Trampolines" 
				for 2 to 6 players. Players will move around a board consisting 
				of 142 positions by rolling a pair of dice. On the board, there 
				are certain spaces containing trap doors and certain spaces 
				containing trampolines. If a player lands on a trap door, they 
				fall down to a less advantageous position. If a player lands on  
				a trampoline, then they jump up to a more advantageous 
				position. If they land on neither, then they remain in the 
				position they landed on.

Input:			The number of players playing and symbols for each of those  
				players will be input from the console.

Output:			Output denoting the current game state will be printed to 
				the console using an ASCII "grid" display.


NOTE: DO NOT MODIFY THIS FILE UNLESS YOU DISCUSS WITH ME DIRECTLY! YOUR CLASSES
	  MUST WORK WITH THIS CLIENT FILE
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include "Game.h"
#include "Player.h"
using namespace std;

void getPlayers(Player players[], int &numPlayers, const int MAXPLAYERS);

int main(){
	const int MAX_PLAYERS =   6;	//Max # players allowed
	Game	G;	
	
	Player	players[MAX_PLAYERS];	//Array of Player objects
	int		dice;					//Value of dice roll			
	int		pos;					//Position variable for a player
	int		t = 0;					//Index to keep track of whose turn it is
	int		numPlayers;				//Number of players playing the game
	string  skip;					//Denotes name of special space if landed on
	
	//Game simulation object
	srand(time(NULL));

	G.printGameHeader();

	getPlayers(players, numPlayers, MAX_PLAYERS);

	G.printGameBoard(players, numPlayers);

	//note: one loop iteration = 1 turn. Turn is decided upon by which 
	//overall turn number it is
	while(G.noWinner(players[t].getPos())){
		
		//set up for the next player's turn (player will be index t in array)
		G.nextTurn();
		t	 = (G.getTurn() - 1) % numPlayers;

		//handle turn for the current player (again, current player is at index t)
		pos = players[t].getPos();
		cout << "\n\n" << players[t].getSymbol() << "'s turn (space " << pos << ")." 
			 << " Press any Key to Continue..." << endl;

		//wait for user input to proceed
		_getch();

		skip = "";
		dice = G.rollDice();
		G.movePlayer(pos, skip, dice);
		players[t].setPos(pos);

		cout << dice << " was rolled.";
		if(skip != ""){
			cout << " You landed on a " << skip;
		}
		cout << "\nMoving player " << players[t].getSymbol() 
			 << " to " << players[t].getPos() << endl;
		
		G.printGameBoard(players, numPlayers);
	}


	//print who won and end the program
	G.printWinner(players[t].getSymbol());

	cout << endl << endl;

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
//Asks the user how many players will be playing. Then, retrieve player symbols 
//for each player from the user and store in the player array. 
////////////////////////////////////////////////////////////////////////////////
void getPlayers(Player players[], int &numPlayers, const int MAX_PLAYERS){
	char symbol;
	
	while(numPlayers > MAX_PLAYERS || numPlayers < 2){
		cout << "\n\nHow many players will play (2 - " << MAX_PLAYERS << ")? ";
		cin  >> numPlayers;
		cout << endl;
	}

	for(int i = 0; i < numPlayers; i++){
		cout << "Enter Player " << i + 1 << "'s Symbol: ";
		cin >> symbol;
		players[i].setSymbol(symbol);
	}
}

