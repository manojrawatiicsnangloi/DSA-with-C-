#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class graphs
{

private:
    unordered_map<string, vector<pair<string, int>>> root;
    void _dfs(string &node, unordered_map<string, bool> &visited)
    {
        cout << node << " ";
        for (pair<string, int> &i : root[node])
        {
            if (!visited[i.first])
            {
                visited[i.first] = true;
                _dfs(i.first, visited);
            }
        }
    }

public:
    void insert(string u, string v, int w)
    {
        root[u].push_back({v, w});
    }

    void dfs(string s)
    {
        unordered_map<string, bool> visited;
        cout << "\nDFS ";
        visited[s] = true;
        _dfs(s, visited);
    }

    void bfs(string s) {
        cout << "\nBFS ";
        queue<string> qu;
        unordered_map <string, bool> visited;
        qu.push(s);
        visited[s] = true;
        while (!qu.empty()){
            string node = qu.front();
            qu.pop();
            cout << node << " ";
            for (pair<string, int> &i : root[node]){
                if (!visited[i.first]){
                    qu.push(i.first);
                    visited[i.first] = true;
                }
            }
        }
    }

    void printGraph()
    {
        for (auto &i : root)
        {
            cout << i.first << " : ";
            for (pair<string, int> &j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    graphs g;
    g.insert("D", "A", 4);
    g.insert("D", "E", 2);
    g.insert("A", "E", 4);
    g.insert("A", "C", 3);
    g.insert("E", "C", 4);
    g.insert("E", "G", 5);
    g.insert("C", "B", 3);
    g.insert("C", "F", 4);
    g.insert("C", "G", 5);
    g.insert("G", "C", 5);
    g.insert("G", "F", 5);

    g.printGraph();

    g.bfs("A");
    g.dfs("A");
    return 0;
}