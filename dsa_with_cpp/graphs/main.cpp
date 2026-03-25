#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph{
    private: unordered_map<string, list<string>> G;
    public: addEdge(string u, string v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    printGraph(){
        for (auto &i : G){
            cout << i.first << " : ";
            for (auto &j : i.second){
                cout << j << "  ";
            }
            cout << "\n";
        }
    }
};
int main(){
    Graph g;
    g.addEdge("A", "B");
    g.addEdge("B", "C");
    g.addEdge("B", "D");
    g.addEdge("C", "D");
    g.addEdge("E", "C");
    g.printGraph();
    return 0;
}