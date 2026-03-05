#include <iostream>
#include <algorithm>

class Node{
    public:int data;
    Node * left;
    Node * right;
    int height;
    Node(int value){
        this -> data = value;
        this -> left = nullptr;
        this -> right = nullptr;
        this -> height = 1;
    }
};

class AvlTree{
    private: Node * root = nullptr;

    public: void insert(int value){
        root = insertRec(root, value);        
    }

    Node * insertRec(Node *node, int value){
        if (node == nullptr) return new Node(value);
        if (node -> data > value) node -> left = insertRec(node -> left, value);
        if (node -> data < value) node -> right = insertRec(node -> right, value);
        
        node ->height = 1 + std::max(height(node ->left), height(node ->right));
        int balance = getBalance(node);
        if (balance > 1 && value < node -> left -> data){
            return rightRotate(node);
        }
        if (balance < -1 && value > node -> right ->  data){
            return leftRotate(node);
        }
        
        if (balance > 1 && value > node -> left -> data){
            node -> left = leftRotate(node -> left);
            return rightRotate(node);
        }
        if (balance < -1 && value < node -> right ->  data){
            node -> right = rightRotate(node -> right);
            return leftRotate(node);
        }
       

        return node;
    }

    int height(Node * node){
        return node == nullptr ? 0 : node -> height;
    }
    int getBalance(Node * node){
        return node == nullptr ? 0 : height(node ->left) - height(node -> right);
    }

     Node * rightRotate(Node * node){
            Node *y = node -> left;
            Node *t2 = y ->  right;
            y -> right = node;
            node -> left = t2;
            node -> height = std::max(height(node -> left), height(node -> right)) + 1;
            y -> height = std::max(height(y -> left), height(y -> right)) + 1;
            return y;
        }
        Node * leftRotate(Node * node){
            Node * y = node -> right;
            Node * t2 = y ->left;
        
            y -> left = node;
            node -> right = t2;

            node -> height = 1 + std::max(height(node->left), height(node ->right));
            y -> height = 1 + std::max(height(y->left), height(y ->right));
            return y;
        }
    public: void buildTree(int arr[], int size){
        for (int i = 0; i < size; i++){
            insert(arr[i]);
        }
    }


};

int main(){
    AvlTree tree;
    int arr [] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    tree.buildTree(arr, size);
    return 0;
}