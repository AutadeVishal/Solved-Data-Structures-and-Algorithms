void solve(vector,vector<int>>&adj,vector<int>&parent,vector<bool>&visited,vector<int>&ans,int &src,int &dest){
queue<int>q;
q.push(src);
while(!q.empty()){
    int curr=q.front();
    q.pop();
    if(curr==dest){
        int i=curr;
        while(i!=-1){
            ans.push_back(i);
            i=parent[i];
        }
        ans.push_back(src);
       reverse(ans.begin(),ans.end());
        return;
    }
    visited[curr]=true;
    for(int nbor:adj[curr]){
        if(!visited[nbor]){
            parent[nbor]=curr;
            visited[nbor]=true;
            q.push(nbor);
        }
    }
}
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	vector<vector<int>>adj;
    for(int i=0;i<m;i++){
        adj[edges.first].push_back(edges.second);
        adj[edges.second].push_back(edges.first);
    }
    vector<int>ans;
    vector<int>parent(n,-1);
    vector<bool>visited(n,false);
    solve(adj,parent,visited,ans,s,t);
	return ans;
	
}
