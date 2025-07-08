class Solution {
  public:
    vector<int> diagonal(Node *root) {
        if(!root) return {};
      queue<Node * >q;
      q.push(root);
      vector<int>ans;
      while(!q.empty()){
          Node* curr=q.front();
          q.pop();
          while(curr){
              
              ans.push_back(curr->data);
              if(curr->left){
                  q.push(curr->left);
              }
              if(curr->right){
                  curr=curr->right;
            }
            else{
                curr=NULL;
            }
          }
      }
      return ans;
    }
};
