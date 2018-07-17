class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cur=INT_MAX, count=0, ret=0;
        for(int num:nums){
            if(num>cur) count++;
            else count=1;
            ret=max(count, ret);
            cur=num;
        }
        return ret;
    }
};
