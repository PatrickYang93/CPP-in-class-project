#ifndef SQUARE_H
#define SQUARE_H

#include "Rect.h"

class Square : private Rect{
private:

public:
  Square();
  Square(double s);
  ~Square();

  void   setLength(double s);
  double getLength();
  double area     ();
  double perimeter();
  void   print    ();
};

#endif
