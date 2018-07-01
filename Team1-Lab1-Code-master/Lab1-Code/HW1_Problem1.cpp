#include <iostream>
#include <cstdlib>
#include <math.h> 

//Created by Alex Budke and Kaitlyn Woods on aug 29 2016

//Class: Data structures
//Homework 1, Problem 1 

using namespace std;

//Function to act as the calculator and choose the operation
int calculate(int integer1, int integer2, char operation)
{
  int output;
  
  switch(operation)
  {
    case '+':
      output = integer1+integer2;
      break;
    case '-':
    	output = integer1-integer2;
    	break;
    case '*':
    	output = integer1*integer2;
    	break;
    case '/':
    	output = integer1/integer2;
    	break;
    case '%':
      output = integer1%integer2;
      break;
    default:
      cout << "Error: Invalid operation." << endl;
      return 0;
  }
  
  return output;
}

//Main function to write to the prompt and accept variables
int main()
{ 
  int integer1, integer2;
  char operation, do_another;
  
  start:
  
  cout << "    Welcome to DS_Team_1 Calculator." << endl;
  cout << "  Input two integers and an operation (+, -, *, /, %)." << endl;
  cout << "Integer 1: ";
  cin >> integer1;
  cout << "Integer 2: ";
  cin >> integer2;
  cout << "Operation: ";
  cin >> operation;
  
  
  cout << integer1 << " " << operation << " " << integer2 << " = "<< calculate(integer1, integer2, operation) << endl;
  
  
  cout << "Do another problem? (Y or N) " << endl;
  cin >> do_another;
  
  if(do_another == 'Y' || do_another == 'y'){
    goto start;
  }
  
}

