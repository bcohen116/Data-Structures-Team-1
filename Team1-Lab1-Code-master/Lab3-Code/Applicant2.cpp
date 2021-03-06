//Written by Kaitlyn Woods
//Edited by Alex Budke and Ben Cohen
//Group 1: Ben Cohen, Kaitlyn Woods, Alex Budke, Jose Banda. //9/13/2016

#include <iostream>
#include <sstream>
#include <fstream>

#include "Applicant.h"

using namespace std;


Applicant * insertInList(Applicant *newapp, Applicant *head){
  Applicant *helper = head;
  Applicant *helper2 = head; //KW: this is necessary when the new node goes in the middle of the list.
  // Debug cout << "Comparing for middle of list" << endl;
    
  //KW: if the new node goes at the beginning of the list:
  if(helper->getRank() < newapp->getRank()){
  // Debug cout << "Comparing for start of list" << endl;
    newapp->setNext(head);
    head = newapp;
  }else{
    //KW: compare each node in the list to the new node.
    while(helper->getRank() >= newapp->getRank()){
      if(!(helper->getNext())){
        //KW: if the new node belongs at the end of the list
        // Debug cout << "Comparing for end of list" << endl;
        helper->setNext(newapp);
        return head;
        }
        //KW: move on to the next node
      helper2 = helper;
      helper = helper->getNext();      
      } 
      /* KW: have the node before the desired spot point to the new node
      and have the new node point to the node immediately after the desired spot. */
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

  //KW: initialize any pointers we might need.
  Applicant *head;
  Applicant *newapp;
  Applicant *helper;

	string line;
  string firstName, lastName, firstSchool, secondSchool, school;
  float num1, num2, num3;
  ifstream myfile("myData.rtf");

  for(int i = 1; i < 13; i++){
    
    //ANB: Reads from the rtf file
    getline(myfile, line);
    myfile >> firstName >> lastName >> firstSchool >> secondSchool >> num1 >> num2 >> num3; //long line: adds all the words on the line in the file into different varaibles
    school = firstSchool + " " + secondSchool;
    // Debug testing if rtf file is read: cout << school << endl;
    
    if(i==1) 
    {
      head = new Applicant(firstName,lastName,school,num1,num2,num3);
    }else{
      newapp = new Applicant(firstName,lastName,school,num1,num2,num3);
    
      /*KW: enter the address for the new node and the address of the head,
      and get back the new address of the head (in case it changed). */
      head = insertInList(newapp, head);
    }
  }
  
  //KW: print the resulting list
  printList(head);
  
  return 0;
}
