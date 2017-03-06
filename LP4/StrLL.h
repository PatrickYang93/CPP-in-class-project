/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016
Class Name:        StrLL

Data Members:      Head (StrNode*) - Pointer to first (head) node in a 
                                     linked list of strings

**************************************************************************/
#ifndef STRLL_H
#define STRLL_H
#include <string>
#include "StrNode.h"
using namespace std;

class StrLL{
 protected:
  StrNode* Head;
  
 public:
  StrLL();
  ~StrLL();
  StrLL(const StrLL &s);
  void operator=(const StrLL &s);
  void clear();
  bool insertAt(int pos, string value);
  bool removeAt(int pos, string &value);
  bool removeAt(int pos);
  int  posInList(string value);
  void dump();
};

#endif
