#include "Classroom.h"

Classroom::Classroom() : students(nullptr), studMaxCount(0), studCount(0) {}

std::string Classroom::getName() const { return className; }

void Classroom::setName(const std::string &n) { className = n; }
void Classroom::setStudCount(int n) {
  studMaxCount = n;
  students = new Student[n];
}
void Classroom::addStudent(const Student &s) {

  if (studCount < studMaxCount) {
    students[studCount].setName(s.name);
    students[studCount].setLastName(s.lname);
    for (int i = 0; i < 5; i++) {
      students[studCount].marks[i] = s.marks[i];
    }
    studCount++;
  }
}

double Classroom::getRate(){
  double r = 0;
  for(int i = 0;i < studCount;i++){
    r += students[i].getMarksSum();
  }
  return r / studCount;
}