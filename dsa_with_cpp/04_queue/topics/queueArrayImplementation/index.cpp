#include <iostream>
using namespace std;


class queue{
    private : 
    int capacity;
    int front;
    int rear;
    int * arr;

    public:
    queue(int c){
        front = -1;
        rear = -1;
        this -> capacity = c;
        arr = new int[c];
    }
    void enqueue(int x){
        if (rear == capacity - 1){
            cout << "Queue Over flow";
            return;
        }
        if (front == -1) {
            front = 0; // first element case
        }
        arr[++rear] = x;
    }
    void dequeue(){
    if (front == -1 || front > rear){
            cout << "Already Empty";
            return;
        }
        front++;
        if (front > rear){
            front = rear = -1;
        }
    }

    int getFront(){
        if (front == -1 || front > rear){
            cout << "Queue is empty";
            return -1;
        }
        return arr[front];
    }

    bool isEmpty(){
        return front == -1 || front > rear;
    }

    int size(){
         if (front == -1 || front > rear) return 0;
            return rear - front + 1;
    }
    bool isFull(){
        return rear == capacity - 1;
    }
    void display(){
        if (isEmpty()){
            cout << "Queue is empty";
            return;
        }

        for (int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
    }
};

int main(){
    
    return 0;
}