class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>vv;
        int n=pow(2,nums.size());
        while(n!=0){
            int a=n;
            int x=0;
            vector<int>v;
            while(a!=0){

                if( x<nums.size() && a&1==1){
                    v.push_back(nums[x]);
                    
                }
                a=a>>1;
                x++;
            }
            vv.push_back(v);
            n--;
        }
        return vv;
    }
};
