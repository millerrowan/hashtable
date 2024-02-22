#include <iostream>
#include "student.h"
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;
//random student
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

          id = numofStudents;
          cout << "id: " << id << endl;

          gpa = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/4);
 
}
//manual student
Student::Student() {
  cout << "enter a first name" << endl;
  firstName = new char[20];
  cin >> firstName;
  cout << "enter a last name" << endl;
  lastName = new char[20];
  cin >> lastName;
  cout << "enter an id" << endl;
  cin >> id;
  cout << "enter a gpa" << endl;
    cin >> gpa; 

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
