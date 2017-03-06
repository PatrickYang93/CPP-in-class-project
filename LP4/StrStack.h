/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016
Class Name:        StrStack

Data Members:      None

**************************************************************************/
#include <iostream>
#include <string>
#include "StrIndexed.h"
using namespace std;

#ifndef STRSTACK_H
#define STRSTACK_H

class StrStack : private StrIndexed{
	
public:
	void clear();
	void push(string);
	bool pop(string &);
	bool isEmpty();
	void dump();
};
#endif