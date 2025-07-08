class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>v;
        if(!root) return v;
        queue<pair<Node *,int >>q;
        map<int,int>m;
        q.push({root,0});
        while(!q.empty()){
            Node * curr=q.front().first;
            int position=q.front().second;
            m[position]=curr->data;
            if(curr->left)q.push({curr->left,position-1});
            if(curr->right)q.push({curr->right,position+1});
            q.pop();
        }
        for( auto i:m){
            v.insert(v.end(),i.second);
        }
        return v;
    }
};
