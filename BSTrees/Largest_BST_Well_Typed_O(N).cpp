
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    struct info{
        int size;
        int min;
        int max;
        bool isbst;
    };
    info solve(Node * root){
     if(!root){
         return {0,INT_MAX,INT_MIN,true};
     }
   
 info left=solve(root->left);
  info right=solve(root->right);
   
    info curr;
    if(left.isbst && right.isbst){
       
        curr.max=max(root->data,right.max);
        curr.min=min(root->data,left.min);
        if(root->data>left.max && root->data<right.min){
            curr.isbst=true;
             curr.size=left.size+right.size+1;
        }
        else{
            curr.isbst=false;
            curr.size=max(left.size,right.size);
        }
    }
    else{
        curr.size=max(left.size,right.size);
        curr.max=max(root->data,right.max);
        curr.min=min(root->data,left.min);
        curr.isbst=false;
    }
    return curr;
   
     
    }
    int largestBst(Node *root)
    {
        if(!root) return 0;
    return solve(root).size;
    }
};
