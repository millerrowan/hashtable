#include <iostream>
#include <vector>
#include <cstring>
#include "node.h"
#include "student.h"

/* Hash Table creates a student list using a hashtable 
   Author: Rowan Miller
   1/9/24
 */

using namespace std;

void add(int size, Node** ht, Node* current);
void print(int size, Node** ht);
void Delete(int stored, Node** ht, int size);
void rehash(int size, Node** &ht);

int main() {
  
  bool stillPlaying = true; 

  int size = 10;
  
  Node** ht = new Node*[size];
  for(int i = 0; i < size; i++) {
    ht[i] = NULL:
  }

  Node* head = NULL; 
  
  char input[10];

  int numofStudents = 0;
  int inputStudents = 0;

  while(stillPlaying == true) {
    cout << "Enter 'ADD', 'PRINT', 'DELETE', or 'QUIT'" << endl;
    
    cin >> input;
    //if user input equals ADD
    if(strcmp(input, "ADD")==0) {

      cout << "how many students would you like to add" << endl;
      cin >> inputStudents;

      for(int i =0; i < inputStudents; i++) {
      Student* s = new Student(numofStudents);
      Node* current = new Node(s);
      numofStudents++;
      add(size, ht, current);
      }
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
void add(int size, Node** &ht, Node* current) {
  
  int hashIndex = (current->getStudent()->getID()) % size; //probably going to say current isn't defined
    
    if(ht[hashIndex] == NULL) {
      ht[hashIndex] = current; 
      ht[hashIndex]->setNext(NULL);
    }
    else if(ht[hashIndex]->getNext() == NULL) {
      ht[hashIndex]->setNext(current);
      ht[hashIndex]->getNext()->setNext(NULL);
    }
    else if(ht[hashIndex]->getNext()->getNext() == NULL) {
      cout << "3rd else if" << endl; 
      ht[hashIndex]->getNext()->setNext(current);
      ht[hashIndex]->getNext()->getNext()->setNext(NULL);
      
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
  int hashIndex =  (current->getStudent()->getID()) % size;

  if(ht[hashIndex]->getID() == stored) {
    Node* current = ht[hashIndex]->getNext();
    delete ht[hashIndex]; 

  }
  else if(ht[hashIndex]->getNext()->getID() == stored){

  }
  else if(ht[hashIndex]->getNext()->getNext()->getID() == stored) {
    

  }
  else {
    cout << "there is no student with that id" << endl;

  }
  
  
}

//rehashing the hash table
void rehash(int size, Node** &ht) {

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
	  add(size, temp, head);
	}
	add(size, temp, head);
      }
      add(size, temp, head);
    }
    
  }

  delete ht;
  ht = temp; 
  
}
