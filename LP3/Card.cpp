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
				 This file was used to store the information of each card in Card class.
*******************************************************************************/
#include "Card.h"
#include <iostream>
using namespace std;

#ifndef NULL
#define NULL 0
#endif

Card::Card(){
  setThis(0,'-',NULL);
}

Card::Card(int v,char s,Card* n){
  setThis(v,s,n);
}

void Card::setVal(int v){
  value = v;
}

void Card::setSuit(char s){
  suit = s;
}

void Card::setNextNode(Card* n){
  nextCard = n;
}

void Card::setThis(int v,char s,Card* n){
  setVal(v);
  setSuit(s);
  setNextNode(n);
}

int Card::getVal(){
  return value;
}

char Card::getSuit(){
  return suit;
}

Card* Card::getNextNode(){
  return nextCard;
}

void Card::print(){
	if(value == 1){
		cout << "A";
	}

	else if(value == 10){
		cout << "T";
	}

	else if(value == 11){
		cout << "J";
	}

	else if(value == 12){
		cout << "Q";
	}

	else if(value == 13){
		cout << "K";
	}

	else{
		cout << value;
	}
	

	if(suit == 'S'){
		cout << "♠";
	}

	else if(suit == 'H'){
		cout << "♥";
	}

	else if(suit == 'D'){
		cout << "♦";
	}

	else if(suit == 'C'){
		cout << "♣";
	}

}
