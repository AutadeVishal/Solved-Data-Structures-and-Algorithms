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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode *>q;
        if(!root) return ans;
        q.push(root);
    bool lefttoright=true;
        while(!q.empty()){
            
            int s=q.size();
            vector<int>v(s);
            for(int i=0;i<s;i++){
                TreeNode * frontnode=q.front();
                q.pop();
                if(lefttoright){
                    v[i]=frontnode->val;
                }
                else{
                    v[s-i-1]=frontnode->val;
                }
               if(frontnode->left) q.push(frontnode->left);
               if(frontnode->right) q.push(frontnode->right);
            }
             lefttoright=!lefttoright;
            ans.push_back(v);
        }
        return ans;
    }
};
