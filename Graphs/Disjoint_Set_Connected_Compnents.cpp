
class Solution {
  public:
  void unionSet(int a,int b,vector<int>&parents,vector<int>&rank){
      int parA=findPar(a,parents);
      int parB=findPar(b,parents);
      if(rank[parA]>rank[parB]){
          parents[parB]=parA;
      }
      else{
          parents[parA]=parB;
      }
  }
  int findPar(int node,vector<int>&parents){
      if(parents[node]==node)return node;
      return parents[node]=findPar(parents[node],parents);
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        vector<int>parents(V);
        
        
        vector<int>rank(V,1);
    
        for(int i=0;i<V;i++){
            parents[i]=i;
        }
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            unionSet(u,v,parents,rank);
        }
        unordered_map<int,vector<int>>m;
        for(int i=0;i<V;i++){
           int parent= findPar(i,parents);
            m[parent].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};
