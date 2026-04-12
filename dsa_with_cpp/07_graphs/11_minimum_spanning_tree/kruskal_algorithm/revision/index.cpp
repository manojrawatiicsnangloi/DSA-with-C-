#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


class graphs{
    private: unordered_map<string, vector<pair<string, int>>> root;
    public: 
    
    void add(string u, string v, int w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

    void kruskal_algorithm(){
        priority_queue<
        tuple<int, string , string>,
        vector<tuple<int, string , string>>,
        greater<tuple<int, string , string>>> pq;
        for (auto &i: root){
            for (auto &j : i.second){
                if(i.first > j.first ){
                    pq.push({j.second, i.first, j.first});
                }
            }
        }
        unordered_map<string, int> g;
        int id = 0;
        for (auto &i: root){
            g[i.first] = id;
            id++;
        }
        while (!pq.empty()){
            tuple<int, string, string> top = pq.top();
            int w = get<0>(top);
            string u = get<1>(top);
            string v = get<2>(top);
            pq.pop();
            if (g[u] != g[v]){
                cout << u << "-" << v << ' ' << w << endl;
                int oId = g[u];
                int newId = g[v];
                for (auto &i : g){
                    if (i.second == oId){
                        i.second = newId;
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
    gp.printGraphs();
    gp.kruskal_algorithm();
    return 0;
}