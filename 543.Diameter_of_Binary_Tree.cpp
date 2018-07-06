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
        int left=solve(root->left, ret);
        int right=solve(root->right, ret);
        ret=max(ret, left+right);
        return max(left, right)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ret=0;
        solve(root, ret);
        return ret;
    }
};

