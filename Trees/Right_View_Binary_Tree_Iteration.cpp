class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
  
    vector<int> rightView(Node *root)
    {
       vector<int>v;
       queue<pair<Node *,int>>q;
       q.push({root,0});
       while(!q.empty()){
       Node * curr=q.front().first;
       int level=q.front().second;
       if(v.size()==level){
           v.push_back(curr->data);
       }
        if(curr->right) q.push({curr->right,level+1});
       if(curr->left) q.push({curr->left,level+1});
      
      
       q.pop();
    }
     return v;
}};
