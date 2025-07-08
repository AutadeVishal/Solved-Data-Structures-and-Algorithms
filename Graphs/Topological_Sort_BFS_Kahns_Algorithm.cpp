class Solution {
  public:
  void solve(queue<int>&q,vector<int>&ans,vector<int>&indirected,vector<vector<int>>&adj){
      int start;
      while(!q.empty()){
           start=q.front();
           q.pop();
           ans.push_back(start);
           for(int nbor:adj[start]){
               indirected[nbor]--;
               if(indirected[nbor]==0){
                   q.push(nbor);
               }
           }
             
      }
  }
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
       vector<int>indirected(adj.size(),0);
       for(auto i:adj){
           for(int j:i){
               indirected[j]++;
           }
       }
       
       queue<int>q;
       for(int i=0;i<indirected.size();i++){
           if(indirected[i]==0){
               q.push(i);
           }
       }
       vector<int>ans;
       solve(q,ans,indirected,adj);
       return ans;
    }
};
