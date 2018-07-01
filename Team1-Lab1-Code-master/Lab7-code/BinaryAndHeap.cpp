//Group 1
//Written by Alex Budke
//Edited by Ben Cohen, Jose Banda

#include <iostream>
#include <fstream>
#include "Heap.h"
#include "Binary.h"
#include <cstdlib>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

int main()
{ 
  //read the data file
  ifstream inFile;
  inFile.open("Data.dat", ios::in); 
  
  //declaring variables
  string input;
  int input_int;
  char BH;
  bool Heap_bool;
  bool Binary_bool;
  BinTree BinaryTree(1);
  Heap HeapTree(1);
  
  //debug test for reading all the data file lines
  /*
  while(!inFile.eof( )){
    getline(inFile, input);
    cout << input << endl;
  }
  cout << "All lines have been read" << endl;
  */
  
  Binary_bool = false;
  Heap_bool = false;
  
  choose:
  cout << "Choose Binary Tree or Heap: Type (B) or (H)" << endl;
  cin >> BH;
  switch(BH){
    case 'B':
      Binary_bool = true;
      break;
    case 'H':
      Heap_bool = true;
      break;
    default:
      cout << "ERROR: Invalid Choice." << endl;
      goto choose;
      break;
  }
  
  cout << "Input comes from Data.dat" << endl;
  
  while(!inFile.eof())
  {
    getline(inFile, input);
    input_int = atoi(input.c_str());
    
    if(Binary_bool){
      BinaryTree.addNode(input_int);
    }
    if(Heap_bool){
      HeapTree.addNode(input_int);
    }
  }
  if(Binary_bool){
    //Print preOrder
    cout << endl << "PreOrder: ";
    BinaryTree.preOrder();
    //Print inOrder
    cout << endl <<"InOrder: ";
    BinaryTree.inOrder();
    //Print postOrder
    cout << endl << "PostOrder: ";
    BinaryTree.postOrder();
    cout << endl;
  }
  if(Heap_bool){
    //Print Heap
    cout << endl << "Heap: ";
    HeapTree.print();
  }

}
