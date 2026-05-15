#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;


class graphs{
    unordered_map<int, vector<pair<int, int>>> root;
    public:void insert(int u, int v, int w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void printData(){
        for (auto &i:root){
            cout << i.first << " : ";
            for (pair<int, int> j : i.second){
                cout << "(" << j.first << ", " << j.second << ")";
            }
            cout << endl;
        }
    }

    void bfs(int start){ 
        queue<int> q;
        
        unordered_map<int , bool> vis;
        
        q.push(start);
        vis[start] = true;
    while (!q.empty())
        {
            int current = q.front();
            cout << current << " ";
            q.pop();
            for (auto &i: root[current]){
                if (!vis[i.first]){
                    q.push(i.first);
                    vis[i.first] = true;
                }               
            }
            /* code */

        }
        
    }
    void load_from_file(string name){
        int u, v;
         ifstream file(name);
          while (file >> u >> v) {
        root[u].push_back({v, 0});
        root[v].push_back({u, 0});
    }
    }

    void show_info(){
        cout << "Total Users " << root.size() << endl;

        int connections = 0;

        for (auto &it : root) {
            connections += it.second.size();
        }

        cout << "Total Connections: " << connections / 2 << endl;
    }
};

int main(){
    graphs g;
    g.load_from_file("0.edges");
    // g.printData();
    g.show_info();
    g.bfs(1);
    return 0;
}