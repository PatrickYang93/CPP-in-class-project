/*************************************************************************

Author:				Qiguang Yang
Last Rev. Date:		April 1, 2016
Class Name:			StrQueue

Data Members:		None

**************************************************************************/
#include <iostream>
#include <string>
#include "StrIndexed.h"
using namespace std;

#ifndef STRQUEUE_H
#define STRQUEUE_H

class StrQueue : private StrIndexed{
	
public:
	void clear();
	void enqueue(string);
	bool dequeue(string &);
	bool isEmpty();
	void dump();
};
#endif