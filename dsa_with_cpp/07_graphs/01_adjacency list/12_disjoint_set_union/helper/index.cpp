#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph
{

private:
    // Graph storage
    unordered_map<string, vector<pair<string, int>>> adj;

    // DSU storage
    unordered_map<string, string> parent;
    unordered_map<string, int> rankArr;

public:
    // Create node in DSU
    void makeSet(string node)
    {

        if (parent.find(node) == parent.end())
        {

            parent[node] = node;
            rankArr[node] = 0;
        }
    }

    // Find Parent with Path Compression
    string findParent(string node)
    {

        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    // Union By Rank
    void unionSet(string u, string v)
    {
        string pu = findParent(u);
        string pv = findParent(v);
        if (pu == pv)
            return;
        if (rankArr[pu] < rankArr[pv]){
            parent[pu] = pv;
        }
        else if (rankArr[pv] < rankArr[pu]) {
            parent[pv] = pu;
        }
        else {
           parent[pv] = pu;
            rankArr[pu]++;
        }
    }

    // ONE METHOD handles everything
    void addEdge(string u, string v, int w)
    {

        // Graph storage
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});

        // DSU setup
        makeSet(u);
        makeSet(v);

        // DSU union
        unionSet(u, v);
    }

    void printGraph()
    {

        cout << "Graph:\n";

        for (auto &i : adj)
        {

            cout << i.first << " : ";

            for (auto &j : i.second)
            {

                cout << "(" << j.first << ", "
                     << j.second << ") ";
            }

            cout << "\n";
        }
    }

    void printParents()
    {

        cout << "\nDSU Parents:\n";

        for (auto &i : parent)
        {

            cout << i.first
                 << " -> "
                 << findParent(i.first)
                 << "\n";
        }
    }

    bool isConnected(string u, string v)
    {

        return findParent(u) == findParent(v);
    }
};

int main()
{

    Graph gp;

    gp.addEdge("A", "B", 4);
    gp.addEdge("B", "C", 3);
    gp.addEdge("D", "E", 2);

    gp.printGraph();

    gp.printParents();

    cout << "\n";

    if (gp.isConnected("A", "C"))
    {
        cout << "A and C connected\n";
    }

    if (!gp.isConnected("A", "E"))
    {
        cout << "A and E NOT connected\n";
    }

    return 0;
}