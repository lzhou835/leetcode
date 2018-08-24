class Solution {
public:
    void solve(vector<int> & nums, int start, vector<int> & prefix, set<vector<int>> & ret){
        ret.insert(prefix);

        for(int i=start;i<nums.size();i++){
            prefix.push_back(nums[i]);
            solve(nums, i+1, prefix, ret);
            prefix.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ret;
        vector<int> prefix;
        sort(nums.begin(), nums.end());
        solve(nums, 0, prefix, ret);

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

