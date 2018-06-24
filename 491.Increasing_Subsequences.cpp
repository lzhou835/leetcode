class Solution {
public:
    void solve(vector<int> & nums, int start, vector<int> & prefix, set<vector<int>> & ret){
        if(prefix.size()>=2) ret.insert(prefix);
        
        for(int i=start; i<nums.size();i++){
            if(!prefix.empty() && prefix.back()>nums[i]) continue;
            prefix.push_back(nums[i]);
            solve(nums, i+1, prefix, ret);
            prefix.pop_back();
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ret;
        
        vector<int> prefix;
        solve(nums, 0, prefix, ret);
        
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};
