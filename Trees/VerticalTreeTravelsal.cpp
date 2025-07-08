class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
   void solve(Node* root, int position,int level,  map<int, map<int, vector<int>>>&m) {
        if (!root) return;
        m[position][level].push_back(root->data);
        if (root->left) {
            solve(root->left, position - 1,level+1, m);
        }
        if (root->right) {
            solve(root->right, position + 1,level+1, m);
        }
    }

    vector<int> verticalOrder(Node* root) {
        vector<int> v;
        if (!root) return v;
        map<int, map<int,vector<int>>> m;
        solve(root, 0,0, m); 
        for (auto& vertical : m) {
    for (auto& level : vertical.second) {
        v.insert(v.end(), level.second.begin(), level.second.end());
    }
}

        return v;
    }
};
