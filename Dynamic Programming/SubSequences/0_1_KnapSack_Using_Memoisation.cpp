class Solution {
  public:
  int solve(int idx,int remainWeight,vector<vector<int>>&dp,vector<int>&val,vector<int>&wt){
   if(idx<0 || remainWeight<0) return 0;
   if(dp[idx][remainWeight]!=-1) return dp[idx][remainWeight];
   int taken=0;
   if(wt[idx]<=remainWeight){
       taken=val[idx]+solve(idx-1,remainWeight-wt[idx],dp,val,wt);
   }
   int nottaken=solve(idx-1,remainWeight,dp,val,wt);
   return dp[idx][remainWeight]=max(taken,nottaken);
      
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        return solve(n-1,W,dp,val,wt);
    }
};
