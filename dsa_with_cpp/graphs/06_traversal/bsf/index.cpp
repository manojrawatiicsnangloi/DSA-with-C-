#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class graphs_bsf{
    private:unordered_map<string, vector<pair<string, int>>> root;
    public:
    void addEdge(string u, string v, int w){
        root[u].push_back({u, w});
        root[v].push_back({v, w});
    }
    void printGraph(){
        for (auto &i : root){
            cout << i.first << " : ";
            for (pair<string, int> j : i.second){
                cout << "(" << j.first << j.second << "), ";
            }
        }
    }
};


int main(){

    return 0;
}