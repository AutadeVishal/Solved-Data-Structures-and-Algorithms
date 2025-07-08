class Solution {
  public:
  void solve(int node,vector<bool>&visited,stack<int>&st,vector<vector<int>>&adjlist){
      visited[node]=true;
      for(auto &nbor:adjlist[node]){
          if(!visited[nbor]){
              solve(nbor,visited,st,adjlist);
          }
      }
      st.push(node);
  }
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<bool>visited(n,false);
        stack<int>st;
        vector<vector<int>>adjlist(n);
        for(auto &i:prerequisites){
            int toNode=i[0];
            int fromNode=i[1];
            adjlist[fromNode].push_back(toNode);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                solve(i,visited,st,adjlist);
            }
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
