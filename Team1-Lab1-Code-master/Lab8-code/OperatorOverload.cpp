//Group 1: Ben Cohen, Alex Budke, Jose Banda. //11/18/2016
//Written by Ben Cohen
//Edited by Alex Budke

#include <iostream>
#include <string>
#include <limits>
#include <exception>

/*Pseudo code:
* Take input like "2,6 + 4,7"
* Take input on data type
* make calculations based on type
* exception handling
* ask to repeat
*/

using namespace std;

//Calculate rational functions
double calculateR(double num1, double num2, double num3, double num4, char operation){
  
  	if(num2 == 0 || num4 == 0){
    	cerr << "ERROR: Input Divides by 0 error. Sorry." << endl;
  }
    double number1 = (double) num1/num2;
    double number2 = (double) num3/num4;
  //cout << "Numbers: " << number1 << number2 << num1 << num3 << (double)1/2 << endl; //debug
  //cout << "Running Calculate" << endl; //debug
  switch (operation){
    case '+':
      //cout << "Running +" << endl; //debug
	  cout << "This runs as a double calulation instead of a fraction." << endl;
      cout << number1 + number2;
      break;
    case '-':
	  cout << "This runs as a double calulation instead of a fraction." << endl;
      cout << number1 - number2;
      break;
    case '*':
      cout << (num1 + num3) << "," << (num2 + num4);
      break;
    case '/':
      cout << (num1 + num4) << "," << (num2 + num3);
      break;
  }
}

//calculate complex functions
int calculateC(int num1, int num2, int num3, int num4, char operation){
   switch (operation){
    case '+':
      //cout << "Running +" << endl; //debug
      cout << (num1 + num3) << "," << (num2 + num4);
      break;
    case '-':
      cout << (num1 - num3) << "," << (num2 - num4);
      break;
    case '*':
      cout << ((num1 * num3) - (num2 * num4)) << "," << ((num1 * num4) + (num2 * num3));
      break;
    case '/':
	  double dem = (double)(num3*num3 + num4*num4);
	  cout << (((num1 * num3) + (num2 * num4))/dem) << "," << (((num2 * num3) - (num1 * num4))/dem);

      break;
  }
   //return 0;
}

//Overloaded functions for error handling
bool inputCheck(double num){
  try{
  if (cin.fail()){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    throw "Incorrect Input";
    return true;
  }
  return false;
  }catch(const char* msg){
  	cerr << msg << endl;
  }
}
bool inputCheck(char data){
try{
  if (data != '+' && data != '-' && data != '*' && data != '/'){
    
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    throw "Incorrect Input";
    return true;
  }
  return false;
    }catch(const char* msg){
  	cerr << msg << endl;
  }
}
bool inputChecker(char datatype){
try{
  if (datatype != 'r' && datatype != 'R' && datatype != 'c' && datatype != 'C'){

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    throw "Incorrect Input";
    return true;
  }
  return false;
    }catch(const char* msg){
  	cerr << msg << endl;
  }
}

int main(){
  //initialize variables
  string simplified;
  char datatype;
  double num1, num2, num3, num4;
  char operation;
  bool continuing = true;
  char input2;
  
  //inputs
 while (continuing){
 try{
 do {
  cout << "Enter first number: ";
  cin >> num1; 
  cout << endl;
  }while(inputCheck(num1));
  
  do{
  cout << "Enter second number: ";
  cin >> num2; 
  cout << endl;
  }while(inputCheck(num2));
  
  do{
  cout << "Enter operation: ";
  cin >> operation; 
  cout << endl;
  }while(inputCheck(operation));
  
  do{
  cout << "Enter third number: ";
  cin >> num3;
  cout << endl;
  }while(inputCheck(num3));
  
  do{
  cout << "Enter last number: ";
  cin >> num4; 
  cout << endl;
  }while(inputCheck(num4));
  
  do{
  cout << "Rational (Type R), or Complex (Type C): ";
  cin >> datatype;
  cout << endl;
  }while(inputChecker(datatype));
  }catch(const char* msg){
  	cerr << msg << endl;
  }
//handle inputs
    switch (datatype){
     case 'r':
     case 'R':
       calculateR(num1, num2, num3, num4, operation);
       break;
     case 'c':
     case 'C':
       calculateC(num1,num2,num3,num4,operation);
       break;
    }
    
  //repeat function  
    cout << endl << "Do another? Y/N: ";
    cin >> input2;
    switch (input2){
      case 'y':
      case 'Y':
        break;
      case 'n':
      case 'N':
        continuing = false;
    }
  }
}
