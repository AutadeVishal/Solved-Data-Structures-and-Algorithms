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
        unordered_set<int>s;
        bool result=false;
        TreeNode * curr=root;
        while(curr){
            if(!curr->left){
             if(!result){   if(s.find(k-curr->val)!=s.end()){
                    result= true;
                }
                s.insert(curr->val);
             }
                curr=curr->right;
            }
            else {
                TreeNode * pre=curr->left;
                while(pre->right!=NULL && pre->right!=curr){
                    pre=pre->right;
                }
                if(!pre->right){
                    pre->right=curr;
                  
                    curr=curr->left;
                   
                }
                else{
                      
                    pre->right=NULL;
                   if(!result){  if(s.find(k-curr->val)!=s.end()){
                    result= true;
                }
                s.insert(curr->val);
                   }
                    curr=curr->right;
                    
                }
            }
        }
    return result;
    }
};
