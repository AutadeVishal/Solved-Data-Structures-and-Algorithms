void inorder(BinaryTreeNode * &root,vector<int >&v){
	if(!root) return;
	inorder(root->left,v);
	v.push_back(root->data);
inorder(root->right,v);
}
BinaryTreeNode * preorder(BinaryTreeNode * root,vector<int>v,int &index,int &size){
if(!root) return nullptr;
root->data=v[index++];
root->left=preorder(root->left,v,index,size);
root->right=preorder(root->right,v,index,size);
return root;
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
vector<int>v;
inorder(root,v);
int index=0;
int size=v.size();
return  preorder(root,v,index,size);

}
