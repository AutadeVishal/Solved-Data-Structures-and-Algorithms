class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e8);
        dist[k]=0;
        for(int j=0;j<n-1;j++){
             for(auto &i:times){
                int u=i[0];
                int v=i[1];
                int w=i[2];
                if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
        int maxtime=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e8) return -1;
            else if(dist[i]>maxtime) maxtime=dist[i];
        }
        return maxtime;
    }
};
