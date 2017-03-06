//multiplication table
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int h;
  int w;
  int **table;

  cout << "Please enter how many rows (i.e. the height)\n"
       << "of your multiplication table: ";
  cin  >> h;
  cout << endl;

  cout << "Please enter how many columns (i.e. the width)\n"
       << "of your multiplication table: ";
  cin  >> w;
  cout << endl;

  //create a new array of pointers of size h
  table = new int*[h];
 
  //each row array element will now be its
  //own array (creating an array of arrays,
  //typically referred to as a  2D array)
  for(int row = 0; row < h; row++){
    table[row] = new int[w];
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

  //now to do the proper cleanup...
  //this would belong in a destructor if
  //the 2D array was a member of a class

  //delete each row array
  for(int row = 0; row < h; row++){
    delete[] table[row];
  }
  //delete the array
  delete[] table;

  cout << endl;
  return 0;
}
