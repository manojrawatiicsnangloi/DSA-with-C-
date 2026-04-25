#include <iostream>
using namespace std;

class node
{
public:
    int t;
    int *keys;
    node **C;
    int n; // current number of keys
    bool leaf;
    node(int p_t, bool leaf)
    {
        this->t = p_t;
        this->leaf = leaf;
        this->keys = new int[2 * t - 1];
        this->C = new node *[2 * t];
        this->n = 0;
    }

    void traversal()
    {
        int i;
        for (i = 0; i < n; i++)
        {
            if (!leaf)
            {
                C[i]->traversal();
            }
            cout << keys[i] << " ";
        }
        if (!leaf)
        {
            C[i]->traversal();
        }
    }
    void insertAtNonFull(int data)
    {
        int i = n - 1;
        if (leaf)
        {
            while (i >= 0 && data < keys[i])
            {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1] = data;
            n++;
        }
        else
        {
            while (i >= 0 && keys[i] > data)
            {
                i--;
            }
            if (C[i + 1]->n == 2 * t - 1)
            {
                splitChild(i + 1, C[i + 1]);

                if (keys[i + 1] < data)
                {
                    i++;
                }
            }
            C[i + 1]->insertAtNonFull(data);
        }
    }

    void splitChild(int i, node *newNode)
    {
        node *right = new node(newNode->t, newNode->leaf);
        right->n = t - 1;

        // copy keys
        for (int j = 0; j < t - 1; j++)
        {
            right->keys[j] = newNode->keys[j + t];
        }

        // copy children
        if (!newNode->leaf)
        {
            for (int j = 0; j < t; j++)
            {
                right->C[j] = newNode->C[j + t];
            }
        }

        newNode->n = t - 1;

        //  SHIFT CHILD POINTERS (YOU MISSED THIS)
        for (int j = n; j >= i + 1; j--)
        {
            C[j + 1] = C[j];
        }

        C[i + 1] = right;

        // shift keys in parent
        for (int j = n - 1; j >= i; j--)
        {
            keys[j + 1] = keys[j];
        }

        // move middle key
        keys[i] = newNode->keys[t - 1];

        n++;
    }
};

class BTree
{
    node *root;
    int t;

public:
    BTree(int t)
    {
        this->t = t;
        root = nullptr;
    }

    void insert(int k)
    {
        if (root == nullptr)
        {
            root = new node(t, true);
            root->keys[0] = k;
            root->n = 1;
        }
        else
        {
            if (root->n == 2 * t - 1)
            {
                node *s = new node(t, false);
                s->C[0] = root;

                s->splitChild(0, root);

                int i = 0;
                if (s->keys[0] < k)
                    i++;

                s->C[i]->insertAtNonFull(k);

                root = s;
            }
            else
            {
                root->insertAtNonFull(k);
            }
        }
    }

    void traverse()
    {
        if (root != nullptr)
            root->traversal();
    }
};
int main()
{
    BTree tree(2);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(15);
    tree.insert(16);
    tree.insert(17);
    tree.insert(18);
    tree.insert(19);

    tree.traverse();
    return 0;
}