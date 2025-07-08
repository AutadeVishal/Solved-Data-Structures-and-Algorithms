class Solution {
public:
int minSum(vector<vector<int>>&grid,vector<vector<int>>&dp,int row,int col){
    if(row==0 && col==0) return dp[0][0]=grid[0][0];
    if(row<0 || col<0)return INT_MAX;
    if(dp[row][col]!=INT_MAX) return dp[row][col];
    int top=minSum(grid,dp,row-1,col);
    int left=minSum(grid,dp,row,col-1);
    return dp[row][col]=grid[row][col]+min(left,top);
}
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        return minSum(grid,dp,m-1,n-1);
    }
};
