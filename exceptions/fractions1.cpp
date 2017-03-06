#include <iostream>
#include <assert.h>
using namespace std;

double division(int a, int b){
  assert(b != 0);
  return (double)a/b;
}

int main(){
  int    x = 0;
  int    y = 0;
  double z = 0;
  

  cout <<"Please enter the numerator: ";
  cin >> x;
  cout <<"Please enter the denominator: ";
  cin >> y;
  
  z = division(x, y);
  
  cout << "Fraction to decimal: ";
  cout << z << endl;
  
  return 0;
}
