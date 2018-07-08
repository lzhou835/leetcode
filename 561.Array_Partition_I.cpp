class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ret=0, n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i+=2)
        {
            ret+=nums[i];
        }
        return ret;
    }
};
