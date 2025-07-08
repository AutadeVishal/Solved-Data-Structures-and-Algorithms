class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[2], flight[1]});
            //{price,node}
        }

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q; 
        // {stops,cost,node}
        q.push({0, 0, src});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!q.empty()) {
            auto curr = q.top();
            q.pop();
            int node = curr[2];
            int cost = curr[1];
            int stops = curr[0];

            if (stops > K) break;
            
            for (auto it : adj[node]) {
                int next = it.second;
                int price = it.first;
                if (cost + price < minCost[next]) {
                    minCost[next] = cost + price;
                    q.push({stops + 1,cost+price,next });
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
