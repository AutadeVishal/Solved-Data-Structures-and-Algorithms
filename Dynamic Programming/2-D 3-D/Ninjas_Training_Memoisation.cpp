class Solution {
  public:
  int solve(int currPosition,vector<vector<int>>&dp,vector<vector<int>>&arr,int previousTaskTaken){
      if(currPosition==0) {
          int maxi=0;
          for(int i=0;i<3;i++){
              int points=arr[0][i];
              if(i!=previousTaskTaken) maxi=max(maxi,points);
          }
          return maxi;
      }
      int maxi=0;
      for(int i=0;i<3;i++){
          if(i!=previousTaskTaken){
              int points=0;
              if(dp[currPosition][i]!=-1) points=dp[currPosition][i];
              else {
                  points=arr[currPosition][i]+solve(currPosition-1,dp,arr,i);
                  dp[currPosition][i]=points;
              }
            maxi=max(maxi,points);
          }
      }
      return maxi;
  }
    int maximumPoints(vector<vector<int>>& arr) {
  
        int rows=arr.size();
        int cols=3;
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        return solve(rows-1,dp,arr,-1);
    }
};
