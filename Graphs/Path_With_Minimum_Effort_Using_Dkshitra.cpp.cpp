class Solution {
public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        // {effort, row, col}
        vector<vector<int>> visited(rows, vector<int>(columns, false));
        vector<int> nr = {1, 0, -1, 0};
        vector<int> nc = {0, 1, 0, -1};
        int maxEffort = 0;

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int effort = curr[0], row = curr[1], col = curr[2];

            if (row == rows - 1 && col == columns - 1) return effort; 
            //bhetla bhetla re bho
            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (int i = 0; i < 4; ++i) {
                int newRow = row + nr[i];
                int newCol = col + nc[i];

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && !visited[newRow][newCol]) {
                    int newEffort = max(effort, abs(heights[newRow][newCol] - heights[row][col]));
                    pq.push({newEffort, newRow, newCol});
                }
            }
        }

        return -1;
    }
};
