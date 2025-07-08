/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode *>st;
        st.push(p);
        st.push(q);
        
        while(!st.empty()){
            TreeNode * two=st.top(); st.pop();
            TreeNode * one=st.top(); st.pop();
            if(!two &&  !one) continue;
            if(!two || !one || one->val!=two->val) return false;
            st.push(one->left);
            st.push(two->left);
            st.push(one->right);
            st.push(two->right);

        }
        return true;
    }
};
