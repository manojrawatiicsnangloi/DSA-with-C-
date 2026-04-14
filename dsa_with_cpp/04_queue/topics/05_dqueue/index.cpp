#include <iostream>

class deque {
    int* arr;
    int cap;
    int front;
    int rear;

public:
    // constructor
    deque(int c) {
        arr = new int[c];
        cap = c;
        front = rear = -1;
    }

    // insertion
    void pushFront(int value) {
        if (isFull()) return;
        if (front == -1){
            front = rear = 0;
        }
        else{
            front = (front - 1 + cap) % cap;
        }
        arr[front] = value;
    }

    void pushRear(int value) {
        if (isFull()) return;
        if (rear == -1){
            front = rear = 0;
        }
        else{
            rear = (rear + 1) % cap;
        }
        arr[rear] = value;
    }

    // deletion
    void popFront() {
        if (isEmpty()) return;
        if (front == rear){ 
            front = rear = -1;
        }
        else{
            front = (front + 1) % cap;
        }
    }

    void popRear() {
        if (isEmpty()) return;
        if (front == rear){
            front = rear = -1;
        }
        else{
            rear = ((rear - 1) + cap ) % cap;
        }
    }

    // access
    int getFront() {
        if (front != -1) return arr[front];
        return -1;
    }

    int getRear() {
        if (rear != -1){ return arr[rear];}
        return -1;
    }

    // utility
   bool isEmpty() {
    return front == -1;
}

    bool isFull() {
         return (front == 0 && rear == cap - 1) || (front == rear + 1);
    }

    void display() {
            if (isEmpty()) {
        std::cout << "Deque is empty\n";
        return;
    }
    int i = front;
    while (true){
        std::cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % cap;
    }
    std::cout << "\n";
    }
};

int main() {
    deque dq(5);

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);

    dq.display();

    dq.popFront();
    dq.popRear();

    dq.display();

    return 0;
}