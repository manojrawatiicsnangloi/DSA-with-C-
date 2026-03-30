#include <iostream>
using namespace std;

enum Color
{
    RED,
    BLACK
};

class Node
{
public:
    int data;
    Color color;
    Node *left, *right, *parent;

    Node(int data)
    {
        this->data = data;
        left = right = parent = NULL;
        color = RED; // new node always red
    }
};

class RedBlackTree
{
private:
    Node *root;

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

        y->parent = x->parent; //
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

    void fixViolation(Node *pt)
    {
        Node *parent_pt = nullptr;
        Node *grand_parent_pt = nullptr;

        while (pt != root && pt->color == RED && pt->parent->color == RED)
        {
            parent_pt = pt->parent;
            grand_parent_pt = parent_pt->parent;
            // Parent is LEFT child
            if (parent_pt == grand_parent_pt->left)
            {
                Node *uncle_pt = grand_parent_pt->right;

                // Case 1: Uncle is RED
                if (uncle_pt != nullptr && uncle_pt->color == RED)
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    // Case 2: Triangle
                    if (pt == parent_pt->right)
                    {
                        leftRotate(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    // Case 3: Line
                    rightRotate(grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
            else
            {
                // Mirror case

                Node *uncle_pt = grand_parent_pt->left;

                // Case 1
                if (uncle_pt != nullptr && uncle_pt->color == RED)
                {
                    grand_parent_pt->color = RED;
                    parent_pt->color = BLACK;
                    uncle_pt->color = BLACK;
                    pt = grand_parent_pt;
                }
                else
                {
                    // Case 2
                    if (pt == parent_pt->left)
                    {
                        rightRotate(parent_pt);
                        pt = parent_pt;
                        parent_pt = pt->parent;
                    }

                    // Case 3
                    leftRotate(grand_parent_pt);
                    swap(parent_pt->color, grand_parent_pt->color);
                    pt = parent_pt;
                }
            }
        }
        root->color = BLACK; // root must always be black
    }
    Node *insert(Node *root, Node *pt)
    {
        if (root == nullptr)
            return pt;

        if (pt->data < root->data)
        {
            root->left = insert(root->left, pt);
            root->left->parent = root;
        }
        else
        {
            root->right = insert(root->right, pt);
            root->right->parent = root;
        }

        return root;
    }

    void inorderHelper(Node *root)
    {
        if (root == NULL)
            return;

        inorderHelper(root->left);
        cout << root->data << "(" << (root->color == RED ? "R" : "B") << ") ";
        inorderHelper(root->right);
    }

public:
    RedBlackTree() { root = NULL; }

    void insert(int data)
    {
        Node *pt = new Node(data);

        root = insert(root, pt);
        fixViolation(pt);
    }

    void inorder()
    {
        inorderHelper(root);
        cout << endl;
    }
};

int main()
{
    RedBlackTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);

    tree.inorder();

    return 0;
}