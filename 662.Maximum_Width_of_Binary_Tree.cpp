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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode *, int>> q;
        int res=0;
        q.push({root, 1});
        while(!q.empty()){
            int left=q.front().second, right=left, n=q.size();
            for(int i=0;i<n;i++){
                auto t=q.front();
                q.pop();
                right=t.second;
                if(t.first->left) q.push({t.first->left, 2*right});
                if(t.first->right) q.push({t.first->right, 2*right+1});
            }
            res=max(res, right-left+1);
        }
        return res;
    }
};
