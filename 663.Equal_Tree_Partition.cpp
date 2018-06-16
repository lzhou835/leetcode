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
    int solve(TreeNode * root, unordered_map<int, int> & m){
        if(!root) return 0;
        int sum=root->val+solve(root->left, m)+solve(root->right, m);
        m[sum]++;
        return sum;
    }
    
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int, int> m;
        int sum=solve(root, m);
        if( sum== 0) return m[0] > 1;
        return sum%2==0 && m.count(sum/2);
    }
};
