class Solution {
  public:
  int findParent(int node,vector<int>&parents){
      if(parents[node]==node)return node;
      return parents[node]=findParent(parents[node],parents);
  }
  void unionBySize(int node1,int node2,vector<int>&parents,vector<int>&size){
      int par1=findParent(node1,parents);
      int par2=findParent(node2,parents);
      if(par1!=par2){
          if(size[par1]>=size[par2]){
              parents[par2]=par1;
              size[par1]+=size[par2];
          }
          else{
              parents[par1]=par2;
              size[par2]+=size[par1];
          }
      }
  }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>parents(n*n);
        for(int i=0;i<n*n;i++){
            parents[i]=i;
        }
         
         //creating islands
         //union them based on size 
         int nr[]={1,0,-1,0};
         int nc[]={0,1,0,-1};
         vector<int>size(n*n,1);
         for(int row=0;row<n;row++){
             for(int col=0;col<n;col++){
                 if(grid[row][col]==0) continue;
                 int currNode=row*n+col;
                 for(int i=0;i<4;i++){
                     int newrow=row+nr[i];
                     int newcol=col+nc[i];
                     if(newrow>=0 && newrow<n && newcol>=0 && newcol<n){
                  
                        if(grid[newrow][newcol] == 1){
                        int newNode = newrow * n + newcol;
                    unionBySize(currNode, newNode, parents, size);
}

                     }
                    
                 }
             }
         }
       
         
         //check for each 0 position to convert it into 1 
         int LargestIsland=0;
         int numberOfOnes=0;
         for(int row=0;row<n;row++){
             for(int col=0;col<n;col++){
                 if(grid[row][col]==1) 
                 {
                     numberOfOnes++;
                     continue;
                 }
                 unordered_set<int>canBeConnectedIslands;
                 for(int i=0;i<4;i++){
                     int newrow=nr[i]+row;
                     int newcol=nc[i]+col;
                     if(newrow>=0 && newcol>=0 && newrow<n && newcol<n){
                         if(grid[newrow][newcol]==1){
                             canBeConnectedIslands.insert(findParent(newrow*n+newcol,parents));
                         }
                     }
                 }
                 //we got all islands possible to be connected
                 // to this position if converted form 0 to 1
                 int currIslandSize=1;//becouse this curr 0 is converted to 1 
                 //so +1 size already taken
                 for(auto &i:canBeConnectedIslands){
                     currIslandSize+=size[i];
                 }
                 LargestIsland=max(LargestIsland,currIslandSize);
             }
         }
         if(numberOfOnes==n*n) return numberOfOnes;
         return LargestIsland;
         
    }
};
