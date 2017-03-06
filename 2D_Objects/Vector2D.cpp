//multiplication table
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
  int h;
  int w;
  vector<vector<int> > table;

  cout << "Please enter how many rows (i.e. the height)\n"
       << "of your multiplication table: ";
  cin  >> h;
  cout << endl;

  cout << "Please enter how many columns (i.e. the width)\n"
       << "of your multiplication table: ";
  cin  >> w;
  cout << endl;
 
  //resize the vector to height h
  table.resize(h);
 
  //each row vector element will now be its
  //own vector (creating a vector of vector,
  //typically referred to as a 2D vector)
  for(int row = 0; row < h; row++){
    table[row].resize(w);
  }

  //initialize each table element
  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      //note that the +1 on row and col is just so
      //the numbers in the table go from 1 to n
      //instead of 0 to n-1
      table[row][col] = (row + 1) * (col + 1);
    }
  }
 
  //print the table
  for(int row = 0; row < h; row++){
    for(int col = 0; col < w; col++){
      cout << setw(5) << table[row][col];
    }
    cout << endl << endl;
  }

  cout << endl;
  return 0;
}
