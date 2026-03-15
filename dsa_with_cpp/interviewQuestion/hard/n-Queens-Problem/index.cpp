#include <iostream>
#include <vector>

class Solution{
    private:void printBoard(std::vector <std::vector<char>> &board){
    for (std::vector<char> i : board){
        for (char j : i){
            std::cout << j << " "; 
            }
        std::cout << "\n"; 
        }
    }
    
    public: bool isSafe(std::vector <std::vector<char>> &board, int row , int col, int n){
        // Check column
        for (int i = 0; i < row; i++){
            if (board[i][col] == 'Q'){
                return false;
            }
        }

        // Check the left digonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (board[i][j] == 'Q'){
                return false;
            }
        }

        // Check the upper digonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void solve(std::vector <std::vector<char>> &board, int row, int n){
        if (row == n){
            printBoard(board);
            std::cout << "------------------------\n";
            return;
        }

        for (int col = 0; col < n; col++){
            if (isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, row + 1, n);
                board[row][col] = '.'; 
            }
        }
    }
};

int main(){
    int n = 4;
    std::vector <std::vector<char>> board (n, std::vector<char> (n, '.'));
    Solution s;
    s.solve(board, 0, n);

    return 0;
}