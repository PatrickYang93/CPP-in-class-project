/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016
Class Name:        StrSet

Data Members:      None

**************************************************************************/
#include <iostream>
#include <string>
#include "StrLL.h"
#include "StrNode.h"

using namespace std;

class StrSet : public StrLL {

public:
	StrSet();
	~StrSet();
	StrSet(const StrSet &);
	void	operator= (const StrSet &);
	bool    insert(string);
	bool	remove(string);
	bool	isEmpty();
	friend	ostream &operator<<(ostream &out, const StrSet &);
	StrSet	operator+ (const StrSet &) const;
	StrSet	operator* (const StrSet &) const;
	StrSet	operator- (const StrSet &) const;
	bool	operator<=(const StrSet &) const;
	bool	operator>=(const StrSet &) const;
	bool	operator==(const StrSet &) const;
};