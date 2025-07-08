
class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        queue<pair<int,int>>q;
        for(int row=0;row<rows;row++){
                if(grid[row][0]==1 ){
                     q.push({row,0});
                visited[row][0]=true;
                }
                if(grid[row][cols-1]==1){
                    q.push({row,cols-1});
                    visited[row][cols-1]=true;
                }
        }
         for(int col=0;col<cols;col++){
                if(grid[0][col]==1 ){
                     q.push({0,col});
                visited[0][col]=true;
                }
                if(grid[rows-1][col]==1){
                    q.push({rows-1,col});
                    visited[rows-1][col]=true;
                }
        }
        int nr[]={1,0,-1,0};
        int nc[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newrow=row+nr[i];
                int newcol=col+nc[i];
if(newrow>=0 && newcol>=0 && newrow<rows && newcol<cols && grid[newrow][newcol]==1 && visited[newrow][newcol]==false){
                    visited[newrow][newcol]=true;
                    q.push({newrow,newcol});
                }
            }
        }
             int count=0;
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(grid[row][col]==1 && visited[row][col]==false){
                    count++;
                }
            }
        }
        return count;
    
      }  };
