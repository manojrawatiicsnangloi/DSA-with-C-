#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    node *children[26];

    bool isEnd;

    vector<int> stationIds;

    vector<string> stationNames;

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

    string cleanWord(string word)
    {
        string result;

        for (char c : word)
        {
            c = tolower(c);

            if (c >= 'a' && c <= 'z')
            {
                result += c;
            }
        }

        return result;
    }
    void insert(string word, int stationId)
    {
        word = cleanWord(word);

        node *temp = root;

        for (char c : word)
        {
            int index = c - 'a';

            if (temp->children[index] == NULL)
            {
                temp->children[index] = new node();
            }

            temp = temp->children[index];
        }

        temp->isEnd = true;

        temp->stationIds.push_back(stationId);

        temp->stationNames.push_back(word);
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
    void collectWords(
        node *n,
        vector<pair<string, int>> &result)
    {
        if (n->isEnd)
        {
            for (int i = 0; i < n->stationIds.size(); i++)
            {
                result.push_back({n->stationNames[i],
                                  n->stationIds[i]});
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (n->children[i] != NULL)
            {
                collectWords(
                    n->children[i],
                    result);
            }
        }
    }
vector<pair<string, int>>
autoComplete(string prefix)
{
    prefix = cleanWord(prefix);

    node *temp = root;

    for (char c : prefix)
    {
        int index = c - 'a';

        if (temp->children[index] == NULL)
        {
            return {};
        }

        temp = temp->children[index];
    }

    vector<pair<string, int>> result;

    collectWords(temp, result);

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

    return 0;
}