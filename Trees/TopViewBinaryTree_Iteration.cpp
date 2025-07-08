class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int>v;
        if(!root) return v;
        // code here
        queue<pair<Node *,pair<int,int>>>q;
        map<int,pair<int,int>>m;
        q.push({root,{0,0}});
        while(!q.empty()){
            Node* curr=q.front().first;
            int position=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            if(m.find(position)==m.end() || m[position].first>level){
                m[position]={level,curr->data};
                
            }
            
            if(curr->left) {
                q.push({curr->left,{position-1,level+1}});
            }
            if(curr->right){
                q.push({curr->right,{position+1,level+1}});
            }
        }
        for(auto i:m){
                v.push_back(i.second.second);
            
        }
        return v;
    }
};
