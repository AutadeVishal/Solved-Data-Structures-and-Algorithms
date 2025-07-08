class Solution {
  public:
    // Function to return the lowest common ancestor in a Binary Tree.
    bool found = false;
    
    void solve(Node*& root, int& n, vector<Node*>& v1) {
        if (!root) return;

        if (root->data == n) {
            found = true;
        }

        if (!found) {
            solve(root->left, n, v1);
        }
        if (!found) {
            solve(root->right, n, v1);
        }

        if (found) {
            v1.push_back(root);
            return;
        }
    }

    Node* lca(Node* root, int n1, int n2) {
        if (!root) return NULL;

        vector<Node*> v1;
        vector<Node*> v2;

        solve(root, n1, v1);
        if (!found) return NULL;

        found = false; // Reset the `found` variable for the second node
        solve(root, n2, v2);
        if (!found) return NULL;

        Node* ans = NULL;
        for (auto i : v1) {
            for (auto j : v2) {
                if (i->data == j->data) {
                    ans = i;
                    break;
                }
            }
            if(ans) break;
        }
        return ans;
    
