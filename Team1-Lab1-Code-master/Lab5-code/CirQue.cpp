//Group 1: Ben Cohen, Alex Budke, Jose Banda.
//written by Alex Budke and Ben Cohen


//Group 1: Ben Cohen, Alex Budke, Jose Banda. //10/5/2016
//Written by Ben Cohen


/* Psuedocode
    1. declare variables
    2. Print intro
    3. do while input is not Q
      1. take input
      2. E: enqueue
      3. D: dequeue
      4. S: show queue
      5. Q: quit
    
    Create class
    1. private variables
    2. public methods
      1. Enqueue
      2. Dequeue
      3. isEmpty
      4. isFull
      5. printQueue
*/
#include <iostream>
#include "Que.h"
#include <string>

using namespace std;

int main(){
  
  //declare variables
  char input, input2;
  //char in, in2;
  int queue_size;
  //declare an array of char with queue_size
  circular_Queue CirQ(1); //the 1 is just to use the overwritten constructor
  
  cout << "This circular queue can store a maximum of " << CirQ.getSize()-1 << " characters." << endl;
  cout << "Current queue contents: " << endl;
  cout << "( ";
  CirQ.printQueue();
  cout << ")" << endl;
  cout << "Choose E (for Enqueue), D (for Dequeue), S (for show contents), Q for quit." << endl;
  
  do
  {
    cin.get(input);
    cin.ignore(256,'\n');
    //cout << input << endl;
    
    switch(input)
    {
      case 'E': //Enqueue an element
      case 'e':
        if(CirQ.isFull()){
          cout << "Sorry, queue is full";
        }else{
          cout << "Character to input: ";
          cin.get(input2);      //take input to enqueue
          cin.ignore(256,'\n');
          cout << "Enqueing: " << input2;
          CirQ.enqueue(input2);
        }
        break;
      case 'D': //Dequeue an element
      case 'd':
        if(CirQ.isEmpty()){
          cout << "Sorry, queue is empty";
        }else{
          cout << "Dequeing: " << CirQ.dequeue();
        }
        break;
      case 'S': //Show contents
      case 's':
        cout << "Displaying queue";
        break;
      case 'Q': //Quit
      case 'q':
        cout << "Exiting program, final queue contents: " << endl;
        break;
      default:
        cout << "That's Invalid. Try again";
        break;
    }
    
    if(!(input == 'Q' || input == 'q')){    //if its not quiting then print this
      cout << ", queue contents:" << endl;
    } 
    cout << "( ";
    CirQ.printQueue();
    cout << ")" << endl;
  
  }while(!(input == 'Q' || input == 'q'));
  
}
