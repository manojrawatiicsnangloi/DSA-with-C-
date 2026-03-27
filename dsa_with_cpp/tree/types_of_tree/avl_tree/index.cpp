#include <iostream>
using namespace std;

class Node{
    public: int data;
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
    private : Node * root;
    public : AvlTree(){
        root = nullptr;
    }

    void pR (){
       cout << "\nRoot : "  << root -> data << "\n";
    }
    Node * insertRec(Node * n, int value){
        if (n == nullptr){
            return new Node(value);
        }
        if (value < n -> data ){
            n-> left = insertRec(n -> left, value);
        }
        else if (value > n -> data ){
            n-> right = insertRec(n -> right, value);
        }
        else{
            return n;
        }

        n -> height = 1 + max(height(n-> left), height(n -> right));
        int balance = getBalance(n);
        // ll
        if (balance > 1 && value < n -> left -> data){
            return rightRotate(n);
        }

        // lr
        if (balance > 1 && value > n -> left -> data){
            n -> left = leftRotate(n->left);
            return rightRotate(n);
        }
        if (balance < -1 && value > n -> right -> data){
            return leftRotate(n);
        }

        if (balance < -1 && value < n -> right -> data){
            n -> right = rightRotate(n -> right);
            return leftRotate(n);
        }
        return n;
    }

    int getBalance(Node * n){
        return n == nullptr ? 0 : height(n -> left) - height(n -> right);
    }

    Node * rightRotate(Node * node) {
        Node * y = node -> left;
        Node * t2 = y -> right;

        y -> right = node;
        node -> left = t2;
        node -> height =  1 + max(height(node -> right), height(node -> left));
        y -> height =  1 + max(height(y -> right), height(y -> left));
        return y;
    }

    Node * leftRotate(Node * x){
        Node * y = x -> right;
        Node * t2 = y -> left;

        y ->left = x;
        x -> right = t2;
        x -> height =  1 + max(height(x -> right), height(x -> left));
        y -> height =  1 + max(height(y -> right), height(y -> left));
        return y;
    }

    int height (Node * n){
        return n == nullptr ? 0:  n-> height;
    }


    void inorder(Node * n){
        if (n == nullptr) return;
        inorder(n -> left);
        cout << n->data;
        inorder(n -> right);
    }
     void _inorder()
    {
        inorder(root);
    }
     void insert(int value)
    {
        root = insertRec(root, value);
    }

    void buildTree(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            insert(arr[i]);
        }
    }
};

int main()
{
    AvlTree tree;
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    tree.buildTree(arr, size);
    tree._inorder();
    tree.pR();
    return 0;
}