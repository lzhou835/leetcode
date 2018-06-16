class Solution {
public:
    void solve(int k, int n, int level, vector<vector<int>> & res, vector<int> & out){
        if(n<0) return;
        if(n==0 && out.size()==k) res.push_back(out);
        for(int i=level;i<=9;i++){
            out.push_back(i);
            solve(k, n-i, i+1, res, out);
            out.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> out;
        solve(k, n, 1, res, out);
        return res;
    }
};
