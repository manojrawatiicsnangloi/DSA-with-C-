#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class graphs{
private:
    unordered_map<string, vector<pair<string, int>>> root;

public:
    void add(string u, string v, int w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

  };


int main(){
    graphs gp;
    gp.add("D", "A", 4);
    gp.add("A", "E", 4);
    gp.add("D", "E", 2);
    gp.add("A", "C", 3);
    gp.add("E", "C", 4);
    gp.add("C", "B", 3);
    gp.add("C", "F", 4);
    gp.add("G", "C", 5);
    gp.add("F", "B", 2);
    gp.add("G", "F", 5);

    gp.astar("A", "E");
    return 0;
}