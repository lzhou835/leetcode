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
    void recoverTree(TreeNode* root) {
        TreeNode * first=NULL, * second=NULL, * parent=NULL;
        TreeNode * pre=NULL, * cur;
        cur=root;
        while(cur){
            if(!cur->left){
                if(parent && parent->val > cur->val){
                    if(!first) first=parent;
                    second=cur;
                }
                parent=cur;
                cur=cur->right;
            }else{
                pre=cur->left;
                while(pre->right && pre->right != cur) pre=pre->right;
                if(!pre->right){
                    pre->right=cur;
                    cur=cur->left;
                }else{
                    pre->right=NULL;
                    if(parent->val > cur->val){
                        if(!first) first=parent;
                        second=cur;
                    }
                    parent=cur;
                    cur=cur->right;
                }
            }
        }
        if(first && second) swap(first->val, second->val);
    }
};
