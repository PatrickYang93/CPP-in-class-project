#include "Dog.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

int main(){
	Dog myDog, yourDog; // two instances of Dog
	string feedPlay = "sleep";
	string food = "air";
	int time = 0;

	myDog.setName("Haig");
	myDog.setWeightLB(60);
	myDog.setBreed("Samoyed");
	myDog.setHungeriness(8);

	yourDog.setName("Alissa");
	yourDog.setWeightLB(20);
	yourDog.setBreed("Poodle");
	yourDog.setHungeriness(3);

	cout << setprecision(1) << fixed;

	cout << myDog.getName()     << " is a "
		<< myDog.getBreed()    << " and weight "
		<< myDog.getWeightKG() << " kg.\n";

	while(myDog.hungerStatus() == "normal"){
		while(feedPlay == "sleep"){
			cout << "\nDo you want to feed or play with "
			<< myDog.getName() << "?" << endl;
			cin >> feedPlay;

			if(feedPlay == "feed"){
				cout << "\nChoose steak, cookie or milk to feed: ";
				cin >> food;
				cout << endl;

				myDog.feed(food);

				cout << "...............................................................\n";
				cout << myDog.getName()		<< " ate "
					 << food << " and his hunger is ";
				cout << myDog.getHungriness() << endl;
				cout << myDog.getName()     << " is " 
					 << myDog.hungerStatus() << endl;
				cout << "...............................................................\n";
			}

			else if(feedPlay == "play"){
				cout << "\nHow long do you want to play with "
					 << myDog.getName() << "?(min)\n";
				cin >> time;
				myDog.play(time);
				cout << "...............................................................\n";
				cout << myDog.getName() << "has played with you for " << time << " minutes." << endl;
				cout << "His hunger is " << myDog.getHungriness() << ". He is " << myDog.hungerStatus() << endl;
				cout << "...............................................................\n";
			}
		}
		feedPlay = "sleep";
	}

	feedPlay = "sleep";
	food = "air";
	time = 0;
	cout << endl;

	cout << yourDog.getName()     << " is a "
		<< yourDog.getBreed()    << " and weight "
		<< yourDog.getWeightKG() << " kg.\n";

	while(yourDog.hungerStatus() == "normal"){
		while(feedPlay == "sleep"){
			cout << "\nDo you want to feed or play with "
			<< yourDog.getName() << "?" << endl;
			cin >> feedPlay;

			if(feedPlay == "feed"){
				cout << "\nChoose steak, cookie or milk to feed: ";
				cin >> food;
				cout << endl;

				yourDog.feed(food);

				cout << "...............................................................\n";
				cout << yourDog.getName()		<< " ate "
					 << food << " and her hunger is ";
				cout << yourDog.getHungriness() << endl;
				cout << yourDog.getName()     << " is " 
					 << yourDog.hungerStatus() << endl;
				cout << "...............................................................\n";
			}

			else if(feedPlay == "play"){
				cout << "\nHow long do you want to play with "
					 << yourDog.getName() << "?(min)\n";
				cin >> time;
				yourDog.play(time);
				cout << "...............................................................\n";
				cout << yourDog.getName() << "has played with you for " << time << " minutes." << endl;
				cout << "Her hunger is " << yourDog.getHungriness() << ". She is " << yourDog.hungerStatus() << endl;
				cout << "...............................................................\n";
			}
		}
		feedPlay = "sleep";
	}
	return 0;
}