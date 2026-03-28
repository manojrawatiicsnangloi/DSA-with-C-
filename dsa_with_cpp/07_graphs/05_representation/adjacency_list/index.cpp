#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class graphs{
    private: 
    unordered_map<string, vector<pair<string, int>>> root;
     public:void add(const string &u, const string &v, const int &w){
        root[u].push_back({v, w});
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
    return 0;
}