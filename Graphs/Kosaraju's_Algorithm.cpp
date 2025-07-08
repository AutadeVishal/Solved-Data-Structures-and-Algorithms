//Position this line where user code will be pasted.
class Solution {
  public:
  void putinstack(vector<vector<int>>&adj,stack<int>&st,vector<bool>&visited,int curr){
      visited[curr]=true;
      for(int nbor:adj[curr]){
          if(!visited[nbor]){
              putinstack(adj,st,visited,nbor);
          }
      }
      st.push(curr);
  }
  void dfs(int curr,vector<vector<int>>&trans,vector<bool>&visited){
      visited[curr]=true;
      for(int nbor:trans[curr]){
          if(!visited[nbor]){
              dfs(nbor,trans,visited);
          }
      }
  }
    int kosaraju(vector<vector<int>> &adj) {
        stack<int>st; 
         vector<bool>visited(adj.size(),false);
        for(int i=0;i<adj.size();i++){
            if(!visited[i]){
             putinstack(adj,st,visited,i);
            }
        }
       
       
        for(int i=0;i<visited.size();i++) visited[i]=false;
        //reverse the direction of arrows
        vector<vector<int>>transpose(adj.size());
        for(int i=0;i<adj.size();i++){
            for(int nbor:adj[i]){
                transpose[nbor].push_back(i);
            }
        }
        
        int scc=0;
       
        while(!st.empty()){
            int curr=st.top();
            st.pop();
            if(!visited[curr])  
            {
                scc++;
                dfs(curr,transpose,visited);
                
            }
           
        }
        return scc;
    }
};
