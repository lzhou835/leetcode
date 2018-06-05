class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        string tmps1=s1, tmps2=s2;
        sort(tmps1.begin(), tmps1.end());
        sort(tmps2.begin(), tmps2.end());
        if(tmps1 != tmps2) return false;
        for(int i=1;i<s1.size();i++){
            string s11=s1.substr(0, i);
            string s12=s1.substr(i);
            string s21=s2.substr(0, i);
            string s22=s2.substr(i);
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
            s21=s2.substr(s2.size()-i);
            s22=s2.substr(0, s2.size()-i);
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
        }
        return false;
    }
};
