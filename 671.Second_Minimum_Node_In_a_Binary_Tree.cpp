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
    void solve(TreeNode * root, int & first, int & second){
        if(!root) return;
        if(root->val!=first && root->val<second) second=root->val;
        solve(root->left, first, second);
        solve(root->right, first, second);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int first=root->val;
        int second=INT_MAX;
        solve(root, first, second);
        return (second==first || second==INT_MAX)?-1:second;
    }
};
