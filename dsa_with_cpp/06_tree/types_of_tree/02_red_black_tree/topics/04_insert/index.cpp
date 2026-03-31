#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *parent, *left, *right;
    bool isBlack;
   Node(int v)
{
    this->data = v;
    this->left = this->right = nullptr;
    this->parent = nullptr;  
    this->isBlack = false;
}
};

class RedBlackTree
{
private:
    Node *root;

public:
    RedBlackTree()
    {
        root = nullptr;
    }
    Node *_insert(Node *root, Node *x)
    {
        if (root == nullptr)
            return x;

        if (x->data < root->data)
        {
            root->left = _insert(root->left, x);
            root->left->parent = root;
        }
        else
        {
            root->right = _insert(root->right, x);
            root->right->parent = root;
        }

        return root;
    }

    void leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
        {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x->parent->left == x)
        {
            x->parent->left = y;
        }
        else if (x->parent->right == x)
        {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node *x)
    {
        Node *y = x->left;
        x->left = y->right;

        if (y->right != nullptr)
        {
            y->right->parent = x;
        }

        y->parent = x->parent; // ✅ VERY IMPORTANT

        if (x->parent == nullptr)
        {
            root = y;
        }
        else if (x == x->parent->left)
        {
            x->parent->left = y;
        }
        else
        {
            x->parent->right = y;
        }

        y->right = x;
        x->parent = y;
    }

    void fixVoilation(Node *x)
    {
        Node *parent = nullptr;
        Node *grand_parent = nullptr;

      while (x != root && x->parent != nullptr && !x->parent->isBlack)
        {
            parent = x->parent;
            if (parent == nullptr)
                break;

            grand_parent = parent->parent;
            if (grand_parent == nullptr)
                break;
            if (parent == grand_parent->left)
            {
                Node *uncle = grand_parent->right;

                // Case 1: Uncle RED
                if (uncle != nullptr && !uncle->isBlack)
                {
                    grand_parent->isBlack = false;
                    parent->isBlack = true;
                    uncle->isBlack = true;
                    x = grand_parent;
                }
                else
                {
                    // Triangle
                    if (x == parent->right)
                    {
                        leftRotate(parent);
                        x = parent;
                        parent = x->parent;
                    }

                    rightRotate(grand_parent);
                    parent = x->parent; 
                    if (parent != nullptr && grand_parent != nullptr){
                        swap(parent->isBlack, grand_parent->isBlack);
                    }
                    x = parent;
                }
            }
            else
            {
                Node *uncle = grand_parent->left;

                if (uncle != nullptr && !uncle->isBlack)
                {
                    grand_parent->isBlack = false;
                    parent->isBlack = true;
                    uncle->isBlack = true;
                    x = grand_parent;
                }
                else
                {
                    if (x == parent->left)
                    {
                        rightRotate(parent);
                        x = parent;
                        parent = x->parent;
                    }

                    leftRotate(grand_parent);
                    parent = x->parent;
                    if (parent != nullptr && grand_parent != nullptr){
                        swap(parent->isBlack, grand_parent->isBlack);
                    }
                    x = parent;
                }
            }
        }

        root->isBlack = true;
    }
    void _inorder(Node *root)
    {
        if (root == nullptr)
            return;
        _inorder(root->left);
        cout << root->data << " ";
        _inorder(root->right);
    }

public:
    void insert(int data)
    {
        Node *x = new Node(data);
        root = _insert(root, x);
        fixVoilation(x);
        root->isBlack = true;
    }

    void pRoot()
    {
        cout << "\n Root :" << root->data << " \n";
    }

    void inorder()
    {
        _inorder(root);
    }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    RedBlackTree rb;
    for (int i : v)
    {
        rb.insert(i);
    }
    rb.pRoot();
    rb.inorder();
    return 0;
}