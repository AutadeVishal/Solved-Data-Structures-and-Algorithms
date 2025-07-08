class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>dp(n,INT_MAX);
        dp[0]=grid[0][0];
        for(int i=1;i<n;i++){
            dp[i]=grid[0][i]+dp[i-1];
        }
        int top=INT_MAX;
        int left=INT_MAX;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                top=dp[j];
                j-1>=0 ? left=dp[j-1]:left=INT_MAX; 
                dp[j]=min(top,left)+grid[i][j];
            }
        }
        return dp[n-1];
    }
};
