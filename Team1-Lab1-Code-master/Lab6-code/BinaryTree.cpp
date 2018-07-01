//Written by Alex Budke Edited by Ben Cohen
//Group 1: Ben Cohen, Alex Budke, Jose Banda. //10/20/2016

/* PusedoCode
  class for the binary tree
    A node of the tree
    
    add function
      create newNode
      insert newNode
    endf
    search function
      while
    endf
  endc
  
  main
    while reading file
      read line
      change str to int
      add that int to a newNode
    endw
    search for the data points
  endm
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

//We could put this in a header file but this is easier
class BinTree //A class to hold the entire tree
{
  private:
    struct BinNode{ // The single node of the tree
      int value;
      BinNode *Right;
      BinNode *Left;
    };
    BinNode *TOP;
  public:
    //constructor of the entire tree
    BinTree(int n){TOP = NULL;}
    
    //debug printer
    int print(){
      cout << TOP->Right->value << endl;
    }
    
    //function to add to the binary tree
    int addNode(int new_value){
      BinNode *newNode = new BinNode;
      newNode->value = new_value;
      newNode->Right = newNode->Left = NULL;
      
      BinNode *helper = TOP;
      if(!helper){
        TOP = newNode;
        //cout << "Created node with value " << newNode->value << endl; //debug for creating tree from data file
      }
      if(helper){
        //cout << "This is helper " << helper->value << endl;
        //cout << "This is new value " << new_value << endl;
      }
      while(helper){
        if(helper->value == new_value){
          //cout << "This is a duplicate. " << new_value << endl; //debug for creating tree from data file
          return 1;
        }else if(helper->value > new_value){
          if(!helper->Left){
            helper->Left = newNode;
            //cout << "Created node with value " << newNode->value << endl; //debug for creating tree from data file
            return 1;
          }else{
            helper = helper->Left;
          }
        }else if(helper->value < new_value){
          if(!helper->Right){
            helper->Right = newNode;
            //cout << "Created node with value " << newNode->value << endl; //debug for creating tree from data file
            return 1;
          }else{
            helper = helper->Right;
          }
        }
      }
      //cout << "Node added." << endl;
    }
    
    //function to search for some data
    int search(int data){
      BinNode *helper = TOP;
      while(helper){
        if(helper->value == data){
          cout << "Found " << data << endl;
          return 1;
        }else if(helper->value > data){
          helper = helper->Left;
        }else if(helper->value < data){
          helper = helper->Right;
        }
      }
      cout << data << " was not found." << endl;
    }
    
    //used this to print entire tree for debug purposes
    //void inOrder(){
      
    //}
};

int main()
{
  //read the data file
  ifstream inFile;
  inFile.open("MyData.dat", ios::in); 
  
  //declaring variables
  string input;
  int input_int;
  char input_char;
  bool search = true;
  BinTree BinaryTree(1);
  
  //debug test for reading all the data file lines
  /*
  while(!inFile.eof( )){
    getline(inFile, input);
    cout << input << endl;
  }
  cout << "All lines have been read" << endl;
  */
  
  cout << "We will be ignoring Duplicate values." << endl;
  
  //add all of the mydata file to a tree
  while(!inFile.eof())
  {
    getline(inFile, input);
    //cout << input << endl;
    
    input_int = atoi(input.c_str());
    
    BinaryTree.addNode(input_int);
  }
  
  //BinaryTree.print();
  
  //search for these data values
  /*
  BinaryTree.search(74);
  BinaryTree.search(7);
  BinaryTree.search(19);
  BinaryTree.search(55);
  BinaryTree.search(6);
  */
  while (search){ //allow user to input numbers to search for ending when they type 'n'
    cout << "Number to search: ";
    cin >> input_int;
    BinaryTree.search(input_int);
    cout << "Search another? Y/N" << endl;
    cin >> input_char;
    switch (input_char){
      case 'y':
      case 'Y':
        break;
      case 'n':
      case 'N':
        search = false;
        break;
    }
    }
  }
