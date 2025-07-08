class Solution {
  public:
  int solve(vector<int>&arr,int start,int end){
      int prev1=arr[start];
      int prev2=0;
      for(int i=start+1;i<end;i++){
          int include=arr[i]+prev2;
          int exclude=prev1;
          int curr=max(include,exclude);
          prev2=prev1;
          prev1=curr;
      }
      return prev1;
  }
    int maxValue(vector<int>& arr) {
        // your code here
        int n=arr.size();
        int excludeleft=solve(arr,1,n);
        int excluderight=solve(arr,0,n-1);
        return max(excludeleft,excluderight);
    }
};
