#include <string>
#include "Player.h"
using namespace std;

class Game{
	private:
		int					turn;
		static const int NUMROWS = 15;
		static const int NUMCOLS = 10;
		static const int WINPOS  = 142;

	public:
		Game();
		void printGameHeader();
		bool checkTraps(int &p);
		bool checkTrampolines(int &p);
		void printGameBoard(Player P[], int n);
		int  rollDice();
		void movePlayer(int &p, string &x, int dice);
		int  getTurn();
		void nextTurn();
		void printWinner(char name);
		bool noWinner(int p);
};