class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ret;
        if(candidates.size()<1) return ret;
        vector<int> tmp;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, ret, tmp, 0);

        return ret;
    }

    void solve(vector<int> & candidates, int target, vector<vector<int> > & ret, vector<int> & tmp, int indice){
        if(target==0)
        {
            ret.push_back(tmp);
            return;
        }

        for(int i=indice;i<candidates.size();i++)
        {
            if(i>indice && candidates[i]==candidates[i-1]) continue;
            if(target>=candidates[i])
            {
                tmp.push_back(candidates[i]);
                solve(candidates, (target-candidates[i]), ret, tmp, i);
                tmp.pop_back();
            }
        }
    }
};

