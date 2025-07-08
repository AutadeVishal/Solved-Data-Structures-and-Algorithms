class Solution {
public:
    int solve(int idx,int amountLeft,vector<int>&coins,vector<vector<int>>&dp){
           if(idx<0) {
            if(amountLeft==0) return 1;
            return 0;
           }
          
        if(dp[idx][amountLeft]!=-1)return dp[idx][amountLeft];
        int taken=0;
        if(coins[idx]<=amountLeft){
            taken=solve(idx,amountLeft-coins[idx],coins,dp);
        }
        int nottaken=solve(idx-1,amountLeft,coins,dp);
        return dp[idx][amountLeft]=taken+nottaken;

    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};
