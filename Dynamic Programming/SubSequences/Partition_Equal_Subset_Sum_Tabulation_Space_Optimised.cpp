class Solution {
public:

    bool canPartition(vector<int>& nums) {
      int  maxsum =0;
      for(int i:nums){
        maxsum+=i;
      }
        if(maxsum%2==1) return false;
        int k=maxsum/2;
       vector<bool>dp(k+1,false);
       dp[0]=true;
       
       if(nums[0]<=k) dp[nums[0]]=true;
       for(int i=1;i<nums.size();i++){
        vector<bool>temp(k+1,false);
        temp[0]=true;
        for(int target=1;target<=k;target++){
            bool taken=false;
            if(nums[i]<=target) {
                taken=dp[target-nums[i]];
            }
            bool nottaken=dp[target];
            temp[target]=taken || nottaken;
        }
        dp=temp;
       }
       return dp[k];
    }
};
