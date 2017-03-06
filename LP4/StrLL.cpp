/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016

Description: This StrLL class includes operations to construct and 
             manipulate a linked list of string nodes. Basic methods 
             include inserting and removing strings, finding the position
             in the list of a given string, clearing the list, and 
             printing (i.e. dumping) the list. One bit of unique 
             functionality is that insertion is guaranteed when called.
             This means that no matter what position the user tries to 
             insert into, the string will be inserted. For instance, even
             if the position for the insert is beyond the minimum bounds
             (for example, a negative number), it will insert at position
             0. If the position for the insert is beyond the maximum 
             bounds (for example, trying to insert at position 10 when
             the list only has 6 items), it will still insert at the end
             of the list (position 7 in the previously mentioned example).
             If the given position is within the valid bounds of the list,
             the value will be inserted in the appropriate position. Note
             also that there are two remove functions. One takes an extra
             'value' parameter (passed by reference), which stores the
             string value that was removed into the argument passed in 
             the calling function.
**************************************************************************/
#include <iostream>
#include <string>
#include "StrNode.h"
#include "StrLL.h"
using namespace std;

#ifndef NULL
#define NULL 0
#endif

/********************************************************
// Default Constructor
*********************************************************/
StrLL::StrLL() {
  Head = NULL;
}

/********************************************************
// Destructor
********************************************************/
StrLL::~StrLL() {
  clear();
}

/********************************************************
// Copy Constructor
********************************************************/
StrLL::StrLL(const StrLL &s){
  //cout << "BASE COPY CONSTRUCTOR CALLED" << endl;
  Head  = NULL;
  *this = s;
}

/********************************************************
// Overloaded Assignment Operator
********************************************************/
void StrLL::operator=(const StrLL &s){
  //cout << "BASE ASSIGNMENT OPERATOR CALLED" << endl;
  StrNode* Walk = s.Head;
  int loc = 0;

  //In case a list is assigned to itself (e.g. A = A;)
  if(Head == s.Head){
    return;
  }

  //In case anything was in 'this' list
  clear();

  //Insert each node from s into 'this' list
  while(Walk != NULL){
    insertAt(loc, Walk->getValue());
    Walk = Walk->getNextNode();
    loc++;
  }
}

/********************************************************
// Clear the list
********************************************************/
void StrLL::clear() {
  StrNode* Del;
  
  while (Head != NULL) {
    Del  = Head;
    Head = Head->getNextNode();
    delete Del;
  }
}

/********************************************************
// Inserts a value at a specified position (pos)
// returns false if pos is too large or too small
// but still inserts the value (at Head if too small
// at end if too large)
********************************************************/
bool StrLL::insertAt(int pos, string value) {
  bool result = false;
  
  StrNode* Next    = Head;
  StrNode* Trail   = Head;
  StrNode* NewNode = new StrNode(value, NULL);
  
  //if new node can't be created, notify lack of memory
  if(NewNode == NULL){
    cerr << "\n INSUFFICIENT MEMORY \n";
  }
  
  //if Head is NULL or pos is 0 or less, insert at Head
  if(Head == NULL || pos <= 0){
    
    //if list not empty, point the new node to the
    //start, or Head, of the existing list 
    if(Head != NULL){
      NewNode ->setNextNode(Head);
    }
    
    //Head needs to now point at new node
    Head = NewNode;
    
    //if position was 0, item was inserted in correct
    //spot; if not, it was still added at position 0
    //but result should be false
    if(pos == 0){
      result = true;
    }
  }
  
  //else Head is not NULL and pos is 1 or more
  //so Head pointer does not change
  else{
    //take 'pos' number of steps walking down the list,
    //but if pos is past the end of the list, stop walking
    while(pos > 0 && Next!= NULL){
      pos--;
      Trail = Next;
      Next  = Next->getNextNode();
    }
    
    //insert the node
    Trail->setNextNode(NewNode);
    
    //if pos equals 0 at this point, the correct number 
    //of steps were taken; if not, pos must be past the 
    //end of the list. Item is still added at the end of 
    //the list, but result should be false
    if(pos == 0){
      NewNode->setNextNode(Next);
      result = true;
    }
  }
  
  return result;
}

/********************************************************
// Remove the node at a specified position (pos). 
// Deletes the node at pos if pos is a valid position in
// the list and returns true. Does not delete and returns 
// false if pos is outside the list bounds. The removed
// string will be stored in the reference parameter 
// 'value' if successfully removed. If unsuccessful,
// 'value' will simply be set as the empty string ("").
********************************************************/
bool StrLL::removeAt(int pos, string &value){
  bool result    = false;
  StrNode* Del   = Head;
  StrNode* Trail = Head;
  
  value = "absolutely nothing";
  
  if (Head != NULL){
    //at position 0, delete from Head
    if (pos == 0){
      value = Head->getValue(); 
      Head  = Head->getNextNode();
      delete Del;
      result = true;
    }
    else{
      //traverse the list to find correct deletion spot
      while(pos > 0 && Del != NULL){
	pos--;
	Trail = Del;
	Del = Del->getNextNode();
      }
      
      //if pos isn't beyond the end of the list,
      //delete it
      if(pos == 0 && Del != NULL){
        value = Del->getValue();
	Trail->setNextNode(Del->getNextNode());
	delete Del;
	result = true;
      }
    }
  }

  return result;
}

/********************************************************
// Overloaded Remove function (takes only a position 
// parameter and does not update a passed-by-reference
// value parameter as in the prior remove function):
// Remove the node at a specified position (pos). 
// Deletes the node at pos if pos is a valid position in
// the list and returns true. Does not delete and returns 
// false if pos is outside the list bounds. 
********************************************************/
bool StrLL::removeAt(int pos){
  string null;

  //we don't care what the string reference parameter
  //parameter becomes in this version of the function 
  return removeAt(pos, null);
}

/********************************************************
// Returns the first position in the list of the given  
// value. The first position is given as position 0 (like  
// array indexing).
********************************************************/
int StrLL::posInList(string value){
  StrNode* Walk = Head;
  int pos = 0;
  
  //traverse the list, stopping at the end of the 
  //list or if the given value was found in the list
  while(Walk != NULL && Walk->getValue() != value){
    Walk = Walk->getNextNode();
    pos++;
  }

  //if list was fully traversed and value wasn't
  //in the list, return -1
  if (Walk == NULL){
    pos = -1;
  }
  
  return pos;
}

/********************************************************
// Prints out the list on one line. Each string value
// printed in the list will be separated by an arrow (->)
********************************************************/
void StrLL::dump(){
  StrNode* Walk = Head;
  
  cout << ". ";
  
  while (Walk!= NULL){
    cout << Walk->getValue() << "->";
    Walk= Walk->getNextNode();
  }
  
  cout << " .";
}
