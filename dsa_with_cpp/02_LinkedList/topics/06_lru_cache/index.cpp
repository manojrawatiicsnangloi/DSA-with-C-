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
    public:
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

    int get(int key){
         if (cache.find(key) == cache.end()) {
            return -1;
        }
        Node* node = cache[key];
        deleteNode(node);
        addNode(node);
        return node->value;
    }

    void put(int key, int value){
        if (cache.find(key) != cache.end()){
            Node * existing = cache[key];
            deleteNode(existing);
            cache.erase(key);
            delete existing;
        }

        if (cache.size() == capacity){
            Node * lru = tail -> prev;
            deleteNode(lru);
            cache.erase(lru->key);
            delete lru;
        }
        Node * newNode = new Node(key, value);
        addNode(newNode);
        cache[key] = newNode;
    }

      void printCache() {
        Node* temp = head->next;
        while (temp != tail) {
            cout << "(" << temp->key << "," << temp->value << ") ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

     LRUCache cache(3);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    cache.printCache(); // (3,30) (2,20) (1,10)

    cache.get(1);       // access 1 → becomes MRU
    cache.printCache(); // (1,10) (3,30) (2,20)

    cache.put(4, 40);   // removes LRU (2)
    cache.printCache(); // (4,40) (1,10) (3,30)

    cout << cache.get(2) << endl; 
    return 0;
}