
// User function Template for C++

class Solution {
  public:
  void bfs(queue<pair<int,int>>&q,vector<vector<char>>&ans,vector<vector<bool>>&visited){
     int nc[]={1,0,-1,0};
     int nr[]={0,1,0,-1};
      while(!q.empty()){
          int row=q.front().first;
          int col=q.front().second;
          q.pop();
          visited[row][col]=true;
          for(int i=0;i<4;i++){
              int newrow=row+nr[i];
              int newcol=col+nc[i];
              if(newrow>=0 && newcol>=0 && newrow<ans.size() && newcol<ans[0].size() && ans[newrow][newcol]=='O' && !visited[newrow][newcol]){
                  visited[newrow][newcol]=true;
                  q.push({newrow,newcol});
              }
          }
      }
  }
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<char>>ans=mat;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
           for(int i = 0; i < rows; i++){
          if(ans[i][0] == 'O') q.push({i, 0});
          if(ans[i][cols-1] == 'O') q.push({i, cols-1});
      }
      for(int i = 0; i < cols; i++){
          if(ans[0][i] == 'O') q.push({0, i});
          if(ans[rows-1][i] == 'O') q.push({rows-1, i});
      }

       bfs(q,ans,visited);
        for(int row=0;row<rows;row++){
            for(int col=0;col<cols;col++){
                if(ans[row][col]=='O' && !visited[row][col]){
                    ans[row][col]='X';
                }
            }
        }
        return ans;
    }
};
