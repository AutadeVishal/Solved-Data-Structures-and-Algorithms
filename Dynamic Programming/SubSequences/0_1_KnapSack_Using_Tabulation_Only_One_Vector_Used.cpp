class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code her
       vector<int>dp(W+1,0);
        for(int i=0;i<=W;i++){
            if(wt[0]<=i){
                dp[i]=val[0];
            }
        }
        for(int idx=1;idx<val.size();idx++){
            vector<int>temp(W+1,0);
            for(int weight=W;weight>0;weight--){
                int taken=0;
                if(wt[idx]<=weight){
                    taken=val[idx]+dp[weight-wt[idx]];
                }
                int nottaken=dp[weight];
               dp[weight]=max(taken,nottaken);
            }
        }
        return dp[W];
    }
};
