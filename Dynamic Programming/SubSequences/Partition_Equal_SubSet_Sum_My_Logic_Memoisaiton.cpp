class Solution {
public:
bool solve(int idx,int sum1,int sum2,vector<int>&nums,vector<vector<vector<int>>>&dp){
    if(idx==-1){
        if(sum1==sum2) return true;
        return false;
    }
    if(dp[idx][sum1][sum2]!=-1) return dp[idx][sum1][sum2]==1;
    bool takenInFirst=solve(idx-1,sum1+nums[idx],sum2,nums,dp);
    bool takenInSecond=solve(idx-1,sum1,sum2+nums[idx],nums,dp);
    dp[idx][sum1][sum2]=(takenInFirst || takenInSecond) == true ? 1:0;
    return dp[idx][sum1][sum2]==1 ? true:0;
}
    bool canPartition(vector<int>& nums) {
        int maxsum=0;
        for(int i=0;i<nums.size();i++){
            maxsum+=nums[i];
        }
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(maxsum+1,vector<int>(maxsum+1,-1)));
        return solve(nums.size()-1,0,0,nums,dp);
    }
};
