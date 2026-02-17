#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class customQue {
public:
    Node* front;
    Node* rear;

    customQue() {
        front = nullptr;
        rear = nullptr;
    }

    // ---------------------- PUSH ----------------------
    void push(int value) {
        Node* newNode = new Node(value);

        // If queue is empty
        if (front == nullptr) {
            front = newNode;
            rear = newNode;
            return;
        }

        // Otherwise connect at end
        rear->next = newNode;
        rear = newNode;
    }

    // ---------------------- EMPTY ----------------------
    bool empty() {
        return (front == nullptr);
    }

    // ---------------------- POP ----------------------
    void pop() {
        if (front == nullptr) return;

        Node* temp = front;
        front = front->next;

        // If queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // ---------------------- FRONT ELEMENT ----------------------
    int first() {
        if (front == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return front->data;
    }

    // ---------------------- BACK ELEMENT ----------------------
    int back() {
        if (rear == nullptr) {
            cout << "Queue is empty\n";
            return -1;
        }
        return rear->data;
    }
};

// ---------------------- MAIN ----------------------
int main() {
    customQue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Front Element: " << q.first() << endl;

    while (!q.empty()) {
        cout << q.first() << " ";
        q.pop();
    }
}
