class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree and return edges.
    pair<int, vector<pair<int, int>>> spanningTree(int V, vector<vector<int>> adj[]) {
        vector<bool> visited(V, false);
        vector<pair<int, int>> mstEdges; // Stores the edges of the MST
        int ans = 0;

        // Min-heap to store {weight, node, parent}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, 0, -1}); // {weight, node, parent}

        while (!q.empty()) {
            auto [edge, curr, parent] = q.top();
            q.pop();

            if (visited[curr]) continue;
            
            visited[curr] = true;
            ans += edge;
            
            // If it's not the starting node, add the edge to the MST
            if (parent != -1) {
                mstEdges.push_back({parent, curr});
            }
            
            for (auto nbor : adj[curr]) {
                if (!visited[nbor[0]]) {
                    q.push({nbor[1], nbor[0], curr});
                }
            }
        }
        
        return {ans, mstEdges};
    }
};
