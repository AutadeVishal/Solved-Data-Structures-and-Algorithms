class Solution {
public:
int solve(int row,int col,vector<vector<int>>&dp,vector<pair<int,int>>&nd){
    if(dp[row][col]!=-1) return dp[row][col];
    dp[row][col]=0;
    int sum=0;
    
    for(int i=0;i<2;i++){
        int nr=row+nd[i].first;
        int nc=col+nd[i].second;
        
        if(nr>=0 && nc>=0){
            sum+=solve(nr,nc,dp,nd);
        }
       
    }
     return dp[row][col]=sum;
}
    int uniquePaths(int m, int n) {
        vector<pair<int,int>>nd={{-1,0},{0,-1}};
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        return solve(m-1,n-1,dp,nd);

    }
};
