#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int value){
        this -> data = value;
        this -> next = nullptr;
    }
};

class linkedlist{
    private: node * root;
    public:linkedlist(){
        root = nullptr;
    }

    void insertAtHead(int value){
        node * newNode = new node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        newNode -> next = root;
        root = newNode;
    }

    void pLinkedList(){
        node * temp = root;
        while (temp != nullptr){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
    }
};

int main(){
    linkedlist list;
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);
    list.insertAtHead(0);

    list.pLinkedList();
    return 0;
}