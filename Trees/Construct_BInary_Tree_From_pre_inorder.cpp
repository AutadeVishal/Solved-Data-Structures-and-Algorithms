class Solution {
public:

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder.front());
        int currroot = preorder[0];
        preorder.erase(preorder.begin());
       
        int i = 0;
        while (inorder[i] != currroot) {
           i++;
        }
       vector<int> leftinorder(inorder.begin(), inorder.begin() + i);
        vector<int> rightinorder(inorder.begin() + i + 1, inorder.end());
        vector<int> leftpreorder(preorder.begin(), preorder.begin() +i);
        vector<int> rightpreorder(preorder.begin() + i, preorder.end());
        root->left = buildTree(leftpreorder, leftinorder);
        root->right = buildTree(rightpreorder, rightinorder);

        return root;
    }
};
