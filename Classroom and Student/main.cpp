#include <iostream>
using namespace std;
#include "Classroom.h"

int main() {

  int N;
  cout << "enter classes count\n";
  cin >> N;
  Classroom *classes = new Classroom[N];
  std::string className;
  std::string stName, stLastName;
  int k;

  for (int i = 0; i < N; i++) {
    cout << "enter class name\n";
    cin >> className;
    classes[i].setName(className);
    cout << "enter students count\n";
    cin >> k;
    classes[i].setStudCount(k);
    for (int j = 0; j < k; j++) {
      cout << "enter student name lastname and five marks\n";
      cin >> stName >> stLastName;
      int ms[5] = {0};
      for (int t = 0; t < 5; t++) {
        cin >> ms[t];
      }
      Student s(stName, stLastName, ms);
      classes[i].addStudent(s);
    }
  }
  double maxRate = 0;
  int index = -1;
  for (int i = 0; i < N; i++) {
    double Rate = classes[i].getRate();
    if (Rate > maxRate) {
      index = i;
      maxRate = Rate;
    }
  }
  cout<<classes[index].getName()<< " has the highest rate of all which is "<<maxRate<<"\n";
  
}