// Online C++ compiler to run C++ program online
#include <iostream>

class Node{
    public : int data;
    Node * prev;
    Node * next;
   
    Node (int value){
        data = value;
        next = nullptr;
    }
};

void insertAtHead(Node * & head, int value){
    Node * newNode = new Node(value);
    if (head == nullptr){
        head = newNode;
        return;
    }
    newNode -> next = head;
    head -> prev = newNode;
    head = newNode;
}


void insertAtEnd(Node *&head, int value){
    Node * newNode = new Node(value);
    if (head == nullptr){
        head = newNode;
        return;
    }
    Node * temp = head;
    while (temp -> next != nullptr){
        temp = temp->next;
    }
    
    newNode -> prev = temp;
    temp -> next = newNode;

}

void printLinkedList(Node * head){
    Node * temp = head;
    while (temp != nullptr){
        std::cout << temp -> data << " <--> ";
        temp = temp -> next;
    }
    std::cout << " nullptr \n";
}

int main(){
    Node * head = nullptr;
    insertAtHead(head, 10);
    insertAtHead(head, 9);
    insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printLinkedList(head);
    return 0;
}