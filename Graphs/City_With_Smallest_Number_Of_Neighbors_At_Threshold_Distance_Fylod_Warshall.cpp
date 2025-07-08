class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto &i:edges){
            dist[i[0]][i[1]]=i[2];
            dist[i[1]][i[0]]=i[2];
            
        }
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via]==1e8 || dist[via][j]==1e8 ) continue;
                    if(dist[i][via]+dist[via][j]<dist[i][j]){
                        dist[i][j]=dist[i][via]+dist[via][j];
                    }
                }
            }
        }
        int mostNbors=1e8;
        int node=-1;
        for(int row=0;row<n;row++){
            int count=0;
            for(int col=0;col<n;col++){
               if(row != col && dist[row][col] <= distanceThreshold){
               count++;
               }

            }
            if(count<=mostNbors){
                node = row;
                mostNbors=count;
            }
        }
        return node;
    }
};
