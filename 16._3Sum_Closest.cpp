class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dif=2147483647;
        int ret;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;

            int target2=target-nums[i];
            int left=i+1;
            int right=nums.size()-1;

            while(left<right)
            {
                int tmpdif=nums[left]+nums[right]-target2;
                if(abs(tmpdif)<abs(dif)) dif=tmpdif;
                if(nums[left]+nums[right]==target2)
                {
                    return target;
                }else if(tmpdif>0)
                {
                    right--;
                }else if(tmpdif<0)
                {
                    left++;
                }
            }
        }
        return target+dif;
    }
};
~  
