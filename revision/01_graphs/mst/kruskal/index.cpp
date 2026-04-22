#include <unordered_map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>
#include <iostream>
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
        >pq;
        for (auto &u : root){
            for (auto &v : u.second){
                if (v.first < u.first){
                    pq.push({v.second, u.first, v.first});
                }
            }
        }
        unordered_map<string, int> groups;
        int id = 0;
        for (auto &i: root){
            groups[i.first] = id;
            id++;
        }

        while (!pq.empty()){
            tuple<int, string, string> top = pq.top();
            int w = get<0>(top);
            string u = get<1>(top);
            string v = get<2>(top);
            pq.pop();
            if (groups[u] != groups[v]){
                cout << u << "---" << w << "---" << v << endl;
                int oldG = groups[u];
                int newG = groups[v];
                for(auto&i:groups){
                    if (i.second == oldG){
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

    // gp.kruskal_mst();
    gp.printGraphs();

    return 0;
}