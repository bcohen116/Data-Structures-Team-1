#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h> 


//this program provides some useful simple examples 
//that you may (or may not) want to use in your program
//to evaluate arithmetic expressions

//it was written by C. Purdy on 09/23/16 using the gedit editor


using namespace std;

//function prototype
int get_type(char c); //decide type of each character in string

int main()
{ //variables and functions

//--create input and output files for the program to uuse
  
  ifstream inFile;
  ofstream outFile;
  
//--create variables  
  
  string buffer;  //hold the expression being input
  char ch;   //character being processed
  string buffer_type_string;  //decide whether each character is number, operator, etc.
  int char_type;  //hold type of character (number, operator, parenthesis)
  
 
//--associate the user file MyData.dat with the program's inFile and open it for reading
  
  inFile.open("MyData.dat", ios::in);

//--associate the new file MyOutput.out with the program's outFile and open it for writing

  outFile.open("MyOutput.out", ios::out);
  

//--get one line from the input file and output it to see that it is what you expected
//  getline(inFile, buffer);
//  cout << buffer << endl;

//Comment out the part for reading 1 line and test that we can read all the lines and output them
//to the screen and to the output file


   while(!inFile.eof( ))
   {  getline(inFile, buffer);
      cout << buffer << endl;
      outFile << buffer << endl;
   }   

   cout << "all lines read!" << endl;
   
 //--now comment out the test of input & output and figure out how to interpret string
 //get one line from the input file and output it to see that it is what you expected  
   getline(inFile, buffer);
   cout << buffer << endl; 
   
   for (int pos = 0; pos < buffer.length( ); pos++)
   {ch = buffer[pos];
   cout << ch << endl;
   }
      
   cout << "all characters read!"  << endl; 
   
   //now we must convert to numbers and operators
   
   buffer = "57 + 3";
   
   cout << buffer << endl;
   
   cout << "conversion of characters to numbers, operators, etc." << endl;
   
   //finding the type of the buffer characters
   
   
   
    for (int pos = 0; pos < buffer.length( ); pos++)
    { char_type = get_type(buffer[pos]);
      cout << char_type << ' ';
    }     

    cout << endl;
   
//close the files

   inFile.close( );   
   outFile.close( );
    
	return 0;
}


//function
int get_type(char c) 
{
    const int NUMBER = 0, OPERATION = 1, PARENTHESIS = 2, OTHER = 3; //error condition or space
    
    if  (c >= '0' && c <= '9') return NUMBER;
    if (c == '*' || c == '+' || c == '-' ||c == '/' || c == '%' ) return OPERATION;
    if (c == '('|| c == ')') return PARENTHESIS;
    return OTHER;    
}
