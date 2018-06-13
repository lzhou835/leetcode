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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        unordered_set<int> s;
        queue<TreeNode *> q({root});
        while(!q.empty()){
            TreeNode * p=q.front();
            q.pop();
            if(s.count(k-p->val)) return true;
            s.insert(p->val);
            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
        return false;
    }
};
