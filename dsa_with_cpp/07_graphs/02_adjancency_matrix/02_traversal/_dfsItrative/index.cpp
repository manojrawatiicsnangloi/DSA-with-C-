    #include <iostream>
    #include <vector>
    #include <stack>
    using namespace std;

    class matrix_graph
    {
        vector<vector<int>> root;
        
        public:
        matrix_graph(int size)
        {
            root.resize(size, vector<int>(size, 0));
        }
        void _dfs(int u)
        {
            vector<bool> vis(root.size(), false);
            stack<int> st;
            st.push(u);
            vis[u] = true;
            while (!st.empty()){
                int top = st.top();
                cout << top << " ";
                st.pop();
                for(int i = 0; i < root.size(); i++){
                    if (!vis[i] && root[top][i] == 1){
                        vis[i] = true;
                        st.push(i);
                    }
                }
            }
        }
        
        void addEdge(int u, int v)
        {
            root[u][v] = 1;
            root[v][u] = 1;
        }
        void printGraph()
        {

            for (int i = 0; i < root.size(); i++)
            {

                for (int j = 0; j < root[i].size(); j++)
                {

                    cout << root[i][j] << " ";
                }

                cout << "\n";
            }
        }


    };

    int main()
    {
        matrix_graph g(5);
        g.addEdge(1, 2);
        g.addEdge(1, 0);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(2, 4);

        // g._bfs(0);
        g._dfs(0);
        // g.printGraph();
        return 0;
    }