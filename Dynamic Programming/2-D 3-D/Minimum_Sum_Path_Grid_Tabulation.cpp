class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++) dp[0][i]=grid[0][i]+dp[0][i-1];
        for(int i=1;i<m;i++) dp[i][0]=grid[i][0]+dp[i-1][0];
        int top=INT_MAX;
        int left=INT_MAX;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                 top=dp[i-1][j];
                left=dp[i][j-1];
                dp[i][j]=grid[i][j]+min(top,left);
            }
        }
        return dp[m-1][n-1];
    }
};
