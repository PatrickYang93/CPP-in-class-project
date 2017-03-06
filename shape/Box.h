#ifndef BOX_H
#define BOX_H

#include "Rect.h"

class Box : public Rect{

private:
  double height;

public:
  Box();
  Box(double l, double w, double h);
  ~Box();

  void   setDimensions(double l, double w, double h);
  double getHeight();
  double area();
  double volume();
  void   print();

};

#endif
