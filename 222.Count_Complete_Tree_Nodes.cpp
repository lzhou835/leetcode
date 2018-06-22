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
    int countNodes(TreeNode* root) {
        int lefth=0, righth=0;
        TreeNode * pleft=root;
        TreeNode * pright=root;
        while(pleft){
            lefth++;
            pleft=pleft->left;
        }
        while(pright){
            righth++;
            pright=pright->right;
        }
        if(lefth==righth) return pow(2, lefth)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
