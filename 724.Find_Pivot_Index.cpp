class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(), nums.end(),0);
        int cur=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(sum-nums[i]==2*cur) return i;
            cur+=nums[i];
        }
        return -1;
    }
};
