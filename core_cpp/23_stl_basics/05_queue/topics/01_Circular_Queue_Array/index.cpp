#include <iostream>
using namespace std;


class CircularQueue {
    int *arr;
    int front;
    int rear;
    int capacity;
    int arrSize;

    public:CircularQueue(int size){
        this -> arr = new int[size];
        this -> front = 0;
        this -> rear = -1;
        this -> arrSize = 0;
        this -> capacity = size;
    }
    
    bool isFull() {
         return arrSize == capacity;
    }
    
    bool isEmpty() {
        return arrSize == 0;
    }
    void push(int data){
        if (isFull()){
            cout << "Stack overflow";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        arrSize++;
    }
    void pop(){
        if (isEmpty()){
            cout << "Already Empty";
            return;
        }
        front++;
        arrSize--;
    }
    void printCircularQueue(){
        int index = front;
        for (int i = 0; i < arrSize; i++){
            cout << arr[i] << " ";
            index = (index + 1) % capacity;
        }
        cout << "\n";
    }

};

int main() {
    CircularQueue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.printCircularQueue();
    q.pop();
    q.push(5);
    q.printCircularQueue();
    
    // q.push(1);
}