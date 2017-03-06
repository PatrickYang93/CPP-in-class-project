/****************************************
Name:			Qiguang Yang
Date:			9/26/2015
Course:			CSCI240

Properties:		This project can run a game called roulette.
				Users need to choose their type of wager.
				The project can outcome a random number between 0-36.
				Then, users' choosen will be evaluated.

Inputs:			Type of wager, number of chips

Outputs:		Result of roulette, users' gaming imformation

*****************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
	const int startChips = 1000;
	int chips = startChips;
	int winingNum;
	const int high = 36;
	const int low = 0;
	int wager;
	int totalWin;
	int Case;
	int guessNum;
	string type;
	int valid = 0;
	char confirm;

	// Payout form
	cout << setw(12) << setfill(' ') << "" << "Welcome to roulette game. Good luck!";
	cout << setw(12) << setfill(' ') << "" <<endl;

	cout << setw(62) << setfill('-') << "" << endl;
	cout << "| Payout |" << setw(51) << setfill(' ') << left << " Wager" << "|" << endl;
	cout << setw(62) << setfill('-') << "" << endl;

	cout << "| 1 to 1 |" << setw(20) << setfill(' ') << left << " Odd numbers";
	cout << setw(31) << setfill(' ') << " ( 1,  3,  5, ..., 35)" << "|" << endl;

	cout << "| 1 to 1 |" << setw(20) << setfill(' ') << left << " Even numbers";
	cout << setw(31) << setfill(' ') << " ( 2,  4,  6, ..., 36)" << "|" << endl;

	cout << "| 1 to 1 |" << setw(20) << setfill(' ') << left << " 1st half";
	cout << setw(31) << setfill(' ') << " ( 1,  2,  3, ..., 18)" << "|" << endl;

	cout << "| 1 to 1 |" << setw(20) << setfill(' ') << left << " 2nd half";
	cout << setw(31) << setfill(' ') << " (19, 20, 21, ..., 36)" << "|" << endl;

	cout << "|35 to 1 |" << setw(20) << setfill(' ') << left << " Exact guess";
	cout << setw(31) << setfill(' ') << "" << "|" << endl;

	int run = 1;

	// Roulette game loop
	while (run == 1){
		cout << setw(62) << setfill('-') << "" << endl;
	
		cout << setw(61) << setfill(' ') << left << "| [1] Even" << "|" << endl;
		cout << setw(61) << setfill(' ') << left << "| [2] Odd" << "|" << endl;
		cout << setw(61) << setfill(' ') << left << "| [3] 1st half" << "|" << endl;
		cout << setw(61) << setfill(' ') << left << "| [4] 2nd half" << "|" << endl;
		cout << setw(61) << setfill(' ') << left << "| [5] Exact" << "|" << endl;
		cout << setw(62) << setfill('-') << "" << endl;

		// Input type and wager
		while (valid == 0){
			
			cout << endl;
			cout << "Please choose a type of wager: " << endl;
			cin >> Case;

			switch(Case){
				case 1:
					type = "Even";
					valid = 1;
					break;
			
				case 2:
					type = "Odd";
					valid = 1;
					break;

				case 3:
					type = "1st half";
					valid = 1;
					break;
			
				case 4:
					type = "2nd half";
					valid = 1;
					break;
	
				case 5:
					type = "Exact guess";
					valid = 1;
					break;
				}
			}
			
			valid = 0;

			cout << "Current chips: " << chips << endl;
			cout << "How many chips would you like to wager? (Between 1-" << chips << ")" << endl;
			cin >> wager;
			cout << endl;
			cout << endl;

		while (wager <= 0 || wager > chips){
			cout << "Invalid input!" << endl;
			cout << "How many chips would you like to wager? (Between 1-" << chips << ")" << endl;
			cin >> wager;
			cout << endl;
			cout << endl;
		}
	
		cout << "You have decided to wager " << wager << " chips on " << type << "." << endl;
		cout << endl;
		cout << "Is this correct?" << endl;
		cout << "Enter 'Y' to proceed with the game" << endl;
		cout << "Or enter 'N' to take back your wager:" << endl;
				
		cin >> confirm;

		if(confirm == 'Y' || confirm == 'y'){
				valid = 0;
			}

		else if(confirm == 'N' || confirm == 'n'){
				valid = 1;
			}
		
		// Begin spining
		while(valid == 0){
			chips -= wager;
			winingNum = rand() % (high - low) + low;

			switch(Case){
			case 1:
				type = "Even";
				cout << setw(30) << setfill('-') << "" << endl;
				cout << setw(28) << setfill(' ') << "|  Wining number is " << winingNum << "|" << endl;
				cout << setw(30) << setfill('-') << "" << endl;
			
				if(winingNum % 2 == 1){
						
					totalWin = wager * 2;
					cout << "You get " << wager << " chips!" << endl;
					chips += totalWin;
				}
				else{
					cout << "Unlucky, try again!" << endl; 
				}

				valid = 1;
				break;
			
			case 2:
				type = "Odd";
				cout << setw(30) << setfill('-') << "" << endl;
				cout << setw(28) << setfill(' ') << "|  Wining number is " << winingNum << "|" << endl;
				cout << setw(30) << setfill('-') << "" << endl;
	
				if(winingNum % 2 == 0){
					
					totalWin = wager * 2;
					cout << "You get " << wager << " chips!" << endl;
					chips += totalWin;
				}
				else{
					cout << "Unlucky, try again!" << endl; 
				}
	
				valid = 1;
				break;

			case 3:
				type = "1st half";
				cout << setw(30) << setfill('-') << "" << endl;
				cout << setw(28) << setfill(' ') << "|  Wining number is " << winingNum << "|" << endl;
				cout << setw(30) << setfill('-') << "" << endl;

				if(winingNum <= 18){
					
					totalWin = wager * 2;
					cout << "You get " << wager << " chips!" << endl;
					chips += totalWin;
				}
				else{
					cout << "Unlucky, try again!" << endl; 
				}

				valid = 1;	
				break;
			
			case 4:
				type = "2nd half";
				cout << setw(30) << setfill('-') << "" << endl;
				cout << setw(28) << setfill(' ') << "|  Wining number is " << winingNum << "|" << endl;
				cout << setw(30) << setfill('-') << "" << endl;
					
				if(winingNum > 18){

					totalWin = wager * 2;
					cout << "You get " << wager << " chips!" << endl;
					chips += totalWin;
				}
				else{
					cout << "Unlucky, try again!" << endl; 
				}
				
				valid = 1;
				break;
	
			case 5:
				type = "Exact guess";
				cout << "PLease enter your choosing number: " << endl;
				cin >> guessNum;

				cout << setw(30) << setfill('-') << "" << endl;
				cout << setw(28) << setfill(' ') << "|  Wining number is " << winingNum << "|" << endl;
				cout << setw(30) << setfill('-') << "" << endl;
	
				if(winingNum == guessNum){
						
					totalWin = wager * 36;
					cout << "You get " << wager*35 << " chips!" << endl;
					chips += totalWin;
				}
				else{
					cout << "Unlucky, try again!" << endl; 
				}
				valid = 1;
				break;
				
			default:
				cout << "Invalid value!" << endl;
				valid = 0;
			}	
		}		
		valid = 0;

		if( chips > 0){
			cout << endl;
			cout << "Your current chips are " << chips << endl;
			cout << "Do you want to try again?" << endl;
			cout << setw(60) << setfill('-') << "" << endl;
			cout << "Enter 'Y' to try again" << endl;
			cout << "Or enter 'N' to exit:" << endl;
			cout << setw(60) << setfill('-') << "" << endl;

			cin >> confirm;

			if(confirm == 'Y' || confirm == 'y'){
				run = 1;
			}

			else if(confirm == 'N' || confirm == 'n'){
				run = 0;
			}
		}

		else if( chips <= 0){
			cout << endl;
			cout << "You don't have any chips now!" << endl;
			run = 0;
		}
	}

	cout << "Your current chips are" << endl;
	cout << chips << endl;

	if ( chips > startChips){
		cout << "Good job!" << endl;
	}

	else if ( chips == 0){
		cout << "Tough break, kid" << endl;
	}

return 0;
}