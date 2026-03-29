#include <iostream>

class Node{
    public:
    int data;
    Node * parent, *left, *right;
    bool isBlack;
    Node(int v){
        this -> data = v;
        this -> left = this -> right = nullptr;
        this -> isBlack = false;
    }
};
int main(){

    return 0;
}