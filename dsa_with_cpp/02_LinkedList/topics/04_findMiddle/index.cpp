#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        this->data = value;
        this->next = nullptr;
    }
};

class linkedlist
{
private:
    node *root;

public:
    linkedlist()
    {
        root = nullptr;
    }

    void insertAtHead(int value)
    {
        node *newNode = new node(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }
        newNode->next = root;
        root = newNode;
    }

    void deleteAtHead(){
        if (root == nullptr) return;
        node* temp = root;
        root = root -> next;
        delete temp;
    }

    void deleteAtNthPosition(int n){
        if (root == nullptr) return;
        if (n == 0){
            deleteAtHead();
            return;
        }
        node * temp = root;
        int i = 0;
        while (temp != nullptr && i < n - 1){
            temp = temp -> next;
            i++;
        }
        if (temp != nullptr && temp -> next != nullptr){
            node * nodeTodelete = temp -> next;
            temp -> next = temp -> next -> next;
            delete nodeTodelete;
        }
    }


    void deleteAtEnd(){
        if (root == nullptr) return;
        node * temp = root;
        while (temp -> next -> next != nullptr){
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = nullptr;
    }
    
    void insertAtNthPosition(int value, int n)
    {
        node *newNode = new node(value);
        if (n == 0 || root == nullptr)
        {
            insertAtHead(value);
            return;
        }
        node *temp = root;
        int i = 0;
        while (temp->next != nullptr && i < n - 1)
        {
            temp = temp->next;
            i++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    node * findMiddle(){
        node * slow = root;
        node * fast = root;
        while (slow != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    void insertAtEnd(int value)
    {
        node *newNode = new node(value);
        if (root == nullptr)
        {
            insertAtHead(value);
            return;
        }
        node *temp = root;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void pLinkedList()
    {
        node *temp = root;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    linkedlist list;
    list.insertAtHead(3);
    list.insertAtHead(1);
    list.insertAtHead(0);
    list.insertAtNthPosition(2, 2);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.pLinkedList();
    return 0;
}