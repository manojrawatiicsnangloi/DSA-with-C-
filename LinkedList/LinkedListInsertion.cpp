#include <iostream>
using namespace std;


class Node{
    public : int data;
    Node * next;
   
    Node (int value){
        data = value;
        next = nullptr;
    }
};

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
   
    temp -> next = newNode;
}
void printLinkedList(Node * head){
    Node * temp = head;
    while (temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout << " nullptr ";
}

void insertAtHead(Node * & head, int value){
    Node * newNode = new Node(value);
    if (head == nullptr){
        head = newNode;
        return;
    }
    Node * temp = head;
    head = newNode;
    head -> next = temp;
}
void insertAtNthPosition(Node * head, int value, int index){
    Node * newNode = new Node(value);
    if (index == 0){
        insertAtHead(head, value);
    }
    Node * temp = head;
    int i = 0;
    while (temp != nullptr && i < index - 1){
        temp = temp -> next;
        i++;
    }
    
    if (temp != nullptr){
        newNode -> next = temp->next;
        temp -> next = newNode;
    }
    else{
        delete newNode;
    }
    
}

int main() {
       Node * head = nullptr;
       insertAtHead(head, 1);
       insertAtEnd(head, 40);
       insertAtNthPosition(head, 2, 2);
       insertAtNthPosition(head, 3, 3);
       insertAtEnd(head, 98);
       insertAtEnd(head, 89);
       printLinkedList(head);
    return 0;
}
