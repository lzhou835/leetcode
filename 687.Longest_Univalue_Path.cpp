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
    int solve(TreeNode * node, TreeNode * parent, int & len){
        if(node==NULL) return 0;
        int left=solve(node->left, node, len);
        int right=solve(node->right, node, len);
        left=(node->left && node->left->val==node->val)?left+1:0;
        right=(node->right && node->right->val==node->val)?right+1:0;
        len=max(len, left+right);
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL) return 0;
        int ret=0;
        solve(root, root, ret);
        return ret;
    }
};

