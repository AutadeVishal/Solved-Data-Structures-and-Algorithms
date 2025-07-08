class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>>adjlist(V);
        vector<int>indirected(V,0);
        for(int i=0;i<V;i++){
            for(auto &nbor:adj[i]){
                adjlist[nbor].push_back(i);
                indirected[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indirected[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto &nbor:adjlist[node]){
                indirected[nbor]--;
                if(indirected[nbor]==0){
                    q.push(nbor);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
