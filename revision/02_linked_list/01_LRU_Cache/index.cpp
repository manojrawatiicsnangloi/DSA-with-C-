#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class node{
    public:
    int key;
    int value;
    node * next, *prev;
    node(int k, int v){
        this ->key = k;
        this -> value = v;
        this -> next = this -> prev = nullptr;
    }
};
class LRUCache{
    int cap;
    unordered_map <int, node *>cache; 
    node * head;
    node * tail;
public:
    LRUCache(int c){
        this -> head = new node(-1, -1);
        this -> tail = new node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        this -> cap = c;
    }

    void add(node * node){
        node -> next = head -> next;
        head -> next = node;

        node -> prev = head;
        node -> next -> prev = node;
    }

    
    void removeNode(node * n){
        n -> prev -> next = n -> next;
        n -> next -> prev = n -> prev;
    }


    int getCache(int key){
        if (cache.find(key) == cache.end()){
            return -1;
        }
        node * n = cache[key];
        removeNode(n);
        add(n);
        return n -> value;
    }

    void put(int key, int value){
        if (cache.find(key) != cache.end()){
            node * n = cache[key];
            removeNode(n);
            cache.erase(key);
            delete n;
        }
        if (cache.size() == cap){
            node * lru = tail -> prev;
            removeNode(lru);
            cache.erase(lru-> key);
            delete lru;
        }
        node * newNode =  new node(key, value);
        add(newNode);
        cache[key] = newNode;
    }
    void printCache(){
         node* temp = head->next;
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

    cache.getCache(1);       // access 1 → becomes MRU
    cache.printCache(); // (1,10) (3,30) (2,20)

    cache.put(4, 40);   // removes LRU (2)
    cache.printCache(); // (4,40) (1,10) (3,30)

    cout << cache.getCache(2) << endl; 
    return 0;
}