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
void deleteleft(TreeNode * root,int key){
    TreeNode * maain=root;
    TreeNode * pre=NULL;
    root=root->left;
    while(root->right)
    {
        pre=root;
        root=root->right;
    
    }
    maain->val=root->val;
   if(pre)  pre->right=root->left;
   else maain->left=root->left;
     
    delete root;
   
    
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
      TreeNode * curr=root;
        TreeNode * pre=NULL;
       
        while(curr && curr->val!=key){
            pre=curr;
            if(key<curr->val){
                curr=curr->left;

            }
            else 
            {
                curr=curr->right;
            }
        }
        if(!curr) return root;
       if(!curr->left && !curr->right){
        if(!pre)return NULL;
        if(pre->left==curr){
            pre->left=NULL;
        }
        else pre->right=NULL;
        delete curr;
       }
       else if(!curr->left || !curr->right){
        TreeNode * child=(curr->left)? curr->left:curr->right;
        if(!pre){
            delete curr;
            return child;
        }
        else{
            if(pre->left==curr){
                pre->left=child;
                delete curr;
            }
            else {
                pre->right=child;
                delete curr;
            }
        }
       }
       else{
            deleteleft(curr,key);
        
       }
        return root;
    }
};
