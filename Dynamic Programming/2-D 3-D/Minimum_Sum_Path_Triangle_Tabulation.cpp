class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        dp[m-1]=triangle[m-1];
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]=min(dp[i+1][j+1],dp[i+1][j])+triangle[i][j];
            }
        }
        return dp[0][0];
    }
};
