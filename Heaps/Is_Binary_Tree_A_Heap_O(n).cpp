class Solution {
  public:
int size(struct Node * root){
    if(!root) return 0;
    int left=size(root->left);
    int right=size(root->right);
    return left+right+1;
}
bool iscbt(struct Node * root,int position,int size){
    if(!root) return true;
    if(position>size)return false;
    bool left=iscbt(root->left,position*2,size);
    bool right=iscbt(root->right,position*2+1,size);
    return right && left;
}
bool iscorrect(struct Node * root){
    if(!root) return true;
  if(root->left && root->left->data>root->data) return false;
      
  
  if(root->right && root->right->data>root->data) return false;
  return iscorrect(root->left) && iscorrect(root->right);
  
}
    bool isHeap(struct Node* tree) {
      if(iscbt(tree,1,size(tree))){
          return iscorrect(tree);
      }
      return false;
    }
};
