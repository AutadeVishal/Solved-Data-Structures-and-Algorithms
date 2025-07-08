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
TreeNode * solve(vector<int>& preorder,vector<int>&inorder,int &index,int inorderstart,int inorderend,int &n,unordered_map<int,int>&m){
    if(index>n || inorderstart>inorderend){
        return NULL;
    }
    TreeNode * root=new TreeNode(preorder[index]);
    int pos=m[preorder[index]];


    index++;
    root->left=solve(preorder,inorder,index,inorderstart,pos-1,n,m);
     root->right=solve(preorder,inorder,index,pos+1,inorderend,n,m);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0,inorderstart=0,inorderend=inorder.size()-1;
        int n=inorderend;
        unordered_map<int,int>m;
        for(int i=0;i<=n;i++){
            m[inorder[i]]=i;
        }
        return solve(preorder,inorder,index,inorderstart,inorderend,n,m);
    }
};
