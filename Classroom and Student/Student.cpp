#include "Student.h"

Student::Student(const std::string &n, const std::string &ln, int *m)
    : name(n), lname(ln) {

  for (int i = 0; i < 5; i++) {
    if (m == nullptr) {
      marks[i] = 0;
    } else {
      marks[i] = m[i];
    }
  }
}

void Student::setName(const std::string &s) { name = s; }
void Student::setLastName(const std::string &s) { lname = s; }

int Student::getMarksSum() const{
  int sum = 0;
  for(int i = 0;i < 5;i++){
    sum += marks[i];
  }
  return sum;
}