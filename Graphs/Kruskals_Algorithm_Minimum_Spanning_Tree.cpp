
class Solution {
  public:
    int findparent(int u, vector<int>& parent) {
        if (parent[u] != u) {
            parent[u] = findparent(parent[u], parent);
        }
        return parent[u];
    }

    int spanningTree(int V, vector<vector<int>> adj[]) {
        int ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> edges;

        for (int i = 0; i < V; i++) {
            for (auto j : adj[i]) {
                edges.push({j[1], i, j[0]}); 
              //weight,currnode,childnode
            }
        }

        vector<int> parent(V);
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        while (!edges.empty()) {
            auto edge = edges.top();
            edges.pop();
            int weight = edge[0], u = edge[1], v = edge[2];
            int parentU = findparent(u, parent);
            int parentV = findparent(v, parent);

            if (parentU != parentV) { 
                ans += weight;
                parent[parentU] = parentV; 
            }
        }
        return ans;
    }
};
