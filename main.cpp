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

void add();
void print();
void Delete();
void rehash();

int main() {
  
  bool stillPlaying = true; 

  
  Node** ht = new Node*[size];

  char input[10];

  int numofStudents = 0;

  int size = 100;

  while(stillPlaying == true) {
    cout << "Enter 'ADD', 'PRINT', 'DELETE', 'AVERAGE', or 'QUIT'" << endl;
    
    cin >> input;
    //if user input equals ADD
    if(strcmp(input, "ADD")==0) {
      Student* s = new Student(numofStudents);
      Node* current = new Node(s);
      numofStudents++;
      add();
    }
    //if user input equals PRINT
    if(strcmp(input, "PRINT")==0) {
      print();
    }

    //if user input equals DELETE
    if(strcmp(input, "DELETE")==0) {
      int stored;
      cout << "Type in the student id of the student you want to delete" << endl;
      cin >> stored;
      Delete();
    }
    //if user input equals REHASH
    if(strcmp(input, "REHASH")==0) {
      rehash();
    }

    //if user input equals QUIT
    if(strcmp(input, "QUIT")==0) {
      stillPlaying = false; 
    }
  }
}

//adds a student to the hashtable
void add(int size, Node** ht, Node* current) {
  int input;
  cout << "how many students would you like to add?" << endl;
  cin >> input;
  
  int hashIndex = (s->getID()) % size;

  for (int i = 0; i <= input; i++) {
    
    if(ht[hashIndex] == NULL) {
      ht[hashIndex] = new Node(s);
      ht[hashIndex]->setNext(NULL);
    }
    else if(ht[hashIndex]->getNext() == NULL) {
      Node* temp = new Node(s);
      ht[hashIndex]->setNext(temp);
    }
    else if(ht[hashIndex]->getNext()->getNext() == NULL) {
      Node* temp = new Node(s);
      ht[hashIndex]->getNext()->setNext(temp);
      
    }
    else{
      //need to rehash table
      size = size*2;
      hashIndex = (s->getID()) % size;
      rehash(); 
    }
  }
  
  //ht[3]->next = new Node; 
  
  
}

//prints out all students in the hashtable	   
void print() {
  
}

//deletes a student from the hashtable
void Delete() {
  
}

//rehashing the hash table
void rehash(int size, Node** ht) {

  Node** temp = new Node[size]; 
  
  for(int i = 0; i < size; i++) {
    temp[i] = NULL; 
    
  }

  for(int j = 0; j < size; j++) {         
    if(ht[j] != NULL) {
      Node* head = ht[j];
      if(head->getNext() != NULL) {
	if(head->getNext()->getNext() != NULL){
	  ADD(size, temp, head);
	}
	ADD(size, temp, head);
      }
      ADD(size, temp, head);
    }
    
  }

  
  
}
