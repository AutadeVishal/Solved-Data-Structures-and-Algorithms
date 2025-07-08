class Solution {
  public:
//for single component
  void dfs(vector<vector<int>>&adj,vector<bool>&visited,int start,vector<int>&ans){
      ans.push_back(start);
      visited[start]=true;
      for(int i:adj[start]){
          if(!visited[i]){
              dfs(adj,visited,i,ans);
          }
      }
  }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
       vector<bool>visited(adj.size(),0);
       vector<int>ans;
      //for all Components
       for(int i=0;i<adj.size();i++){
           if(!visited[i]){
               
               dfs(adj,visited,i,ans);
           }
       }
       return ans;
    }
};
