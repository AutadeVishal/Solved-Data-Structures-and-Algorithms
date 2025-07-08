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
 #include<utility>
class Solution {
public:
pair<int,int>  solve(TreeNode * root){
    if(!root) return {0,0};
    auto left=solve(root->left);
    auto right=solve(root->right);
    int height=max(left.first,right.first)+1;
    int currdiameter=left.first+right.first+1;
    int previousmaxdiameter=max(left.second,right.second);
    return {height,max(currdiameter,previousmaxdiameter)};
}
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int>p=solve(root);
        return p.second-1;

    }
};
