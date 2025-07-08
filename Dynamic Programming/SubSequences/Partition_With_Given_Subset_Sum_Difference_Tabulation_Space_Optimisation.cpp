class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
        }
       if ((total - d) < 0 || (total - d) % 2 != 0) return 0;

      vector<int>dp(total+1,0);
      if(arr[0]==0){
          dp[0]=2;
      }
      else{
          dp[0]=1;
          dp[arr[0]]=1;
      }
       
        for(int i=1;i<arr.size();i++){
            vector<int>temp(total+1,0);
            for(int j=0;j<total+1;j++){
                int taken=0;
                if(arr[i]<=j) taken=dp[j-arr[i]];
                int  nottaken=dp[j];
                temp[j]=taken+nottaken;
            }
            dp=temp;
        }
       
       //a+b=total
       //a-b=d
       //2a=total-d
       //a=(total-d)/2
        int sum1=(total-d)/2;
        return dp[sum1];
        
    }
};
