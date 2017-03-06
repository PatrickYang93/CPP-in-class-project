#ifndef RECT_H
#define RECT_H

class Rect{
private:
  double length;
  double width;

public:
  Rect();
  Rect(double l, double w);
  ~Rect();

  void   setDimensions(double l, double w);
  double getLength();
  double getWidth(); 
  double area();
  double perimeter();
  void   print();
};


#endif
