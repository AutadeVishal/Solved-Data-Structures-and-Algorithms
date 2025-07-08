class Solution {
  public:
  bool solve(int idx,int target,vector<vector<int>>&dp,vector<int>&arr){
      if(target==0) return true;
      if(idx==0)return (arr[0]==target);
      bool taken=false;
      if(dp[idx][target]!=-1) return( dp[idx][target]==1 ? true:false);
      if(arr[idx]<=target){
          taken=solve(idx-1,target-arr[idx],dp,arr);
      }
      bool nottaken=solve(idx-1,target,dp,arr);
      bool ans=taken || nottaken;
      return  dp[idx][target] = ans==1 ? true:false;
  }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
    vector<vector<int>>dp(arr.size(),vector<int>(sum+1,-1));
    return solve(arr.size()-1,sum,dp,arr);
    
    }
};
