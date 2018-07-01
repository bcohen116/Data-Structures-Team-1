//Written by Kaitlyn Woods

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

//initialize functions

  

//Create a struct for the nodes in the linked list.
struct Applicant{
  string firstName, lastName;
  string school;
  float a, b, c;
  float rank;
  
  Applicant *next;
};

Applicant * insertInList(Applicant *newapp, Applicant *head){
  Applicant *helper = head;
  Applicant *helper2 = head; //this is used for one type of instance
    
  //if the new node goes at the beginning of the list:
  if(head->rank < newapp->rank){
    newapp->next = head;
    head = newapp;
  }else{
    //compare each node in the list to the new node.
    while(helper->rank >= newapp->rank){
      if(!(helper->next)){
        //if the new node belongs at the end of the list
        helper->next = newapp;
        return head;
        }
        //move on to the next node
      helper2 = helper;
      helper = helper->next;      
      } 
      //have the node before the desired spot point to the new node
      //and have the new node point to the node immediately after the desired spot
    helper2->next = newapp;
    newapp->next = helper;
    }
    return head;
}
void printList(Applicant *printer){
    while(printer){
      cout << printer->firstName << " " << printer->lastName;
      cout << " " << printer->rank << endl;
      printer = printer->next;
    }
}


int main(){

  //create an array for each category. This was instead of reading in an .rtf file.
  string firstName_arr[12] = {"Jane", "Bill", "Karen", "Susan", "Frank", "George", "Ernie", "Bert", "Brittany", "Joe", "Ashley", "Thomas"};
  string lastName_arr[12] = {"Grey", "Clinton", "Rose", "Anthony", "Capra", "Carlin", "Banks", "Muppet", "Spears", "Jackson", "Wilkes", "Becket"};
  string school_arr[12] = {"East High", "West High", "North High", "South High", "Oak Hills", "Maple Knoll", "Sycamore East", "Sycamore North", "Sycamore South", "Sycamore West", "Riverview Central", "Ocean Park"};
  int a_arr[12] = {2, 5, 5, 4, 5, 3, 3, 2, 3, 4, 4, 3};
  float b_arr[12] = {8.3, 3.7, 8.6, 2.2, 4.5, 9.7, 4.6, 8.6, 3.0, 4.3, 9.8, 3.9};
  int c_arr[12] = {6, 4, 6, 5, 6, 8, 7, 7, 5, 7, 8, 9};
  
  //initialize any pointers we might need.
  Applicant *head;
  Applicant *newapp;
  Applicant *helper;

  //set the first node in the list
  head = new Applicant;
  head->firstName = firstName_arr[0];
  head->lastName = lastName_arr[0];
  head->school = school_arr[0];
  head->a = a_arr[0];
  head->b = b_arr[0];
  head->c = c_arr[0];
  head->rank = (2*head->a + head->b + head->c)/3;
  head->next = 0;
    
  //set the incoming node, this repeats 11 times for the 11 other applicants
  for(int i = 1; i < 12; i++){
    newapp = new Applicant;
    
    newapp->firstName = firstName_arr[i];
    newapp->lastName = lastName_arr[i];
    newapp->school = school_arr[i];
    newapp->a = a_arr[i];
    newapp->b = b_arr[i];
    newapp->c = c_arr[i];
    newapp->rank = (2*newapp->a + newapp->b + newapp->c)/3;
    newapp->next = NULL;
    
    //enter the address for the new node and the address of the head,
    //and get back the new address of the head (in case it changed changed)
    head = insertInList(newapp, head);
    

  }
  
  //print the resulting list
  printList(head);
  
  return 0;
}
