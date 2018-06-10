class Solution {
public:
    bool ispalindrome(string s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    void solve(string s, int start, vector<string> & prefix, vector<vector<string>> & ret){
        if(start==s.size()){
            ret.push_back(prefix);
            return;
        }
        
        for(int i=start;i<s.size();i++){
            if(ispalindrome(s, start, i)){
                prefix.push_back(s.substr(start, i-start+1));
                solve(s, i+1, prefix, ret);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> prefix;
        solve(s, 0, prefix, ret);
        return ret;
    }
};
