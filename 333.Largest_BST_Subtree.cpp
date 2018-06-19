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
    bool validBST(TreeNode * root, int & mn, int & mx, int & res){
        if(!root) return true;
        int left_n=0, right_n=0;
        int left_mn=INT_MIN, left_mx=INT_MAX, right_mn=INT_MIN, right_mx=INT_MAX;
        bool left=validBST(root->left, left_mn, left_mx, left_n);
        bool right=validBST(root->right, right_mn, right_mx, right_n);
        if(left && right){
            if((!root->left || root->val > left_mx) && (!root->right || root->val < right_mn)){
                res=left_n+right_n+1;
                mn=root->left?left_mn:root->val;
                mx=root->right?right_mx:root->val;
                return true;
            }
        }
        res=max(left_n, right_n);
        return false;
    }
    
    int largestBSTSubtree(TreeNode* root) {
        int res=0;
        int mn=INT_MIN, mx=INT_MAX;
        bool d=validBST(root, mn, mx, res);
        return res;
    }
};
