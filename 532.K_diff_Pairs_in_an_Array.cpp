class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ret=0;
        unordered_map<int, int> m;
        for(auto n:nums) m[n]++;
        for(auto i:m){
            if(k==0 && i.second>1) ret++;
            if(k>0 && m.count(k+i.first)) ret++;
        }
        return ret;
    }
};
