#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;




class graphs{
    private: 
    unordered_map<string, vector<pair<string, int>>> root;
    unordered_map<string, string> parents;
    unordered_map<string, int> ranks;
    
     public:void add(const string &u, const string &v, const int &w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
        makeSet(v);
        makeSet(u);
        unionSet(u, v);
    }

    void makeSet(string node){
        if (parents.find(node) == parents.end()){
            parents[node] = node;
        }
    }
    string findParent(string node){
        if (node == parents[node]){
            return node;
        }
        return parents[node] = findParent(parents[node]);
    }

    void unionSet(string u, string v){
        string pu = findParent(u);
        string pv = findParent(v);
        if (pu == pv){
            return;
        }
        if (ranks[pu] < ranks[pv]){
            parents[pu] = pv;
        }
        else if (ranks[pu] > ranks[pv]){
            parents[pv] = pu;
        }

        else {
            parents[pv] = pu;
            ranks[pu]++;
        }

    }

    bool isConnected(string u, string v){
        return findParent(u) == findParent(v);
    }
  void printGraph(){
    for (auto &i : root){
        cout << i.first << " : ";
        for (pair<string, int> &j: i.second){
            cout << "(" << j.first << ", " << j.second << ") ";
        }
        cout << "\n";
        }
    }
    void printParents()
    {

        cout << "\nDSU Parents:\n";

        for (auto &i : parents)
        {

            cout << i.first
                 << " -> "
                 << findParent(i.first)
                 << "\n";
        }
    }

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


     gp.printParents();

    cout << "\n";

    if (gp.isConnected("A", "C"))
    {
        cout << "A and C connected\n";
    }

    if (!gp.isConnected("A", "E"))
    {
        cout << "A and E NOT connected\n";
    }

    gp.printGraph();
    return 0;
}