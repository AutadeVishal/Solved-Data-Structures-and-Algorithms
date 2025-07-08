class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
   void solve(Node * root,int level,vector<int>&v){
         if(!root) return;
         if(v.size()==level){
             v.push_back(root->data);
         }
         if(root->right) solve(root->right,level+1,v);
         if(root->left) solve(root->left,level+1,v);
    }
    vector<int> rightView(Node *root)
    {
       vector<int>v;
       solve(root,0,v);
       return v;
       
    }
};
