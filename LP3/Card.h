/*******************************************************************************
Title:			 Go Fish
Name:			 Qiguang Yang
Course:			 CSCI241.01
Instructor:		 Jordan Ringenberg
Date:			 2/25/2016
*******************************************************************************/
#ifndef CARD_H
#define CARD_H

using namespace std;

class Card {
 private:
  int      value;
  char	   suit;
  Card*    nextCard;

 public:
  Card ();
  Card (int value,char suit, Card* n);

  void     setVal		(int);
  void	   setSuit		(char);
  void     setNextNode	(Card*);
  void     setThis		(int,char,Card*);
  int      getVal		();
  char	   getSuit		();
  Card*	   getNextNode	();

  void     print(); 
};

#endif