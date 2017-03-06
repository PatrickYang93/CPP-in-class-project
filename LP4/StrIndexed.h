/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016
Class Name:        StrIndexed

Data Members:      length  (int)   - number of elements in the list

**************************************************************************/
#include <iostream>
#include <string>
#include "StrLL.h"
using namespace std;

#ifndef STRINDEXED_H
#define STRINDEXED_H

class StrIndexed : public StrLL {

 private:
	int length;

 public:

	StrIndexed();
	int numElements();
	bool insertAt(int,string);
	bool removeAt(int,string &);
	int  posInList(string);
	void clear();
	void dump(bool printLen = false);

};
#endif
 