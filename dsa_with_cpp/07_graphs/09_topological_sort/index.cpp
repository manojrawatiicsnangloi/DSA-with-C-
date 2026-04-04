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

    void shortestPath(string scource){
       
        priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
        > pq;
        unordered_map<string, int> dist;
        // unordered_map <string, bool> visited;
        for (auto &i: root){
            dist[i.first] = INT_MAX;
        }
        dist[scource] = 0;
        pq.push({0, scource});
        // visited[scource] = true;
        while (!pq.empty()){
            pair<int, string> node = pq.top();
            pq.pop();
            for (auto& neigh: root[node.second]){
                int total_distance = node.first + neigh.second;
                if (total_distance < dist[neigh.first]){
                    pq.push({total_distance, neigh.first});
                    // visited[neigh.first] = true;
                    dist[neigh.first] = total_distance;
                }
            }
        }
        cout << "\nShortest Path ";
        for (auto&i: dist){
            cout << i.first << " - " << i.second << "\n";
        }
    }


    void topologicalSort() {
    unordered_map<string, int> indegree;

    // Step 1: Initialize indegree of all nodes
    for (auto &i : root) {
        if (indegree.find(i.first) == indegree.end())
            indegree[i.first] = 0;

        for (auto &j : i.second) {
            indegree[j.first]++;
        }
    }

    // Step 2: Push nodes with 0 indegree
    queue<string> q;
    for (auto &i : indegree) {
        if (i.second == 0) {
            q.push(i.first);
        }
    }

    // Step 3: Process nodes
    cout << "\nTopological Sort: ";
    while (!q.empty()) {
        string node = q.front();
        q.pop();

        cout << node << " ";

        for (auto &neigh : root[node]) {
            indegree[neigh.first]--;

            if (indegree[neigh.first] == 0) {
                q.push(neigh.first);
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
    // g.insert("D", "A", 4);
    // g.insert("D", "E", 2);
    // g.insert("A", "E", 4);
    // g.insert("A", "C", 3);
    // g.insert("E", "C", 4);
    // g.insert("E", "G", 5);
    // g.insert("C", "B", 3);
    // g.insert("C", "F", 4);
    // g.insert("C", "G", 5);
    // g.insert("G", "C", 5);
    // g.insert("G", "F", 5);


    g.insert("D", "A", 4);
g.insert("D", "E", 2);
g.insert("A", "E", 4);
g.insert("A", "C", 3);
g.insert("E", "C", 4);
g.insert("E", "G", 5);
g.insert("C", "B", 3);
g.insert("C", "F", 4);
g.insert("C", "G", 5);
g.insert("G", "F", 5);


    g.printGraph();
    g.bfs("A");
    g.dfs("A");
    g.shortestPath("A");
    g.topologicalSort();
    return 0;
}