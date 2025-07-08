class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<bool>visited(V,false);
        int ans=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0,0});//distance,node
        
        while(!q.empty()){
            auto it=q.top();
            int curr=it.second;
           
            int edge=it.first;
            q.pop();
             if(visited[curr]) continue; 
            ans+=edge;
            visited[curr]=true;
            
            for(auto nbor:adj[curr]){
                if(!visited[nbor[0]]){
                    q.push({nbor[1],nbor[0]});
                }
            }
            
        }
        return ans;
    }
};
