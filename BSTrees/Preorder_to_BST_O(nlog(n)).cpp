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

 #include<vector>
class Solution {
public:
TreeNode * solve(vector<int>& preorder,vector<int>&inorder,int &index,int start,int end,unordered_map<int,int>m){
    if(index>=preorder.size() ||end<start){
        return NULL;
    }
    TreeNode * temp=new TreeNode(preorder[index++]);
    temp->left=solve(preorder,inorder,index,start,m[temp->val]-1,m);
    temp->right=solve(preorder,inorder,index,m[temp->val]+1,end,m);
    return temp;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int index=0;
        unordered_map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
       return solve(preorder,inorder,index,0,preorder.size()-1,m);
    }
};
