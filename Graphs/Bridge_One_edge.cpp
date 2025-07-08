class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
void dfs(int node,int parent,vector<bool>&visited,vector<int> adj[]){
        
        visited[node]=true;
        for(auto nbor:adj[node]){
            if(nbor!=parent && !visited[nbor]){
               dfs(nbor,node,visited,adj);
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool>visited(V,false);
       dfs(c,d,visited,adj);
        if(visited[c]==1 && visited[d]==1) return false;
        return true;
    }
};
