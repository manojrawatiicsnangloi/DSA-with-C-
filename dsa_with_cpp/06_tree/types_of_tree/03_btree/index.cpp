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
    void insertAtNonFull(int data){
        int i = n - 1;
        if (leaf){
            while (i >= 0 && data < keys[i]){
                keys[i + 1] = i;
                i--;
            }
            keys[i + 1] = data;
            n++;
        }
        else{
            while (i >= 0 && keys[i] > data){
                i--;
            }
            if (C[i + 1]->n == 2*t - 1) {
                splitChild(i + 1, C[i + 1]);

                if (keys[i + 1] < data){
                    i++;
                }
            }
            C[i + 1]->insertAtNonFull(data);
        }        
    }

    void splitChild(int i, node * n){}
};
int main(){
    return 0;
}