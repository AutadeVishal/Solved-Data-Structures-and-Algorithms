class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
       Node * curr=root;
       while(curr){
           if(curr->key>key){
              if(!suc || curr->key<suc->key){
                  suc=curr;
              }
               curr=curr->left;
           } 
           else if(curr->key<key){
                if(!pre || curr->key>pre->key){
                   pre=curr;
               }
               curr=curr->right;
           }
          else{
              Node * right=curr->right;
              curr=curr->left;
              while(right){
                  if(right->key>key){
                       if(!suc || right->key<suc->key){
                  suc=right;
                                             }
                     right=right->left;
                  }
              }
          }
       }
    }
};
