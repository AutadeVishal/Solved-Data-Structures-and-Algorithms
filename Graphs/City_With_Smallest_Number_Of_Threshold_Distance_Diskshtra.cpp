class Solution {
  public:

void dikstra(int n,vector<int> &dists, vector<vector<pair<int,int>>> &adj, int node)
  {   priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

      pq.push({0,node});
      dists[node]=0;
      while(!pq.empty()){
          auto curr=pq.top();
          pq.pop();
          int currNode=curr.second;
          int cost=curr.first;
          for(auto nbor:adj[currNode]){
              int nborNode=nbor.second;
              int edgeCost=nbor.first;
            if(dists[currNode]<cost) continue;
              if(edgeCost+cost<dists[nborNode]){
                  dists[nborNode]=edgeCost+cost;
                  pq.push({dists[nborNode],nborNode});
              }
          }
      }
  }
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    
       vector<vector<pair<int,int>>>adj(n);
       for(auto &i:edges){
           int u=i[0];
           int v=i[1];
           int wt=i[2];
           adj[u].push_back({wt,v});
           adj[v].push_back({wt,u});
       }
       int minimumNbors=1e8;
       int node=-1;
       for(int i=0;i<n;i++){
           vector<int>dists(n,1e8);
           dikstra(n,dists,adj,i);
           int count=0;
           for(int j=0;j<n;j++){
               if(dists[j]<=distanceThreshold){
                   count++;
               }
           }
           if(count<=minimumNbors){
               minimumNbors=count;
               node=i;
           }
       }
       return node;
    }
};
