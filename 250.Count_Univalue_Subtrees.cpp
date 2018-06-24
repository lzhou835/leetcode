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
    bool isUnivalSubtrees(TreeNode * root, int val, int & res){
        if(!root) return true;
        if(!isUnivalSubtrees(root->left, root->val, res) | !isUnivalSubtrees(root->right, root->val, res)){
            return false;
        }
        res++;
        return root->val==val;
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        int res=0;
        isUnivalSubtrees(root, -1, res);
        return res;
    }
};
