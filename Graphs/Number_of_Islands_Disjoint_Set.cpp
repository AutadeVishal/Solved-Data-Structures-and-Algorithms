class Solution {
  public:
    int findParent(int node, vector<int>& parents) {
        if (parents[node] != node) {
            parents[node] = findParent(parents[node], parents);
        }
        return parents[node];
    }

    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int size = operators.size();
        vector<int> parents(size);
        for (int i = 0; i < size; i++) {
            parents[i] = i;
        }

      //  unordered_map<int, unordered_map<int, int>> toindex; 
        vector<vector<int>> visited(n, vector<int>(m, -1));
        vector<int> ans;

        int count = 0;
        int nr[] = {1, 0, -1, 0};
        int nc[] = {0, 1, 0, -1};

        for (int i = 0; i < size; i++) {
            int row = operators[i][0];
            int col = operators[i][1];
            if (visited[row][col]!=-1) {
                ans.push_back(count);
                continue;
            }

            visited[row][col] = i;//put index of curr node
          //  toindex[row][col] = i;
            count++; 

            for (int j = 0; j < 4; j++) {
                int newrow = row + nr[j];
                int newcol = col + nc[j];

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m) {
                    if (visited[newrow][newcol] != -1) {
                        int par1 = findParent(i, parents);
                        int par2 = findParent(visited[newrow][newcol], parents);

                        if (par1 != par2) {
                            parents[par1] = par2;
                            count--; 
                        }
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};

