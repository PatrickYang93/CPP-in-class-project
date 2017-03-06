/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016

Description: This StrNode class models a string element for a linked list,
             consisting simply of a string value for the node, and a 
             pointer to a next node, (i.e. so that a list can be built).
**************************************************************************/
#include <string>
#include "StrNode.h"
using namespace std;


#ifndef NULL
#define NULL 0
#endif

StrNode::StrNode() {
  setStrNode("", NULL);
}

StrNode::StrNode(string value, StrNode* nextNode){
  setStrNode(value, nextNode);
}

void StrNode::setValue(string value){
  str = value;
}

void StrNode::setNextNode(StrNode* nextNode){
  next = nextNode;
}

void StrNode::setStrNode(string value, StrNode* nextNode){
  setValue(value);
  setNextNode(nextNode);
}

string StrNode::getValue(){
  return str;
}

StrNode* StrNode::getNextNode(){
  return next;
}
