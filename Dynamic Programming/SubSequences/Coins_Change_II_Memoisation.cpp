class Solution {
public:
    

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,0));
       for(int i=0;i<=amount;i++){
        if(i%coins[0]==0){
            dp[0][i]=1;
        }
        
       }
       for(int i=1;i<coins.size();i++){
        for(int amountLeft=0;amountLeft<amount+1;amountLeft++){
            long taken=0;
            if(coins[i]<=amountLeft){
                taken=dp[i][amountLeft-coins[i]];
                
            }
            long nottaken=dp[i-1][amountLeft];
            dp[i][amountLeft]=taken+nottaken;
        }
       }
    return dp[coins.size()-1][amount];
    }
};
