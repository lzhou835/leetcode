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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode *> ret;
        if(n==0) return ret;
        ret=solve(1, n);
        return ret;
    }

    vector<TreeNode *> solve(int minval, int maxval)
    {
        vector<TreeNode *> ret;

        if(minval>maxval)
        {
            ret.push_back(NULL);
            return ret;
        }

        for(int i=minval;i<=maxval;i++)
        {
            vector<TreeNode *> left_subtree=solve(minval, i-1);
            vector<TreeNode *> right_subtree=solve(i+1, maxval);

            for(int m=0;m<left_subtree.size();m++)
            {
                for(int n=0;n<right_subtree.size();n++)
                {
                    TreeNode * root=new TreeNode(i);
                    root->left=left_subtree[m];
                    root->right=right_subtree[n];
                    ret.push_back(root);
                }
            }
        }

        return ret;
    }
};

