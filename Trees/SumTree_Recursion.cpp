// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  pair<bool,int> solve(Node * root){
      if(!root) return {true,0};
      if(!root->right && !root->left) return {true,root->data}; 
      if(root->left && root->right)
      {auto left=solve(root->left);
     auto right=solve(root->right);
      if(left.first && right.first)
      { if(left.second+right.second==root->data){
          return {true,root->data+left.second+right.second};
      }
     }
     
      }
      return {false,0};
    
  }
    bool isSumTree(Node* root) {
        return solve(root).first;
    }
};
