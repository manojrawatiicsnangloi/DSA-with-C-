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
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    for (char num = '1'; num <= '9'; num++){
                        if (isSafe(i, j, num)){
                            board[i][j] = num;
                            if (solve()) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void printBoard(){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << board[i][j] << " ";
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

    suduko_solver s(board);
    if (s.solve()){
        s.printBoard();
    }
    else{
        cout << "No solutionss";
    }
    
    return 0;
}