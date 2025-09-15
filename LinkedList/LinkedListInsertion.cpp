// Online C++ compiler to run C++ program online
#include <iostream>

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
void deleteAtEnd(Node *&head){
    if (head == nullptr) return;
    Node * temp = head;
    while (temp -> next -> next != nullptr){
        temp = temp->next;
    } 
    delete temp -> next;
    temp -> next = nullptr;
}

void printLinkedList(Node * head){
    Node * temp = head;
    while (temp != nullptr){
        std::cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    std::cout << " nullptr \n";
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
void deleteAtHead(Node * & head){
    if (head == nullptr){
        return;
    }
    Node * temp = head;
    head = head-> next;
    delete temp;
}

void insertAtNthPosition(Node * head, int value, int index){
    Node * newNode = new Node(value);
    if (index == 0){
        insertAtHead(head, value);
        return;
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

void deleteAtNthPosition(Node *&head, int index){
    if (index == 0){
        deleteAtHead(head);
        return;
    }
    Node * temp = head;
    int i = 0;
    
    while (temp != nullptr && i < index - 1){
        temp = temp -> next;
        i++;
    }
    
    if (temp != nullptr && temp -> next != nullptr){
        Node * nodeToDelete = temp -> next;
        temp -> next = nodeToDelete -> next;
        delete nodeToDelete;
    }
}

int main() {
       Node * head = nullptr;
       insertAtHead(head, 1);
       insertAtEnd(head, 2);
       insertAtNthPosition(head, 2, 3);
       insertAtNthPosition(head, 3, 4);
       insertAtEnd(head, 5);
       insertAtEnd(head, 6);
       insertAtEnd(head, 7);
       insertAtEnd(head, 8);
       insertAtEnd(head, 9);
       insertAtEnd(head, 10);
       insertAtEnd(head, 11);
       
       printLinkedList(head);
       deleteAtHead(head);
       printLinkedList(head);
       deleteAtEnd(head);
       printLinkedList(head);
       deleteAtNthPosition(head, 3);
       printLinkedList(head);
    return 0;
}