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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        TreeNode * prev=NULL;
        TreeNode * curr=root;
    while(curr){
        
       if(val>curr->val){
        prev=curr;
            curr=curr->right;
        }
        else{
            prev=curr;
            curr=curr->left;
        }
    }
    curr=new TreeNode(val);
    if(prev->val>val){
        
        prev->left=curr;
    }
    else{
        prev->right=curr;
    }
    return root;
    }
};
