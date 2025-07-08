
// User function Template for C++

class Solution {
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (X >= N || Y >= M || X < 0 || Y < 0 || A[0][0] == 0 || A[X][Y] == 0) {
            return -1;
        }

        queue<vector<int>> pq;  
        //no priority queue used as bfs gives shortest distance only in unweigted movements
        vector<vector<int>> dist(N, vector<int>(M, 1e8));

        pq.push({0, 0, 0});
        dist[0][0] = 0;

        int nr[] = {1, 0, -1, 0};
        int nc[] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto curr = pq.front();
            pq.pop();

            int dt = curr[0];
            int row = curr[1];
            int col = curr[2];

            if (row == X && col == Y) return dt;

            for (int i = 0; i < 4; i++) {
                int newrow = row + nr[i];
                int newcol = col + nc[i];

                if (newrow >= 0 && newrow < N && newcol >= 0 && newcol < M && A[newrow][newcol] == 1) {
                    if (dt + 1 < dist[newrow][newcol]) {
                        dist[newrow][newcol] = dt + 1;
                        pq.push({dt + 1, newrow, newcol});
                    }
                }
            }
        }

        return -1;
    }
};
