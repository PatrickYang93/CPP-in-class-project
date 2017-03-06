#include <iostream>
#include <stdexcept>
#include <math.h>
using namespace std;

unsigned int multiply(unsigned int a, unsigned int b){
  if(pow(256, sizeof(int))/a < b){
    throw overflow_error("Overflow exception");
  }
  return a * b;
}

int main(){
  unsigned int x = 0;
  unsigned int y = 0;
  unsigned int z = 0;

  bool valid;
  
  do{
    try{
      valid = true;
      cout << "Please enter the first number: ";
      cin  >> x;
      cout << "Please enter the second number: ";
      cin  >> y;
      
      z = multiply(x, y);
      
      cout << "Multiplied value: ";
      cout << z << endl;
    }
    catch(exception &e) {
      cerr << "Exception caught: " << e.what() << '\n';
      valid = false;
    }
  }
  while(!valid);
  
  return 0;
}
