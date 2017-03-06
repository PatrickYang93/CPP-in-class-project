#ifndef CUBE_H
#define CUBE_H

#include "Box.h"

class Cube : private Box{

private:

public:
  Cube();
  Cube(double l);
  ~Cube();

  void   setLength(double l);
  double getLength();
  double area();
  double volume();
  void   print();

};

#endif
