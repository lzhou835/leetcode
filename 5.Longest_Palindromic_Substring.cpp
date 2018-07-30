class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if (n<=1) return s;

        int k=n-1;
        int len=1;

        bool flag[1000][1000]={false};
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(s[i]==s[j] && (i+1>j-1 || flag[i+1][j-1])){
                    flag[i][j]=true;
                    if (j-i+1 > len)
                    {
                        k=i;
                        len=j-i+1;
                    }
                }
            }
        }
        return s.substr(k,len);
    }
};
