bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<int> inDegree(V, 0);

   
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    //if(count) <v that means some nodes were already visited so at last count didn't got updated that means its the cycle 
//by the way count==v is not cycle and count==v-1 is cycle try it
    return count != V;
}
