#include <iostream>

class circularqueue{
    int * root;
    int front;
    int rear;
    int cap;


    circularqueue(int cap){
        root = new int[cap];
        this -> cap = cap;        
        front = rear = -1;
    }

    void push(int value){
        if ((rear + 1) % cap == front){
            return;
        }
        if (front == -1){
            rear = front = 0;
        }
        else{
            rear = (rear + 1) % cap;
        }
        root[rear] = value;
    }
    void pop(){
        if (front == -1){
            return;
        }

        if (front == rear){
            front = rear = -1; 
        }       
        else{
            front = (front + 1 ) % cap;
        }
    }
};

int main(){}