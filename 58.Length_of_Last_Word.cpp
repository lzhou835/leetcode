class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                if(i!=0 && s[i-1]==' ') ret=1;
                else ret++;
            }
        }
        return ret;
    }
};
