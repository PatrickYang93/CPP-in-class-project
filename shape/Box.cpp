#include <iostream>
#include "Rect.h"
#include "Box.h"  
using namespace std;

/************************************************************
//Default constructor (calls Rect's default 
//constructor to set length & width each to 0)
************************************************************/
Box::Box():Rect(){
  cout << "Box default constructor called" << endl;
  height = 0;
}

/************************************************************
//Overloaded constructor (calls Rect's overloaded 
//constructor to set length & width based on l and w)
************************************************************/
Box::Box(double l, double w, double h):Rect(l, w){
  cout << "Box overloaded constructor called" << endl; 
  if(h >= 0){
    height = h;
  }
  else{
    height = 0;
  }
}

/************************************************************
//Destructor
************************************************************/
Box::~Box(){
  cout << "Box Class Destructor Called" << endl;
}

/************************************************************
//Set the dimensions of the box (calls Rect's setDimensions 
//function to set length & width based on l and w)
************************************************************/
void Box::setDimensions(double l, double w, double h){
  Rect::setDimensions();
    if(h>=0){
      height = h;
    }
    else{
      height = 0
    }
}

/************************************************************
//returns height of the box
************************************************************/
double Box::getHeight(){
  return height;
}

/************************************************************
//returns the surface area of the box
************************************************************/
double Box::area(){
  return 2 * (getLength() * getWidth()
	      + getLength() *getHeight()
	      + getWidth() * getHeight());
}

/************************************************************
//returns the volume of the box
************************************************************/
double Box::volume(){
  return Rect::area() * height;
}

/************************************************************
//Prints the length, width, and height of the box
************************************************************/
void Box::print(){
  cout << " Height = " << height;
  cout << " Length = " << length;
  cout << " Width = " << width;
}


