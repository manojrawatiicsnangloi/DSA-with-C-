#include <iostream>
using namespace std;
#include <vector>

class chessboard{
    vector<vector<char>> board;
    int size;
    void printBoard(){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    public:chessboard(int n){
         board = vector<vector<char>>(n , vector<char>(n , '.'));
        size = n;
    }

    void solve(int row){
        if (row == size){
            printBoard();
            cout  << "\n------------------------\n";
            return;
        }
        for (int i = 0; i < board.size(); i++){
            if (isSafe(row, i)){
                board[row][i] = 'Q';
                solve(row+ 1);
                board[row][i] = '.';
            }
        }
    }

    bool isSafe(int row, int col){
        for (int i = row -1,  j = col -1; i >= 0 && j >= 0;i--, j--){
            if (board[i][j] == 'Q') return false; 
        }
        
        for (int i = row -1,  j = col + 1; i >= 0 && j < size;i--, j++){
            if (board[i][j] == 'Q') return false; 
        }

        for (int i = 0; i < row; i++){
            if (board[i][col] == 'Q') return false;
        }
        return true;
    }
};
int main(){
    int n = 4;
    chessboard ch(n);
    ch.solve(0);
    return 0;
}