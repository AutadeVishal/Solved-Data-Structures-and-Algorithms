/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void solve(TreeNode * curr,map<int,vector<pair<int,int>>>&m,int row,int col){
if(!curr)return;
m[col].push_back({row,curr->val});
solve(curr->left,m,row+1,col-1);
solve(curr->right,m,row+1,col+1);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,vector<pair<int,int>>>m;
        solve(root,m,0,0);
        for(auto &i:m){
            vector<pair<int,int>>curr=i.second;

            sort(curr.begin(),curr.end());//how to sort based on i.second.first
            vector<int>currans;
           for(int i=0;i<curr.size();i++){
            currans.push_back(curr[i].second);
           }
           ans.push_back(currans);
        }
       
        return ans;

    }
};
