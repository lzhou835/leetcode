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
    TreeNode * solve(vector<int> & inorder, int ileft, int iright, vector<int> & postorder, int pleft, int pright){
        if(pleft>pright || ileft>iright) return NULL;
        int i;
        for(i=ileft;i<=iright;i++){
            if(inorder[i]==postorder[pright]) break;
        }
        TreeNode * ret=new TreeNode(postorder[pright]);
        ret->left=solve(inorder, ileft, i-1, postorder, pleft, pleft+i-ileft-1);
        ret->right=solve(inorder, i+1, iright, postorder, pleft+i-ileft, pright-1);
        return ret;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};

