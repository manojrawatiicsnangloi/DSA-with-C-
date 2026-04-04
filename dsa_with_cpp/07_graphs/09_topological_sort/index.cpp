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
    void _dfs(string &node, unordered_map<string, bool>&visited){
        if(!visited[node]){
            visited[node] = true;
            _dfs(node, visited);
        }
    }
public:
    void insert(string u, string v, int w)
    {
        root[u].push_back({v, w});
    }

    void dfs(string s){
        unordered_map<string, bool> visited;
        visited[s] = true;
        _dfs(s, visited);
    }

    void bfs(){}

    void printGraph()
    {
        for (auto &i : root)
        {
            cout << i.first << " : ";
            for (pair<string, int> &j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << ") ";
            }
        }
    }
};

int main()
{

    return 0;
}