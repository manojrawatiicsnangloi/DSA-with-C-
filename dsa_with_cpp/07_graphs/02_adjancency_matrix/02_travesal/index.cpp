#include <iostream>
#include <vector>
#include <list>
using namespace std;


class graphs{
    int V;
    list<int> * l;
    public:
    graphs(int v){
        this -> V = v;
        this -> l = new list<int> [v];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList(){
        for (int i = 0; i < V; i++){
            
        }
    }
};
int main(){
    graphs g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    return 0;
}