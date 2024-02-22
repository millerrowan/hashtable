#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

class Student {
 public:
  Student(int numofStudents);
  Student(); 
  ~Student();
  char* getFN();
  char* getLN();
  int getID();
  float getGPA();
  
 protected:
  char* firstName;
  char* lastName;
  int id;
  float gpa;
   ifstream first;
  ifstream last;
  vector<char*> fn;
   vector<char*> ln;
};
#endif
