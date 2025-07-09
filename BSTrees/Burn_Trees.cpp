/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  unordered_map<Node * ,Node *>parentOf;
  void findParent(Node * &root,Node * &start,int target){
      if(!root) return;
      if(root->data==target) start=root;
      if(root->left) {
          parentOf[root->left]=root;
          findParent(root->left,start,target);
      }
      if(root->right){
          parentOf[root->right]=root;
          findParent(root->right,start,target);
      }
  }
  
    int minTime(Node* root, int target) {
        // code here
        if(!root) return 0;
         Node * start;
        findParent(root,start,target);
        unordered_map<Node *,bool>visited;
        queue<Node *>q;
       
        q.push(start);
        int time=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                Node * curr=q.front();
                q.pop();
                visited[curr]=true;
                if(curr!=root && !visited.count(parentOf[curr])) {
                    q.push(parentOf[curr]);
                }
                if(curr->left && !visited.count(curr->left)){
                    q.push(curr->left);
                }
                if(curr->right && !visited.count(curr->right)){
                    q.push(curr->right);
                }
            }
            time++;
            
        }
        return time-1;
    }
};
