class Solution {
  public:
  void findforeach(Node * &root,int &count,int &targetsum){
      if(!root) return;
      solve(root,count,targetsum,0);
      if(root->left) findforeach(root->left,count,targetsum);
      if(root->right) findforeach(root->right,count,targetsum);
     
  }
  void solve(Node * &root,int &count,int &targetsum,int currsum){
      if(!root) return;
      currsum+=root->data;
      if(currsum==targetsum){
          count++;
      }
      if(root->left) solve(root->left,count,targetsum,currsum);
      if(root->right) solve(root->right,count,targetsum,currsum);
  }
    int sumK(Node *root, int k) {
        // code here
        int count=0;
        findforeach( root,count,k);
        return count;
    }
};
