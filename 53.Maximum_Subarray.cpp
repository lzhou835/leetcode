class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<1) return 0;
        int maxsum=nums[0];
        int currentsum=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            currentsum = currentsum<=0?nums[i]:currentsum+nums[i];
            maxsum = max(maxsum, currentsum);
        }

        return maxsum;
    }
};

