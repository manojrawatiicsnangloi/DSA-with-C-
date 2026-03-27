#include <iostream>
using namespace std;


class Node{
    public:
    Node * children[26];
    bool isEnd;
    Node(){
        isEnd = false;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    Node * root;
    public: 
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node * temp = root;
        for (char c: word){
            int index = c - 'a';
            if (temp -> children[index] == NULL){
                temp -> children[index] = new Node();
            }
            temp = temp -> children[index];
        }
        temp -> isEnd = true;
    }
     bool search(string word) {
        Node * node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == NULL)
                return false;
            node = node->children[index];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node * node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == NULL)
                return false;
            node = node->children[index];
        }
        return true;
    }

    
};

int main(){
    Trie t;
    t.insert("apple");
    t.insert("app");
    t.insert("banana");
    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.search("appl") << endl;
    cout << t.startsWith("app") << endl;
    return 0;
}