class Solution {
public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
            //{node,price}
        }

        queue<vector<int>> q; 
        // {node, cost, stops}
        q.push({src, 0, 0});

        vector<int> minCost(n, INT_MAX);
        minCost[src] = 0;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int node = curr[0];
            int cost = curr[1];
            int stops = curr[2];

            if (stops > K) continue;
            
            for (auto it : adj[node]) {
                int next = it.first;
                int price = it.second;
                if (cost + price < minCost[next]) {
                    minCost[next] = cost + price;
                    q.push({next, cost + price, stops + 1});
                }
            }
        }

        return minCost[dst] == INT_MAX ? -1 : minCost[dst];
    }
};
