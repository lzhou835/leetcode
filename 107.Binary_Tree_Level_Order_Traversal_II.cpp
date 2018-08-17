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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL) return ret;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            vector<int> onelevel;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode * node=q.front();
                q.pop();
                onelevel.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ret.insert(ret.begin(), onelevel);
        }
        return ret;
    }
};

