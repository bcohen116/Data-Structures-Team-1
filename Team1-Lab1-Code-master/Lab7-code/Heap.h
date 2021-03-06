
#ifndef Heap_H
#define Heap_H

#include <vector>

using namespace std;

class Heap
{
  private:
    //vector<int> HeapVec;
    int HeapArray[32];
    int count;
  public:
    Heap(int n){
      count = 0;
    };
    
    int getParent(int i){
      return (i-1)/2;
    }
    
    int getChild(){
      
    }
    
    void swap(int& i, int& j) {
      int t = i;
      i = j;
      j = t;
    }
       
    //add a node to the vector with value
    void addNode(int value){
      //HeapVec.push_back(value);
      HeapArray[count] = value;
      
      //check that heap is in order
      heapify(count);
      
      count++;
    }
    
    void heapify(int n){
      if(HeapArray[n]<HeapArray[getParent(n)]){
        swap(HeapArray[n], HeapArray[getParent(n)]);
        heapify(getParent(n));
      }
    }
    
    void print(){
      for(int i=0; i<count; i++){
        cout << HeapArray[i] << " ";
      }
      cout << endl;
    }
    
};

#endif
