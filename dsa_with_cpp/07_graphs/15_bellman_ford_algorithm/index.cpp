#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class graphs{
    private: unordered_map<string, vector<pair<string, int>>>root;
    void _dfs(string node, unordered_map<string, bool> &vis){
        vis[node] = true;
        for (auto &i: root[node]){
            if (!vis[i.first]){
                _dfs(i.first, vis);
            }
        }
    }

    public:
    void insert(string u, string v, int w){
        root[u].push_back({v, w});
        if (root.find(v) == root.end()){
            root[v] = {};
        }
    }

    void dfs(string s){
        unordered_map<string, bool> vis;
        _dfs(s, vis);
    }

    void bfs(string s){
        unordered_map<string, bool> vis;
        queue<string> q;
        q.push(s);
        vis[s] = true;
        while(!q.empty()){
            string node = q.front();
            q.pop();
            cout << node << " ";
            for (auto & i: root[node]){
                if (!vis[i.first]){
                    q.push(i.first);
                    vis[i.first] = true;
                }
            } 
        }
    }
};
int main(){
    return 0;
}