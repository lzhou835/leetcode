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
    void solve(TreeNode * root, TreeNode *  & pre, int & count, int & mx, vector<int> & ret){
        if(!root) return;
        solve(root->left, pre, count, mx, ret);
        if(pre){
            count=(root->val==pre->val)?count+1:1;
        }
        if(count>=mx){
            if(count>mx) ret.clear();
            ret.push_back(root->val);
            mx=count;
        }
        pre=root;
        solve(root->right, pre, count, mx, ret);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        int count=1, mx=0;
        TreeNode * pre=NULL;

        solve(root, pre, count, mx, ret);

        return ret;
    }
};
