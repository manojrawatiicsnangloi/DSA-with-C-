#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};

class LinkedQueue
{
    Node *front;
    Node *rear;
   public:
    LinkedQueue()
    {
        this->front = nullptr;
        this->rear = nullptr;
    }
    bool isEmpty()
    {
        return this->front == nullptr;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void pop()
    {
        if (isEmpty())
        {
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }
    int peek()
    {
        return front->data;
    }

    void displayQueue()
    {
        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->data << " " ;
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    LinkedQueue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.displayQueue();
    q.pop();
    q.push(5);
    q.displayQueue();
}