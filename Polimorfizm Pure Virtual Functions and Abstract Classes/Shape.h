#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
//  Abstract Class

class Shape {
public:
  virtual ~Shape() {std::cout<<"shape dtor\n";}
  virtual double getArea() = 0;
};

#endif