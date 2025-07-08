class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node], parent);
    }

    void unionNodes(int u, int v, vector<int>& parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) {
            parent[pu] = pv;
        }
    }

    int maxRemove(vector<vector<int>>& stones, int n) {
        unordered_map<int, int> row;
        unordered_map<int, int> col;
        int maxcol = 0;
        int maxrow = 0;

        for (int i = 0; i < n; i++) {
            maxrow = max(maxrow, stones[i][0]);
            maxcol = max(maxcol, stones[i][1]);
        }

        int size = (maxrow + 1) * (maxcol + 1);
        vector<int> parent(size, -1);  

        unordered_set<int> usedNodes;

        for (int i = 0; i < n; i++) {
            int currNodeRow = stones[i][0];
            int currNodeCol = stones[i][1];
            int currNode = currNodeCol + currNodeRow * (maxcol + 1);

            if (parent[currNode] == -1) parent[currNode] = currNode;
            usedNodes.insert(currNode);

            if (row.find(currNodeRow) != row.end()) {
                unionNodes(currNode, row[currNodeRow], parent);
            }
            if (col.find(currNodeCol) != col.end()) {
                unionNodes(currNode, col[currNodeCol], parent);
            }

            row[currNodeRow] = currNode;
            col[currNodeCol] = currNode;
        }

        int count = 0;
        for (int node : usedNodes) {
            if (parent[node] == node) {
                count++;
            }
        }

        return n - count;
    }
};
