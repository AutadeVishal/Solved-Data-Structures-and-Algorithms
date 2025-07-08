class Solution {
public:
int solve(vector<vector<int>>&dp,vector<vector<int>>&triangle,int row,int col,int m,int n){
    if(row==m-1) return dp[row][col]=triangle[row][col];
    if(dp[row][col]!=-1) return dp[row][col];
    int down=solve(dp,triangle,row+1,col,m,n);
    int downRight=solve(dp,triangle,row+1,col+1,m,n);
    return dp[row][col]=triangle[row][col]+min(down,downRight);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=m;
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(dp,triangle,0,0,m,n);
    }
};
