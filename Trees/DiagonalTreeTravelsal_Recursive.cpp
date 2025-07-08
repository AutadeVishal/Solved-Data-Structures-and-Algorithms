
class Solution {
  public:
  void solve(Node * root,int diagonal,map<int,vector<int>>&m){
      if(!root) return;
      m[diagonal].push_back(root->data);
      if(root->left){
          solve(root->left,diagonal+1,m);
          
      }
      if(root->right){
          solve(root->right,diagonal,m);
      }
  }
    vector<int> diagonal(Node *root) {
        vector<int>v;
        if(!root) return {};
       map<int,vector<int>>m;
       solve(root,0,m);
       for(auto i:m){
           v.insert(v.end(),i.second.begin(),i.second.end());
       }
       return v;
    }
};
