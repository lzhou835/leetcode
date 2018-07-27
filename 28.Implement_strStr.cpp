class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="") return 0;
        if(haystack=="" || needle.length()>haystack.length()) return -1;

        for(int i=0;i<=haystack.length()-needle.length();i++)
        {
            for(int j=0;j<=needle.length();j++)
            {
                if(j==needle.length()) return i;
                if(needle[j]!=haystack[i+j]) break;
            }
        }

        return -1;
    }
};
