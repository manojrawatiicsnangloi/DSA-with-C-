#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class matrix_graph
{
    vector<vector<int>> root;
    void _dfs(int u,stack<int> &st,  vector<bool> &vis)
    {
        vis[u] = true;
        for (int i = 0; i < root[u].size(); i++)
        {
            if (!vis[i] && root[u][i] == 1)
            {
                _dfs(i, st, vis);
            }
        }
        st.push(u);
    }

public:
    matrix_graph(int size)
    {
        root.resize(size, vector<int>(size, 0));
    }
    void addEdge(int u, int v)
    {
        root[u][v] = 1;
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

    void topologicalSort() {
        stack<int> st;
        vector<bool> vis(root.size(), false);
        for (int i = 0; i < root.size(); i++){
            if (!vis[i]){
                _dfs(i, st, vis);
            }
        }

        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
    }
};

int main()
{
    matrix_graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.topologicalSort();
    return 0;
}