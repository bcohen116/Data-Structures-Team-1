

#include <iostream>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <string>

using namespace std;

//initialize functions
float rankCalc();
void insertInList();

struct Applicant{
  string firstName, lastName;
  string school;
  float a, b, c;
  float rank;
  
  Applicant *next;
};

/*void insertInList(Applicant *newapp, Applicant *head){
  Applicant *helper = head;
  while(helper->rank >= newapp->rank){
    helper = helper->next;
  }
  
  newapp->next = helper->next;
  helper->next = newapp;
    
  return;

}
*/
int main(){
  string firstName_arr[12] = {"Jane", "Bill", "Karen", "Susan", "Frank", "George", "Ernie", "Bert", "Brittany", "Joe", "Ashley", "Thomas"};
  string lastName_arr[12] = {"Grey", "Clinton", "Rose", "Anthony", "Capra", "Carlin", "Banks", "Muppet", "Spears", "Jackson", "Wilkes", "Becket"};
  string school_arr[12] = {"East High", "West High", "North High", "South High", "Oak Hills", "Maple Knoll", "Sycamore East", "Sycamore North", "Sycamore South", "Sycamore West", "Riverview Central", "Ocean Park"};
  int a_arr[12] = {2, 5, 5, 4, 5, 3, 3, 2, 3, 4, 4, 3};
  float b_arr[12] = {8.3, 3.7, 8.6, 2.2, 4.5, 9.7, 4.6, 8.6, 3.0, 4.3, 9.8, 3.9};
  int c_arr[12] = {6, 4, 6, 5, 6, 8, 7, 7, 5, 7, 8, 9};
  
  Applicant *head;
  Applicant *newapp;
  Applicant *helper;

  head = new Applicant;
  head->firstName = firstName_arr[0];
  head->lastName = lastName_arr[0];
  head->school = school_arr[0];
  head->a = a_arr[0];
  head->b = b_arr[0];
  head->c = c_arr[0];
  head->rank = (2*helper->a + helper->b + helper->c)/3;
  head->next = 0;
  cout << "Check1" << endl;
  int i = 1;
  for(int i = 1; i < 12; i++){
    cout << "check2" << endl;
    newapp = new Applicant;
    
    cout << "Check3" << endl;
    newapp->firstName = firstName_arr[i];
    newapp->lastName = lastName_arr[i];
    newapp->school = school_arr[i];
    newapp->a = a_arr[i];
    newapp->b = b_arr[i];
    newapp->c = c_arr[i];
    newapp->rank = (2*helper->a + helper->b + helper->c)/3;
    newapp->next = NULL;
    cout << "Check4" << endl;
    helper = head;
    Applicant *helper2;
    cout << "Check5" << endl;
    while(helper->rank >= newapp->rank){
      cout << "Check5a" << endl;
      if(!(helper->next)){
        break;
      }else{
      helper = helper->next;
      }    
    }
    
    cout << "Check6" << endl;
    newapp->next = helper;
    helper = newapp;
    
    cout << "Check7" << endl;
    }
 
  return 0;
}
