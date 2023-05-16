#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include <iostream>

class Square:public Shape {
public:
  Square(double s) : a(s){};
  virtual ~Square() {std::cout<<"Square dtor\n";}
  virtual double getArea() { return a * a; }

private:
  double a;
};

#endif