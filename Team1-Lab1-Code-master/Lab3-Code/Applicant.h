#ifndef APPLICANT_H
#define APPLICANT_H

//Written by Kaitlyn Woods
//Edited by Alex Budke and Ben Cohen
//Group 1: Ben Cohen, Kaitlyn Woods, Alex Budke, Jose Banda. //9/13/2016

#include <iostream>
#include <sstream>

using namespace std;

class Applicant {
  private:
  //KW: set all of the data as private.
    string firstName;
    string lastName;
    string school;
    float scores[3];
    float rank;
    
    /* KW: set a private function that will calculate the rank.
    This way, the user can't change the rank. */
    void setRank(){
      rank = (2*scores[1] + scores[2] + scores[3])/3;
      // Debug cout << rank << endl;
    }
    
    Applicant *next;
  
  public:
    Applicant() /* KW: this constructor needs to be set; it cannot be used in the program as is. */
    //ANB: Just need to set everything to "empty" values
    {
      firstName = "";
      lastName = "";
      school = "";
      scores[0] = 0;
      scores[1] = 0;
      scores[2] = 0;
      setRank();
      next = NULL;
      // Debug cout << "Applicant Created Empty" << endl;
    }
    
    Applicant(string in_first, string in_last, string in_school, float in_a, float in_b, float in_c){
    /*KW: set an overloaded constructor that takes all data */
      firstName = in_first;
      lastName = in_last;
      school = in_school;
      scores[0] = in_a;
      scores[1] = in_b;
      scores[2] = in_c;
      /*KW: automatically call the private function everytime
      this is used. */
      setRank();
      next = NULL;
      // Debug cout << "Applicant Created Empty" << endl;
    }
    
    //ANB: Destructor to delete all data
    ~Applicant(){
      delete next;
      cout << "Deconstructed." << endl;
    }
    
    void setInfo(string in_first, string in_last, string in_school, float in_a, float in_b, float in_c){
    /*KW: A mutator that can change all of the info for an 
    already defined applicant. */
      firstName = in_first;
      lastName = in_last;
      school = in_school;
      scores[0] = in_a;
      scores[1] = in_b;
      scores[2] = in_c;
      /*KW: automatically call the private function everytime 
      this is used.*/
      setRank();
      next = NULL;
    }

    /*KW: The only member functions needed are an accessor and 
    mutator of the next variable and a rank accessor.
    nothing else should ever need to be changed. */
    
    float getRank() const{
      return rank;
    }
    Applicant *getNext() const{
      return next;
    }
    void setNext(Applicant *app){
      next = app;
    }
    
    /*KW: This will print the neccessary info about an Applicant.
    It's easier to have this as a member function that can be 
    called repeatedly by a program function. Otherwise, if
    everything was in the program function, 2 more accessors
    are neccessary. */
    void printApplicant() const{
      cout << firstName << " " << lastName;
      cout << " " << rank << endl;
    }
    

};
#endif
