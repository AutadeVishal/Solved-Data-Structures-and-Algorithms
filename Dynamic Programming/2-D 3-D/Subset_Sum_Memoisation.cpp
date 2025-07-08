class Solution {
public:

    int solve(int idx, int target, vector<vector<int>>& dp, vector<int>& arr) {
        if (idx == 0) {
            if (target == 0 && arr[0] == 0) return 2; // include 0 and exclude 0 1+1
            if (target == 0 || arr[0] == target) return 1;
            return 0;//this route fails
        }       
        if (dp[idx][target] != -1) return dp[idx][target];

        int notTaken = solve(idx - 1, target, dp, arr) ;
        int taken = 0;
        if (arr[idx] <= target)
            taken = solve(idx - 1, target - arr[idx], dp, arr);

        return dp[idx][target] = (taken + notTaken);
    }

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(n - 1, target, dp, arr);
    }
};
