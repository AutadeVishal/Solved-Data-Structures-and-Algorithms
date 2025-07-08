class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    void solve(Node * &root,int position,int level,map<int,pair<int,int>>&m){
      
          if(m.find(position)==m.end() || level<m[position].first){ 
              m[position]={level,root->data};
          }
        if(root->left) {solve(root->left,position-1,level+1,m);}
        if(root->right){
            solve(root->right,position+1,level+1,m);
        }
        
    }
    vector<int> topView(Node *root) {
        vector<int>v;
        if(!root)return v;
        
        map<int,pair<int,int>>m;
       solve(root,0,0,m);
       for(auto i:m){
           v.push_back(i.second.second);
       }
       return v;
    }
};
