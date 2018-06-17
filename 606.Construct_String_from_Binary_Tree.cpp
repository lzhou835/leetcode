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
    void solve(TreeNode * t, string & res){
        if(!t) return;
        res+="("+to_string(t->val);
        if(!t->left && t->right) res+="()";
        solve(t->left, res);
        solve(t->right, res);
        res+=")";
    }
    
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string res="";
        solve(t, res);
        return string(res.begin()+1, res.end()-1);
    }
};
