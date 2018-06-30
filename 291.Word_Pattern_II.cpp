class Solution {
public:
    bool find(unordered_map<char, string> & m, string pattern, int p, string str, int s){
        if(p==pattern.size() && s==str.size()) return true;
        if(p==pattern.size() || s==str.size()) return false;
        char c=pattern[p];
        for(int i=s;i<str.size();i++){
            string t=str.substr(s, i-s+1);
            if(m.count(c) && m[c]==t){
                if(find(m, pattern, p+1, str, i+1)) return true;
            }else if(!m.count(c)){
                bool flag=false;
                for(auto it:m){
                    if(it.second==t) flag=true;
                }
                if(!flag){
                    m[c]=t;
                    if(find(m, pattern, p+1, str, i+1)) return true;
                    m.erase(c);
                }
            }
        }
        return false;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        return find(m, pattern, 0, str, 0);
    }
};
