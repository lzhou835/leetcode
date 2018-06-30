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
    void helper(TreeNode * node, int v, int out, int & res){
        if(!node) return;
        if(node->val==v+1) out++;
        else out=1;
        res=max(res, out);
        helper(node->left, node->val, out, res);
        helper(node->right, node->val, out, res);
    }
    
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        int res=0;
        helper(root, root->val, 0, res);
        return res;
    }
};
