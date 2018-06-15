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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int mx=INT_MIN, id=0;
        for(int i=0;i<nums.size();i++){
            if(mx<nums[i]){
                mx=nums[i];
                id=i;
            }
        }
        
        TreeNode * t=new TreeNode(mx);
        vector<int> left=vector<int>(nums.begin(), nums.begin()+id);
        vector<int> right=vector<int>(nums.begin()+id+1, nums.end());
        t->left=constructMaximumBinaryTree(left);
        t->right=constructMaximumBinaryTree(right);
        return t;
    }
};
