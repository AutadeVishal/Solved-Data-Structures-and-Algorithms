class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int left=0;
                int top=dp[j];
            if(j-1>=0)  obstacleGrid[i][j-1]==0 ? left=dp[j-1]:left=0;
            
            
                int currsum=0;
                if(obstacleGrid[i][j]==0) {
        
                        currsum+=top;
                    
                        currsum+=left;
                   
                }
                dp[j]=currsum;
            }
        }
        return dp[n-1];
    }
};
