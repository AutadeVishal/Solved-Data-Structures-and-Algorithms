class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>dp(arr.size(),vector<int>(3,0));
        for(int i=0;i<3;i++){
            dp[0][i]=arr[0][i];
        }
        for(int i=1;i<arr.size();i++){
            
            
            for(int j=0;j<3;j++){
                int prevmaxi=-1;
                for(int k=0;k<3;k++){
                if(j!=k)prevmaxi=max(prevmaxi,dp[i-1][k]);
            }
                dp[i][j]=arr[i][j]+prevmaxi;
            }
        }
        int maxi=-1;
        for(int i=0;i<3;i++){
            maxi=max(maxi,dp[arr.size()-1][i]);
        }
        return maxi;
    }
};
