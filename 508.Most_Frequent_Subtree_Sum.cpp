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
    int postorder(TreeNode * root, unordered_map<int, int> & m, vector<int> & res, int & cnt){
        if(!root) return 0;
        int left=postorder(root->left, m, res, cnt);
        int right=postorder(root->right, m, res, cnt);
        int sum=left+right+root->val;
        m[sum]++;
        if(m[sum]>=cnt){
            if(m[sum]>cnt) res.clear();
            res.push_back(sum);
            cnt=m[sum];
        }
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> m;
        int cnt=0;
        postorder(root, m, res, cnt);
        return res;
    }
};
