class Solution {
public:
void solve(vector<int>&candidates,int &target,int index,vector<int>output,vector<vector<int>>&v,int size){
if(size>target){
    return;
}
if(size==target){
    v.push_back(output);
    return;
}
if(index>=candidates.size()) return;
output.push_back(candidates[index]);
solve(candidates,target,index,output,v, size+candidates[index]);
output.pop_back();
solve(candidates,target,index+1,output,v,size); 
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>v;
        vector<int>output;
        solve(candidates,target,0,output,v,0);
        return v;
    }
};
