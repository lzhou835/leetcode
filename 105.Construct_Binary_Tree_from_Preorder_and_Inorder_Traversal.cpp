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
    TreeNode * solve(vector<int> & preorder, int pleft, int pright, vector<int> & inorder, int ileft, int iright){
        if(pleft>pright || ileft>iright) return NULL;
        int i;
        for(i=ileft;i<=iright;i++){
            if(inorder[i]==preorder[pleft]) break;
        }
        TreeNode * ret=new TreeNode(preorder[pleft]);
        ret->left=solve(preorder, pleft+1, pleft+i-ileft, inorder, ileft, i-1);
        ret->right=solve(preorder, pleft+i-ileft+1, pright, inorder, i+1, iright);
        return ret;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

