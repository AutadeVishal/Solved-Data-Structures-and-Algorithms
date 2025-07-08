class Solution {
public:
    void solve(string &output, int open, int close, vector<string>& ans, int n) {
        if (open == n && close == n) {
            ans.push_back(output);
            return;
        }
        if (open < n) {
            output.push_back('(');
            solve(output, open + 1, close, ans, n);
            output.pop_back();
        }
        if (close < open) {
            output.push_back(')');
            solve(output, open, close + 1, ans, n);
            output.pop_back(); 
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output;
        solve(output, 0, 0, ans, n);
        return ans;
    }
};
