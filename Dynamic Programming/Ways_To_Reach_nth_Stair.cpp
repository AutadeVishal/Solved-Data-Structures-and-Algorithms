//Tabulation
class Solution {
  public:
    int countWays(int n) {
        // your code here
        int prev2=0;
        int prev1=1;
        for(int i=1;i<=n;i++){
            int curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};


//Memoisation 
class Solution {
  public:
  int ways(int curr,vector<int>&v){
      if(curr<=1) return 1;
      if(v[curr]!=0) return v[curr];
      return v[curr]=ways(curr-1,v)+ways(curr-2,v);
  }
    int countWays(int n) {
        // your code here
      vector<int>v(n+1,0);
      v[0]=1;
      v[1]=1;
      return ways(n,v);
    }
};
