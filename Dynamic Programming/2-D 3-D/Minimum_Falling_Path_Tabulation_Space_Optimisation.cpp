class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>dp(n);
        dp=matrix[n-1];
        vector<int>temp(n);
        int leftDown=INT_MAX;
        int down=INT_MAX;
        int rightDown=INT_MAX;
        for(int i=n-2;i>=0;i--){
             temp=dp;
            for(int j=0;j<n;j++){
                 leftDown=INT_MAX;
                 down=temp[j];
                 rightDown=INT_MAX;
                
                 if(j-1>=0) leftDown=temp[j-1];
                 if(j+1<n)rightDown=temp[j+1];
                 dp[j]=matrix[i][j]+min(leftDown,min(rightDown,down));
            }
        }
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
       mini=min(mini,dp[i]);
       }
       return mini;
    }
};
