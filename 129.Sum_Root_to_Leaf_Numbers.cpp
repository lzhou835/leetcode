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
    int solve(TreeNode * root, int sum){
        if(!root) return 0;
        sum=sum*10+root->val;
        if(!root->left && !root->right) return sum;
        return solve(root->left, sum)+solve(root->right, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};
