#include "Dog.h"
#include <string>
#include <iostream>
using namespace std;

Dog::Dog(){ 
    name   = "No Name"; 
    weight = -1;
	breed  = "Mutt";
	hungeriness = 0;
	food   = "air";
	status = "normal";
}

void	Dog::setName(string s)	   { name = s; }
    
string	Dog::getName()	   { return name; }
    
void	Dog::setWeightLB(double w) { weight = w; }

double	Dog::getWeightLB() 	   { return weight; }
    
void	Dog::setWeightKG(double w) { weight = (w * 2.2); }
    
double	Dog::getWeightKG() 	   { return (weight / 2.2); }

void	Dog::setBreed(string b) { breed = b; }
	
string	Dog::getBreed()  { return breed; }

void	Dog::setHungeriness(int h) { hungeriness = h; }

void Dog::feed(string food){
	if(food == "steak"){
		hungeriness += 5;
	}

	else if(food == "cookie"){
		hungeriness += 3;
	}

	else if(food == "milk"){
		hungeriness += 1;
	}
}

int  Dog::getHungriness(){
	return hungeriness; 
}

string	Dog::hungerStatus(){

	if(hungeriness > 10){
		status = "sickly overfed! Game Over!";
	}

	if(hungeriness < 0){
		status = "starving! Game Over!";
	}

	return status;
}

void	Dog::play(int t) { 
	hungeriness = hungeriness - t/10;
}
