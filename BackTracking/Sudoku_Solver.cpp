class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char ch) {
       
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == ch) return false;
        }

        // Check 3×3 subgrid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((startRow + i != row || startCol + j != col) && board[startRow + i][startCol + j] == ch) 
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (issafe(board, i, j, k)) {
                            board[i][j] = k;  
                            if (solve(board)) return true;  
                            board[i][j] = '.';
                        }
                    }
                    return false; 
            }
        }
        }
        return true; 
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
