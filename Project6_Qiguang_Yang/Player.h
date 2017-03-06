#ifndef Player_HEADER
#define Player_HEADER

#include <string>
using namespace std;

class Player{

  public:

///////////////////////
	char	symbol;  //		This two values should be private. But I do not know how to use them as Player array 
	int		pos;     //		in Game.cpp "printGameBoard" function.
///////////////////////		I made them as public value so that I can use them in Game.cpp

	Player();
	void	setSymbol(char s);	
	char	getSymbol();
	void	setPos(int p);
	int		getPos();
};

#endif