class Solution {
  public:
    int findParent(int node,vector<int>&parents){
      if(parents[node]==node)return node;
      return parents[node]=findParent(parents[node],parents);
  }
    int numProvinces(vector<vector<int>> adj, int V) {
       vector<int>parents(adj.size());
       for(int i=0;i<parents.size();i++){
           parents[i]=i;
       }
       for(int i=0;i<adj.size();i++){
           
           for(int j=0;j<adj.size();j++){
               if(adj[i][j]==1){
                   int par1=findParent(i,parents);
                   int par2=findParent(j,parents);
                   if(par1!=par2){
                       parents[par1]=par2;
                   }
               }
           }
       }
       int count=0;
        for(int i=0;i<parents.size();i++){
            if(parents[i]==i)count++;
        }
        return count;
    }
};
