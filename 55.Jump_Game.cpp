class Solution {
public:
    bool canJump(vector<int>& nums) {
        int dst=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>dst || dst>=n-1) break;
            dst=max(dst, i+nums[i]);
        }

        return dst>=n-1;
    }
};

