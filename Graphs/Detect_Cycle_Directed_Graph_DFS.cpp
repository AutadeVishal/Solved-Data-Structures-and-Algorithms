
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>&currvisited,vector<bool>&visited) {
        visited[node] = true;
        currvisited[node]=true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, currvisited,visited)) 
                    return true;
               
            } 
            else if(currvisited[neighbor]) return true;
        }
    currvisited[node]=false;
        return false;
    }

    bool isCyclic(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> currvisited(n, false);
        vector<bool>visited(n,false);
        for (int i = 0; i < n; i++) {
           if(!visited[i])
                {
                    if (dfs(i, adj, currvisited,visited)) 
                    return true;
                }
        }
        return false;
    }
};
