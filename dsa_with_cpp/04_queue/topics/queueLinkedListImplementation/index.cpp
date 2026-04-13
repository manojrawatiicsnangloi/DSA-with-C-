#include <iostream>
class Node{
    public:
    int data;
    Node * next;
    Node(int v){
        this->data = v;
        this -> next = nullptr;
    }
};

class queue{
    private : Node * front;
    Node * rear;
    
    public:
    queue(){
        front = rear = nullptr;
    } 
    void enqueue(int data){
        Node * newNode = new Node(data);
        if (front == nullptr){
            front = rear =  newNode;
            return;
        }

        Node * temp = rear; 
        temp -> next = newNode;
        rear = newNode;    
    }

    void dequeue(){
        if (front == nullptr){
            std::cout << "already empty";
            return;
        }
        Node * temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr){
            rear = nullptr;
        }
    }
    int top(){
        if (front == nullptr){
            std::cout << "Not found";
            return -1;
        }
        return front->data;
    }
    bool isEmpty(){
        return front == nullptr;
    }
    
};
int main(){

    return 0;
}