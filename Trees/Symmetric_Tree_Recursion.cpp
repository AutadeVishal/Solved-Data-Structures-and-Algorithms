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
bool dfs(TreeNode * &node1,TreeNode * &node2){
    if(!node1 && !node2) return true;
    if(!node1 || !node2 || node1->val!=node2->val) return false;
   bool left= dfs(node1->left,node2->right);
   bool right= dfs(node1->right,node2->left);
return left && right;
}
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return dfs(root->left,root->right);
    }
};
