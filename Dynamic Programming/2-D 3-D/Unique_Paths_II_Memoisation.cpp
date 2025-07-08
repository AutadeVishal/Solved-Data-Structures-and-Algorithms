class Solution {
public:
int solve(vector<vector<int>>obstacleGrid,vector<vector<int>>&dp,int row,int col){
    if(row<0 || col<0) return 0;
    if(obstacleGrid[row][col]==1) return 0;
    if(dp[row][col]!=-1) return dp[row][col];
    int top=solve(obstacleGrid,dp,row-1,col);
    int left=solve(obstacleGrid,dp,row,col-1);
    return dp[row][col]=top+left;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        dp[0][0]=1;
        
        return solve(obstacleGrid,dp,m-1,n-1);
    }
};
