#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student {

public:
  Student(const std::string &n = "", const std::string &ln = "",
          int *m = nullptr);
  int getMarksSum() const;
  void setName(const std::string &);
  void setLastName(const std::string &);

public:
  std::string name;
  std::string lname;
  int marks[5];
};

#endif