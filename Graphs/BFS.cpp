class Solution {
  public:
    // Function to perform BFS from a given starting node
    void bfs(int start, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
    }

    // Function to return Breadth First Traversal of the given graph
    vector<int> bfsOfGraph(vector<vector<int>>& adj) {
        vector<int> result;
        vector<int> visited(adj.size(), 0);
        
        // Perform BFS from node 0 (assuming a connected graph)
        bfs(0, adj, visited, result);
        //else use For Loop for Non COnencted graph
        return result;
    }
};
