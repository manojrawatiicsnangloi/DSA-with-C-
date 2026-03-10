#include <iostream>


class Node {
    public:int data;
    Node * next;
    Node(int value){
        this -> data = value;
        this -> next = nullptr;
    }
};

class Stack{
    private: Node * top;
    public:
     Stack(){
        top = nullptr;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    void push(int value){
        Node * newNode = new Node(value);
        newNode -> next = top;
        top = newNode;
    }
    void pop(){
        if (isEmpty()){
            std::cout << "Stack Overflowed";
            return;
        }
        Node * temp = top;
        top = top-> next;
        delete temp;
    }
    int peek(){
        if (isEmpty()){
            return -1;
        }
        return top -> data;
    }
    void display(){
        Node * temp = top;
        while (temp != nullptr){
            std::cout << temp -> data << " ";
            temp = temp -> next;
        }
        std::cout << std::endl;
    }
};

int main(){
  Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push( 4);
    s.display();
       s.pop();
    s.display();

    std::cout << "Top Element: " << s.peek() << std::endl;
    return 0;
}