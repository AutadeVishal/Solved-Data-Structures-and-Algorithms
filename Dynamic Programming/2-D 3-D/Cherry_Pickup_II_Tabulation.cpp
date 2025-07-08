class Solution {
public:
int solve(int r,int c1,int c2,int m,int n,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp){
    if(c1 < 0 || c2<0 ||c1 ==n || c2==n) return INT_MIN;
    if(r==m-1){
        if(c1==c2) return dp[r][c1][c2]=grid[r][c1];
        else return dp[r][c1][c2]=grid[r][c1]+grid[r][c2];
        //how to read for understanding
    // when we at rth row c1th column and robo at c2th column we get max val as dp[r][c1] [c2]

    }
    if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
    int maxi=INT_MIN;
    for(int i=-1;i<2;i++){//for c1
        for(int j=-1;j<2;j++){//for c2
            int value=solve(r+1,c1+i,c2+j,m,n,grid,dp);
            maxi=max(maxi,value);
        }
    }
   int maxvalue= (c1==c2) ? maxi+grid[r][c1]: maxi+grid[r][c1]+grid[r][c2];
    return dp[r][c1][c2]=maxvalue;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(n,0)));
        //initialise the bottom row max values in dp
       for(int j1=0;j1<n;j1++){
        for(int j2=0;j2<n;j2++){
           if(j1!=j2) dp[m-1][j1][j2]=grid[m-1][j1]+grid[m-1][j2];
           else dp[m-1][j1][j2]=grid[m-1][j1];
        }
       }

        for(int i=m-2;i>=0;i--){
            for(int j1=0;j1<n;j1++){
                for(int j2=0;j2<n;j2++){
                    
                    if(j1==j2){
                        dp[i][j1][j2]=grid[i][j1];
                    }
                    else {
                        dp[i][j1][j2]=grid[i][j1]+grid[i][j2];
                    }
                    
                    int maxi=INT_MIN;
                    for(int k1=-1;k1<2;k1++){
                       for( int k2=-1;k2<2;k2++){
                        int value;
                      if ((j1 + k1 < 0 || j1 + k1 == n) || (j2 + k2 < 0 || j2 + k2 == n)) {
                        value=0;
                      }
                    else value=dp[i+1][j1+k1][j2+k2];
                        maxi=max(maxi,value);
                      
                       }
                    }
                    dp[i][j1][j2]+=maxi;
                   
                }
            }
        }
        return dp[0][0][n-1];
    }
};
