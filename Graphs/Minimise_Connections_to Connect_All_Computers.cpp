class Solution {
  public:
  int findParent(int node,vector<int>&parent){
      if(parent[node]==node){
          return node;
      }
      return parent[node]=findParent(parent[node],parent);
  }
  void unionByRank(int pu,int pv,vector<int>&rank,vector<int>&parent){
      if(rank[pu]<rank[pv]){
          parent[pu]=parent[pv];
      }
      else if(rank[pu]>rank[pv]){
          parent[pv]=parent[pu];
      }
      else{
          parent[pv]=parent[pu];
          rank[pu]++;
      }
  }
    int minimumConnections(int n, vector<vector<int>> &connections) {
        // code here
        vector<int>rank(n,0);
        vector<int>parent(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        //so question is you have limited wires so remove unnessesary connections to add new connections
        int extraConnections=0;
        vector<vector<int>>copy=connections;
        for(int i=0;i<connections.size();i++){
            int pu=findParent(connections[i][0],parent);
            int pv=findParent(connections[i][1],parent);
            if(pu==pv){
                extraConnections++;
            }
            else{
                unionByRank(pu,pv,rank,parent);
            }
        }
       int requiredWires=-1;
       // ultimate parent will get added to the requiredWires so initially keep it -1 to find actually required connections
       for(int i=0;i<n;i++){
           if(parent[i]==i){
               requiredWires++;
           }
       }
      if(extraConnections>=requiredWires) return requiredWires;
      else return -1;
    }
};
