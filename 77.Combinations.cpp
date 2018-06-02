class Solution {
public:
    void solve(int n, int k, int cur, vector<int> & tmp, vector<vector<int>> & ret){
        if(tmp.size()==k){
            ret.push_back(tmp);
            return;
        } 
        for(int i=cur;i<=n;i++){
            tmp.push_back(i);
            solve(n, k, i+1, tmp, ret);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> tmp;
        solve(n, k, 1, tmp, ret);
        return ret;
    }
};
