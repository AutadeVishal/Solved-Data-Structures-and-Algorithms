
class Solution{
    public:
    bool isvalidbst(Node *root,int minval,int maxval){
        if(!root) return true;
        if(root->data>=maxval || root->data<=minval) return false;
        return isvalidbst(root->left,minval,root->data) && isvalidbst(root->right,root->data,maxval);
        
    }
    int count(Node * root){
        if(!root) return 0;
        int left=count(root->left);
        int right=count(root->right);
        return left+right+1;
    }
    void solve(Node * root,int &maxvalue){
        if(!root) return;
          if(isvalidbst(root,INT_MIN,INT_MAX)){
            maxvalue=max(maxvalue,count(root));
            return;
        }
     else{  solve(root->left,maxvalue);
       solve(root->right,maxvalue);
     }
        
       
    }
    int largestBst(Node *root)
    {int maxvalue=0;
    	 solve(root,maxvalue);
    	 return maxvalue;
    }
};
