//Group 1: Ben Cohen, Alex Budke, Jose Banda.
//Written by Alex Budke and Ben Cohen
#include <iostream>
 #include "Que.h"
 
 using namespace std;
 
 //Constructor to create the head and tail
 circular_Queue::circular_Queue(int a){
   //cout << "Object created.";
   head = 0;
   tail = 0;  //same when empty
   //cout << tail<<endl;
 }
 //Get the size of the Queue
 int circular_Queue::getSize(){
   return sizeof(arry);
 }
 //Take the First element off the Queue and move the head
 char circular_Queue::dequeue(){
   if(!isEmpty()){
     char val = arry[(head%getSize())];  //I used head % Size to act as the
     head = head + 1;                    // loop around to make it easier
     return val;
   }else{
     cout << "error" << endl;  //just in case
  }
 }
 //Add a char to the end of the Queue and move the tail
 void circular_Queue::enqueue(char ch){
   if(!isFull()){
     arry[(tail%getSize())] = ch;
     tail = tail + 1;
     //cout << arry[tail%getSize()];
   }else{
     cout << "error" << endl;  //just in case
   }
 }
 //Check if the Queue is Empty
 bool circular_Queue::isEmpty(){
   if(head%getSize() == tail%getSize()){
     return true;
   }else{
     return false;
   }
 }
 //Check if the Queue is Full
 bool circular_Queue::isFull(){ 
   if((head+(getSize()-1))%getSize() == tail%getSize()){
     return true;    //this gave me trouble //so the array is actually one
   }else{            // size bigger than it can hold. There needs to be a 
     return false;   // sorta buffer or space to know its full. IDK it worked
   }
 }
 //Print out the contents of the queue
 void circular_Queue::printQueue(){
   int helper=head;
   while(helper != tail){
     cout << arry[helper] << " ";
     helper++;
   }
 }
