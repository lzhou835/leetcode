class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int left=0;
        for(int right=0;right<nums.size();right++){
            if(right-left>k) m.erase(nums[left++]);
            auto a=m.lower_bound((long long)nums[right]-t);
            if(a!=m.end() && abs(a->first-nums[right])<=t) return true;
            m[nums[right]]=right;
        }
        return false;
    }
};
