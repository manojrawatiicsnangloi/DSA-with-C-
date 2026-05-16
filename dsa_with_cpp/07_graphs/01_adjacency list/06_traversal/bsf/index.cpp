    #include <iostream>
    #include <unordered_map>
    #include <vector>
    #include <queue>

    using namespace std;

    class graphs_bsf{
        private:unordered_map<string, vector<pair<string, int>>> root;
        public:
        void addEdge(string u, string v, int w){
            root[u].push_back({v, w});
            root[v].push_back({u, w});
        }

        void bfs(string s){
            queue<string> q;
            unordered_map <string, bool> vis;
            q.push(s);
            vis[s] = true;
            while (!q.empty()){
                string current = q.front(); 
                q.pop();
                cout << current << " ";
                for (auto &i : root[current]){
                    if (!vis[i.first]){
                        q.push(i.first);
                        vis[i.first] = true;
                    }
                }          
            }
        }
        
        void printGraph(){
            for (auto &i : root){
                cout << i.first << " : ";
                for (pair<string, int> j : i.second){
                    cout << "(" << j.first << ", " << j.second << "), ";
                }
                cout << "\n";
            }
        }
    };


    int main(){
        graphs_bsf gp;

    gp.addEdge("D","A", 4);
        gp.addEdge("A","E", 4);
        gp.addEdge("D","E", 2);
        gp.addEdge("A","C", 3);
        gp.addEdge("E","G", 5);
        gp.addEdge("E","C", 4);
        gp.addEdge("C","B", 3);
        gp.addEdge("C","F", 4);
        gp.addEdge("G","C", 5);
        gp.addEdge("F","B", 2);
        gp.addEdge("G","F", 5);

        gp.printGraph();
        gp.bfs("D");
        return 0;
    }