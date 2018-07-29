class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(solve_left(nums, target));
        ret.push_back(solve_right(nums, target));
        return ret;
    }

    int solve_left(vector<int> & nums, int target)
    {
        if(nums.size() == 0) return -1;
        int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(target<nums[mid])
            {
                right=mid-1;
            }else if(target>nums[mid])
            {
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        if(left>=0 && left<=nums.size()-1 && nums[left]==target) return left;
        return -1;
    }

     int solve_right(vector<int> & nums, int target)
    {
        if(nums.size() == 0) return -1;
        int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(target<nums[mid])
            {
                right=mid-1;
            }else if(target>nums[mid])
            {
                left=mid+1;
            }else{
                left=mid+1;
            }
        }
        if(right>=0 && right<=nums.size()-1 && nums[right]==target) return right;
        return -1;
    }
};

