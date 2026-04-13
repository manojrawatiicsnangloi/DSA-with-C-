#include <stdio.h>

class queue{
   int* root;
   int cap;
   int front;
   int rear; 
   public : queue(int c)   {
    this-> root = new int[c];
    front = rear = -1;
    cap = c;
   } 
      void enqueue(int value){};   // insert element
    void dequeue(){};            // remove element
    int getFront(){};            // see front element

    // utility
    bool isEmpty(){};
    bool isFull(){};
    void display(){};
};


int main(){
    return 0;
}