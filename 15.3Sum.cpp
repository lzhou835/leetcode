class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > ret;
        if(nums.size()<3) return ret;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int target=0;
            int sum2=target-nums[i];
            int left=i+1;
            int right=nums.size()-1;
            while(left<right)
            {
                if(nums[left]+nums[right]<sum2)
                {
                    left++;
                }else if(nums[left]+nums[right]>sum2)
                {
                    right--;
                }else if(nums[left]+nums[right]==sum2)
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ret.push_back(tmp);
                    left++;
                    right--;

                    while(nums[left]==nums[left-1]) left++;
                    while(nums[right]==nums[right+1]) right++;
                }
            }
        }

        return ret;
    }
};
~  
