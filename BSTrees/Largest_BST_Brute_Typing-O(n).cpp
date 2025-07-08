class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> solve(Node * root){
        if(!root) return {0,INT_MIN,INT_MAX,1};//size,maxvalue of right,minvalue of left side
        //,boolean
    
    vector<int> left=solve(root->left);
    vector<int> right=solve(root->right);
    if(left[3]==1 && right[3]==1){
        
        if(root->left && root->right ) {
        if( root->data>left[1] && root->data<right[2]){
            return {1+left[0]+right[0],right[1],left[2],1};
        }
        else{
            return {max(left[0],right[0]),right[1],left[2],0};
        }
        }
        if(root->left){
            if(root->data>left[1]){
                return {1+left[0],root->data,left[2],1};
            }
            else {
                return {left[0],root->data,left[2],0};
            }
        }
        if(root->right){
            if(root->data<right[2]){
                return {1+right[0],right[1],root->data,1};
            }
            else {
                return {right[0],right[1],root->data,0};
            }
        }
        else return {1,root->data,root->data,1};
        
    }
    else{
       if(root->right && root->left){
           return {max(left[0],right[0]),right[1],left[2],0};
       }
       if(root->right){
           return {right[0],right[1],root->data,0};
       }
       else{
           return {left[0],root->data,left[2],0};
       }
       
    }
}
    int largestBst(Node *root)
    {
    return solve(root)[0];
    }
};
