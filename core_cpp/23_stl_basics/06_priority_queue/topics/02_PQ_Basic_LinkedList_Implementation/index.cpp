#include <iostream>

class Node{
    public:int data;
    Node * next;
    Node(int value){
        this -> data = value;
        this -> next = nullptr;
    }
};

class priority_queue{
    private:Node * root;
       public:
       priority_queue(){
        this -> root = nullptr;
    }

 
    void insert(int value){
        Node* n = new Node(value);
        if (root == nullptr || root -> data > value) {
            n -> next = root;
            root = n;
            return;
        }
        Node * temp = root;
        while (temp-> next != nullptr && temp -> next -> data <= value){
            temp = temp -> next;
        }
        n -> next = temp -> next;
        temp -> next = n;
    }

    void pop(){
        if (root == nullptr) return;
        Node * temp = root;
        root = temp -> next;
        delete temp;
    }
    
    void printList(){
        Node *temp = root;
        while (temp != nullptr){
            std::cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
};


int main(){
    priority_queue q;
    q.insert(34);
    q.insert(43);
    q.insert(78);
    q.insert(98);
    q.insert(1);
    q.printList();
    q.pop();
    q.printList();
    return 0;
}