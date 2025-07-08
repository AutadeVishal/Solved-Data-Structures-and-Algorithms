// User function Template for C++
class Solution {
  public:
  //My Made Function for TOPO Sort
  void topo(unordered_map<int,unordered_map<int,int>>&adj,stack<int>&st,vector<bool>&visited,int start){
      visited[start]=true;
      for(auto nbor:adj[start]){
          if(!visited[nbor.first]){
              topo(adj,st,visited,nbor.first);
          }
      }
      st.push(start);
  }
  
  //Orignal Function
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    unordered_map<int, unordered_map<int, int>> adj;

for (int i = 0; i < edges.size(); i++) {
    int u = edges[i][0];
    int v = edges[i][1];
    int weight = edges[i][2];

    adj[u][v] = weight;
}
    vector<bool>visited(V,false);
    vector<int>distances(V,INT_MAX);
    stack<int>st;
    
    //Update Stack
    topo(adj,st,visited,0);
    
    //Keep SRC as 0
    distances[0]=0;
    
  
    
    //Update Distances based on Stack
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        if(distances[curr]!=INT_MAX){
            for(auto nbor:adj[curr]){
               distances[nbor.first]=min(adj[curr][nbor.first]+distances[curr],distances[nbor.first]);
            }
        }
    }
   // make unreachable ones -1
    for(int i=0;i<distances.size();i++){
        if(distances[i]==INT_MAX){
            distances[i]=-1;
        }
    }
    return distances;
    }
};
