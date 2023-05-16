// #include "Shape.h"
#include "Square.h"
#include "Triangle.h"
#include <iostream>

int main() {

  const int size = 5;
  Shape *shape_ptr_arr[size];
  Square k (1.5);
  shape_ptr_arr[0] = new Square(1.1);
  shape_ptr_arr[1] = new Square(2.2);
  shape_ptr_arr[2] = new Triangle(4, 5, 3);
  shape_ptr_arr[3] = new Triangle(30, 40, 50);
  shape_ptr_arr[4] = new Triangle(15, 25, 30);

  for (int i = 0; i < size; i++) {
    std::cout << shape_ptr_arr[i]->getArea() << std::endl;
  }
  for (int i = 0; i < size; i++) {
    delete shape_ptr_arr[i];
  }
}