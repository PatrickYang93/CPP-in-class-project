#include <iostream>
#include "Square.h"

using namespace std; 

/************************************************************
//Default constructor
************************************************************/
Square::Square():Rect(){
  cout << "Square default constructor called" << endl;
}

/************************************************************
//Overloaded constructor to set length
************************************************************/
Square::Square(double s):Rect(s,s){
  cout << "Square overloaded constructor called" << endl;
}

/************************************************************
//Destructor
************************************************************/
Square::~Square(){
   cout << "Square Class Destructor Called" << endl;
}

/************************************************************
//set the length and width of the square
************************************************************/
void Square::setLength(double s){
  Rect::setDimensions(s,s);
}

/************************************************************
//return the edge length of the square
************************************************************/
double Square::getLength(){
  return Rect::getLength();
}

/************************************************************
//return the area of the Square
************************************************************/
double Square::area(){
  return Rect::area();
}

/************************************************************
//return the perimeter of the Square
************************************************************/
double Square::perimeter(){
  return Rect::perimeter();
}

/************************************************************
//output the length and width of the Square
************************************************************/
void Square::print(){
}

