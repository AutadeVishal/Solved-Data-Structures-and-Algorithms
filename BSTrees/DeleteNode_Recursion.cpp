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
TreeNode * leftmax(TreeNode * root){
while(root->right!=NULL){
    root=root->right;
}
return root;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL && root->right==NULL){
                TreeNode * temp=root->left;
                delete root;
                return temp;
            }
            else if(root->left==NULL && root->right!=NULL){
                TreeNode * temp=root->right;
                delete root;
                return temp;
            }
            else{
                TreeNode * left= leftmax(root->left);
                root->val=left->val;
                root->left=deleteNode(root->left,left->val);
            }

        }
        else if( root->val<key){
            root->right=deleteNode(root->right,key);

        }
        else{
            root->left=deleteNode(root->left,key);

        }
        return root;
    }
};
