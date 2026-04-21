#include <iostream>
#include <vector>
using namespace std;

class suduko_solver{
     private : vector<vector<char>> board;   
    
    public:

    suduko_solver(vector<vector<char>> b) {
        this -> board = b;
    }

    bool isSafe(int row, int col, char num){
        for (int i = 0; i < 9; i++){
            if (board[i][col] == num) return false;
            if (board[row][i] == num) return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[startRow + i][startCol + i] == num) return false;
            }
        }
        return true;
    }

    bool solve(){

    }

    void printBoard(){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
            }
            cout << " ";
        }

    }
};

int main(){
    return 0;
}