class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e8);
        dist[k]=0;
          vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& i : times) {
            adj[i[0]].push_back({i[1], i[2]});
        }
      priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        q.push({0,k});
        while(!q.empty()){
            auto curr=q.top();
            q.pop();
            int node =curr[1];
            int cost=curr[0];
            if(cost>dist[node]) continue;
            for(auto &i:adj[node]){
                int nbor=i.first;
                int price=i.second;
                if(dist[nbor]>cost+price){
                    dist[nbor]=price+cost;
                    q.push({cost+price,nbor});
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
