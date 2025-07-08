class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n));
        dp[n-1]=matrix[n-1];
        int leftDown=INT_MAX;
        int down=INT_MAX;
        int rightDown=INT_MAX;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                 leftDown=INT_MAX;
                 down=dp[i+1][j];
                 rightDown=INT_MAX;
                 if(j-1>=0) leftDown=dp[i+1][j-1];
                 if(j+1<n)rightDown=dp[i+1][j+1];
                 dp[i][j]=matrix[i][j]+min(leftDown,min(rightDown,down));
            }
        }
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
       mini=min(mini,dp[0][i]);
       }
       return mini;
    }
};
