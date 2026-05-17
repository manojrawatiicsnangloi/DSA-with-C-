#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class matrix_graph
{
    vector<vector<int>> root;
    bool _dfs(int u, int parent, vector<bool> &vis)
    {
        cout << u << " ";
        vis[u] = true;
        for (int i = 0; i < root[u].size(); i++)
        {
            if (root[u][i] == 1){
            if (!vis[i] )
            { 
                if (_dfs(i, u, vis)){
                    return true;
                }
            }
            else if (i != parent){
                return true;
            }   
            }
        }
        return false;
    }

public:
    matrix_graph(int size)
    {
        root.resize(size, vector<int>(size, 0));
    }
    void addEdge(int u, int v)
    {
        root[u][v] = 1;
        root[v][u] = 1;
    }
    void printGraph()
    {

        for (int i = 0; i < root.size(); i++)
        {

            for (int j = 0; j < root[i].size(); j++)
            {

                cout << root[i][j] << " ";
            }

            cout << "\n";
        }
    }

    void _bfs(int start)
    {
        vector<bool> visited(root.size(), false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int i = 0; i < root.size(); i++)
            {
                if (root[node][i] == 1 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    void isCycle(int start) {
        vector<bool> vis(root.size(), false);
        if (_dfs(start, -1, vis)){
            cout << "Cycle Detected";
        }
    }

};

int main()
{
    matrix_graph g(5);
    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(2, 4);


    g.isCycle(0);
    // g.printGraph();
    return 0;
}