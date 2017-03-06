/****************************************
Name:			Qiguang Yang
Date:			10/26/2015
Course:			CSCI240

Properties:		This project allows three players join a game call "trap doors & trampolines"
				It will record players old position, then a random number will be made to determine
				this player's step. Before the player move, two functions called "checkTraps" and "checkTtampolines"
				will be passed to judge rewards or punishment.

Inputs:			Three players name.

Outputs:		Players' position, rewards or punishment, winner of the game.

*****************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <conio.h>
#include <cstdlib>
using namespace std;

void printGameHeader();
void getName(string &,string &,string &);
void printChartHeader();
bool noWinner(int,int,int);
void printTurn(string,int,int);
int rollDice();
void movePlayer(int &);
bool checkTraps(int &);
bool checkTrampolines(int &);
void printMove(int);
void printWinner(string,string,string,int,int,int);

int main(){
	int player1 = 1;
	int player2 = 1;
	int player3 = 1;
	int counter = 0;

	string name1;
	string name2;
	string name3;

	printGameHeader();

	getName(name1,name2,name3);

	while(noWinner(player1,player2,player3) == true){
		printChartHeader();

		cout << setw(78) << setfill('-') << "-" << endl;
		for(int i = 0; i<3; i++){
			counter ++;
			int player;
			string name;

			if(i == 0){
				name = name1;
				player = player1;
			}

			else if(i == 1){
				name = name2;
				player = player2;
			}

			else if(i == 2){
				name = name3;
				player = player3;
			}

			printTurn(name,player,counter);
			
			player = player + rollDice();

			movePlayer(player);
			printMove(player);

			if(i == 0){
				player1 = player;
				player = player2;
			}

			else if(i == 1){
				player2 = player;
				player = player3;
			}

			else if(i == 2){
				player3 = player;
				player = player1;
			}
		}

		cout << setw(78) << setfill('-') << "-" << endl;
		cout << endl;
	}

	printWinner(name1,name2,name3,player1,player2,player3);

	return 0;
}

void printGameHeader(){
	cout << "+" << setw(31) << setfill('-') << "+" << endl;
	cout << "|" << setw(9) << right << setfill(' ') << " " << "Welcome to " << setw(11);
	cout << setfill(' ') << "|" << endl;
	cout << "|" << setw(31) << setfill(' ') << "|" << endl;
	cout << "|" << "   Trap Doors & Trampolines   " << "|" << endl;
	cout << "|" << setw(31) << setfill(' ') << "|" << endl;
	cout << "+" << setw(31) << setfill('-') << "+" << endl;
	cout << "|" << "   Trap Doors  " << " Trampolines   " << "|" << endl;
	cout << "|" << "   ----------  " << " -----------   " << "|" << endl;
	cout << "|" << "     9 ->   2  " << "    3 ->  59   " << "|" << endl;
	cout << "|" << "    22 ->   8  " << "   16 ->  32   " << "|" << endl;
	cout << "|" << "    30 ->  14  " << "   24 ->  54   " << "|" << endl;
	cout << "|" << "    51 ->  48  " << "   35 ->  41   " << "|" << endl;
	cout << "|" << "    60 ->  42  " << "   56 ->  78   " << "|" << endl;
	cout << "|" << "    88 ->  61  " << "   66 ->  92   " << "|" << endl;
	cout << "|" << "   116 ->  86  " << "   96 -> 110   " << "|" << endl;
	cout << "|" << "   128 -> 108  " << "  109 -> 140   " << "|" << endl;
	cout << "|" << "   135 -> 100  " << "  124 -> 134   " << "|" << endl;
	cout << "+" << setw(31) << setfill('-') << "+" << endl;
}

void getName(string &name1,string &name2,string &name3){
	cout << endl;
	cout << "Enter Player 1 Name: ";
	cin >> name1;

	cout << "Enter Player 2 Name: ";
	cin >> name2;

	cout << "Enter Player 3 Name: ";
	cin >> name3;
}

void printChartHeader(){
	cout << endl;
	cout << "Player     " << "Turn  " << "Old Pos  " << setw(25) << setfill(' ') << " ";
	cout << "Dice  " << "   Special   " << "New Pos" << endl;

}

bool noWinner(int player1, int player2, int player3){
	if(player1 >= 142){
		return false;
	}

	else if(player2 >= 142){
		return false;
	}

	else if(player3 >= 142){
		return false;
	}

	else{
		return true;
	}
}

void printTurn(string name, int player, int counter){
	cout << setw(12) << setfill(' ') << left << name << counter << "        " << setw(3) << setfill(' ') << player;
	cout << "    <Press enter to roll>    ";
	_getch();
}

int rollDice(){
	int dice = 0;
	int dice1 = 0;
	int dice2 = 0;

	dice1 = rand() * 100 % 6 + 1;
	dice2 = rand() * 100 % 6 + 1;
	dice = dice1 + dice2;

	cout << setw(3) << setfill(' ') << dice;
	return dice;
}

void movePlayer(int &player){
	if(checkTraps(player) == false && checkTrampolines(player) == false){
		cout << "               ";
	}

}

bool checkTraps(int &player){
	if(player == 9){
		player = 2;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 22){
		player = 8;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 30){
		player = 14;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 51){
		player = 48;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 60){
		player = 42;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 88){
		player = 61;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 116){
		player = 86;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 128){
		player = 108;
		cout << "    Trap Door! ";
		return true;
	}

	else if(player == 135){
		player = 100;
		cout << "    Trap Door! ";
		return true;
	}

	else{
		return false;
	}
}

bool checkTrampolines(int &player){
	if(player == 3){
		player = 59;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 16){
		player = 32;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 24){
		player = 54;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 35){
		player = 41;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 56){
		player = 78;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 66){
		player = 92;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 96){
		player = 110;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 109){
		player = 140;
		cout << "    Trampoline!";
		return true;
	}

	else if(player == 124){
		player = 134;
		cout << "    Trampoline!";
		return true;
	}

	else{
		return false;
	}
}

void printMove(int player){
	cout << setw(5) << setfill(' ') << right << player << endl;
}

void printWinner(string name1,string name2,string name3,int player1,
				 int player2, int player3){
					 if(player1 >= 142){
						cout << endl;
						cout << name1 << " win the game!" << endl;
					 }

					 else if(player2 >= 142){
						cout << endl;
						cout << name2 << " win the game!" << endl;
					 }

					  if(player3 >= 142){
						cout << endl;
						cout << name3 << " win the game!" << endl;
					 }
}