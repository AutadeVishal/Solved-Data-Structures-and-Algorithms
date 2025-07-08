class Solution
{
    public:


    vector<int> verticalOrder(Node* root) {
        vector<int> v;
        if (!root) return v;
        map<int, map<int,vector<int>>> m;
        queue<pair<Node*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
           auto curr=q.front();
           q.pop();
             Node * frontNode=curr.first;
             int position = curr.second.first;
int level = curr.second.second;

             m[position][level].push_back(frontNode->data);
              if (frontNode->left) {
                q.push({frontNode->left, {position - 1, level + 1}});
            }
             if (frontNode->right) {
                q.push({frontNode->right, {position + 1, level + 1}});
            }
             
        }
        
        
        for(auto& position:m){
            for(auto& level:position.second){
                v.insert(v.end(),level.second.begin(),level.second.end());
            }
        }


        return v;
    }
};
