class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0, res=0;
        for(auto num:nums){
            cnt=(num==0)?0:cnt+1;
            res=max(cnt, res);
        }
        return res;
    }
};
