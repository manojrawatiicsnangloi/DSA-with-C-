#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <stack>
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
        if (root.find(v) == root.end())
        {
            root[v] = {};
        }
    }

    void topological_dfs(string curr, unordered_map<string, bool> &vis, stack<string> &st)
    {
        vis[curr] = true;
        for (pair<string, int> &i : root[curr])
        {
            if (!vis[i.first])
            {
                topological_dfs(i.first, vis, st);
            }
        }
        st.push(curr);
    }

    void topologicalSort()
    {
        unordered_map<string, bool> vis;
        stack<string> st;
        for (auto &i : root)
        {
            cout << i.first << " ";
            if (!vis[i.first])
            {
                topological_dfs(i.first, vis, st);
            }
        }
        cout << "\n Topological Sort";
        while (!st.empty())
        {
            cout << " " << st.top();
            st.pop();
        }
    }

    void dfs(string s)
    {
        unordered_map<string, bool> visited;
        cout << "\nDFS ";
        visited[s] = true;
        _dfs(s, visited);
    }

    void bfs(string s)
    {
        cout << "\nBFS ";
        queue<string> qu;
        unordered_map<string, bool> visited;
        qu.push(s);
        visited[s] = true;
        while (!qu.empty())
        {
            string node = qu.front();
            qu.pop();
            cout << node << " ";
            for (pair<string, int> &i : root[node])
            {
                if (!visited[i.first])
                {
                    qu.push(i.first);
                    visited[i.first] = true;
                }
            }
        }
    }

    void shortestPath(string scource)
    {
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>>
            pq;
        unordered_map<string, int> dist;
        // unordered_map <string, bool> visited;
        for (auto &i : root)
        {
            dist[i.first] = INT_MAX;
        }
        dist[scource] = 0;
        pq.push({0, scource});
        // visited[scource] = true;
        while (!pq.empty())
        {
            pair<int, string> node = pq.top();
            pq.pop();
            for (auto &neigh : root[node.second])
            {
                int total_distance = node.first + neigh.second;
                if (total_distance < dist[neigh.first])
                {
                    pq.push({total_distance, neigh.first});
                    // visited[neigh.first] = true;
                    dist[neigh.first] = total_distance;
                }
            }
        }
        cout << "\nShortest Path ";
        for (auto &i : dist)
        {
            cout << i.first << " - " << i.second << "\n";
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
    g.insert("5", "0", 0);
    g.insert("4", "0", 0);
    g.insert("5", "2", 0);
    g.insert("4", "1", 0);
    g.insert("2", "3", 0);
    g.insert("3", "1", 0);
    g.printGraph();
    g.topologicalSort();

    return 0;
}