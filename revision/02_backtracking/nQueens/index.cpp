#include <iostream>
#include <vector>
using namespace std;

class chess{
    vector<vector<char>> board;
  public:  chess(int n){
        board = vector<vector<char>>(n, vector<char>(n, '.')); 
    }


    void solve(int row){
        if (row == board.size()){
            cout << endl << "---------------------" << endl;
            printBoard();
            return;
        }
        for (int col = 0; col < board.size(); col++){
            if (isSafe(row, col)){
                board[row][col] = 'Q';
                solve(row + 1);
                board[row][col] = '.';

            }
        }
    }

    void printBoard(){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                cout << board[i][j] << " ";
            }   
            cout << endl;
        }
    }

    bool isSafe(int row, int col){
        for (int i = 0; i < row; i++){
            if (board[i][col] == 'Q'){
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++){
            if (board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
};
int main(){
    chess ch(4);
    ch.solve(0);
    return 0;
}