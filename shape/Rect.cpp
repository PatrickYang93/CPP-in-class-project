#include <iostream>
#include "Rect.h"

using namespace std; 

/************************************************************
//Default constructor
************************************************************/
Rect::Rect(){
  cout << "Rect default constructor called" << endl;
  length = 0;
  width  = 0;
}

/************************************************************
//Overloaded constructor to set length & width
************************************************************/
Rect::Rect(double l, double w){
  cout << "Rect overloaded constructor called" << endl;
  setDimensions(l, w);
}

/************************************************************
//Destructor
************************************************************/
Rect::~Rect(){
  cout << "Rect Class Destructor Called" << endl;
}

/************************************************************
//set the length and width of the rectangle, ensuring
//non-negative values
************************************************************/
void Rect::setDimensions(double l, double w){
  if (l >= 0)
    length = l;
  else
    length = 0;

  if (w >= 0)
    width = w;
  else
    width = 0;
}

/************************************************************
//return the length of the rectangle
************************************************************/
double Rect::getLength(){
  return length;
}

/************************************************************
//return the width of the rectangle
************************************************************/
double Rect::getWidth(){
  return width;
}

/************************************************************
//return the area of the rectangle
************************************************************/
double Rect::area(){
  return length * width;
}

/************************************************************
//return the perimeter of the rectangle.
************************************************************/
double Rect::perimeter(){
  return 2 * (length + width);
}

/************************************************************
//output the length and width of the rectangle.
************************************************************/
void Rect::print(){
  cout << "Length = "  << length << "; Width = " << width;
}

