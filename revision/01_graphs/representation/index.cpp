#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
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
        root[v].push_back({u, w});
    } 

    void dfs(string s){
        unordered_map<string, bool> vis;
        vis[s] = true;
        _dfs(s, vis);
    }

    void printGraphs(){
        for (auto & i: root){
            cout << i.first << " : ";
            for (auto &j : i.second){
                cout << " (" << j.first << "," << j.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkastra(string s){
        unordered_map<string, int> dist;
        for (auto &i: root){
            dist[i.first] = INT_MAX;
             for (auto &j : i.second){
                dist[j.first] = INT_MAX; // ✅ ensure all nodes covered
            }
        }

        priority_queue<
        pair<int, string>,
        vector<pair<int, string>>,
        greater<pair<int, string>>
        > pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()){
            pair<int, string> curr = pq.top();
            if (curr.first > dist[curr.second]) continue;
            
            pq.pop();
            for (auto &i : root[curr.second]){
                int d = curr.first + i.second; 
                if (dist[i.first] > d){
                    dist[i.first] = d;
                    pq.push({d, i.first});
                } 
            }
        }

        for (auto &i: dist){
            cout << i.first << " : " << i.second << " \n";
        }
    }
    
    void bfs(string s){
        unordered_map<string, bool> vis;
        queue<string> q;
        vis[s] = true;
        q.push(s);
        while (!q.empty()){
            string node = q.front(); 
            q.pop();
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

    graphs gp;
     gp.addEdge("D", "A", 4);
    gp.addEdge("A", "E", 4);
    gp.addEdge("D", "E", 2);
    gp.addEdge("A", "C", 3);
    gp.addEdge("E", "C", 4);
    gp.addEdge("C", "B", 3);
    gp.addEdge("C", "F", 4);
    gp.addEdge("G", "C", 5);
    gp.addEdge("F", "B", 2);
    gp.addEdge("G", "F", 5);
    gp.printGraphs();

    gp.dijkastra("A");
    return 0; 

}