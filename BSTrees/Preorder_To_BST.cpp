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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            TreeNode * temp=new TreeNode(preorder[i]);
            TreeNode * curr=root;
            TreeNode * prev=NULL;
        while(curr){
            if(temp->val>curr->val){
                prev=curr;
                curr=curr->right;
            }
            else{
                prev=curr;
                curr=curr->left;
            }
        }
        if(prev->val<temp->val){
            prev->right=temp;
        }
        else{
            prev->left=temp;
        }
        }
        return root;
    }
};
