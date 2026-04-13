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

    int getBack(){
        if (rear == nullptr) return -1;
        return rear->data;
    }

    bool isEmpty(){
        return front == nullptr;
    }

};
int main(){
queue q;
     q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    std::cout << "Front element: " << q.top() << std::endl;
    std::cout << "Rear element: " << q.getBack() << std::endl;

    // Dequeue one element
    q.dequeue();  // Removes 10

    // Traverse queue (destructively)
    std::cout << "Elements in queue: ";
    while (!q.isEmpty()) {
        std::cout << q.top() << " ";
        q.dequeue();
    }
    return 0;
}