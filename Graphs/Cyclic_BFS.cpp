class Solution {
  public:
  bool iscyclic(vector<vector<int>>&adj,vector<bool>&visited,vector<int>&parent,int start){
      queue<int>q;
      q.push(start);
      visited[start]=true;
      while(!q.empty()){
          start=q.front();
          q.pop();
          for(int i:adj[start]){
              if(!visited[i]   ){
                  visited[i]=true;
                  parent[i]=start;
                  q.push(i);
              }
              else if(parent[start]!=i) return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        vector<bool>visited(adj.size(),false);
        vector<int>parent(adj.size(),-1);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
                bool cyclefound=iscyclic(adj,visited,parent,i);
                if(cyclefound) return true;
            }
        }
        return false;
    }
};
