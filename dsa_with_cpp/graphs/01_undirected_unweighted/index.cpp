#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class graphs{
    private: 
    unordered_map<string, vector<string>> root;
     public:void add(const string &u, const string &v){
        root[u].push_back(v);
        root[v].push_back(u);
    }

  void printGraph(){
    for (auto &i : root){
        cout << i.first << " : ";
        for (int k = 0; k < i.second.size(); k++){
            cout << i.second[k];
            if (k != i.second.size() - 1) cout << ", ";
        }
        cout << "\n";
    }
}
};

int main(){
    graphs gp;
    gp.add("A","D");
    gp.add("A","E");
    gp.add("A","C");
    gp.add("E","C");
    gp.add("C","B");
    gp.add("C","F");
    gp.add("C","G");
    gp.add("B","F");
    gp.add("G","F");
    gp.printGraph();
    return 0;
}