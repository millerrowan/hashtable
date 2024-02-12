#include <iostream>
#include "student.h"
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

Student::Student(int numofStudents) {
  first.open ("FirstNames.txt");
  // first >> skipws;
  last.open("LastNames.txt");
          //last >> skipws;

          for(int l = 3897; l > 0; l--){
            char* tmp = new char[20];
            first >> tmp;
            fn.push_back(tmp);
            //cout << tmp << endl;
            char* temp = new char[20];
            last >> temp;
            ln.push_back(temp);
            //cout << temp << endl;
          }
          int nn = 0 + (rand() % 3897);

          firstName = fn[nn];
          lastName = ln[nn];

          cout << "first: " << firstName << endl;
          cout << "last: " << lastName << endl;

          id = numofStudents;
          cout << "id: " << id << endl;

          gpa = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/4);

          cout.precision(2);
          cout << "gpa: " << gpa << endl; 
}

Student::~Student() {
  delete firstName;
  delete lastName;
}

char* Student::getFN() {
  return firstName;
}

char* Student::getLN() {
  return lastName;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa; 
}
