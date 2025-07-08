class Solution {
public:
TreeNode * solve(vector<int>& inorder,vector<int>& postorder,int &index,int inorderstart,int inorderend,unordered_map<int,int>&m){
    if(index<0 || inorderstart>inorderend) return NULL;
    TreeNode * root=new TreeNode(postorder[index]);
    int position=m[postorder[index--]];
     root->right=solve(inorder,postorder,index,position+1,inorderend,m);
    root->left=solve(inorder,postorder,index,inorderstart,position-1,m);
   
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        int index=postorder.size()-1;
        return solve(inorder,postorder,index,0,index,m);
    }
};
