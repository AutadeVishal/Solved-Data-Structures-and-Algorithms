#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int>&nums,vector<int>output,int index,vector<vector<int>>&answer){
if(index>=nums.size()){
    answer.push_back(output);
    return ;
}
// exclude the number
solve(nums,output,index+1,answer);
//include 
int element=nums[index];
output.push_back(element);
solve(nums,output,index+1,answer);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        solve(nums,output,0,ans);
        return ans;
    }

int main(){
vector<int>a={1,2,3};
vector<vector<int>>answer;
vector<int>output;
solve(a,output,0,answer);
for(auto i:answer){
    for(auto j:i){
        cout<<j<<" ";
    }
    cout<<endl;
}
    return 0;
}
