class Solution {
public:
bool issafe(vector<vector<char>>&board,int &row,int &col,char ch){
    
for(int i=0;i<board.size();i++){
  if(board[i][col]!='.' &&  board[i][col]==ch){
    return false;
  }
}
for(int i=0;i<board[0].size();i++){
    if(board[row][i]!='.'  && board[row][i]==ch) return false;
}
//logic for each 3*3 submatrix
int startRow = (row / 3) * 3;
int startCol = (col / 3) * 3;
for (int i = 0; i < 3; i++) {
     for (int j = 0; j < 3; j++) {
        if (board[startRow+i][startCol+j]!='.' &&  board[startRow + i][startCol + j] == ch) return false;
    }
}
return true;
}
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.')
                {char c=board[i][j];
                board[i][j]='.';
                    if( !issafe(board,i,j,c)) return false;
                     board[i][j]=c;
            }
        }
        }
        return true;
    }
};
