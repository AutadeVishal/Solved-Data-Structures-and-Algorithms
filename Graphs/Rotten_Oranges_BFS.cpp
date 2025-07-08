
class Solution {
  public:
  void updatedistances(int row,int col,vector<vector<int>>&mat,vector<vector<int>>&dists){
      int nr[]={1,0,-1,0};
      int nc[]={0,1,0,-1};
      queue<vector<int>>q;
      q.push({row,col,0});
      while(!q.empty()){
          int currow=q.front()[0];
          int currcol=q.front()[1];
          int dist=q.front()[2];
          q.pop();
          if(dists[currow][currcol]>dist){
              dists[currow][currcol]=dist;
              for(int i=0;i<4;i++){
                  int newrow=currow+nr[i];
                  int newcol=currcol+nc[i];
                  if(newrow<mat.size() && newrow>=0 && newcol<mat[0].size() && newcol>=0){
                      if(dists[newrow][newcol]>dist+1 && mat[newrow][newcol]==1){
                          q.push({newrow,newcol,dist+1});
                      }
                  }
              }
          }
      }
  }
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        vector<vector<int>>dists(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        for(int row=0;row<mat.size();row++){
            for(int col=0;col<mat[0].size();col++){
                if(mat[row][col]==2){
                    updatedistances(row,col,mat,dists);
                }
            }
        }
        int m=0;
        for(int row=0;row<mat.size();row++){
            for(int col=0;col<mat[0].size();col++){
                if(mat[row][col]==1 && dists[row][col]==INT_MAX){
                    return -1;
                }
                 if (mat[row][col] != 0) {
                    m = max(dists[row][col], m);
                }
            }
        }

        return m;
    }
};





// Now Here Doing BFS Simultaneusly 

class Solution {
  public:
  void updatedistances(vector<vector<int>>&mat,vector<vector<int>>&dists,queue<vector<int>>&q){
      int nr[]={1,0,-1,0};
      int nc[]={0,1,0,-1};
      while(!q.empty()){
          int currow=q.front()[0];
          int currcol=q.front()[1];
          int dist=q.front()[2];
          q.pop();
          if(dists[currow][currcol]>dist){
              dists[currow][currcol]=dist;
              for(int i=0;i<4;i++){
                  int newrow=currow+nr[i];
                  int newcol=currcol+nc[i];
                  if(newrow<mat.size() && newrow>=0 && newcol<mat[0].size() && newcol>=0){
                      if(dists[newrow][newcol]>dist+1 && mat[newrow][newcol]==1){
                          q.push({newrow,newcol,dist+1});//ONLY INSERT ALL STARTING NODES INITIALLY AND THEN DO BFS AT END
                      }
                  }
              }
          }
      }
  }
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        queue<vector<int>>q;
        vector<vector<int>>dists(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        for(int row=0;row<mat.size();row++){
            for(int col=0;col<mat[0].size();col++){
                if(mat[row][col]==2){
                    q.push({row,col,0});
                }
            }
        }
        updatedistances(mat,dists,q);
        int m=0;
        for(int row=0;row<mat.size();row++){
            for(int col=0;col<mat[0].size();col++){
                if(mat[row][col]==1 && dists[row][col]==INT_MAX){
                    return -1;//NOT REACHED NODE
                }
                 if (mat[row][col] ==1) {
                    m = max(dists[row][col], m);
                }
            }
        }

        return m;
    }
};
