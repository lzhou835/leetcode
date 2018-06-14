class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int left=0, right=nums.size()-1, res=nums[left];
        while(left<right-1){
            int mid=left+(right-left)/2;
            if(nums[left]<nums[mid]){
                res=min(nums[left], res);
                left=mid+1;
            }else if(nums[left]>nums[mid]){
                right=mid;
            }else left++;
        }
        res=min(res, nums[left]);
        res=min(res, nums[right]);
        return res;
    }
};
