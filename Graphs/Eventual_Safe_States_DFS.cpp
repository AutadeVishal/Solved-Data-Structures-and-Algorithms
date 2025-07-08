class Solution {
  public:
  void dfs(int node,vector<int> adj[],vector<bool>&visited,vector<bool>&currVisited,unordered_set<int>&st){
      visited[node]=true;
      currVisited[node]=true;
      for(auto &nbor:adj[node]){
          if(!visited[nbor]){
              dfs(nbor,adj,visited,currVisited,st);
          }
          if(currVisited[nbor]){
              st.insert(nbor);
          }
          if(st.find(nbor)!=st.end()){
              st.insert(node);
          }
      }
      currVisited[node]=false;
      
  }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>currVisited(V,false);
        vector<int>ans;
        unordered_set<int>st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,currVisited,st);
            }
        }
        for(int i=0;i<V;i++){
            if(st.find(i)==st.end())ans.push_back(i);
        }
        return ans;
    }
};
