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
int ans=INT_MIN;
int solve(TreeNode * &curr){
    if(!curr) return INT_MIN;
    int left=solve(curr->left);
    int right=solve(curr->right);
    int leftCurr=INT_MIN;
    int rightCurr=INT_MIN;
    if(left!=INT_MIN){
        leftCurr=left+curr->val;
    }
    if(right!=INT_MIN){
        rightCurr=right+curr->val;
    }
    int includingCurr=INT_MIN;
  if(left!=INT_MIN && right!=INT_MIN) includingCurr=left+curr->val+right;
    ans=max(ans,includingCurr);
    ans=max(ans,leftCurr);
    ans=max(ans,rightCurr);
    ans=max(curr->val,ans);
    return max(curr->val,max(leftCurr,rightCurr));

}
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};
