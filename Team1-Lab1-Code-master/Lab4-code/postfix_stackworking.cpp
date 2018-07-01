//Group 1: Ben Cohen, Kaitlyn Woods, Alex Budke, Jose Banda. //9/24/2016
//Written by Ben Cohen
//Edited by Alex Budke and Kaitlyn Woods

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
    //cout << "in pop member function" << endl;
    stack_node *temp; //temp pointer
    if(top == NULL){      //check if empty
      //cout << "The stack is empty" << endl;
    }else{
      //cout << "recognized something is in stack" << endl;
      int value = top->val;   //this is the "pop"
      temp = top->next; 
      delete top;       //delete the node to save space
      top = temp;       //new top of stack
      return value;
    }
  }
  
  void clear()
  {
    char c;
    while(top){
      c = pop();
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
      //cout << "The stack is empty" << endl;
    }else{
      char val = top->ch;   //this is the "pop"
      temp = top->next; 
      delete top;       //delete the node to save space
      top = temp;       //new top of stack
      return val;
    }
  }
  void clear()
  {
  //cout << "trying to clear stack" << endl;
    char c;
    while(top){
      c = pop();
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
  //this is too difficult
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
      //cout << "The queue is empty" << endl;
    }else{
      char val = head->ch;     //this is the value read
      temp = head->next;
      delete head;        //delete node to save space
      head = temp;        //new head of queue
      queueNum--;   //update the queue length
      return val;
    }
  }
  
  void clear()
  {
    //cout << "trying to clear queue" << endl; used to find that member function wasn't working
    char c;   
    while(head){
      c = dequeue();
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
  char flag = 'X';
  while(!inFile.eof()){  //Read until file ends
    //clear all stacks and queues
    queue1.clear();
    stack1.clear();
    stack2.clear();
    
    getline(inFile, buffer);
    //cout << buffer << endl;
    for (int pos = 0; pos < buffer.length(); pos++)
    { 
    //for the length of the buffer
      ch = buffer[pos];
      char_type = get_type(ch);
      //cout << char_type << ' ';
      switch(char_type) //which type is the char
      {
        case 0:   //Number
          queue1.enqueue(ch);   //add the num to the queue
          //cout << "queued number" << endl;
          break;
        case 1:   //Operator
          queue1.enqueue(flag);
          //cout << "queued a flag" << endl;
          if(stack1.top !=NULL){ //if there is an operator in the stack
            //cout << "Stack has a character" << endl;
            switch(ch)  //type of operation to determine presedence
            { //these case are in order of presedence
              
              case '*':
               
              case '/':
                  
              case '%':
                  
                if(stack1.top->ch == '*' || stack1.top->ch == '/' ||stack1.top->ch == '%')
                {
                  //if operator in stack has equal precedence, put in queue
                  queue1.enqueue(stack1.pop());
                }
                //if ch has greater precedence, goes in stack on top of lesser operator
                break;
              case '+':
                
              case '-':
                
                if((stack1.top->ch == '*' || stack1.top->ch == '/' ||stack1.top->ch == '%')||(stack1.top->ch == '+' || stack1.top->ch == '-')) 
                {
                  queue1.enqueue(stack1.pop());
                }
                break;
            } 
          }
          //cout << "stacked an operator" << endl;
          stack1.push(ch); //ch always goes into the stack.
          break;
        case 2:   //Parenthesis
          if(ch == '(')       //left parenthesis
          {
            stack1.push(ch);
          }
          else if(ch == ')')  //right parenthesis
          {
            while(stack1.top != NULL && stack1.top->ch != '(')
            {
              queue1.enqueue(stack1.pop());
            }
            if(stack1.top == NULL){
              cout << "mismatched parentheses";
              outFile << "mismatched parentheses";
              goto end;
              //should have a break here to keep program from crashing
            }
            else if(stack1.top->ch == '('){
              stack1.pop();
              queue1.enqueue(flag);
            }
          }
          break;
        case 3:   //Other (ie, space)
            //ignore
            break;
      }
    }
    //why was this loop commented out?
    //The function to do the math of the postfix notation
    char op;
    while(stack1.top)      //while there is still items in the stack,
    { 
      ch = stack1.pop();
      if(ch == '(')
      {
        cout << "mismatched parentheses";
        outFile << "mismatched parentheses";
        goto end;
      }
      queue1.enqueue(ch); //pop them into the queue
    }
    
    //cout << "check" << endl;
    
    //cout << "queued everything" << endl;
    char a,b;
    int num1, num2;
    while(queue1.head){
      //cout << queue1.dequeue();
      //cout << "starting to print" << endl;
      a = queue1.dequeue();
      //cout << a;
      
      switch(get_type(a)){
        case 0:
          cout << a;
          outFile << a;
          num1 = a - '0';
          if(get_type(queue1.head->ch) == 0)
          {
            b = queue1.dequeue();
            cout << b;
            outFile << b;
            num2 = b - '0';
            num1 = 10*num1 + num2;
          }
          stack2.push(num1);
          break;
        case 1:
          //cout << "recognized an operator" << endl;
          cout << a;
          outFile << a;
          //cout << "trying to print operator" << endl;
          num1 = stack2.pop();
          if(!stack2.top && (a == '+' || a == '-'))
          { 
            //cout << "Got here" << endl;
            if(queue1.head && queue1.head->ch == a){
              
              char ch = queue1.dequeue();
              cout << ch;
              outFile << ch;
              switch(a){
                case '+':
                  num1 = num1+1;
                  break;
                case '-':
                  num1 = num1-1;
                  break;
              }
              //cout << "after the if statement" << endl;
              stack2.push(num1);
            }
          }else{
            num2 = num1;
            num1 = stack2.pop();
            cout << "Got all the values" << endl;
            switch(a){
              case '*':
                stack2.push(num1*num2);
                break;
              case '/':
                stack2.push(num1/num2);
                break;
              case '%':
                stack2.push(num1%num2);
                break;
              case '+':
                //cout << "right before if statement" << endl;
                if(queue1.head){
                  if(queue1.head->ch == '+' && queue1.head->next->ch == flag){
                    char ch = queue1.dequeue();
                    cout << ch;
                    outFile << ch;
                    num2 = num2 + 1;
                    stack2.push(num1);
                    stack2.push(num2);
                  }
                }else{
                  //cout << "made it through the if statment" << endl;
                  stack2.push(num1+num2);
                }
                break;
              case '-':
                //cout << "Check1";
                if(queue1.head)
                {
                  if(queue1.head->ch == '-' && queue1.head->next)
                  { 
                    if(queue1.head->next->ch == flag)
                    {
                    char ch = queue1.dequeue();
                    cout << ch;
                    outFile << ch;
                    num2 = num2 - 1;
                    stack2.push(num1);
                    stack2.push(num2);
                    break;
                    }
                  }
                }
                stack2.push(num1-num2);
                break;
              default: 
                cout << "ERROR" << endl;
            }
          }
          
          
      }
      /*if(a = flag){
        continue;
      }
      cout << a;
       */
    } //end of evaluation loop
    int ans;
    ans = stack2.pop();
    cout << " = " << ans;
    outFile << " = " << ans;
    
    
    end:
    cout << endl;
    outFile << endl;
    
  } //on to next line of input file.
  
  //cout << endl;
  
  //close files
  inFile.close();
  outFile.close();
  
  exit(0);
  return 0;
} //end of int main()




int get_type(char c) //gets the type of the character
{
    const int NUMBER = 0, OPERATION = 1, PARENTHESIS = 2, OTHER = 3; //error condition or space
    
    if  (c >= '0' && c <= '9') return NUMBER;
    if (c == '*' || c == '+' || c == '-' ||c == '/' || c == '%' ) return OPERATION;
    if (c == '('|| c == ')') return PARENTHESIS;
    return OTHER;    
}
