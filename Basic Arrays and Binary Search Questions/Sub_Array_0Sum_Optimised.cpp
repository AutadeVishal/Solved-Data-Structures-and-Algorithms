class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int sum=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(auto i:arr){
          sum+=i;
            if(m.find(sum)!=m.end()){
                return true;
            }
            m[sum]++;
        }
        return false;
    }
};
