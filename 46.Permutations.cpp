class Solution {
public:
    void solve(vector<vector<int> > & ret, vector<int> & nums, int n, vector<bool> & used, vector<int> & tmp)
    {
        if(tmp.size()==n)
        {
            ret.push_back(tmp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if(used[i]) continue;
            tmp.push_back(nums[i]);
            used[i]=true;
            solve(ret, nums, n, used, tmp);
            used[i]=false;
            tmp.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ret;
        int n=nums.size();
        if(n==0) return ret;

        vector<int> tmp;
        vector<bool> used(n, false);
        solve(ret, nums, n, used, tmp);

        return ret;
    }
};
