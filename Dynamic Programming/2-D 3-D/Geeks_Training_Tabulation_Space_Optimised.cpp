class Solution {
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> dp = arr[0];  

        for (int i = 1; i < n; i++) {
            vector<int> temp(3, 0);
            for (int j = 0; j < 3; j++) {
                int maxi = INT_MIN;
                for (int k = 0; k < 3; k++) {
                    if (k != j) {
                        maxi = max(maxi, arr[i][j] + dp[k]);
                    }
                }
                temp[j] = maxi;
            }
            dp = temp;
        }

        return max({dp[0], dp[1], dp[2]});
    }
};
