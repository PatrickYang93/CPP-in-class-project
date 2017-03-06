/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016
Class Name:        StrNode

Data Members:      str  (string)   - value of the string node
                   next (StrNode*) - pointer to the next node in a list 
                                     (NULL if pointing to nothing)
**************************************************************************/
#ifndef STRNODE_H
#define STRNODE_H

#include <string>
using namespace std;

class StrNode {
 private:
  string str;
  StrNode* next;

 public:
  StrNode();
  StrNode(string value, StrNode* nextNode);

  void     setValue(string value);
  void     setNextNode(StrNode* nextNode);
  void     setStrNode(string value, StrNode* nextNode);
  string   getValue();
  StrNode* getNextNode();
};

#endif
