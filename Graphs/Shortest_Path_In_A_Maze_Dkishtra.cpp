class Solution {
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0 || A[X][Y] == 0) return -1;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
       
        pq.push({0, 0, 0});

        vector<vector<bool>> visited(N, vector<bool>(M, false));

        vector<int> dRow = {1, -1, 0, 0};
        vector<int> dCol = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int dist = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (row == X && col == Y) {
                return dist;
            }

            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (int i = 0; i < 4; ++i) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];

                if (newRow >= 0 && newRow < N && newCol >= 0 && newCol < M &&
                    !visited[newRow][newCol] && A[newRow][newCol] == 1) {
                    pq.push({dist + 1, newRow, newCol});
                }
            }
        }

        return -1;
    }
};
