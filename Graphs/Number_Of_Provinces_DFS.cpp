class Solution {
  public:
  void dfs(int node,vector<bool>&visited,vector<vector<int>>&adj,int V){
      visited[node]=true;
      for(int i=0;i<V;i++){
          if(adj[node][i]==1 && !visited[i]){
              dfs(i,visited,adj,V);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        int count=0;
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
           if(!visited[i]){
               count++;
               dfs(i,visited,adj,V);
           }
        }
        return count;
    }
};
