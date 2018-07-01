//Group 1: Ben Cohen, Kaitlyn Woods, Alex Budke, Jose Banda. //9/24/2016
//Written by Ben Cohen
//Edited by Alex Budke

//PsuedoCode
/*
0. declare functions(and stack and queue)
    - no use of the default ones sadly
1. declare variables(files too)
2. debug lines to check if reading
3. Read a line to a while loop
  1. Read each char to a for loop(length of the line)
    1. Find char_type
    2. Follow the Algorithm
    3. check char_type
      1. (num) add to queue
      2. (op) add to stack with presedence
      3. ('()') 
        1. '(' add to stack
        2. ')' pop stack until '('
      4. (other) ignore spaces
    4. Move queue into outFile
4. do the math after postfix expressions(seperate function)
5. Close files
0. create function and stack and queue
function postfix_math
1.
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <math.h> 
//#include <stack>    //Can't use default stack and queue
//#include <queue>
#include <stdlib.h>

using namespace std;

//declare functions
int get_type(char c);
int postfix_math(string buffer);
//void algorithm(int char_type, char ch); //this was too difficult

//A stack for int variables
struct int_stack {
  struct stack_node{    //Node of the stack
    int val;
    stack_node *next;
  };
  stack_node *top;
  int_stack(){top = NULL;}    //constructor with null top of the stack
  void push(int val){
    stack_node *newNode = new stack_node;
    newNode->val = val;       //create new node and put on top of stack
    newNode->next = top;
    top = newNode;
  }
  int pop(){
    stack_node *temp; //temp pointer
    if(top == NULL){      //check if empty
      cout << "The stack is empty" << endl;
    }else{
      int value = top->val;   //this is the "pop"
      temp = top->next; 
      delete top;       //delete the node to save space
      top = temp;       //new top of stack
      return value;
    }
  }
};

//A stack for char variables
struct char_stack {
  struct stack_node{      //Node of the stack
    char ch;
    stack_node *next;
  };
  stack_node *top;
  char_stack(){top = NULL;}  //constructor with a Null top of stack
  void push(char ch){
    stack_node *newNode = new stack_node;
    newNode->ch = ch;     //create new node to put on top of stack
    newNode->next = top;
    top = newNode;
  }
  char pop(){
    stack_node *temp; //temp pointer
    if(top == NULL){      //check if empty
      cout << "The stack is empty" << endl;
    }else{
      char val = top->ch;   //this is the "pop"
      temp = top;
      top = top->next;    //new top of stack
      delete temp;        //delete the node to save space
      return val;
    }
  }
};

//A queue for char variables
struct char_queue {
  struct queue_node{  //Node of the queue
    char ch;
    queue_node *next;
  };
  queue_node *head;   //Queue needs both a head and tail
  queue_node *tail;
  int queueNum;
  char_queue(){     //constructor with NULL and 0
    head = NULL; 
    tail = NULL;
    queueNum = 0;   //a num to hold the length of the queue
  }
  void enqueue(char ch){
    queue_node *newNode = new queue_node;
    newNode->ch = ch;
    newNode->next = NULL;
    if(queueNum == 0){   //check if the list is empty
      head = newNode;   //newNode is both cause its the only node
      tail = newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }
    queueNum++;   //update the queue length
  }
  char dequeue(){
    queue_node *temp;
    if(queueNum == 0){   //check if empty
      cout << "The queue is empty" << endl;
    }else{
      char val = head->ch;     //this is the value read
      temp = head->next;
      delete head;        //delete node to save space
      head = temp;        //new head of queue
      queueNum--;   //update the queue length
      return val;
    }
  }
};
/*
  These structs must be created before the main.
  They could be in a header file but thats just and extra file.
*/


int main(){
  // creates input and output files
  ifstream inFile;
  ofstream outFile;

  //variables
  string buffer;              //holds inputted expression
  char ch;                    //character to process
  string buffer_type_string;  //decide if char is # or string or operator
  int char_type;              //holds the char type
  char_stack stack1;
  int_stack stack2;
  char_queue queue1;
  
    //read the data file
  inFile.open("MyData.dat", ios::in); 
    //make MyOutput.out and open for writing
  outFile.open("MyOutput.out", ios::out); 
  
  
  ////debug test for reading from the data file
  //  getline(inFile, buffer);
  //  cout << buffer << endl;
  
  ////debug test for reading all the data file lines
  /*
  while(!inFile.eof( )){
    getline(inFile, buffer);
    cout << buffer << endl;
    outFile << buffer << endl;
  }
  cout << "All lines have been read"); 
  */
  
  ////debug test for reading all char in a line
  //get one line and output it
  /*
  getline(inFile, buffer);
  cout << buffer << endl;
  
  for (int pos = 0; pos < buffer.length( ); pos++){
    ch = buffer[pos];
    cout << ch << endl;
  }
  cout << "All characters read." << endl;
  */
  
  
  //Let's Start
  while(!inFile.eof()){  //Read until file ends
    getline(inFile, buffer);
    //cout << buffer << endl;
    for (int pos = 0; pos < buffer.length(); pos++){ 
    //for the length of the buffer
      ch = buffer[pos];
      char_type = get_type(ch);
      //cout << char_type << ' ';
      switch(char_type) //which type is the char
      {
          case 0:   //Number
            queue1.enqueue(ch);   //add the num to the queue
            break;
          case 1:   //Operator
            switch(ch)  //type of operation to determine presedence
            { //these case are in order of presedence
              case '*':
                
                stack1.push(ch);
                break;
              case '/':
                
                stack1.push(ch);
                break;
              case '%':
                
                stack1.push(ch);
                break;
              case '+':
                if(stack1.top != NULL){
                  while(stack1.top->ch == '*' || stack1.top->ch == '/' ||stack1.top->ch == '%'){
                    queue1.enqueue(stack1.pop());
                  }
                  /*
                  if(stack1.top->ch == '+'){
                    queue1.enqueue('1');
                  }else{
                    stack1.push(ch);
                  }
                  */
                  stack1.push(ch);
                }else{
                  stack1.push(ch);
                }
                break;
              case '-':
                if(stack1.top != NULL){
                  while(stack1.top->ch == '*' || stack1.top->ch == '/' ||stack1.top->ch == '%'){
                    queue1.enqueue(stack1.pop());
                  }
                }
                stack1.push(ch);
                break;
            }
            break;
          case 2:   //Parenthasis
            if(ch == '(')       //left parenthesis
            {
              stack1.push(ch);
            }
            else if(ch == ')')  //right parenthesis
            {
              while(stack1.top != NULL && stack1.top->ch != '('){
                queue1.enqueue(stack1.pop());
              }
              if(stack1.top == NULL){
                cout << "mismatched Parentheses";
              }
              if(stack1.top->ch == '('){
                stack1.pop();
              }
            }
            break;
          case 3:   //Other (ie, space)
            //ignore
            break;
      }
    }
    /*
    while(stack1.top != NULL){      //while there is still items in the stack,
      //queue1.enqueue(stack1.pop()); //pop them into the queue
      cout << stack1.pop();
    }*/
    
    cout << "check line" << endl;
    
    while(queue1.queueNum != 0){
      outFile << queue1.dequeue();   //put the queue in the outfile
    }
    outFile << endl;
  }//next line
  
  //need a statement to carry out the actual math after arranging the stack/queue. Instructions are in slide 8 of lecture 9.
  
  //need to output postfix expression and value
  
  //cout << "check out" << endl;
  
  //close files
  inFile.close();
  outFile.close();
  
  exit(0);
  return 0;
} //end of int main()

//The function to do the math of the postfix notation
int postfix_math(string buffer)
{
    
    //blah math
    
}


int get_type(char c) //gets the type of the character
{
    const int NUMBER = 0, OPERATION = 1, PARENTHESIS = 2, OTHER = 3; //error condition or space
    
    if  (c >= '0' && c <= '9') return NUMBER;
    if (c == '*' || c == '+' || c == '-' ||c == '/' || c == '%' ) return OPERATION;
    if (c == '('|| c == ')') return PARENTHESIS;
    return OTHER;    
}
