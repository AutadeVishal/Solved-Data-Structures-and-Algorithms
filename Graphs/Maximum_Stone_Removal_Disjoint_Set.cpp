class Solution {
  public:
  int findParent(int node,vector<int>&parents){
      if(parents[node]==node) return node;
      return parents[node]=findParent(parents[node],parents);
  }
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        int maxrow=0;
        int maxcol=0;
        for(auto &i:stones){
            if(maxrow<i[0]) maxrow=i[0];
            if(maxcol<i[1])maxcol=i[1];
            
        }
        vector<int>parents(maxrow+maxcol+2);
        for(int i=0;i<maxrow+maxcol+2;i++){
            parents[i]=i;
        }
        unordered_map<int,int>used;
        for(auto &i:stones){
            int up=findParent(i[0],parents);
            int uv=findParent(i[1]+maxrow+1,parents);
            parents[up]=uv;      
            used[i[0]]=1;
            used[i[1]+maxrow+1]=1;
            }
            int components=0;
        for(int i=0;i<parents.size();i++){
            if(used.find(i)!=used.end() && parents[i]==i){
                components++;
            }
        }
        return stones.size()-components;
    }
};
