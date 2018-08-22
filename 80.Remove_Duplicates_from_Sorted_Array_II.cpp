class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int pre=0, cur=1, cnt=1;
        while(cur<n){
            if(nums[cur]==nums[pre] && cnt==0) cur++;
            else{
                if(nums[cur]==nums[pre]) cnt--;
                else cnt=1;
                nums[++pre]=nums[cur++];
            }
        }
        return pre+1;
    }
};
