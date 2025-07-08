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
pair<TreeNode *,int> height(TreeNode * root){
    if(!root) return {NULL,0};
    auto left=height(root->left);
    auto right=height(root->right);
    return {root,max(left.second,right.second)+1};
}
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        if(abs(height(root->left).second-height(root->right).second ) >1) return false;
        else{
            return left && right ;
        }
    }
};
