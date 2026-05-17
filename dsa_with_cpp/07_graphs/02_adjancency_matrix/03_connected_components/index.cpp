
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
         void _dfs(int u, vector<bool> &vis)
        {
           
            stack<int> st;
            st.push(u);
            vis[u] = true;
            while (!st.empty()){
                int top = st.top();
                st.pop();
                for(int i = 0; i < root.size(); i++){
                    if (!vis[i] && root[top][i] == 1){
                        vis[i] = true;
                        st.push(i);
                    }
                }
            }
        }
        
        int component(){
            vector<bool> vis(root.size(), false);
            int c = 0;
            for (int i = 0; i < root.size(); i++){
                if (!vis[i]){
                    _dfs(i, vis);
                    c++;
                }
            }
            return c;
        }
    };



int main()
{
    matrix_graph g(12);

    // Community 1
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(1, 4);

    // Community 2
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(5, 7);

    // Community 3
    g.addEdge(8, 9);

    // Community 4
    g.addEdge(10, 11);

    // g.printGraph();
    cout << "Total Components" << g.component();

    return 0;
}