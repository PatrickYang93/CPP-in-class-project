#include <iostream>
#include <iomanip>
#include <string>
#include "Account.h"
using namespace std;

// prototypes
int  getSelection();
void printMenu();


int main(){
  //Instantiate your object here
  Account myAcct;
  int amount, selection;

  myAcct.setName("Bruce Wayne");

  // write a statement that will print "Hello" and the name on the account
  // Example: Hello Bruce Wayne
  cout << "Hello " << myAcct.getName() << " !\n";

  printMenu();				   // You need to implement this function below

  selection = getSelection();  // You need to implement this function below

  while (selection != 4){
    if (selection == 1){
      cout << "Please enter the amount [$0.01-$1000.00]: ";
      cin  >> amount;

      // Add your call to the deposit function here
	  myAcct.deposit(amount);

	  if(amount <= 0.00 || amount >= 1000){
		cout << "Invalid value!" << endl;
		}

	else{
		cout << "Invalid value!" << endl;
	}
    }

    else if (selection == 2){
      cout << "Please enter the amount in multiples of 10: ";
      cin  >> amount;

	  if(amount % 10 != ){
		cout << "Invalid value!" << endl;
		}

      // Add your call to the withdraw function here  
	  myAcct.withdraw(amount);
    }

    else if (selection == 3){
      // display the account name and current account balance on one line
		myAcct.display();
    }

    selection = getSelection();  //You need to implement this function below
  }

  cout << "Goodbye!" << endl;
  return 0;
}

void printMenu(){
	cout << "*** Oiler Banking ***" << endl;
	cout << "[1] Deposit" << endl;
	cout << "[2] Withdraw" << endl;
	cout << "[3] Balance" << endl;
	cout << "[4] Done" << endl;
	cout << setw(21) << setfill('*') << "*" << endl;
}

int getSelection(){

	int service;

	cout << "Please select your service: " << endl;
	cin >> service;

	while(service != 1 && service != 2 && service != 3 && service != 4 ){
		cout << "No valid choice has been entered.\n\n";
		cout << "Please select your service: \n";
		cin >> service;
	}
	return service;
}