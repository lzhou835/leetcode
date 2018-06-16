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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        vector<int> res, right;
        TreeNode * l=root->left, * r=root->right, * p=root;
        if(root->left || root->right) res.push_back(root->val);
        while(l && (l->left || l->right)){
            res.push_back(l->val);
            if(l->left) l=l->left;
            else l=l->right;
        }
        
        stack<TreeNode *> s;
        while(p || !s.empty()){
            if(p){
                s.push(p);
                if(!p->left && !p->right) res.push_back(p->val);
                p=p->left;
            }else{
                p=s.top();
                s.pop();
                p=p->right;
            }
        }
        while(r && (r->left || r->right)){
            right.push_back(r->val);
            if(r->right) r=r->right;
            else r=r->left;
        }
        res.insert(res.end(), right.rbegin(), right.rend());
        return res;
    }
};
