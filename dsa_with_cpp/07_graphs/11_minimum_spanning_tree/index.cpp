#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class graphs{
private: 
    unordered_map<string, vector<pair<string, int>>> root;

    // DSU structures
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;

    // Find with path compression
    string find(string x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank
    void unite(string a, string b){
        string pa = find(a);
        string pb = find(b);

        if(pa == pb) return;

        if(rank[pa] < rank[pb]){
            parent[pa] = pb;
        }
        else if(rank[pb] < rank[pa]){
            parent[pb] = pa;
        }
        else{
            parent[pb] = pa;
            rank[pa]++;
        }
    }

public:
    // Undirected graph
    void add(const string &u, const string &v, const int &w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void printGraph(){
        for (auto &i : root){
            cout << i.first << " : ";
            for (auto &j: i.second){
                cout << "(" << j.first << ", " << j.second << ") ";
            }
            cout << "\n";
        }
    }

    void mst_prism(){
        unordered_map <string, bool> vis;
         priority_queue<
        tuple<int, string, string>, 
        vector<tuple<int, string, string>>, 
        greater<tuple<int, string, string>>
    > pq;

    

    }
    //  MST using Kruskal
    // void mst(){
    //     vector<tuple<int,string,string>> edges;

    //     // Step 1: collect unique edges
    //     for(auto &u : root){
    //         for(auto &v : u.second){
    //             if(u.first < v.first) // avoid duplicate edges
    //                 edges.push_back({v.second, u.first, v.first});
    //         }
    //     }

    //     // Step 2: sort edges by weight
    //     sort(edges.begin(), edges.end());

    //     // Step 3: initialize DSU
    //     for(auto &i : root){
    //         parent[i.first] = i.first;
    //         rank[i.first] = 0;
    //     }

    //     int totalCost = 0;

    //     cout << "\nMST Edges:\n";

    //     // Step 4: process edges
    //     for(auto &e : edges){
    //         int w;
    //         string u, v;
    //         tie(w, u, v) = e;

    //         if(find(u) != find(v)){
    //             unite(u, v);
    //             cout << u << " - " << v << " : " << w << "\n";
    //             totalCost += w;
    //         }
    //     }

    //     cout << "Total Cost: " << totalCost << "\n";
    // }
};

int main(){
    graphs gp;

    gp.add("D","A", 4);
    gp.add("A","E", 4);
    gp.add("D","E", 2);
    gp.add("A","C", 3);
    gp.add("E","C", 4);
    gp.add("C","B", 3);
    gp.add("C","F", 4);
    gp.add("G","C", 5);
    gp.add("F","B", 2);
    gp.add("G","F", 5);

    gp.printGraph();

    // gp.mst(); //  call MST
    gp.mst_prism();
    return 0;
}