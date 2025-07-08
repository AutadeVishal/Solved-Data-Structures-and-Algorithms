class Solution {
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            adj[u].push_back({v, weight});
        }

        vector<int> distances(V, INT_MAX);
        queue<int> q;
        distances[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (auto& nbor : adj[curr]) {
                int nextNode = nbor.first;
                int edgeWeight = nbor.second;
                if (distances[curr] + edgeWeight < distances[nextNode]) {
                    distances[nextNode] = distances[curr] + edgeWeight;
                    q.push(nextNode);
                }
            }
        }

       
        for (int i = 0; i < V; i++) {
            if (distances[i] == INT_MAX) {
                distances[i] = -1;
            }
        }

        return distances;
    }
};
