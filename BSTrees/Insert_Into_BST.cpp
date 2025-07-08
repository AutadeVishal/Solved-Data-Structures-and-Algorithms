class Solution {
public:
void solve(TreeNode * &root,int &val){
    if(val<root->val){
        if(root->left!=NULL){
            solve(root->left,val);
        }
        else{
            TreeNode * temp=new TreeNode(val);
            root->left=temp;
        }
    }
    else{
        if(root->right!=NULL){
            solve(root->right,val);
        }
        else{
            TreeNode * temp=new TreeNode(val);
            root->right=temp;
        }
    }
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode * temp=new TreeNode(val);
            return temp;
        }
        solve(root,val);
        return root;
    }
};
