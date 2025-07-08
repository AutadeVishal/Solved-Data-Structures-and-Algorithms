class Solution {

  public:
    int minDifference(vector<int>& arr) {
        int n=arr.size();
       
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
      int  target=totalSum/2;
        vector<bool>dp(target+1,false);
        for(int i=0;i<n;i++){
            dp[0]=true;
            
        }
       if(arr[0]<=target) dp[arr[0]]=true;
       for(int i=1;i<n;i++){
           vector<bool>temp(target+1,false);
           temp[0]=true;
           for(int currTarget=1;currTarget<=target;currTarget++){
               bool taken=false;
               if(arr[i]<=currTarget) taken=dp[currTarget-arr[i]];
               bool nottaken=dp[currTarget];
             temp[currTarget]=taken || nottaken;
           }
           dp=temp;
       }
       int mini=INT_MAX;
     for(int i=target; i>=0; i--){
    if(dp[i]){
        int sum1 = i;
        int sum2 = totalSum - i;
        mini = min(mini, abs(sum1 - sum2));
    }
}
      return mini;
    }
};
