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
void mapThemAll(unordered_map<TreeNode *,TreeNode *>&m,TreeNode * &root,TreeNode * &pappa,int &start,TreeNode * &startNode){
    if(!root) return;
    if(root->val==start) startNode=root;
    m[root]=pappa;
    pappa=root;
    mapThemAll(m,root->left,pappa,start,startNode);
    pappa=root;
    mapThemAll(m,root->right,pappa,start,startNode);
}

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode * ,TreeNode *>m;
            TreeNode * startNode =NULL;
            TreeNode * pappa=NULL;
            mapThemAll(m,root,pappa,start,startNode);
            queue<TreeNode *>q;
            q.push(startNode);
            unordered_map<TreeNode * ,bool>visited;
            int count=-1;
            while(!q.empty()){
                
                int s=q.size();
                for (int i=0;i<s;i++){
            
                    TreeNode * curr=q.front();
                    q.pop();
                    visited[curr]=true;
                    if(m.find(curr)!=m.end() && !visited[m[curr]] && m[curr]!=NULL )
                    { q.push(m[curr]);
                    }
                    
                    if(curr->left && !visited[curr->left]) 
                    {q.push(curr->left);
                    }
                    if(curr->right && !visited[curr->right]) 
                    {q.push(curr->right);
                    }

                }
                count++;
            }
            return count;
        }
    
};
