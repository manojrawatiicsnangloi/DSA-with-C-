#include <iostream>
#include <vector>
using namespace std;

class Sudoku {
    vector<vector<char>> board;

public:
    Sudoku(vector<vector<char>> b) {
        board = b;
    }
    bool isSafe(int row, int col, int num){
        for (int i = 0; i < 9; i++){
            if (board[row][i] == num) return false;
            if (board[i][col] == num) return false;
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (board[startRow + i][startCol + j] == num){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(){
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++){
                        if (isSafe(row, col, num)){
                            board[row][col] = num;
                            if (solve()){
                                return true;
                            }
                            board[row][col] = '.';
                        }
                    }
                    return false; // no number fits
                }
            }
        }
         return true; // solved
    }

     void print() {
        for (auto &row : board) {
            for (auto &c : row) {
                cout << c << " ";
            }
            cout << "\n";
        }
    }
};


int main(){

     vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Sudoku s(board);

    if (s.solve()) {
        s.print();
    } else {
        cout << "No solution\n";
    }

    return 0;
}