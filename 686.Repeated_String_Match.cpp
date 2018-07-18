class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int al=A.length();
        int bl=B.length();
        string tmp=A;
        int count=1;
        while(tmp.length()<bl){
            tmp+=A;
            count++;
        }
        if(tmp.find(B)!=string::npos) return count;
        tmp+=A;
        count++;
        return (tmp.find(B)==string::npos)?-1:count;
    }
};

