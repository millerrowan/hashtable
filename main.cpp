#include <iostream>
#include <vector>
#include <cstring>
#include "node.h"
#include "student.h"

/* Hash Table creates a student list using a hashtable 
   Author: Rowan Miller
   2/8/24
 */

using namespace std;

void add(int &size, Node** &ht, Node* current);
void print(int size, Node** ht);
void Delete(int stored, Node** &ht, int size);
void rehash(int &size, Node** &ht);

int main() {
  
  bool stillPlaying = true; 

  int size = 100;
  
  Node** ht = new Node*[size];
  for(int i = 0; i < size; i++) {
    ht[i] = NULL;
  }

  Node* head = NULL; 
  
  char input[10];
  char input2[20];

  int numofStudents = 0;
  int inputStudents = 0;

  while(stillPlaying == true) {
    cout << "Enter 'ADD', 'PRINT', 'DELETE', or 'QUIT'" << endl;
    
    cin >> input;
    //if user input equals ADD
    if(strcmp(input, "ADD")==0) {

      /*cout << "would you like to enter students manually or randomly generated? Type MANUAL or RANDOM" << endl;
      cin >> input2;

      if(strcmp(input2, "MANUAL")==0) {
	Student* s = new Student();
	cout << "student created" << endl;
	cout << "Enter the first name" << endl;
	char* firstName = new char[20];
	cin >> firstName;
	cout << "Enter the last name" << endl;
	char* lastName = new char[20];
	cin >> lastName;
	cout << "Enter the student id" << endl;
	int id;
	cin >> id;
	cout << "Enter the gpa" << endl;
	float gpa;
	cin >> gpa;
	Node* current = new Node(s);
        numofStudents++;
        add(size, ht, current);
      }
      */
      
      //randomly generated students
      //if(strcmp(input2, "RANDOM")==0) {
	cout << "how many students would you like to add" << endl;
	cin >> inputStudents;

	/* ifstream first;
	ifstream last;
	vector<char*> fn;
	vector<char*> ln; */
	
	for(int i =0; i < inputStudents; i++) {
	  Student* s = new Student(numofStudents);
	  /*  first.open ("FirstNames.txt");
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
	  
	  char* firstName = fn[nn];
	  char* lastName = ln[nn];
	  
	  cout << "first: " << firstName << endl;
	  cout << "last: " << lastName << endl;
	  
	  int id = numofStudents;
	  cout << "id: " << id << endl;
	  
	  float gpa = static_cast <float> (rand()) / static_cast <float> (RAND_MAX/4);
	  
	  cout.precision(2);
	  cout << "gpa: " << gpa << endl; */ 
	  Node* current = new Node(s);
	  numofStudents++;
	  add(size, ht, current);
	}
	// }
    }
    //if user input equals PRINT
    if(strcmp(input, "PRINT")==0) {
      print(size, ht);
    }

    //if user input equals DELETE
    if(strcmp(input, "DELETE")==0) {
      int stored;
      cout << "Type in the student id of the student you want to delete" << endl;
      cin >> stored;
      Delete(stored, ht, size);
    }

    //if user input equals QUIT
    if(strcmp(input, "QUIT")==0) {
      stillPlaying = false; 
    }
  }
}

//adds a student to the hashtable
void add(int &size, Node** &ht, Node* current) {
  
  int hashIndex = (current->getStudent()->getID()) % size; //probably going to say current isn't defined
    

    if(ht[hashIndex] == NULL) {
      ht[hashIndex] = current; 
      ht[hashIndex]->setNext(NULL);
      current->setNext(NULL);
    }
    else if(ht[hashIndex]->getNext() == NULL) {
      ht[hashIndex]->setNext(current);
      ht[hashIndex]->getNext()->setNext(NULL);
      current->setNext(NULL);
    }
    else if(ht[hashIndex]->getNext()->getNext() == NULL) { 
      ht[hashIndex]->getNext()->setNext(current);
      ht[hashIndex]->getNext()->getNext()->setNext(NULL);
      current->setNext(NULL);
      
    }
    else{
      //need to rehash table
      cout << "rehash" << endl;
      size = size*2;
      hashIndex = (current->getStudent()->getID()) % size;
      rehash(size, ht);
    }
  
  //ht[3]->next = new Node; 
  
  
}

//prints out all students in the hashtable	   
void print(int size, Node** ht) {
  cout << "size: " << size << endl;
  for(int i = 0; i < size; i++) {
    Node* temp = ht[i]; 
    while(temp != NULL) {
	cout << temp->getStudent()->getFN() << " " << temp->getStudent()->getLN() << ", " << temp->getStudent()->getID();
	cout.precision(2);
	cout << ", " << temp->getStudent()->getGPA() << endl;
	temp = temp->getNext(); 
    }
  }
}
  
//deletes a student from the hashtable
void Delete(int stored, Node** &ht, int size) {
  int hashIndex =  (stored % size);

  if(ht[hashIndex]->getStudent()->getID() == stored) {
    Node* current = ht[hashIndex]->getNext();
    delete ht[hashIndex];
    ht[hashIndex] = current; 

  }
  else if(ht[hashIndex]->getNext()->getStudent()->getID() == stored){
    Node* current = ht[hashIndex]->getNext()->getNext();
    delete ht[hashIndex]->getNext();
    ht[hashIndex]->setNext(current);
    
  }
  else if(ht[hashIndex]->getNext()->getNext()->getStudent()->getID() == stored) {
    Node* current = ht[hashIndex]->getNext()->getNext()->getNext();
    delete ht[hashIndex]->getNext()->getNext();
    ht[hashIndex]->setNext(current);

  }
  else {
    cout << "there is no student with that id" << endl;

  }
  
  
}

//rehashing the hash table
void rehash(int &size, Node** &ht) {

  Node** temp = new Node*[size]; 
  
  for(int i = 0; i < size; i++) {
    temp[i] = NULL; 
    
  }

  for(int j = 0; j < size/2; j++) {         
    if(ht[j] != NULL) {
      Node* head = ht[j];
      //head->getNext() = NULL; 
      if(head->getNext() != NULL) {
	if(head->getNext()->getNext() != NULL){
	  cout << "ID: " << head->getStudent()->getID() << endl;
	  Node* temp2 = head->getNext()->getNext();
	  add(size, temp, temp2);
	}
	cout << "ID: " << head->getStudent()->getID() << endl;
	Node* temp2 = head->getNext();
	add(size, temp, temp2);
      }
      cout << "ID: " << head->getStudent()->getID() << endl;
      Node* temp2 = head;
      add(size, temp, temp2);
    }
    
  }

  delete ht;
  ht = temp; 
  
}
