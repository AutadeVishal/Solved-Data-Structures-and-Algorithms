class Solution {
public:
void dfs(int curr,int parent,vector<vector<int>>&adj,vector<int>&time,vector<int>&mini,vector<bool>&visited,vector<vector<int>>&ans,int &timer){
    visited[curr]=true;
  time[curr]=mini[curr]=timer++;
    for(int nbor:adj[curr]){
        if(nbor!=parent){
            if(visited[nbor]){
               mini[curr] = min(mini[curr], mini[nbor]);
            }
            else{
                  dfs(nbor, curr, adj, time, mini, visited, ans, timer);
                mini[curr] = min(mini[curr], mini[nbor]); 
                if (mini[nbor] > time[curr]) {
                    ans.push_back({curr, nbor});
                }
            }
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>time(n,INT_MAX);
        vector<int>mini(n,INT_MAX);
        vector<vector<int>>ans;
        vector<bool>visited(adj.size(),false);
        int timer=0;
        dfs(0,-1,adj,time,mini,visited,ans,timer);
    return ans;
        
    }
};
