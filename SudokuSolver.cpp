class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) {
                return false;
            }
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) {
                return false;
            }
        }
        for (int i = (row / 3)*3; i < (row / 3)*3 + 3; i++) {
            for (int j = (col/3)*3; j < (col/3)*3+3; j++){
                if(board[i][j] == ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool Sudoku(vector<vector<char>>& board, int row, int col){
        if(row == 9){
            return true;
        }
        int nxtRow = row, nxtCol = col + 1;
        if(nxtCol == 9){
            nxtRow = row + 1;
            nxtCol = 0;
        }
        if(board[row][col] != '.'){
            return Sudoku(board, nxtRow, nxtCol);
        }
        for(char dig = '1'; dig <= '9'; dig++){
            if(isSafe(board,row,col,dig)){
                board[row][col] = dig;
                if(Sudoku(board, nxtRow, nxtCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        Sudoku(board,0,0);
    }
};
