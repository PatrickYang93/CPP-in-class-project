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
				 This file was used to store a card linked list. each player's card in there
				 hand will be stored in CardLL class.
*******************************************************************************/
#include <iostream>
#include <string>
#include "CardLL.h"
#include "Card.h"

using namespace std;

#ifndef NULL
#define NULL 0
#endif

CardLL::CardLL(){
	first = NULL;
	name = "-";
}

void CardLL::insertOne(int v,char s){

	Card* Last = first;
	Card* Next;
	Card* Tail;

	bool found = false;

  if(Last == NULL){
    Last = new Card(v,s,first);
    first = Last;
  }

  //This part was used to sort the list by order. But it did not work.

  /*
  else{
		Next = Last->getNextNode();
		  while(Last != NULL && !found){
			  if(v < Last->getVal()){
				  Next = new Card(Last->getVal(),Last->getSuit(), NULL);
				  Last->setNextNode(Next);
				  Last->setVal(v);
				  Last->setSuit(s);
				  found = true;
			  }

			  else if(v == Last->getVal()){
				  if(s < Last->getSuit()){
					  Next = new Card(Last->getVal(),Last->getSuit(), NULL);
					  Last->setNextNode(Next);
					  Last->setVal(v);
					  Last->setSuit(s);
					  found = true;
				  }
			  }

			  else{
				  if(Next == NULL){
					Next = new Card(v,s,NULL);
					Last->setNextNode(Next);
					found = true;
				  }

				  else{
					Last = Next;
					Next = Last->getNextNode();
				  }
			  }
			  Last = Next;
		  }
  }
  */

  else{
    Next = Last->getNextNode();
    
    while(Next != NULL){
      Last = Next;
      Next = Next->getNextNode();
    }

    Next = new Card(v,s, NULL);
    Last->setNextNode(Next);
  }
  
}

void CardLL::removeOne(int v){ 
	Card* Lead  = first;
	Card* Trail = first;
	bool  found = false;

	if(first->getVal() == v){
		first = first->getNextNode();
		delete Lead;
	}

	else{

		Lead = Lead->getNextNode();

		while(Lead != NULL && !found){
			if(Lead->getVal() == v){

				found = true;

				Trail->setNextNode(Lead->getNextNode());

				delete Lead;
				Lead = NULL;

			}

			else {
				Trail = Lead;
				Lead  = Lead->getNextNode();

			}
		}
	}

	

}

//Check the card the player want to steal from others.

bool CardLL::hasCard(int value,char &suit){
	Card* Tail = first;
	bool found = false;

	while(Tail != NULL && !found){
		if(Tail->getVal() == value){
			suit = Tail->getSuit();
			found = true;
		}

		Tail = Tail->getNextNode();
	}

	return found;

}

bool CardLL::isEmpty(){ 
	
	if (first == NULL){
		return true;
	}

	else{
		return false;
	}
}

//Check if some player has four same cards.

void CardLL::checkSet(){
	Card* Lead = first;
	Card* Tail = first;
	int counter = 1;
	int value = 0;
	int next = 0;

	Lead = Lead->getNextNode();

	while(Lead != NULL && counter < 4){

		value = Tail->getVal();
		next = Lead->getVal();

		if( value == next){
			counter ++;
		}

		
		if(counter == 4){
			for(int p = 0; p < 4; p++){
				removeOne(Lead->getVal());
			}
		}

		Tail = Lead;
		Lead = Lead->getNextNode();
	}
	
}

void CardLL::print(){
	Card* CurNode = first;

	while(CurNode != NULL){
		CurNode->print();
		cout << " ";
		CurNode = CurNode->getNextNode();
	}

	cout << endl;
}

void CardLL::setName(string n){
	name = n;
}

string CardLL::getName(){
	return name;
}