/* //Written by Kaitlyn Woods
Ben: This file is Obsolete and will make the whole program not work. Use Applicant 2 for the main

#include <iostream>
#include <sstream>

#include "Applicant.h"

using namespace std;


Applicant * insertInList(Applicant *newapp, Applicant *head){
  Applicant *helper = head;
  Applicant *helper2 = head; //KW: this is neccessary when the new node goes in the middle of the list.
    
  //KW: if the new node goes at the beginning of the list:
  if(helper->getRank() < newapp->getRank()){
    newapp->setNext(head);
    head = newapp;
  }else{
    //KW: compare each node in the list to the new node.
    while(helper->getRank() >= newapp->getRank()){
      if(!(helper->getNext())){
        //KW: if the new node belongs at the end of the list
        helper->setNext(newapp);
        return head;
        }
        //KW: move on to the next node
      helper2 = helper;
      helper = helper->getNext();      
      } 
      /* KW: have the node before the desired spot point to the new node
      //and have the new node point to the node immediately after the desired spot. 
    helper2->setNext(newapp);
    newapp->setNext(helper);
    }
    return head;
}

void printList(Applicant *printer){
    while(printer){
      printer->printApplicant();
      printer = printer->getNext();
    }
}


int main(){
   //KW: create an array for each category. This was instead of reading in an .rtf file.
  string firstName_arr[12] = {"Jane", "Bill", "Karen", "Susan", "Frank", "George", "Ernie", "Bert", "Brittany", "Joe", "Ashley", "Thomas"};
  string lastName_arr[12] = {"Grey", "Clinton", "Rose", "Anthony", "Capra", "Carlin", "Banks", "Muppet", "Spears", "Jackson", "Wilkes", "Becket"};
  string school_arr[12] = {"East High", "West High", "North High", "South High", "Oak Hills", "Maple Knoll", "Sycamore East", "Sycamore North", "Sycamore South", "Sycamore West", "Riverview Central", "Ocean Park"};
  int a_arr[12] = {2, 5, 5, 4, 5, 3, 3, 2, 3, 4, 4, 3};
  float b_arr[12] = {8.3, 3.7, 8.6, 2.2, 4.5, 9.7, 4.6, 8.6, 3.0, 4.3, 9.8, 3.9};
  int c_arr[12] = {6, 4, 6, 5, 6, 8, 7, 7, 5, 7, 8, 9};
  
  //KW: initialize any pointers we might need.
  Applicant *head;
  Applicant *newapp;
  Applicant *helper;

  //KW: set the first node in the list
  head = new Applicant(firstName_arr[0], lastName_arr[0], school_arr[0], a_arr[0], b_arr[0], c_arr[0]);
    
  //KW: set the incoming node, this repeats 11 times for the 11 other applicants
  for(int i = 1; i < 12; i++){
    newapp = new Applicant(firstName_arr[i], lastName_arr[i], school_arr[i], a_arr[i], b_arr[i], c_arr[i]);
    
    /* KW: enter the address for the new node and the address of the head,
    //and get back the new address of the head (in case it changed). 
    head = insertInList(newapp, head);
    

  }
  
  //KW: print the resulting list
  printList(head);
  
  
  
  return 0;
}
*/ 
