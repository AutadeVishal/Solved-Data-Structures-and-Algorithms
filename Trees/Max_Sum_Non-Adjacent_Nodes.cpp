
class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node * &root){
        if(!root) return {0,0};
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        pair<int,int> whattoreturn;
        whattoreturn = {root->data + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};

        return whattoreturn;
    }
    int getMaxSum(Node *root) 
    {
      pair<int,int>p;
      p=solve(root);
      return max(p.first,p.second);
    }
};
