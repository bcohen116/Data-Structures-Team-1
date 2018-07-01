//Pseudo code created by Kaitlyn Woods
/*Edited by Alex Budke, Ben Cohen

*/

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

float rankCalc(Applicant *helper){
  //This function returns the rank which is (2*a+b+c)/3
  float a = helper->a;
  float b = helper->b;
  float c = helper->c;
  float rank = (2*a+b+c)/3;
  
  return rank;
}
struct Applicant_List{
  	Applicant app;
  	Applicant_List *next;
};
void sort(Applicant_List *app_List){
	//sort the linked list of applicants
	int counter = 0;
	int tempRank = 0;
	while (app_List) // get the amount of applicants in the list
	{
		app_List = app_List->next;
		counter++;
	}
	for (int x = 0; x < counter; x++){ // sort the list
		if (app_List->app.rank > app_List->next->app.rank){
			tempRank = app_List->app.rank;
			app_List->app.rank = app_List->next->app.rank;
			app_List->next->app.rank = tempRank;
		}
		else if (app_List->app.rank < app_List->next->app.rank){
			app_List->app.rank = tempRank;
			app_List->next->app.rank = app_List->app.rank;
			tempRank = app_List->next->app.rank;
		}
	}
}
void insertInList(Applicant *helper, Applicant_List *app_List){
  //this will put the Node into the linked list ordered by the rank.
  app_List->next->app = *helper;
  sort(app_List);
}
void printList(Applicant_List *app_List){ //prints the list
   Applicant_List *printer = app_List;
   while (printer){
      cout << "Name: " << printer->app.firstName << " " << printer->app.lastName << endl;
      cout << "School: " << printer->app.school << endl;
      cout << "Rank: " << printer->app.rank << endl;
      printer = printer->next;
      }
}
int main(){
  Applicant *head = NULL;
  Applicant *newApplicant = NULL;
  Applicant *helper = NULL;
  
	string line;
  string firstName, lastName, firstSchool, secondSchool, school;
  float num1, num2, num3;
  ifstream myfile("myData.rtf");
  
  
  head = new Applicant;  //add first "node"
  newApplicant = head;

  int i = 0;
  while(getline(myfile,line))  //retrieve the lines of data
  {
    if(i == 12) continue;  //There was a problem with a repeated line
    i++;
    
    myfile >> firstName >> lastName >> firstSchool >> secondSchool >> num1 >> num2 >> num3; //long line: adds all the words on the line in the file into different varaibles
    
    //add info to the struct
    newApplicant->firstName = firstName;
    newApplicant->lastName = lastName;
    newApplicant->school = firstSchool + " " + secondSchool;
    newApplicant->a = num1;
    newApplicant->b = num2;
    newApplicant->c = num3;
    newApplicant->rank = rankCalc(newApplicant);
    
    //move struct to the right place in the list by rank
    Applicant_List *app_List = new Applicant_List; // adding one node
    insertInList(newApplicant, app_List);  
    
    //testing
    cout << newApplicant->rank;
    cout << firstName << lastName << firstSchool << secondSchool << num1 << num2 << num3 << endl;
    
    newApplicant = new Applicant; //last thing in loop 
    printList(app_List); // prints the list
  }
  
  
  
  
  
  return 0;
}
