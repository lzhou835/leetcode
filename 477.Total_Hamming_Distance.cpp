class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ret=0, n=nums.size();
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int num:nums){
                if(num & (1<<i)) cnt++;
            }
            ret+=(n-cnt)*cnt;
        }
        return ret;
    }
};
