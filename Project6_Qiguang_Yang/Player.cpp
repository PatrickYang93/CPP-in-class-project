/*******************************************************************************
Title:			 Trap Doors & Trampolines
Name:			 Qiguang Yang
Course:			 CSCI240.01
Instructor:		 Jordan Ringenberg

Description:	This file contains the functions to record and load player's name and position.

Input:			Input players' name and players' position.

Output:			Output players' name and players' position.
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "Player.h"

Player::Player(){ 
	pos = 1;
	symbol = 'A';
}

void	Player::setSymbol(char s)	{ symbol = s; }
char	Player::getSymbol()			{ return symbol; }
void    Player::setPos(int p)		{ pos = p; }
int		Player::getPos()			{ return pos; }