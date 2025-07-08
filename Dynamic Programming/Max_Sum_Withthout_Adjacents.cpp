//space optimisatoin+tabulation 
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        int prev2=arr[0];
        int prev1=max(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++){
            
            int include=arr[i]+prev2;
            int exclude=prev1;
            int curr=max(include,exclude);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};
//tabulation
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size(),0);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<arr.size();i++){
            int include=arr[i]+dp[i-2];
            int exclude=dp[i-1];
            dp[i]=max(include,exclude);
        }
        return dp[arr.size()-1];
    }
};

//memoisation
// User function template for C++
class Solution {
  public:
    // calculate the maximum sum with out adjacent
    int solve(int i,vector<int>&dp,vector<int>&arr){
        if(i==0)return dp[0]=arr[0];
        if(dp[i]!=0) return dp[i];
        if(i==1) return max(arr[0],arr[1]);
        int included=arr[i]+solve(i-2,dp,arr);
        int excluded=solve(i-1,dp,arr);
        return dp[i]=max(included,excluded);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        vector<int>dp(arr.size(),0);
     int x=solve(arr.size()-1,dp,arr);
        return x;
    }
};
