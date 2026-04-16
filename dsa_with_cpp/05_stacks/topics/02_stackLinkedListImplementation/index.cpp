#include <iostream>

class node{
    public:int data;
    node * next;

    node(int v){
        this ->data = v;
        this -> next = nullptr;
    }
};


class stack {
    private:node * root;
    public: stack(){
        root = nullptr;
    }

    void push (int value){
        node * newNode = new node(value);
        if (root == nullptr){
            root = newNode;
            return;
        }
        newNode -> next = root;
        root = newNode;
    }
    void pop(){
        if (root == nullptr)return;
        node * temp = root;
        root = root -> next;
        delete temp;
    }
    int top() {
        if (root == nullptr) return -1;
        return root-> data;
    }

    int isEmpty(){
        return root == nullptr;
    }
};
int main(){
    return 0;
}