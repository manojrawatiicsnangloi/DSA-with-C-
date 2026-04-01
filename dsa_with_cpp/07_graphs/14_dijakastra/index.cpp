#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class graphs{
    private: unordered_map<string, vector<pair<string, int>>> root;
    void insert(string u, string v, int w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void printGraph(){
        for (auto &i: root){
            cout << i.first << " : ";
            for (pair<string, int> j : i.second){
                cout << "("<< i.first << "," << i.second << ")"
            }
        }
    }

};

int main(){

    return 0;
}