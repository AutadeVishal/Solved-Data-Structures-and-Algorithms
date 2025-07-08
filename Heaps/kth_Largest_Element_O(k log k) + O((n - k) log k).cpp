class Solution {
public:
void hepify(vector<int>&nums,int size,int position){
int smallest=position;
int left=smallest*2+1;
int right=smallest*2+2;
if(left<size && nums[smallest]>nums[left]) smallest=left;
if(right<size && nums[smallest]>nums[right]) smallest=right;
if(smallest!=position){
    swap(nums[smallest],nums[position]);
    hepify(nums,size,smallest);
}
}
    int findKthLargest(vector<int>& nums, int k) {
       for(int i=k/2-1;i>=0;i--){
        hepify(nums,k,i);
       }
       for(int i=k;i<nums.size();i++){
        if(nums[i]>nums[0]) { 
            swap(nums[0],nums[i]);
        hepify(nums,k,0);
        }
       }
        return nums[0];
    }
   
};
