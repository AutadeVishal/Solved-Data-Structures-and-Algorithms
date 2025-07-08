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
void solve(TreeNode * &root ,vector<TreeNode * >&inorder){
    if(!root) return;
    if(root->left){
        solve(root->left,inorder);

    }
    inorder.push_back(root);
    if(root->right) solve(root->right,inorder);
}
TreeNode * bal(vector<TreeNode *>&inorder,int low,int high){
    if(high<low){
        return NULL;
    }
    int m=low+(high-low)/2;
TreeNode * mid=inorder[m];
mid->right=bal(inorder,m+1,high);
mid->left=bal(inorder,low,m-1);
return mid;
}
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode *>inorder;
        solve(root,inorder);
        int low=0,high=inorder.size()-1;
      return  bal(inorder,0,inorder.size()-1);

    }
};
