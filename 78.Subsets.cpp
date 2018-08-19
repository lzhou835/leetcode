class Solution {
public:
    void solve(vector<int> & nums, int start, vector<int> & prefix, vector<vector<int>> & ret){
        ret.push_back(prefix);

        for(int i=start;i<nums.size();i++){
            prefix.push_back(nums[i]);
            solve(nums, i+1, prefix, ret);
            prefix.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> prefix;
        solve(nums, 0, prefix, ret);
        return ret;
    }
};

