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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode *>q;
        q.push(root);
        int maxdepth=0;
        TreeNode * temp;
        while(!q.empty()){
            int currLevelSize=q.size();
            for(int i=0;i<currLevelSize;i++){
                    temp=q.front();
                    q.pop();
                  if(temp->left)  q.push(temp->left);
                   if(temp->right) q.push(temp->right);
            }
            maxdepth++;
        }
        return maxdepth;
    }
};
