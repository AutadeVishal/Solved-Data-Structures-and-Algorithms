class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        // Code here
        int s=dist.size();
        for(int i=0;i<s;i++){
            dist[i][i]=0;
        }
        for(int via=0;via<s;via++){
            for(int i=0;i<s;i++){
                for(int j=0;j<s;j++){
                    if(dist[i][via]<1e8 && dist[via][j]<1e8){
                        long long sum = 1LL * dist[i][via] + dist[via][j];
                        if(sum < dist[i][j]) {
                            dist[i][j] = int(sum);
                        }
                    }
                }
            }
        }
        //for all nodes go from via all nodes and update with minimum dist 
        //if i via some node has better route update it 
        //at end all are updated to minimum dist 
        //if some dist[i][i]<0 means it has negative cycle as i->i can not be <0
        
        /*for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(dist[i][j]==1e8){
                    dist[i][j]=-1;
                }
            }
        }*/
    }
};
