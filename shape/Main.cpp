#include <iostream>                                  
#include <iomanip>                                   
#include "Rect.h"                                 
#include "Box.h" 
#include "Square.h" 
#include "Cube.h"

using namespace std;   

int main(){

  Rect   R;
  Box    B;
  Square S;
  Cube   C;

  R.setDimensions(4, 5);
  B.setDimensions(10,4,8);  
  B.Rect::setDimensions(4, 5);

  //S.setDimensions(4, 5);
  //B.setDimensions(4, 5, 6);

  cout << "Rect   : ";
  R.print();
  cout << endl;

  cout << "Box    : ";
  B.print();
  cout << endl;

  cout << "Square : ";
  S.print(); 
  cout << endl;

  cout << "Cube : ";
  C.print(); 
  cout << endl;

  return 0;                                              
}  

