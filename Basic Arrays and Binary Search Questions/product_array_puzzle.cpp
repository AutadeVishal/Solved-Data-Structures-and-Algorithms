// User function template for C++
#include<vector>
class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
         vector<long long>m;
         long long a=1;
         int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            if(nums[i]!=0){
            a*=nums[i];
        }
        
        }
        for(int i=0;i<nums.size();i++){
            if(count>1){
                m.push_back(0);
            }
            else if(count==1){
                if(nums[i]!=0){
                    m.push_back(0);
                }
                else{
            m.push_back(a);
                }
            }
            else{
                m.push_back(a/nums[i]);
            }
        }
        // code here
        return m;
    }
};
