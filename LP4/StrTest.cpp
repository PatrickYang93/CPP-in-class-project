/*************************************************************************

Author:            Qiguang Yang
Last Rev. Date:    April 1, 2016

Description:       Testing file for StrIndexed, StrStack, StrQueue, and
                   StrSet clases
 
**************************************************************************/

#include <iostream>
#include <string>
#include "StrLL.h"
#include "StrStack.h"
#include "StrQueue.h"
#include "StrSet.h"
#include "StrIndexed.h"
using namespace std;

int main(){

  string v;

  //StrIndexed Testing
  /////////////////////////////////////
  cout << "\n\n--StrIndexed Testing--\n\n";
  StrIndexed I;
  I.insertAt(0, "car");
  I.insertAt(0, "par");
  I.insertAt(0, "tar");
  I.insertAt(0, "scar");
  I.insertAt(0, "car");
  I.insertAt(0, "bar");
  I.insertAt(0, "far");
  I.dump(1);
  cout << endl << endl;

  I.removeAt(0, v);
  cout << " " << v << " removed at index 0" <<endl;
  I.dump(true);
  cout << endl << endl;;

  if(I.removeAt(5, v)){ 
    cout << "\'true\' bool return worked properly on this test" << endl;
  }
  else{
    cerr << "\'true\' bool return test failed!\n";   
  } 
  cout << " " << v << " removed at index 5" << endl;
  cout << endl;

  if(I.removeAt(6, v)){
    cerr << "\'false\' bool return test failed!\n"; 
  }
  else{  
    cout << "\'false\' bool return worked properly on this test" << endl;
  } 
  cout << " " << v << " removed, attempted at index 6" << endl;
  cout << endl;

  cout << "Current list:" << endl;
  I.dump(1);
  cout << endl << endl;

  I.insertAt(2,"LOOK A LEPRECHAUN! GRAB THE GOLD!");
  I.dump(true);
  cout << endl;

  I.removeAt(2, v);
  I.insertAt(2,"OH NO HE GOT AWAY!");
  I.dump(true);
  cout << endl << endl;

  I.removeAt(2, v);
  cout << "When passing 'true' to StrIndexed's dump function, "
       << "\nthe number of elements in the list should be displayed:" << endl;
  I.dump(true);
  cout << endl << endl;
  cout << "When passing 'false' , or no argument at all, to StrIndexed's dump function, "
       << "\nthe number of elements in the list should NOT be displayed:" << endl;
  I.dump(false);
  cout << endl;
  I.dump();
  cout << endl << endl;

   
  I.clear();
  cout << "List cleared" << endl;
  I.dump(true);
  cout << endl;

  I.removeAt(0, v);
  cout << "Empty list. " << v << " removed." << endl;

  I.removeAt(-1, v);

  cout << "Empty list. " << v << " removed." << endl;

  cout << "\n--End StrIndexed Testing--\n\n";
  /////////////////////////////////////

  //StrStack Testing
  /////////////////////////////////////
  cout << "\n\n--StrStack Testing--\n\n";
  StrStack Stack;
  Stack.push("how");
  Stack.push("now");
  Stack.push("brown");
  Stack.push("cow");
  Stack.push("how");
  Stack.push("now");
  Stack.push("brown");
  Stack.push("cow");
  Stack.dump();
  Stack.pop(v);
  cout << endl << v <<" was popped\n";
  Stack.dump();
  Stack.pop(v);
  cout << endl << v <<" was popped\n";
  Stack.dump();
  Stack.pop(v);
  cout << endl << v <<" was popped\n";
  Stack.dump();

  if(Stack.pop(v)){
    cout << endl << v <<" was popped\n";
    Stack.dump();
  }
  else{
    cerr << "pop(v) (\'true\' return) test failed" << endl;
  }
  
  cout << "\nPushing sow to the top:" << endl;
  Stack.push("sow");
  Stack.dump();
  cout << endl;
  
  if(!Stack.isEmpty()){
    Stack.clear();
    cout << endl << "Stack cleared!\n";
  }
  else{
    cerr << "isEmpty() (\'false\' return) test failed" << endl;
  } 

  if(Stack.isEmpty()){
    if(!Stack.pop(v)){
      cout <<  v <<" was popped\n";
      Stack.dump();
    }
    else{
      cerr << "pop(v) (\'false\' return) test failed" << endl;
    }
  }
  else{
    cout << "isEmpty() (\'true\' return) test failed" << endl;
  } 

  cout << "\n\n--End StrStack Testing--\n\n";
  /////////////////////////////////////

  //StrQueue Testing
  /////////////////////////////////////
  cout << "\n\n--StrQueue Testing--\n\n";
  StrQueue Queue;
  Queue.enqueue("how");
  Queue.enqueue("now");
  Queue.enqueue("brown");
  Queue.enqueue("cow");
  Queue.enqueue("how");
  Queue.enqueue("now");
  Queue.enqueue("brown");
  Queue.enqueue("cow");
  Queue.dump();
  Queue.dequeue(v);
  cout << endl << v <<" was dequeued\n";
  Queue.dump();
  Queue.dequeue(v);
  cout << endl << v <<" was dequeued\n";
  Queue.dump();
  Queue.dequeue(v);
  cout << endl << v <<" was dequeued\n";
  Queue.dump();

  if(Queue.dequeue(v)){
    cout << endl << v <<" was dequeued\n";
    Queue.dump();
  }
  else{
    cerr << "dequeue(v) (\'true\' return) test failed" << endl;
  }
    
  cout << "\nEnqueueing sow at the back:" << endl;
  Queue.enqueue("sow");
  Queue.dump();
  cout << endl;

  if(!Queue.isEmpty()){
    Queue.clear();
    cout << endl << "Queue cleared!\n";
  }
  else{
    cerr << "isEmpty() (\'false\' return) test failed" << endl;
  } 

  if(Queue.isEmpty()){
    if(!Queue.dequeue(v)){
      cout <<  v <<" was dequeued\n";
      Queue.dump();
    }
    else{
      cerr << "dequeue(v) (\'false\' return) test failed" << endl;
    }
  }
  else{
    cerr << "isEmpty() (\'true\' return) test failed" << endl;
  } 

  cout << "\n\n--End StrQueue Testing--\n\n";
  /////////////////////////////////////

  //StrSet Testing
  /////////////////////////////////////
  cout << "\n\n--StrSet Testing--\n\n";
  StrSet S1, S2, S3, S4, S5, S6;

  cout << "Set Insert (no duplicates) Test: " << endl;
  S1.insert("D");
  S1.insert("D");
  S1.insert("Y");
  S1.insert("N");
  S1.insert("A");
  S1.insert("M");
  S1.insert("I");
  S1.insert("C");
  S1.insert("D");
  S1.insert("Y");
  S1.insert("N");
  S1.insert("A");
  S1.insert("M");
  S1.insert("I");
  S1.insert("C");
  S1.insert("C");
  cout << S1 << endl;

  cout << "\nCopy Constructor Test: " << endl;
  StrSet Test = S1;
  Test.insert("S");
  Test.remove("D");
  cout << "S1:   " << S1   << endl;
  cout << "Test: " << Test << endl;

  cout << "\nAssignment Operator Test: " << endl;
  Test = S1;
  Test.remove("D");
  Test.remove("N");
  Test.remove("C");
  Test.insert("O");
  cout << "S1:   " << S1   << endl;
  cout << "Test: " << Test << endl;
    
  S2.insert("C");
  S2.insert("A");
  S2.insert("R");
  S2.insert("D");

  cout << "\nUnion Tests: " << endl;
  Test = S1 + S2;
  cout << "S1:   " << S1   << endl;
  cout << "S2:   " << S2   << endl;
  cout << "Test S1 + S2: " << Test << endl;
  cout << "---" << endl;
  Test = S2 + S1;
  cout << "S1:   " << S1   << endl;
  cout << "S2:   " << S2   << endl;
  cout << "Test S2 + S1: " << Test << endl;

  cout << "\nIntersection Tests: " << endl;
  Test = S1 * S2;
  cout << "S1:   " << S1   << endl;
  cout << "S2:   " << S2   << endl;
  cout << "Test S1 * S2: " << Test << endl;
  cout << "---" << endl;
  Test = S2 * S1;
  cout << "S1:   " << S1   << endl;
  cout << "S2:   " << S2   << endl;
  cout << "Test S2 * S1: " << Test << endl;

  cout << "\nDifference Tests: " << endl;
  Test = S1 - S2;
  cout << "S1:   " << S1   << endl;
  cout << "S2:   " << S2   << endl;
  cout << "Test S1 - S2: " << Test << endl;
  cout << "---" << endl;
  Test = S2 - S1;
  cout << "S1:   " << S1   << endl;
  cout << "S2:   " << S2   << endl;
  cout << "Test S2 - S1: " << Test << endl;

  
  cout << "\nQuick insert and remove test:" << endl;

  cout << "\nS5 should be empty. Let's make sure...";
  cout << "\nisEmpty should be true on a list that doesn't have anything in it "
       << "(will output 1 if correct): " << S5.isEmpty();
  cout << "\nTwo dots (an empty list) should be printed: " << S3 << endl;  
  
  S3.insert("I");
  S3.insert("am");
  S3.insert("Sam");
  S3.remove("I");
  S3.remove("am");
  S3.remove("Sam");

  cout << "\nS3 should be empty. Let's make sure...";
  cout << "\nisEmpty should be true on a list which has had everything removed " 
       << "(will output 1 if correct): " << S3.isEmpty();
  cout << "\nTwo dots (an empty list) should be printed: " << S3 << endl;
  
  S3.insert("I");
  S3.insert("am");
  S3.insert("Sam");
  S3.insert("Sam");
  S3.insert("I");
  S3.insert("am");
    
  S4.insert("That");
  S4.insert("Sam");
  S4.insert("I");
  S4.insert("am");
  S4.insert("That");
  S4.insert("Sam");
  S4.insert("I");
  S4.insert("am");
  S4.insert("I");
  S4.insert("do");
  S4.insert("not");
  S4.insert("like");
  S4.insert("that");
  S4.insert("Sam");
  S4.insert("I");
  S4.insert("am");

  cout << "\nNew Lists: " << endl;
  cout << "S3:   " << S3   << endl;
  cout << "S4:   " << S4   << endl;


  cout << "\nEquality and subset Tests: " << endl;
  cout << "S3 <= S4:   " << (S3 <= S4)  << endl;
  cout << "S3 == S3:   " << (S3 == S3)  << endl;
  cout << "S3 <= S3:   " << (S3 <= S3)  << endl;
  cout << "S5 <= S6:   " << (S5 <= S6)  << endl;
  cout << "S5 == S6:   " << (S5 == S6)  << endl;
  cout << "S5 <= S3:   " << (S5 <= S3)  << endl;
  cout << "S3 == S4:   " << (S3 == S4)  << endl;
  cout << "S3 >= S4:   " << (S3 >= S4)  << endl;
  cout << "S3 >= S4:   " << (S3 >= S4)  << endl;
  cout << "S1 <= S2:   " << (S1 <= S2)  << endl;
  cout << "S5 >= S1:   " << (S5 >= S1)  << endl;
  
  cout << "\nClear the lists: " << endl;
  S1.clear();
  S2.clear();
  S3.clear();
  S4.clear();
  Test.clear();
  cout << "S1:   " << S1   << endl;
  cout << "S2:   " << S2   << endl;
  cout << "S3:   " << S3   << endl;
  cout << "S4:   " << S4   << endl;
  cout << "Test: " << Test << endl;

  cout << "\n\n--End StrSet Testing--\n\n";
  /////////////////////////////////////
  cout << "\n-- END TESTING --\n";
 
  return 0;
}

