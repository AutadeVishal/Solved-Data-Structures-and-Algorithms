class Solution {
public:

    bool canPartition(vector<int>& nums) {
      int  maxsum =0;
      for(int i:nums){
        maxsum+=i;
      }
        if(maxsum%2==1) return false;
        int k=maxsum/2;
        vector<vector<bool>>dp(nums.size(),vector<bool>(k+1,false));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
       if(nums[0]<=k) dp[0][nums[0]]=true;
       for(int i=1;i<nums.size();i++){
        for(int target=1;target<=k;target++){
            bool taken=false;
            if(nums[i]<=target) {
                taken=dp[i-1][target-nums[i]];
            }
            bool nottaken=dp[i-1][target];
            dp[i][target]=taken || nottaken;
        }
       }
       return dp[nums.size()-1][k];
    }
};
