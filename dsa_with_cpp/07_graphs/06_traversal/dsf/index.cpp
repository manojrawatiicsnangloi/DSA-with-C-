
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class graphs_dfs
{
private:
    unordered_map<string, vector<pair<string, int>>> root;

public:
    void addEdge(string u, string v, int w)
    {
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void _dfs(string s)
    {
        unordered_map<string, bool> vis;
        dfs(s, vis);
    }
    void dfs(string node, unordered_map<string, bool> &vis)
    {
        vis[node] = true;
        cout << node << " ";
        for (auto &i : root[node])
        {
            if (!vis[i.first]){
                dfs(i.first, vis);
            }
        }
    }
    void printGraph()
    {
        for (auto &i : root)
        {
            cout << i.first << " : ";
            for (pair<string, int> j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    graphs_dfs gp;

    gp.addEdge("D", "A", 4);
    gp.addEdge("A", "E", 4);
    gp.addEdge("D", "E", 2);
    gp.addEdge("A", "C", 3);
    gp.addEdge("E", "G", 5);
    gp.addEdge("E", "C", 4);
    gp.addEdge("C", "B", 3);
    gp.addEdge("C", "F", 4);
    gp.addEdge("G", "C", 5);
    gp.addEdge("F", "B", 2);
    gp.addEdge("G", "F", 5);

    gp.printGraph();
    gp._dfs("D");
    return 0;
}