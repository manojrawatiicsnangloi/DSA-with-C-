#include <iostream>

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
        this->isBlack = false;
    }
};

class RedBlackTree
{
    Node *root;
    RedBlackTree()
    {
        root = nullptr;
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
        while (root != x && !(x->parent->isBlack) && (!x->isBlack))
        {
            parent = x->parent;
            grand_parent = parent->parent;
            if (parent == grand_parent->left)
            {
                Node *uncle = grand_parent->right;
                if (uncle != nullptr && !uncle->isBlack)
                {
                    grand_parent->isBlack = false;
                    parent->isBlack = true;
                    uncle->isBlack = true;
                    x = grand_parent;
                }
            }
            else{
                Node * uncle = grand_parent -> left;
                if (uncle != nullptr && !uncle -> isBlack){
                    grand_parent -> isBlack = false;
                    parent -> isBlack = true;
                    uncle -> isBlack = true;
                    x = grand_parent;
                }
            }
        }
    }
};

int main()
{
    return 0;
}