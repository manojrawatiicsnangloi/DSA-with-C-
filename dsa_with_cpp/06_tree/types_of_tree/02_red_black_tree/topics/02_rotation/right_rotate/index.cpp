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

class RedBlackTree{
    Node * root;
    RedBlackTree (){
        root = nullptr;
    }
    void leftRotate(Node *x){
        Node* y = x -> right;
        x -> right = y -> left;
        if (y -> left != nullptr){
            y -> left -> parent = x;
        }

        y -> parent = x -> parent;

        if (x-> parent == nullptr){
            root = y;
        }
        else if (x->parent -> left == x){
            x->parent -> left = y;
        }
        else if (x->parent -> right == x){
            x->parent -> right = y;
        }
        
        y -> left = x;
        x -> parent = y;
    }
    void rightRotate(Node * x){
        Node * y = x ->left;
        x -> left = y->right;

        if (y-> right != nullptr){
            y-> right -> parent = x;
        }
        if (x -> parent == nullptr){
            root = y;
        }
        else if (x -> parent ->left == x){
            y -> parent ->left = x -> parent;
        }
        else if (x -> parent -> right == x){
            y -> parent -> right = x -> parent;
        }
        y -> right = x;
        x-> parent = y; 
    }
};

int main(){

    return 0;
}