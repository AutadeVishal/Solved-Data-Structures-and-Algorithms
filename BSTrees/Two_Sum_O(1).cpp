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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        stack<TreeNode * >small;
        stack<TreeNode *> large;
        TreeNode *left=root;
        TreeNode * right=root;
        while(left->left){
            small.push(left);
            left=left->left;
        }
        while(right->right){
            large.push(right);
            right=right->right;
        }
        while(left!=right){
          int sum=left->val+right->val;
            if(sum==k && left->val!=right->val){
                return true;
            }
            else if(sum>k){
                if(right->left){
                    
                    right=right->left;
                
                    while(right && right->right) {
                        large.push(right);
                        right=right->right;
                    }
                }
                else if(!large.empty()){
                    right=large.top();
                    large.pop();
                
                }
                else return false;
            }
            else{
                if(left->right){
                
                    left=left->right;
                
                    while(left && left->left){
                        small.push(left);
                        left=left->left;
                    }
            }
                else if(!small.empty()){
                   left=small.top();
                    small.pop();
                  
                }
               
            }
        }
return false;
    }
};
