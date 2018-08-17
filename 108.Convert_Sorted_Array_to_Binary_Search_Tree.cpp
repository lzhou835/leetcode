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
    TreeNode * solve(vector<int> & nums, int left, int right){
        if(left>right) return NULL;
        int mid=left+(right-left)/2;
        TreeNode * ret=new TreeNode(nums[mid]);
        ret->left=solve(nums, left, mid-1);
        ret->right=solve(nums, mid+1, right);
        return ret;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};
