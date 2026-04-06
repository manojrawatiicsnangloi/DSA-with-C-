#include <iostream>
#include <stack>
#include <queue>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;

class graphs{
    private: unordered_map<string, vector<pair<string, int>>>root;
    void insert(string u, string v, int w){
        root[u].push_back({v, w});
        if (root.find(v) == root.end()){
            root[v] = {};
        }
    }

    void dfs(string s){

    }
    void bfs(string s){
        unordered_map<string, bool> vis;
         
    }
};
int main(){
    return 0;
}