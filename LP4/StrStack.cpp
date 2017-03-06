/*************************************************************************

Author:				Qiguang Yang
Last Rev. Date:		April 1, 2016

Description:		This StrStack class is StrIndexed private inheritance.
					It provides functions to push and pop members from link list.
					All members in StrStack are not directly used in StrIndexed
					class.
**************************************************************************/
#include <iostream>
#include <string>
#include "StrStack.h"
#include "StrNode.h"
using namespace std;

#ifndef NULL
#define NULL 0
#endif

//Clear StrLL linked list
void StrStack::clear(){ StrIndexed::clear(); };

//Insert a member at the top of the list.
void StrStack::push(string v){ 
	StrIndexed::insertAt(0,v);
};

//Remove a member from the front of the list.
bool StrStack::pop(string &v){ 
	if (Head == NULL){
		v = "Absolutely nothing";
		return false;
	}

	else{
		StrIndexed::removeAt(0,v);
		return true; 
	}
};

//Check if the StrLL linked list is empty
bool StrStack::isEmpty(){
	if(StrIndexed::numElements() == 0){
		return true;
	}

	else{
		return false;
	}
};

//Print out the whole list
void StrStack::dump(){
	cout << "top: ";
	StrIndexed::dump();
	cout << " :bottom";
};