#include <iostream>
#include <unordered_map>
using namespace std;

class node{
    public:int key, value;
    node * prev;
    node * next;
    node(int k, int v){
        this -> key = k;
        this -> value = v;
    }
};

class lru_cache{
    int capacity;
    unordered_map<int, node *> cache;
    node * head;
    node * tail;
    public : lru_cache(int cap){
        this -> capacity = cap;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        tail -> prev = head;
        head -> next = tail;
    }
    void addNode(node * n){
            n-> next = head -> next;
            n-> prev = head;

            head -> next-> prev = n;
            head -> next = n;
    }

    void removeNode(node * n){
        n -> prev -> next = n -> next;
        n -> next -> prev = n -> prev;
    }

    int get(int key){
        if (cache.find(key) == cache.end()){
            return -1;
        }
        node * n = cache[key];
        removeNode(n);
        addNode(n);
    }
    void put(int key, int value){
        if (cache.find(key) != cache.end()){
            cache.erase(key);
            node * n = cache[key];
            removeNode(n);
            delete n;
        }
        if (cache.size() == capacity){
            node * n = tail->prev;
            removeNode(n);
            cache.erase(key);
            delete n;
        }
        node * newNode = new node(key, value);
        addNode(newNode);
        cache[key] = newNode;
    }

    void printCache(){
        node * temp = head -> next;
        while (temp != tail){
            cout << "( " << temp->key << " : " << temp->value << ") \n";
            temp = temp-> next;
        }
    }
};

int main(){
        lru_cache cache(3);

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