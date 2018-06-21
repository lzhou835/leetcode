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
    int solve(TreeNode * root, vector<vector<int>> & res){
        if(!root) return -1;
        int depth=1+max(solve(root->left, res), solve(root->right, res));
        if(depth>=res.size()) res.resize(depth+1);
        res[depth].push_back(root->val);
        return depth;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        solve(root, res);
        return res;
    }
};
