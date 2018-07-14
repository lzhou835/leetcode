class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret(2, 0), cnt(nums.size(), 0);
        for(auto num:nums) cnt[num-1]++;
        for(int i=0;i<nums.size();i++){
            if(ret[0]!=0 && ret[1]!=0) return ret;
            if(cnt[i]==2) ret[0]=i+1;
            else if(cnt[i]==0) ret[1]=i+1;
        }
        return ret;
    }
};

