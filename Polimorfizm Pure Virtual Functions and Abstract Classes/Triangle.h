#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include <cmath>
#include <iostream>

class Triangle : public Shape {
public:
  Triangle(const double s1, const double s2, const double s3)
      : a(s1), b(s2), c(s3) {}
  virtual ~Triangle() { std::cout << "Triangle dtor\n"; }
  virtual double getArea() {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

private:
  double a;
  double b;
  double c;
};

#endif