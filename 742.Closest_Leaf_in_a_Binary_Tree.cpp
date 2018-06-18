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
    TreeNode * findk(TreeNode * root, int k, unordered_map<TreeNode *, TreeNode *> & back){
        if(root->val==k) return root;
        if(root->left){
            back[root->left]=root;
            TreeNode * left=findk(root->left, k, back);
            if(left) return left;
        }
        
        if(root->right){
            back[root->right]=root;
            TreeNode * right=findk(root->right, k, back);
            if(right) return right;
        }
        return NULL;
    }
    
    int findClosestLeaf(TreeNode* root, int k) {
        unordered_map<TreeNode *, TreeNode *> back;
        TreeNode * t=findk(root, k, back);
        unordered_set<TreeNode *> visited{{t}};
        queue<TreeNode *>  q{{t}};
        while(!q.empty()){
            TreeNode * node=q.front();
            q.pop();
            if(!node->left &&!node->right) return node->val;
            if(node->left && !visited.count(node->left)){
                visited.insert(node->left);
                q.push(node->left);
            }
            
            if(node->right && !visited.count(node->right)){
                visited.insert(node->right);
                q.push(node->right);
            }
            
            if(back.count(node) && !visited.count(back[node])){
                visited.insert(back[node]);
                q.push(back[node]);
            }
        }
        return -1;
    }
};
