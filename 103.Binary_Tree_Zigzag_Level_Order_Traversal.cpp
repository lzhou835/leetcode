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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(root);
        vector<int> tmp;
        
        while(!s1.empty() || !s2.empty()){
            while(!s1.empty()){
                TreeNode * cur=s1.top();
                s1.pop();
                tmp.push_back(cur->val);
                
                if(cur->left) s2.push(cur->left);
                if(cur->right) s2.push(cur->right);
            }
            if(!tmp.empty()) ret.push_back(tmp);
            tmp.clear();
            
            while(!s2.empty()){
                TreeNode * cur=s2.top();
                s2.pop();
                tmp.push_back(cur->val);
                
                if(cur->right) s1.push(cur->right);
                if(cur->left) s1.push(cur->left);
            }
            if(!tmp.empty()) ret.push_back(tmp);
            tmp.clear();
        }
        
        return ret;
    }
};
