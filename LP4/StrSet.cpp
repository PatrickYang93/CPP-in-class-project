/*************************************************************************

Author:				Qiguang Yang
Last Rev. Date:		April 1, 2016

Description:		This StrSet class contains operator overloading functions.
					The operator will be test in client file. StrSet is StrLL 
					public inheritance. Because its clear and pump functions 
					are directly used in StrLL class. All members in StrStack 
					are not directly used in StrIndexed class.

**************************************************************************/

#include <iostream>
#include <string>
#include "StrSet.h"
#include "StrNode.h"

using namespace std;

#ifndef NULL
#define NULL 0
#endif

StrSet::StrSet():StrLL(){};

StrSet::~StrSet(){ };

StrSet::StrSet(const StrSet &rhsList){
  //initialize Head to NULL and use the overloaded 
  //assignment operator for brevity
  Head = NULL;
  *this = rhsList;
}

//Binary operator =
void StrSet::operator=(const StrSet &rhsList){
  StrLL::operator=(rhsList);
}

//Inserting value to set
bool StrSet::insert(string i){
	StrNode* Last = Head;
	StrNode* Next;

	if(Head == NULL){

		StrNode* NewNode = new StrNode(i, Head);

		Head = NewNode;

		return true;
	}

	else{
		Next = Last->getNextNode();

		if(Last->getValue() == i){
				return false;
			}

		while(Next != NULL){
			Last = Next;
			if(Last->getValue() == i){
				return false;
			}
			Next = Next->getNextNode();
		}

		Next = new StrNode(i, NULL);
		Last->setNextNode(Next);

		return true;
	}

};

//Remove value from set
bool StrSet::remove(string i){

	StrNode* Lead  = Head;
	StrNode* Trail = Head;

	bool found  = false;

	if (Head == NULL){

		return false;

	}

	else if(Head->getValue() == i){

		found = true;
		Head = Head->getNextNode();
		delete Lead;

	}

	else{

		Lead = Lead->getNextNode();

		while(Lead != NULL && !found){

			if(Lead->getValue() == i){
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

	return found;
};

//Check if the set is empty
bool StrSet::isEmpty(){

	if(Head == NULL){
		return true;
	}

	else{
		return false;
	}
};

//Binary output operator <<
ostream &operator<<(ostream &out, const StrSet &rhsSet){

	StrNode* CurNode = rhsSet.Head;

	while(CurNode != NULL){
		cout << CurNode->getValue() << endl;
		CurNode = CurNode->getNextNode();
	}

	return out;
};

//Binary operator +
StrSet StrSet::operator+ (const StrSet &rhsSet) const{

	StrSet temp;
	StrNode* next = rhsSet.Head;

	temp = *this;

	while(next != NULL){
		temp.insert(next->getValue());
		next = next->getNextNode();
	}

	return temp;
};

//Binary operator *
StrSet StrSet::operator* (const StrSet &rhsSet) const{
	
	StrSet output;
	StrSet temp;
	StrNode* next = rhsSet.Head;

	temp = *this;

	while(next != NULL){
		if(!temp.insert(next->getValue())){
			output.insert(next->getValue());
		}
		next = next->getNextNode();
	}

	return output;
};

//Binary operator -
StrSet StrSet::operator- (const StrSet &rhsSet) const{
	
	StrSet temp;
	StrNode* next = rhsSet.Head;

	temp = *this;

	while(next != NULL){
		temp.remove(next->getValue());
		next = next->getNextNode();
	}

	return temp;

};

//Binary operator <=
bool StrSet::operator<=(const StrSet &rhsSet) const{
	
	bool check;
	StrSet temp;
	StrNode* next = rhsSet.Head;

	temp = *this;

	while(next != NULL){
		temp.remove(next->getValue());
		next = next->getNextNode();
	}

	check = temp.isEmpty();

	if(check){
		return true;
	}

	else{ 
		return false;
	}
};

//Binary operator >=
bool StrSet::operator>=(const StrSet &rhsSet) const{
	
	StrSet temp;
	temp = *this;

	return !(temp<=rhsSet);
};

//Binary operator ==
bool StrSet::operator==(const StrSet &rhsSet) const{
	
	StrSet temp;
	temp = *this;

	return (temp<=rhsSet && temp>=rhsSet);
};