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

    node* getHead() {
    return root;
}

void setHead(node* head) {
    root = head;
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

    static node* mergeList(node * l1, node * l2){
        node * head = nullptr;
        node * tail = nullptr;

        while (l1 != nullptr && l2 != nullptr){
            node * temp;
            if (l1->data < l2-> data){
                temp = l1;
                l1 = l1 -> next;
            }
            else{
                temp = l2;
                l2 = l2 -> next;
            }
            if (head == nullptr){
                head = temp;
                tail = temp;
            }
            else{
                tail -> next = temp;
                tail = temp;
            }
        }

        if (l1 != nullptr) tail -> next = l1;
        if (l2 != nullptr) tail -> next = l2;
        return head;
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
    linkedlist list1;
    list1.insertAtHead(3);
    list1.insertAtHead(1);
    list1.insertAtHead(0);
    list1.insertAtNthPosition(2, 2);
    list1.insertAtEnd(4);
    list1.insertAtEnd(5);
    // list1.pLinkedList();


    // 
    linkedlist list2;
    list2.insertAtHead(6);
    list2.insertAtEnd(7);
    list2.insertAtEnd(8);
    list2.insertAtEnd(9);
    list2.insertAtEnd(10);
    list2.insertAtEnd(11);

    
    node* listHead = linkedlist::mergeList(list1.getHead(), list2.getHead());
    linkedlist list;

    list.setHead(listHead);
    list.pLinkedList();
    return 0;
}