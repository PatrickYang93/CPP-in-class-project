/*******************************************************************************
Title:			 Go Fish
Name:			 Qiguang Yang
Course:			 CSCI241.01
Instructor:		 Jordan Ringenberg
Date:			 2/25/2016

Description:	 This project allow users input the number of users and their name.
				 In each player's turn, the can input another player's name and number
				 of a card to steal that player's card. When one player get a set of a
				 number, this set will be removed. When some one do not have card in 
				 his or her hand and it is this player's turn. This player will win this
				 game.
				 This file was used as client.
*******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Card.h"
#include "CardLL.h"

using namespace std;
void printState(CardLL*,int,int);
void getOne(int &,char &);

int main(){

	srand(time(NULL));

	bool erroCheck = true;
	bool win = false;
	int numPlayer;
	string name;
	int value;
	char suit;

	//Game start here. Enter player numbers.

	cout << "Please enter the number of players(2-4): ";
	cin >> numPlayer;

	while(numPlayer < 2 || numPlayer > 4){
		cout << "Please enter the number of players(2-4): ";
		cin >> numPlayer;
	}

	CardLL* player;
	player = new CardLL[numPlayer];

	int i = rand() % numPlayer;

	//Enter players' names and give each playe five random cards.

	for(int k = 0; k < numPlayer; k++){

		cout << "\nPlease enter player " << k+1 << " name (two characters): ";
		cin >> name;

		player[k].setName(name);

		for(int j = 0; j < 5; j++){

			getOne(value,suit);

			player[k].insertOne(value,suit);
		}
	}

	cout << endl;

	printState(player,numPlayer,i);

	//Begin stealing others card.

	while(!player[i].isEmpty()){

		//Choose a player.

		while(erroCheck){
			cout << "\nIt is " << player[i].getName() << "'s turn. Please pick a player to ask for a card: ";
			cin >> name;
			cout << endl;

			for(int p = 0; p < numPlayer; p++){
				if(name == player[p].getName()){
					erroCheck = false;
				}
			}
		}

		erroCheck = true;

		//Choose a number of card.

		while(erroCheck){
			cout << "Please specify a card value to ask " << name << " for: ";
			cin >> value;
			cout << endl;

			if(value > 0 && value < 14){
				erroCheck = false;
			}
		}

		erroCheck = true;

		//stealing a card or picking up a card from deck.

		for(int j = 0; j < numPlayer; j++){
			if(player[j].getName() == name){
				if(player[j].hasCard(value,suit)){

					cout << player[j].getName() << " has " << value << suit << ". " << value << suit;
					cout << " was transfered to " << player[i].getName() << "'s hand.\n\n";

					player[j].removeOne(value);

					player[i].insertOne(value,suit);

					printState(player,numPlayer,i);

					player[i].checkSet();

					break;
				}

				else{
					cout << player[j].getName() << " does not has any " << value << "'s. Go Fish " << player[i].getName() << "!\n";

					getOne(value,suit);

					player[i].insertOne(value,suit);

					i++;

					if(i == numPlayer){
						i = 0;
					}

					printState(player,numPlayer,i);

				

					break;
				}
			}
		}

	}

	cout << endl;
	cout << player[i].getName() << " win in this game.";

	return 0;
}

//Print status board

void printState(CardLL* player,int numPlayer,int i){

	for(int j = 0; j < numPlayer; j++){

		cout << player[j].getName() << " ";

		if(j == i){
			cout << " * ";
		}

		else{
			cout << "   ";
		}

		player[j].print();
	}
}

//Pick up one card from deck.

void getOne(int &value,char &suit){
	int suitType;

	value = rand() % 13 + 1;
	suitType = rand() % 4;

	if(suitType == 0){
		suit = 'S';
	}

	else if(suitType == 1){
		suit = 'H';
	}

	else if(suitType == 2){
		suit = 'D';
	}

	else if(suitType == 3){
		suit = 'C';
	}
}
