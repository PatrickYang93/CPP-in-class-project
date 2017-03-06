#include <iostream>
using namespace std;

int main(){
  int x = 0;
  cin >> x;
 
  while (!(cin >> x)) {
    cerr << "you entered a non-digit character\n";
    cin.clear();   // reset the error flag
    cin.ignore();  // ignore the offending character
  }

  cout << "Value is: " << x << endl;
  
  return 0;
}
