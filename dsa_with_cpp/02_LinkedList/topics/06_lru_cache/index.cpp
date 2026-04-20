#include <iostream>

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int key, value;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        prev = next = nullptr;
    }
};

class LRUCache {
    private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    LRUCache(int cap){
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    void addNode(Node * node){
        node -> next = head -> next;
        node -> prev = head;

        head -> next -> prev = node;
        head -> next = node;
    }

    void deleteNode(Node * node){
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

};

int main(){
    return 0;
}