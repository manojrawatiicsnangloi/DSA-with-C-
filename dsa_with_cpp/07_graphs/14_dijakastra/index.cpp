#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#include <queue>
#include <limits.h>
class graphs{
    private: unordered_map<string, vector<pair<string, int>>> root;
    public:void insert(string u, string v, int w){
        root[u].push_back({v, w});
        root[v].push_back({u, w});
    }

     void dijkstra(string source){
        unordered_map<string, int> dist;

        // Initialize distances
        for(auto &i : root){
            dist[i.first] = INT_MAX;
        }

        // Min Heap → (distance, node)
        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            greater<pair<int, string>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int currDist = top.first;
            string node = top.second;

            for(auto &nbr : root[node]){
                string adjNode = nbr.first;
                int weight = nbr.second;

                if(currDist + weight < dist[adjNode]){
                    dist[adjNode] = currDist + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Print result
        cout << "\nShortest distances from " << source << ":\n";
        for(auto &i : dist){
            cout << i.first << " -> " << i.second << "\n";
        }
    }

    void printGraph(){
        for (auto &i: root){
            cout << i.first << " : ";
            for (pair<string, int> j : i.second){
                cout << "("<< j.first  << ", "<< j.second << ")";
            }
            cout << "\n";
        }
    }

};

int main(){
      graphs gp;
    gp.insert("D","A", 4);
    gp.insert("A","E", 4);
    gp.insert("D","E", 2);
    gp.insert("A","C", 3);
    gp.insert("E","C", 4);
    gp.insert("C","B", 3);
    gp.insert("C","F", 4);
    gp.insert("G","C", 5);
    gp.insert("F","B", 2);
    gp.insert("G","F", 5);
    gp.printGraph();
    gp.dijkstra("A");
    return 0;
}