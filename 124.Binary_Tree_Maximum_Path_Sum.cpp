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
    int solve(TreeNode * root, int & ret){
        if(!root) return 0;
        int left=max(solve(root->left, ret), 0);
        int right=max(solve(root->right, ret), 0);
        ret=max(ret, (left+right+root->val));
        return max(left, right)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int ret=INT_MIN;
        solve(root, ret);
        return ret;
    }
};
