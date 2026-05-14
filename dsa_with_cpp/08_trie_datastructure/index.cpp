#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    node *children[26];
    bool isEnd;
    node()
    {
        isEnd = false;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class trie
{
private:
    node *root;

public:
    trie()
    {
        root = new node();
    }

    void insert(string word)
    {
        node *temp = root;
        for (char i : word)
        {
            int index = i - 'a';
            if (temp->children[index] == NULL)
            {
                temp->children[index] = new node();
            }
            temp = temp->children[index];
        }
        temp->isEnd = true;
    }
    bool search(string word)
    {
        node *temp = root;
        for (char i : word)
        {
            int index = i - 'a';
            if (temp->children[index] == NULL)
                return false;
            temp = temp->children[index];
        }
        return temp->isEnd;
    }
    void collectWords(node *n, string current, vector<string> &result)
    {
        if (n->isEnd)
        {
            result.push_back(current);
        }
        for (int i = 0; i < 26; i++)
        {
            if (n->children[i] != NULL)
            {
                char index = 'a' + i;
                collectWords(n->children[i], current + index, result);
            }
        }
    }

    vector<string> autoCompeleate(string prefix)
    {
        node *temp = root;
        for (char i : prefix)
        {
            int index = i - 'a';
            if (temp->children[index] == NULL)
                return {};
            temp = temp->children[index];
        }
        vector<string> result;
        collectWords(temp, prefix, result);
        return result;
    }

    bool startWith(string prefix)
    {
        node *temp = root;
        for (char i : prefix)
        {
            int index = i - 'a';
            if (root->children[index] == NULL)
                return false;
        }
        return true;
    }
};

int main()
{
    trie t;
    t.insert("sarukh");
    t.insert("salman");
    t.insert("aman");
    t.insert("amit");
    t.insert("akansha");
    t.insert("anjali");
    t.insert("bahaskar");
    t.insert("babita");
    t.insert("baba");
    t.insert("cat");
    t.insert("car");
    t.insert("can");

    string username;
    cin >> username;
    vector<string> res = t.autoCompeleate(username);
    for (string &i : res)
    {
        cout << i << endl;
    }
    // if (t.search(username)){
    //     cout << "Already Exists";
    // }
    // else{
    //     cout << "Not Exists";
    // }
    return 0;
}