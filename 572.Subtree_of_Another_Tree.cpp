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
    bool sametree(TreeNode * s, TreeNode * t){
        if(!s && !t) return true;
        if(!s || !t) return false;
        if(s->val!=t->val) return false;
        return sametree(s->left, t->left) && sametree(s->right, t->right);
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;
        if(sametree(s, t)) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
