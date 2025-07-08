class Solution {
  public:
  void solve(vector<vector<int>>& adj,int src,vector<bool>&visited,int &count,vector<int>&ans){
      queue<int>q;
      q.push(src);
    visited[src]=true;
      while(!q.empty()){
         int qsize=q.size();
          for(int i=0;i<qsize;i++){
               int curr=q.front();
          
          q.pop();
          ans[curr]=min(count,ans[curr]);
          
             for(int neighbor:adj[curr]){
                 if(!visited[neighbor]){
                     visited[neighbor]=true;
                     q.push(neighbor);
                 }
             }
          }
        count++;
      }
  }
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int count=0;
        vector<bool>visited(adj.size(),false);
        vector<int>ans(adj.size(),INT_MAX);
        solve(adj,src,visited,count,ans);
        for(int i=0;i<ans.size();i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
};
