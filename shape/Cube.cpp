#include <iostream>
#include "Cube.h"  
using namespace std;

/************************************************************
//Default constructor (calls Box's default 
//constructor to set length & width each to 0)
************************************************************/
Cube::Cube():Box(){
  cout << "Cube default constructor called" << endl;
}

/************************************************************
//Overloaded constructor (calls Rect's overloaded 
//constructor to set length & width based on l and w)
************************************************************/
Cube::Cube(double l):Box(l, l, l){ 
  cout << "Cube overloaded constructor called" << endl;
}

/************************************************************
//Destructor
************************************************************/
Cube::~Cube(){
  cout << "Cube Class Destructor Called" << endl;
}

/************************************************************
//Set the dimensions of the Cube (calls Box's setDimensions 
//function to set length, width, and height based on l)
************************************************************/
void Cube::setLength(double l){
}

/************************************************************
//returns height of the Cube
************************************************************/
double Cube::getLength(){
}

/************************************************************
//returns the surface area of the Cube
************************************************************/
double Cube::area(){
}

/************************************************************
//returns the volume of the Cube
************************************************************/
double Cube::volume(){
}

/************************************************************
//Prints the length, width, and height of the Cube
************************************************************/
void Cube::print(){
}


