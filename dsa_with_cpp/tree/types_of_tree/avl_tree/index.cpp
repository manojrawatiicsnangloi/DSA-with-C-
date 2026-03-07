#include <iostream>
#include <algorithm>

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int value)
    {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class AvlTree
{
private:
    Node *root = nullptr;
    void insert(int value)
    {
        root = insertRec(root, value);
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *t2 = y->left;

        y->left = x;
        x->right = t2;
        x->height = 1 + std::max(height(x->left), height(x->right));
        y->height = 1 + std::max(height(y->left), height(y->right));
        return y;
    }

    Node *rightRotate(Node *x)
    {
        Node *y = x->left;
        Node *t2 = y->right;

        y->right = x;
        x->left = t2;
        x->height = 1 + std::max(height(x->left), height(x->right));
        y->height = 1 + std::max(height(y->left), height(y->right));
        return y;
    }

    Node *insertRec(Node *n, int value)
    {
        if (n == nullptr)
            return new Node(value);
        if (n->data > value)
            n->left = insertRec(n->left, value);
        if (n->data < value)
            n->right = insertRec(n->right, value);
        n->height = 1 + std::max(height(n->left), height(n->right));

        int balance = getBalance(n);

        if ((balance > 1) && value < n-> left -> data)
            return rightRotate(n);

        if ((balance > 1) && value > n-> left -> data)
        {
            n->left = leftRotate(n);
            return rightRotate(n);
        }

        if ((balance < -1) && value > n->right -> data)
            return leftRotate(n);
        if (balance < -1 && value < n->right -> data)
        {
            n->right = rightRotate(n);
            return leftRotate(n);
        }
        return n;
    }

    int height(Node *n)
    {
        return n == nullptr ? 0 : n->height;
    }

    int getBalance(Node *n)
    {
        return n == nullptr ? 0 : height(n->left) - height(n->right);
    }

    void inorder(Node *n)
    {
        if (n == nullptr)
            return;
        inorder(n->left);
        std::cout << n->data;
        inorder(n->right);
    }

public:
    void _inorder()
    {
        inorder(root);
    }
    void buildTree(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            insert( arr[i]);
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
    return 0;
}