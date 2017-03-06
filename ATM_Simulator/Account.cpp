#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"
using namespace std;

Account::Account(){
	name	= "no name";
	amount	= 1000;
}

void	Account::setName(string n){
	name = n;
}

string	Account::getName() {
	return name;
}

void	Account::deposit(double amt) {
	if(amt >= 0.00 && amt <= 1000){
		amount += amt;
	}

	else{
		cout << "Invalid value!" << endl;
	}
}

void	Account::withdraw(double amt) {
	amount -= amt;
}

int		Account::getBalance() {
	return amount;
}

	void	Account::display() {
		cout << setw(21)					<< setfill('*')		<< "*" << endl;
		cout << "Name: "					<< name;
		cout << "	Curent Balance: "		<< "$"				<< amount << endl;
		cout << setw(21) << setfill('*')	<< "*" << endl;
	}