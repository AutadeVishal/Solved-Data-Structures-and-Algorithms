class Solution {
  public:
  void leftside(Node * root,vector<int> & ans){
      if(!root) return ;
      if(!root->left && !root->right){
          return;
      }
      
      ans.push_back(root->data);
      if(root->left){
          leftside(root->left,ans);
      }
      else{
          leftside(root->right,ans);
      }
  }
  void onlyleafs(Node * root,vector<int> & ans){
       if(!root) return;
       if(!root->left && !root->right){
           ans.push_back(root->data);
       }
       if(root->left){
           onlyleafs(root->left,ans);
       }
       if(root->right){
           onlyleafs(root->right,ans);
       }
  }
  void rightside(Node * root,vector<int> & ans){
      if(!root) return;
      if(!root->left && !root->right){
          return;
      }
      if(root->right){
          rightside(root->right,ans);
       
      }
      else{
          rightside(root->left,ans);
      }
         ans.push_back(root->data);
  }
    vector<int> boundaryTraversal(Node *root) {
        if(!root->left && !root->right) return {1};
        // code here
        vector<int>ans;
        if(!root) return ans;
        ans.push_back(root->data);
        leftside(root->left,ans);
        onlyleafs(root,ans);
        rightside(root->right,ans);
        return ans;
    }
};
