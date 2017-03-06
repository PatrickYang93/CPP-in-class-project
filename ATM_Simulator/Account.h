#include <string>
using namespace std;

class Account{
	private:
		string name;
		int amount;
	
public:
	Account();
	void	setName(string);
	string	getName();
	void	deposit(double);
	void	withdraw(double);
	int		getBalance();
	void	display();
};