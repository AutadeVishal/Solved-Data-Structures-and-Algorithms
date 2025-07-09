/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void updateParent(TreeNode * &root ,unordered_map<TreeNode *,TreeNode *>&m){
    if(!root) return;
    if(root->left) {
        updateParent(root->left,m);
        m[root->left]=root;
    }
    if(root->right){
        updateParent(root->right,m);
        m[root->right]=root;
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target) return {}; 
        queue<TreeNode * >q;
        unordered_map<TreeNode *,TreeNode *>parentOf;
        updateParent(root,parentOf);
        q.push(target);
        unordered_map<TreeNode *,bool>visited;
        while(!q.empty() && k!=0){
            int size=q.size();
            for(int i=0;i<size;i++){
                 TreeNode * curr=q.front();
            q.pop();
            visited[curr]=true;
            if(curr->left && !visited.count(curr->left)) q.push(curr->left);
            if(curr->right && !visited.count(curr->right)) q.push(curr->right);
            if(curr!=root ){
                TreeNode * parent=parentOf[curr];
                if(!visited.count(parentOf[curr]))
                q.push(parentOf[curr]);
            }
            }
           k--;
        }
        vector<int>ans;
        int size=q.size();
        for(int i=0;i<size;i++){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
