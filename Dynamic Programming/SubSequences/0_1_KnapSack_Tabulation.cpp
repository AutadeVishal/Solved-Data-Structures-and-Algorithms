class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        vector<vector<int>>dp(val.size(),vector<int>(W+1,0));
        for(int i=0;i<=W;i++){
            if(wt[0]<=i){
                dp[0][i]=val[0];
            }
        }
        for(int idx=1;idx<val.size();idx++){
            for(int weight=1;weight<=W;weight++){
                int taken=0;
                if(wt[idx]<=weight){
                    taken=val[idx]+dp[idx-1][weight-wt[idx]];
                }
                int nottaken=dp[idx-1][weight];
                dp[idx][weight]=max(taken,nottaken);
            }
        }
        return dp[val.size()-1][W];
    }
};
