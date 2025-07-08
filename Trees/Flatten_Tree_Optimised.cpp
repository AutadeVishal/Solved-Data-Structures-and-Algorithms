class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        while(root){
            if(!root->left){
                root=root->right;
            }
          else{  TreeNode * pred=root->left;
            while(pred->right!=NULL ){
                pred=pred->right;
            }
            if(pred->right==NULL){
                pred->right=root->right;
                root->right=root->left;
                root->left=NULL;
                root=root->right;
            }
            
        }
        }
    }
};
