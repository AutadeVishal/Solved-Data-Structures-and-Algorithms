/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    Node * curr=root;
    int ans=-1;
    while(curr!=nullptr){
        if(curr->data>=input){
            ans=curr->data;
            curr=curr->left;
        }
        else{
           curr= curr->right;
        }
    }
    return ans;
}
