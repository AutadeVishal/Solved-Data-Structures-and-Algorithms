#include <bits/stdc++.h> 
int solve(int currrow,int j1,int j2,int row,int col,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(currrow<0 || currrow>=row || j1<0 || j1>=col ||j2<0 || j2>=col) return INT_MIN;
if(currrow==row-1){
    if(j1==j2) return grid[currrow][j1];
    else return grid[currrow][j1]+grid[currrow][j2];
}
if(dp[currrow][j1][j2]!=-1) return dp[currrow][j1][j2];
int currsum;
 if(j1==j2)  currsum=grid[currrow][j1] ;
 else  currsum= grid[currrow][j1]+grid[currrow][j2];
 int maxi=INT_MIN;
for(int i=-1;i<2;i++){//for alice
    for(int j=-1;j<2;j++){//for bob
        int newj1=j1+i;
        int newj2=j2+j;
      
           int value=currsum+solve(currrow+1,newj1,newj2,row,col,grid,dp);
            maxi=max(value,maxi);
       
    }
}
return dp[currrow][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return solve(0,0,c-1,r,c,grid,dp);
}
