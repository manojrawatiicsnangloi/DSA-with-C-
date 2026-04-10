#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
using namespace std;

class graphs
{
private:
    unordered_map<string, vector<pair<string, int>>> root;

public:
    void add(const string &u, const string &v, const int &w)
    {
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void kruskal_mst(){
   priority_queue<
   tuple<int, string, string>,
    vector<tuple<int, string, string>>,
    greater<tuple<int, string, string>>
   > edges;
        for (auto&u: root){
            for (auto&v: u.second){
                // if (v.first < u.first)
                edges.push({v.second, v.first, u.first});
            }
        }   

        //
        unordered_map<string, int> group;
        int id = 0;

        for (auto &i: root){
            group[i.first] = id;
            id++; 
        }

        
        
        while (!edges.empty()){
            tuple<int, string, string> top = edges.top();
            edges.pop();
            int w = get<0>(top);
            string u = get<1>(top);
            string v = get<2>(top);
            if (group[u] != group[v]){
                cout << u << " - " << v << " " <<  w << "\n";
                int oldG = group[u];
                int newG = group[v];
                for (auto&i : group){
                    if (oldG == i.second){
                        i.second = newG;
                    }
                }
            }

        }
    }

    void printGraphs(){
        for (auto&i: root){
            cout << i.first << " : ";
            for (auto &j : i.second){
                cout << "( "<<j.first << ", " << j.second << ") ";
            }
            cout << endl;
        }
    }
};

int main()
{
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

    gp.kruskal_mst();
    // gp.printGraphs();

    return 0;
}