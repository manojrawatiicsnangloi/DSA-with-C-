#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <unordered_map>
#include <vector>
#include <map>
using namespace std;

class graphs
{
private:
unordered_map<string, vector<pair<string, int>>> root;
    void _dfs(string node, unordered_map<string, bool> &vis)
    {
        vis[node] = true;
        for (auto &i : root[node])
        {
            if (!vis[i.first])
            {
                _dfs(i.first, vis);
            }
        }
    }

public:
    void dijkstra(string s)
    {
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>>
            pq;
        unordered_map<string, int> dist;
        for (auto &i : root)
        {
            dist[i.first] = INT_MAX;
        }
        pq.push({0, s});
        dist[s] = 0;
        while (!pq.empty())
        {
            pair<int, string> top = pq.top();
            pq.pop();
            if (top.first > dist[top.second])
                continue;
            for (auto &i : root[top.second])
            {
                string neigh = i.first;
                int current_dis = i.second;
                if (current_dis + dist[top.second] < dist[neigh])
                {
                    pq.push({current_dis + dist[top.second], i.first});
                    dist[i.first] = current_dis + dist[top.second];
                }
            }
        }

        for (auto &i : dist)
        {
            cout << i.first << " : " << i.second << "\n";
        }
    }
    void insert(string u, string v, int w)

    {
        root[u].push_back({v, w});
        if (root.find(v) == root.end())
        {
            root[v] = {};
        }
    }

    void dfs(string s)
    {
        unordered_map<string, bool> vis;
        _dfs(s, vis);
    }

        void bellmanFord(string s){
            unordered_map <string, int> dist;
            int size = root.size();
            for (auto&i:root){
                dist[i.first] = INT_MAX;
            }
            dist[s] = 0;
            // for (int i = 1; i < size; i++){
            for (auto &u : root){
                for (auto &edge : u.second){
                    string v = edge.first;
                    int weight = edge.second;
                    if (dist[u.first] != INT_MAX && 
                        dist[u.first] + weight < dist[v]){
                        dist[v] = dist[u.first] + weight;
                    }
                }
            // }
            }

            for (auto&i:dist){
                cout << endl << i.first << " : " << i.second << endl;
            }
        }
    void bfs(string s)
    {
        unordered_map<string, bool> vis;
        queue<string> q;
        q.push(s);
        vis[s] = true;
        while (!q.empty())
        {
            string node = q.front();
            q.pop();
            cout << node << " ";
            for (auto &i : root[node])
            {
                if (!vis[i.first])
                {
                    q.push(i.first);
                    vis[i.first] = true;
                }
            }
        }
    }


};


int main()
{
    graphs gp;
    gp.insert("A", "B", 6);
    gp.insert("A", "C", 4);
    gp.insert("A", "D", 5);
    gp.insert("B", "E", -1);
    gp.insert("C", "E", 3);
    gp.insert("C", "B", -2);
    gp.insert("E", "F", 3);
    gp.insert("D", "F", -1);
    // gp.dijkstra("D");
    cout << "\nBellman ford Algorithm";
    gp.bellmanFord("A");
    return 0;
}