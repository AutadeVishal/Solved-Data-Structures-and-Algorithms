class Solution {
public:
bool solve(int idx,int target,vector<int>&nums,vector<vector<int>>&dp){
    if(idx<0){
        if(target==0) return true;
        return false;
    }
    if(target==0) return true;
    if(dp[idx][target]!=-1) return dp[idx][target];
    bool taken=false;
    if(nums[idx]<=target) taken=solve(idx-1,target-nums[idx],nums,dp);
    bool nottaken=solve(idx-1,target,nums,dp);
    return dp[idx][target]= taken || nottaken;
}
    bool canPartition(vector<int>& nums) {
      int  maxsum =0;
      for(int i:nums){
        maxsum+=i;
      }
        if(maxsum%2==1) return false;
        int k=maxsum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(k+1,-1));
        return solve(nums.size()-1,k,nums,dp);
    }
};
