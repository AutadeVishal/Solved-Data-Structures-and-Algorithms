
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        vector<int>sums;
        priority_queue<int,vector<int>,greater<int>>p;
        for(int i=0;i<arr.size();i++){
         p.push(arr[i]);   
        }
        int sum=0;
        while(p.size()>1){
            int a=p.top();
            p.pop();
            int b=p.top();
            p.pop();
            sum+=a+b;
            p.push(a+b);
        }
        return sum;
    }
};
