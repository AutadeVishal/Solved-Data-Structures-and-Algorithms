class Solution {
  public:
    int sumOfLongRootToLeafPath(Node *root) {
        if(!root) return 0;
       queue<pair<Node * ,pair<int,int>>>q;
       int maxlength=0;
       int maxsum=0;
       q.push({root,{0,root->data}});
       while(!q.empty()){
         Node * curr=q.front().first;
         int length=q.front().second.first;
         int sum=q.front().second.second;
         q.pop();
         if(!curr->left && !curr->right){
             if(length>maxlength){
                 maxsum=sum;
                 maxlength=length;
             }
             if(length==maxlength){
                 if(sum>maxsum){
                     maxsum=sum;
                 }
             }
         }
         if(curr->left){
             q.push({curr->left,{length+1,sum+curr->left->data}});
         }
         if(curr->right){
             q.push({curr->right,{length+1,sum+curr->right->data}});
         }
         
       }
       return maxsum;
    }
};
