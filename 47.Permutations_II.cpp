class Solution {
public:
    void solve(vector<int> & nums, vector<bool> & used, vector<vector<int> > & ret, vector<int> & tmp)
    {
        if(tmp.size() == nums.size())
        {
            ret.push_back(tmp);
            return;
        }

        for(int i=0;i<nums.size();i++)
        {
            if(used[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            used[i]=true;
            tmp.push_back(nums[i]);
            solve(nums, used, ret, tmp);
            used[i]=false;
            tmp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ret;

        if(nums.empty()) return ret;
        sort(nums.begin(),nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> tmp;

        solve(nums, used, ret, tmp);

        return ret;
    }
};

