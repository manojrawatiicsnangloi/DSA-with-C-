#include <iostream>

class queue{
     int *arr;
    int front; 
    int rear; 
    int capacity;

    public:
    queue(int c){
        arr = new int[c];
        front = rear = -1;
        capacity = c;
    }

    void enqueue(int data){
        if ((rear + 1) % capacity == front){
            std::cout << "Queue Overflowed";
            return;
        }
        
        if (front == -1) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = data;
    }
    void dequeue(){
        if (front == -1) {
            std::cout << "Queue underflow";
            return;
        }
        if (front == rear){
            front = rear = -1;
        }
        else{
            front = (front + 1) % capacity;
        }
    }   
    int top(){
        if (front == -1) return -1;
        return arr[front];
    }

    int back(){
        if (rear == -1) return -1;
        return arr[rear];
    }

};

int main(){

    return 0;
}