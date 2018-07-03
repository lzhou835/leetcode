class Solution {
public:
    void dfs(vector<int> & nums, int target, int & count, vector<int> & tmp, int start, int sum){
        if(sum == target && start==nums.size())
        {
            count++;
            return;
        }else if(abs(target-sum)<=tmp[start]){
            dfs(nums, target, count, tmp, start+1, sum+nums[start]);
            dfs(nums, target, count, tmp, start+1, sum-nums[start]);
        }
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        int ret=0;
        int n=nums.size();
        vector<int> tmp(n,0);
        tmp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            tmp[i]=tmp[i+1]+nums[i];
        }

        dfs(nums, S, ret, tmp, 0, 0);

        return ret;
    }
};
