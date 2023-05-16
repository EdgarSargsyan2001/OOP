#ifndef CLASSROOM_H
#define CLASSROOM_H
#include "Student.h"
#include <string>

class Classroom {

public:
  Classroom();

  std::string getName() const;
  double getRate();
  void setName(const std::string &n);
  void setStudCount(int n);
  void addStudent(const Student &s);

protected:
  std::string className;
  Student *students;
  int studMaxCount;
  int studCount;
};

#endif