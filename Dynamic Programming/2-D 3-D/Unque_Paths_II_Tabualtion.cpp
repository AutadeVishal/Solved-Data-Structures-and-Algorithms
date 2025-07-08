class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),0));
        dp[0][0]=1;
        int left=1;
        int top=0;
     if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(i==0 && j==0)goto end;
                 top=0;
                left=0;
                if(j-1>=0) left=obstacleGrid[i][j-1]==1 ? 0: dp[i][j-1];
                if(i-1>=0) top=obstacleGrid[i-1][j]==1 ? 0:dp[i-1][j];
              end:
               obstacleGrid[i][j]==0 ? dp[i][j]=left+top:dp[i][j]=0;

            }
        }
        return dp[m-1][n-1];
    }
};
