#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class graphs{
    private:
    unordered_map<string, vector<pair<string, int>>> root;

    void _dfs(string s, unordered_map<string, bool> &vis){
        cout << s << " ";
        for (auto& i: root[s]){
            if (!vis[i.first])
            {
                vis[i.first] = true;
                _dfs(i.first, vis);
            }
        }
    }
    public:
    void addEdge(string u, string v, int w){
        root[u].push_back({v, w});
    } 

    void dfs(string s){
        unordered_map<string, bool> vis;
        _dfs(s, vis);
    }

    void printGraphs(){
        for (auto & i: root){
            cout << i.first << " ";
            for (auto &j : i.second){
                cout << " (" << j.first << "," << j.second << ") ";
            }
        }
    }
    
    void bfs(string s){
        unordered_map<string, bool> vis;
        queue<string> q;
        q.push(s);
        while (!q.empty()){
            string node = q.front(); 
            q.pop();
            for (auto & i: root[node]){
                if (!vis[i.first]){
                    q.push(i.first);
                }
            }
        } 
    }
};


int main(){

    graphs g;
    return 0; 

}