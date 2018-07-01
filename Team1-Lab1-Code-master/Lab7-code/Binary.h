
#ifndef Binary_H
#define Binary_H

using namespace std;

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
        //cout << "Created node with value " << newNode->value << endl;
      }
      if(helper){
        //cout << "This is helper " << helper->value << endl;
        //cout << "This is new value " << new_value << endl;
      }
      while(helper){
        if(helper->value == new_value){
          //cout << "This is a duplicate. " << new_value << endl;
          return 1;
        }else if(helper->value > new_value){
          if(!helper->Left){
            helper->Left = newNode;
            //cout << "Created node with value " << newNode->value << endl;
            return 1;
          }else{
            helper = helper->Left;
          }
        }else if(helper->value < new_value){
          if(!helper->Right){
            helper->Right = newNode;
            //cout << "Created node with value " << newNode->value << endl;
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
    
    //used this to print entire tree
    void inOrder(BinNode* Node){
      if(Node==NULL){return;}
      inOrder(Node->Left);
      cout << Node->value << " ";
      inOrder(Node->Right);
    }
    void inOrder(){
      inOrder(TOP);
    }
    
    void postOrder(BinNode* Node){
      if(Node==NULL){return;}
      postOrder(Node->Left);
      postOrder(Node->Right);
      cout << Node->value << " ";
    }
    void postOrder(){
      postOrder(TOP);
    }
    
    void preOrder(BinNode* Node){
      if(Node==NULL){return;}
      cout << Node->value << " ";
      preOrder(Node->Left);
      preOrder(Node->Right);
    }
    void preOrder(){
      preOrder(TOP);
    }
    
};

#endif
