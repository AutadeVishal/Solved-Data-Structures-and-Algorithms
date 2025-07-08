class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        vector<int>dp(m);
        dp=triangle[m-1];
        for(int i=m-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=min(dp[j+1],dp[j])+triangle[i][j];
            }
        }
        return dp[0];
    }
};
