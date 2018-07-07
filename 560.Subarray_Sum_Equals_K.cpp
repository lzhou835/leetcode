class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, count=0;
        unordered_map<int, int> hashmap{{0,1}};
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            count+=hashmap[sum-k];
            hashmap[sum]++;
        }
        return count;
    }
};

