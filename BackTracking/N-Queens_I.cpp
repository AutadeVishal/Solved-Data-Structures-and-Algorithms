class Solution {
public:
    bool issafe(vector<vector<char>>& currans, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (currans[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (currans[i][j] == 'Q') return false;
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (currans[i][j] == 'Q') return false;
        }

        return true;
    }
void solve(int &n,vector<vector<string>>&ans,vector<vector<char>>&currans,int row){
    if(row>=n){
         vector<string> solution;
        //currans is in char format so convert it to string format in solution variable
            for (int i = 0; i < n; i++) {
                solution.push_back(string(currans[i].begin(), currans[i].end()));
            }
            ans.push_back(solution);
            return;
    }
    for(int i=0;i<n;i++){
     if(issafe(currans,row,i,n)){
            currans[row][i]='Q';
            solve(n,ans,currans,row+1);
           currans[row][i]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
     vector<vector<string>> ans;
        vector<vector<char>>currans(n,vector<char>(n,'.'));
        solve(n,ans,currans,0);
        return ans;
    }
};
