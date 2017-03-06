/*************************************************************************

Author:				Qiguang Yang
Last Rev. Date:		April 1, 2016

Description:		This StrIndexed class is the base class of classes StrStack 
					and StrQueue. And it is public inheritance of StrLL class.
					Because its clear and pump functions are directly used in
					StrLL class. It consists functions to insert and remove nodes
					from StrLL link list, clear and print link list. 
**************************************************************************/
#include <iostream>
#include <string>
#include "StrIndexed.h"
using namespace std;

#ifndef NULL
#define NULL 0
#endif

// Default Constructo
StrIndexed::StrIndexed(){ length = 0; };

//Return the number of elements in the linked list
int StrIndexed::numElements(){ return length; };

//Insert an element into a specific place in the linked list
bool StrIndexed::insertAt(int p,string v){ 
	length++;
	return StrLL::insertAt(p,v); 
};

//Remove an element from a specific place in the linked list
bool StrIndexed::removeAt(int p,string &v){ 
	length--;
	return StrLL::removeAt(p,v); 
};

//Return the postition of current string in the linked list
int StrIndexed::posInList(string v){ return StrLL::posInList(v); };

//Clear StrLL linked list
void StrIndexed::clear(){ StrLL::clear(); };

//Print out the whole list
void StrIndexed::dump(bool printLen){ 
	
	if(printLen == true){
		StrLL::dump();
		cout << length;
	}

	else{
		StrLL::dump();
	}
};