#include <iostream>
using namespace std;

class node{
    public : node * children[26];
    bool isEnd;
    node(){
        isEnd = false;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
    }
};

class trie{
    private : node * root; 
    
    public:
    trie(){
        root = new node();
    }

    void insert(string word){
        node * temp = root;
        for (char i: word){
            int index = i - 'a';
            if (temp -> children[index] == NULL){
                temp -> children[index] = new node();
            }
            temp = temp-> children[index];
        }
        temp->isEnd = true;
    }
    bool search(string word){
        node * temp = root;
        for (char i : word){
            int index = i - 'a';
            if (temp -> children[index] == NULL) return false;
            temp = temp -> children[index];
        }
        return temp-> isEnd;
    }
};


int main(){
    trie t;
    t.insert("sarukh");
    t.insert("salman");
    t.insert("elon");

    string username;
    cin >> username;
    if (t.search(username)){
        cout << "Already Exists";
    }
    else{
        cout << "Not Exists";
    }
    return 0;
}