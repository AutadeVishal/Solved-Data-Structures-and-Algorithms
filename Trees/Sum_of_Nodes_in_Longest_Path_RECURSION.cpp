class Solution {
  public:
  
    int longestpath=0;
    int sum=0;
  void solve(Node * root,int path,int  s ){
      if(!root) return ;
          s+=root->data;
          if(!root->left && !root->right){
              if(path>longestpath){
                  longestpath=path;
                  sum=s;
                  
                  return;
              }
              if(path==longestpath){
                  if(s>sum) sum=s;
                  return;
              }
          }
          if(root->left) solve(root->left,path+1,s);
          if(root->right) solve(root->right,path+1,s);
  }
    int sumOfLongRootToLeafPath(Node *root) {
    if(!root) return NULL;
    solve(root,0,0);
    return sum;
    }
};
