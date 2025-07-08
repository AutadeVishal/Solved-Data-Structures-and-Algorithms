class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        int cols = image[0].size();
        int currColor = image[sr][sc];

        if (currColor == newColor) return image; 

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor; 

        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i];
                int newCol = col + dc[i];

                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols &&
                    image[newRow][newCol] == currColor) {
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
        return image;
    }
};
