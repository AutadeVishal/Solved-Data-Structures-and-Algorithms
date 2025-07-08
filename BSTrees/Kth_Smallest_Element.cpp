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

    int kthSmallest(TreeNode* root, int k){
        int count=0;
        int ans=-1;
        TreeNode * curr=root;
    if(!curr) return 0;
       while(curr){ 
        if(curr->left==NULL){
            count++;
            if(k==count)ans=curr->val;
            curr=curr->right;
        }
       else{ 
        TreeNode * pre=curr->left;
       
        while(  pre->right && pre->right!=curr)
        {
             pre=pre->right;
        }
        if(pre->right==NULL){
            pre->right=curr;
            curr=curr->left;
        }
        else{
            count++;
            pre->right=NULL;
            if(k==count) ans=curr->val;
            
            curr=curr->right;
        }
       }
       }
       return ans;
    
    }
};
