#include <string>
using namespace std;

class Dog{
  private:
    	string name;
    	double weight; // in pounds
		string breed;
		int hungeriness;
		string food;
		string status;
		//int time;

  public:
	Dog();
    void   setName(string s); 
    string getName(); 
    void   setWeightLB(double w);
   	double getWeightLB();
	void   setWeightKG(double w);
    double getWeightKG();
	void   setBreed(string b);
	string getBreed();
	void   setHungeriness(int h);
	void   feed(string f);
	int	   getHungriness();
	string hungerStatus();
	void   play(int t);
};

