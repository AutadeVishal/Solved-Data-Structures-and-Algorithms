class Solution {
  public:
void dfs(int node, int parent, vector<bool>&visited, vector<int>adj[], vector<int>&ans, vector<int>&time, vector<int>&mini, int &timer) {
    visited[node] = true;
    time[node] = mini[node] = timer++;
    int childs = 0;
    int isputted=false;
    for (int nbor : adj[node]) {
        if (nbor == parent) continue; 
        if (!visited[nbor]) { 
            childs++;
            dfs(nbor, node, visited, adj, ans, time, mini, timer);
            mini[node] = min(mini[node], mini[nbor]);

            
            if (mini[nbor] >= time[node] && parent != -1) {
            if(!isputted) 
               {
                   ans.push_back(node);
                   isputted=true;
               }
            }
        } else { 
            mini[node] = min(mini[node], time[nbor]);
            /*Very Important Step here min of time[nbor] and mini[node] is taken
            why so 
            Imagine for currnode its updated mini is less than its time
           due to some branch going to its previous parents.
            now suppose next branch goes to itself(currnode) in circle then that child will mark mini of himself
            as mini of the parent(currnode,it could be grandparent(circular)),now when you check backedge it will see that the child
            is having better route than me even if he didn't have so and condition will fail here
            
            */
        }
    }
    if (parent == -1 && childs > 1) {
        ans.push_back(node);
    }
}
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool>visited(V,false);
        vector<int>time(V,-1);
        vector<int>mini(V,-1);
        int timer=0;
        vector<int>ans;
        dfs(0,-1,visited,adj,ans,time,mini,timer);
        sort(ans.begin(), ans.end());
return  ans.empty() ? vector<int>{-1} : ans;
    }
};
