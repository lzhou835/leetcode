class Solution {
public:
    void solve(string & S, int i, vector<string> & ret){
        if(i==S.length()){
            ret.push_back(S);
            return;
        }
        solve(S, i+1, ret);
        if(isalpha(S[i])){
            S[i]^=(1<<5);
            solve(S, i+1, ret);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        solve(S, 0, ret);
        return ret;
    }
};
