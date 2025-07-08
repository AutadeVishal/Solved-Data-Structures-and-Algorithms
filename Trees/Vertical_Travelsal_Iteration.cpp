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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode *,int>>q;//node and its col 
        map<int,vector<pair<int,int>>>m;//map[col] to vector of row,value
        q.push({root,0});
        int row=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * curr=q.front().first;
                int col=q.front().second;
                q.pop();
                m[col].push_back({row,curr->val});
                if(curr->left){
                    q.push({curr->left,col-1});
                }
                if(curr->right){
                    q.push({curr->right,col+1});
                }
            }
            row++;
                
        }
        for(auto &i:m){
            vector<pair<int,int>>currans=i.second;
            sort(currans.begin(),currans.end());
            vector<int>ansToPush;
            for(auto &i:currans){
                ansToPush.push_back(i.second);
            }
            ans.push_back(ansToPush);
        }
        return ans;
    }
};
