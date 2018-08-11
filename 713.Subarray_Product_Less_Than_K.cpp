class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product=1;
        int count=0;
        int left=0;
        int n=nums.size();
        if(k<=1) return 0;

        for(int i=0;i<n;i++){
            product*=nums[i];
            while(product>=k) product/=nums[left++];
            count+=(i-left+1);
        }
        return count;
    }
};

