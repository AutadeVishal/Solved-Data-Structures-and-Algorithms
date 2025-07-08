class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int n=arr.size();
       
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
      int  target=totalSum/2;
        vector<vector<bool>>dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
            
        }
       if(arr[0]<=target) dp[0][arr[0]]=true;
       for(int i=1;i<n;i++){
           for(int currTarget=1;currTarget<=target;currTarget++){
               bool taken=false;
               if(arr[i]<=currTarget) taken=dp[i-1][currTarget-arr[i]];
               bool nottaken=dp[i-1][currTarget];
               dp[i][currTarget]=taken || nottaken;
           }
       }
       int mini=INT_MAX;
     for(int i=target; i>=0; i--){
    if(dp[n-1][i]){
        int sum1 = i;
        int sum2 = totalSum - i;
        mini = min(mini, abs(sum1 - sum2));
    }
}
      return mini;
    }
};
