class Solution {
  public:
  void bfs(queue<vector<int>>& q, vector<vector<int>>& grid, vector<vector<int>>& ans)
{
      
      
      
      
      while(!q.empty()){
          
          int currrow=q.front()[0];
          int currcol=q.front()[1];
          int nr[]={1,0,-1,0};
          int nc[]={0,1,0,-1};
          q.pop();
              for(int i=0;i<4;i++){
                  int newrow=currrow+nr[i];
                  int newcol=currcol+nc[i];
                  if(newrow<grid.size() && newcol<grid[0].size() && newcol>=0 && newrow>=0 && grid[newrow][newcol]==0 && ans[newrow][newcol]>ans[currrow][currcol] +1 ){
                      ans[newrow][newcol]=ans[currrow][currcol]+1;
                      q.push({newrow,newcol});
                  }
              }
          
      }
  }
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        queue<vector<int>>q;
        vector<vector<int>>ans(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]==1){
                   q.push({row,col});
                   ans[row][col]=0;
                }
            }
        }
        bfs(q,grid,ans);
        return ans;
    }
};
