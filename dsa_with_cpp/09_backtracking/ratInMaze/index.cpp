#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RatInMaze {
    int n;
    vector<vector<int>> maze;
    vector<string> result;

public:
    RatInMaze(vector<vector<int>> m) {
        maze = m;
        n = m.size();
    }

    vector<string> findPaths() {
        // edge case
        if (maze[0][0] == 0) return result;

        vector<vector<int>> visited(n, vector<int>(n, 0));
        string path = "";

        solve(0, 0, visited, path);

        return result;
    }

private:
    void solve(int i, int j, vector<vector<int>> &visited, string &path) {
        // YOU IMPLEMENT THIS
        
        // 1. base case (destination reached)
        if (!isValid(i, j, visited)) return;
        
        if (i == n - 1 && j == n - 1) {
            result.push_back(path);
            return;
        }

        visited[i][j] = true;
        // 2. mark visited
        // 3. try all 4 directions (D, L, R, U)
        // down
        path.push_back('D');
        solve(i + 1, j,visited, path);
        path.pop_back();
        // right 
        path.push_back('R');
        solve(i, j + 1,visited, path);
        path.pop_back();
        // left
        path.push_back('L');
        solve(i + 1, j,visited, path);
        path.pop_back();
        // up 
        path.push_back('L');
        solve(i - 1, j,visited, path);
        path.pop_back();
        }
        // 4. backtrack (unmark + pop path)
        
    

    bool isValid(int i, int j, vector<vector<int>> &visited) {
        return (i >= 0 && i < n &&
                j >= 0 && j < n &&
                maze[i][j] == 1 &&
                visited[i][j] == 0);
    
}
};


int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    RatInMaze obj(maze);
    vector<string> paths = obj.findPaths();

    for (auto &p : paths) {
        cout << p << endl;
    }

    return 0;
}