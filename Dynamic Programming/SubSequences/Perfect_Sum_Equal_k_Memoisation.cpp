class Solution {
  public:
  int solve(int idx,int target,vector<int>&arr,vector<vector<int>>&dp){
      if(idx==0){
          if(target==0 && arr[0]==0) return 2;// include 0 +exclude 0 ==2
          if(target==0 ) return 1;
          if(target==arr[0]) return 1;
          return 0;
      }
      
      if(dp[idx][target]!=-1) return dp[idx][target];
      int taken=0,nottaken=0;
      if(arr[idx]<=target){
          taken=solve(idx-1,target-arr[idx],arr,dp);
      }
      nottaken=solve(idx-1,target,arr,dp);
      return dp[idx][target]=taken+nottaken;
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(target+1,-1));
        return solve(arr.size()-1,target,arr,dp) ;
    }
};
