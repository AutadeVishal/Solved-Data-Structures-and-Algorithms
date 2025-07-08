class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<bool>>dp(arr.size(),vector<bool>(sum+1,false));
        for(int i=0;i<arr.size();i++){
            dp[i][0]=true;//for every index i target is 0 means
            //you gaat it (the center of graavity paijan)
        }
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        //from 0 th index if you want to find target (sum here variable name)
        //you can always go to arr[0] but need to check is it less than target
        //else dp[0][arr[0]] could go out of bound and anyway we dont take it when currvalue>target
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<sum+1;j++){
                bool taken=false;
                if(arr[i]<=j){
                    taken=dp[i-1][j-arr[i]];
                }
                int nottaken=dp[i-1][j];
                dp[i][j]=taken || nottaken;
            }
        }
        return dp[arr.size()-1][sum];
    }
};
