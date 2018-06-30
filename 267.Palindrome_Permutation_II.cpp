class Solution {
public:
    void permutations(unordered_map<char, int> & m, vector<string> & res, string mid, int size, string out){
        if(out.size()>=size){
            res.push_back(out+mid+string(out.rbegin(), out.rend()));
            return;
        }
        
        for(auto & a:m){
            if(a.second>0){
                a.second--;
                permutations(m, res, mid, size, out+a.first);
                a.second++;
            }
        }
    }
    
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        string t="", mid="";
        unordered_map<char, int> m;
        for(auto c:s) m[c]++;
        for(auto & it:m){
            if(it.second%2==1) mid+=it.first;
            it.second/=2;
            t+=string(it.second, it.first);
            if(mid.size()>1) return {};
        }
        
        permutations(m, res, mid, t.size(), "");
        
        return res;
    }
};
