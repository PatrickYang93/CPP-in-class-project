#include <iostream>
using namespace std;

double division(int a, int b){
  if(b == 0){
    throw "Division by zero condition!";
  }
  return (double)a/b;
}

int main(){
  int    x = 0;
  int    y = 0;
  double z = 0;
  
  try{
    cout <<"Please enter the numerator: ";
    cin >> x;
    cout <<"Please enter the denominator: ";
    cin >> y;

    z = division(x, y);

    cout << "Fraction to decimal: ";
    cout << z << endl;
  }
  catch (const char* msg) {
    cerr << msg << endl;
  }
  
  return 0;
}
