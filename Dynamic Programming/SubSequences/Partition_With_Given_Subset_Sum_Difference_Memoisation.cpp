class Solution {
  public:
  int solve(int idx,int target,vector<vector<int>>&dp,vector<int>&arr){
      if(idx==0){
          if(target==0 && arr[0]==0) return 2;
          if(target==arr[0]) return 1;
          if(target==0) return 1;
          return 0;
      }
      
      if(dp[idx][target]!=-1) return dp[idx][target];
      int taken=0;
      if(arr[idx]<=target){
          taken=solve(idx-1,target-arr[idx],dp,arr);
      }
      int nottaken=solve(idx-1,target,dp,arr);
     return dp[idx][target]=taken+nottaken;
      
  }
    int countPartitions(vector<int>& arr, int d) {
       int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum < d || (totalSum - d) % 2 != 0)
            return 0;

        int sum1 = (totalSum - d) / 2;
        vector<vector<int>> dp(arr.size(), vector<int>(sum1 + 1, -1));

        return solve(arr.size() - 1, sum1, dp, arr);
    }
};
