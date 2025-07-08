class Solution {
public:
int solve(vector<vector<int>>&matrix,vector<vector<int>>&dp,int row,int col,int n){
    if(row==n)return dp[row][col]=matrix[row][col];
    if(dp[row][col]!=INT_MAX) return dp[row][col];
    int leftdown=INT_MAX;
    int rightdown=INT_MAX;
    int down=INT_MAX;
    if(col-1>=0) leftdown=solve(matrix,dp,row+1,col-1,n);
    if(col+1<n) rightdown=solve(matrix,dp,row+1,col+1,n);
    down=solve(matrix,dp,row+1,col,n);
    return dp[row][col]=min(leftdown,min(rightdown,down))+matrix[row][col];
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        dp[n-1]=matrix[n-1];
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(mini,solve(matrix,dp,0,i,n));
        }
        return mini;
    }
};
