class Solution {
  public:
    void solve(Node* root, int position, int level, map<int, pair<int, int>>& m) {
        if (!root) return;
        if (m.find(position) == m.end() || m[position].first <= level) {
            m[position] = {level, root->data};
        }
        solve(root->left, position - 1, level + 1, m);
        solve(root->right, position + 1, level + 1, m);
    }

    vector<int> bottomView(Node* root) {
        vector<int> v;
        if (!root) return v;
        map<int, pair<int, int>> m;

        solve(root, 0, 0, m);
        for (auto i : m) {
            v.push_back(i.second.second); 
        }

        return v;
    }
};
