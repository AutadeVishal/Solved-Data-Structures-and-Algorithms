class Solution {
  public:
  void solve(vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st,int start){
      visited[start]=true;
      for(int i:adj[start]){
          if(!visited[i]){
              solve(adj,visited,st,i);
          }
      }
      st.push(start);
      return;
  }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        vector<bool>visited(adj.size(),false);
        stack<int>st;
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                solve(adj,visited,st,i);
            }
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
