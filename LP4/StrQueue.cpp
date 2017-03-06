/*************************************************************************

Author:				Qiguang Yang
Last Rev. Date:		April 1, 2016

Description:		This StrQueue class is StrIndexed private inheritance.
					It provides functions to enqueue and dequeue members 
					from link list. All members in StrStack are not directly 
					used in StrIndexed class.
**************************************************************************/
#include <iostream>
#include <string>
#include "StrQueue.h"
#include "StrNode.h"
using namespace std;

#ifndef NULL
#define NULL 0
#endif

//Clear StrLL linked list
void StrQueue::clear(){ StrIndexed::clear(); };

//Insert a member at the back of the list.
void StrQueue::enqueue(string v){ StrIndexed:insertAt((StrIndexed::numElements()-1),v); };

//Remove a member from the front of the list.
bool StrQueue::dequeue(string &v){ 
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
bool StrQueue::isEmpty(){
	if(StrIndexed::numElements() == 0){
		return true;
	}

	else{
		return false;
	}
};

//Print out the whole list
void StrQueue::dump(){
	cout << "front: ";
	StrIndexed::dump();
	cout << " :back";
};