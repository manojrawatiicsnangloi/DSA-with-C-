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

   void kahnTopoSort() {
    unordered_map<string, int> indegree;

    // Step 1: Initialize all nodes with 0
    for (auto &i : root) {
        indegree[i.first] = 0;
    }

    // Step 2: Calculate indegree
    for (auto &i : root) {
        for (auto &j : i.second) {
            indegree[j.first]++;
        }
    }

    // Step 3: Push nodes with indegree 0
    queue<string> q;
    for (auto &i : indegree) {
        if (i.second == 0) {
            q.push(i.first);
        }
    }

    // Step 4: BFS
    cout << "\nKahn Topological Sort: ";
    int count = 0;

    while (!q.empty()) {
        string node = q.front();
        q.pop();

        cout << node << " ";
        count++;

        for (auto &neigh : root[node]) {
            indegree[neigh.first]--;

            if (indegree[neigh.first] == 0) {
                q.push(neigh.first);
            }
        }
    }

    // Cycle detection
    if (count != root.size()) {
        cout << "\nCycle detected! Topological sort not possible";
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
    
    g.kahnTopoSort();

    return 0;
}