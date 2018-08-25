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
    void dfs(TreeNode * root, int sum, vector<int> & prefix, vector<vector<int>> & ret){
        if(!root) return;
        prefix.push_back(root->val);
        if(!root->left && !root->right && root->val==sum){
            ret.push_back(prefix);
        }
        if(root->left) dfs(root->left, sum-root->val, prefix, ret);
        if(root->right) dfs(root->right, sum-root->val, prefix, ret);
        prefix.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> prefix;
        dfs(root, sum, prefix, ret);
        return ret;
    }
};
