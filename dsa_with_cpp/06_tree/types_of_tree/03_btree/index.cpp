#include <iostream>
using namespace std;

class node{
    int t;
    int * keys;
    node **C;
    int n;         // current number of keys
    bool leaf;
    node(int p_t, bool leaf){
        this -> t = p_t;
        this -> leaf = leaf;
        this -> keys = new int[2 * t - 1];
        this -> C = new node* [2 * t];
        this -> n = 0;
    }

    void traversal(){
        int i;
        for (i = 0; i < n; i++){
            if (!leaf){
                 C[i]->traversal();
            }
            cout << keys[i];
        }
        if (!leaf){
            C[i]->traversal();
        }
    }

    
};
int main(){
    return 0;
}