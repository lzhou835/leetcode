class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(root == NULL) return ret;

        stack<TreeNode *> tmp;

        TreeNode * p=root;

        while(p!=NULL || !tmp.empty()){
            if(p)
            {
                tmp.push(p);
                p=p->left;
            }else{
                p=tmp.top();
                ret.push_back(p->val);
                tmp.pop();
                p=p->right;
            }
        }
        return ret;
    }
};

